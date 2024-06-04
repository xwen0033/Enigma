#include "enigma.h"
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Enigma::Enigma(){ rotors = nullptr; }

int Enigma::check_config(int argc,char** argv){
    if (argc < 4){ return 1; }

    //check if all the configure files can open
    for (int i = 1; i < argc; i++)
    {
        ifstream in;
        in.open(argv[i]);
        if (in.fail()){ return ERROR_OPENING_CONFIGURATION_FILE; }
        in.close();
    }

    int error;
    error = plugboard.check_config(argv);
    if (error != 0){ return error; }

    num_rotor = argc-4;
    rotors = new Rotor[num_rotor];

    for (int i = 0; i < num_rotor; i++){
        error = rotors[i].check_config(num_rotor, i, argv);
        if (error != 0){ return error; }
        if (i>0){
            rotors[i].set_left_rotor(rotors+i-1);
        }
        if (i < num_rotor-1){
            rotors[i].set_right_rotor(rotors+i+1);
        }
    }

    ifstream in;
    in.open(argv[argc-1]);
    int number;
    vector <int> position;
    while (!in.eof()) {
        char character;
        in >> ws;
        character = in.peek();
        
        if (character == EOF) { break; }
        
        if (!isdigit(character)){
            return NON_NUMERIC_CHARACTER;
        }else{
            in >> number;
            if (number < 0 || number > 25){ return INVALID_INDEX; }
            position.push_back(number);
        }
    }
    in.close();
    int length = position.size();
    if (length < num_rotor){ return NO_ROTOR_STARTING_POSITION; }

    for (int i = 0; i < num_rotor; i++){
        rotors[i].set_position(position[i]);
    }

    error = reflector.check_config(argv);
    return error;
}

char Enigma::encrypt(char input){
    int number = input - 'A';
    number = plugboard.encrypt(number);

    //right most rotor rotates after typing each input letter
    if (num_rotor > 0) {
        rotors[num_rotor-1].rotate();
        //ignore the notch for the left most rotor
        for (int i = num_rotor-1; i >= 0; i--){
            number = rotors[i].forward_encrypt(number);
            if(i > 0 && rotors[i].on_notch()){
                rotors[i-1].rotate();
            }
        }
    }
    
    //input goes through reflector
    number = reflector.encrypt(number);
    
    //input goes back through rotors from L to R
    if (num_rotor > 0) {
        for (int i = 0; i <= num_rotor-1; i++){
            number= rotors[i].backward_encrypt(number);
        }
    }
    
    //input goes through plugboard again
    number = plugboard.encrypt(number);

    char output = number + 'A';
    
    return output;
}

//destructor
Enigma::~Enigma()
{
    if (rotors != nullptr)
    {
        delete[] rotors;
    }
}