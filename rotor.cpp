#include "rotor.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
//constructor
Rotor::Rotor(){
    left = nullptr;
    right = nullptr;
}

void Rotor::set_left_rotor(Rotor* left_rotor){
    left = left_rotor;
}

void Rotor::set_right_rotor(Rotor* right_rotor){
    right = right_rotor;
}

int Rotor::getTop(){ return top; }

int Rotor::check_config(int num_roter, int rot_position, char **argv){
    ifstream in;
    in.open(argv[3+rot_position]);
    int number;
    int length = 0;
    vector<int> config; //save each number into a config vector
    // check while reading the file until eof is reached
    while (!in.eof())
    {
        char character;
        in >> ws;
        character = in.peek();

        if (character == EOF){break;}

        if (!isdigit(character)){ return NON_NUMERIC_CHARACTER; }
        else {
            in >> number;

            if (number < 0 || number > 25){ return INVALID_INDEX; }
            // if number already exists in config
            // sth mapped twice
            if (length < 26){
                if (find(config.begin(), config.end(), number) != config.end()){
                    return INVALID_ROTOR_MAPPING;
                }
            }
            config.push_back(number);
            length++;
        }
    }

    in.close();
    num_notch = length - 26;
    
    //if does not provide a mapping for some input or no notch
    if (num_notch < 0){ return INVALID_ROTOR_MAPPING; }

    //set the mapping according to the rot configure file
    for (int i = 0; i < 26; i++){
        wiring[0][i] = i;
        wiring[1][i] = config[i];
    }

    //set the notch position
    for (int i = 26; i < length; i++){
        notch[i-26]=config[i];
    }

    return NO_ERROR;
}

void Rotor::set_position(int pos){
    top = pos;
}

bool Rotor::on_notch(){
    for (int i = 0; i < num_notch; i++){
        if(notch[i] == top){ return true;}
    }
    return false;
}

int Rotor::indexof(int target){
    for (int i = 0; i < 26; i++){
        if (wiring[1][i]==target){
            return i;
        }
    }
    return -1;
}

int Rotor::forward_encrypt(int input){
    if (right != NULL){
        return wiring[1][(top+input - right->getTop())%26];
    } else {
        return (input+top)%26;
    }
    return -1;
}


int Rotor::backward_encrypt(int input){
    //reverse
    return (indexof(wiring[0][(input+top)%26])-top)%26;
}

void Rotor::rotate(){
    top = (top+1)%26;
}

