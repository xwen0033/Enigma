#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include "errors.h"

using namespace std;

/* checks while reading the file that applies to all config files*/
std::vector <int> check_general(const char* path){
    
    ifstream in;
    in.open(path);
    
    if (in.fail()||!in.is_open()) {
        cerr << "ERROR_OPENING_CONFIGURATION_FILE" << endl;
        exit(11);
    }
    
    int number;
    vector <int> config; //save each number into a config vector
    // check while reading the file until eof is reached
    while (!in.eof()){
        char character;
        in >> ws;
        character = in.peek();
        
        if (character == EOF) {
            break;
        }
        
        if (!isdigit(character)){
            cerr << "NON_NUMERIC_CHARACTER" << endl;
            exit(4);
            
        }else{
            in >> number;
            
            if (number < 0 || number > 25){
                cerr << "INVALID_INDEX" << endl;
                exit(3);
            }
            // if number already exists in config
            // sth mapped twice
            if ( find(config.begin(), config.end(), number) != config.end() ){
                if (strchr(path,'p')!= NULL){
                    cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION" << endl;
                    exit(5);                }
                
                if (strchr(path,'f')!= NULL){
                    cerr << "INVALID_REFLECTOR_MAPPING" << endl;
                    exit(9);
                }
                //the first 26 numbers cannot repeat in roto config
                if (config.size() < 26 && strchr(path,'o')!= NULL){
                    cerr << "INVALID_ROTOR_MAPPING" << endl;
                    exit(7);                }
            }
            config.push_back(number);
        }
}
    
    in.close();
    return config;
}

std::vector <int> check_plugboard(const char* path){
    vector <int> config = check_general(path);
    int length = config.size();
    // plugboard require even number of parameters
    if (length%2 != 0){
        cerr << "INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS" << endl;
        exit(6);
    }
    return config;
}
std::vector <int> check_reflector(const char* path){
    vector <int> config = check_general(path);
    int length = config.size();
    // reflector require 13 pairs
    if (length/2 != 13){
        cerr << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS" << endl;
        exit(10);
    }
    return config;
}

std::vector <int> check_rotor(const char* path){
    vector <int> config = check_general(path);
    
    int length = config.size();
    int num_notch = length - 26;
    
    //if does not provide a mapping for some input or no notch
    if (num_notch < 0){
        cerr << "INVALID_ROTOR_MAPPING" << endl;
        exit(7);
    }
    //situation where more than one input is mapped to the same output
    // was already accounted for during check general
    return config;
}

std::vector <int> check_rotor_pos(int num_rotor,const char* path){
    ifstream in;
    in.open(path);
    
    if (in.fail()||!in.is_open()){
        cerr << "ERROR_OPENING_CONFIGURATION_FILE" << endl;
        exit(11);
    }
    
    int number;
    vector <int> position;
    while (!in.eof()) {
        char character;
        in >> ws;
        character = in.peek();
        
        if (character == EOF) {
            break;
        }
        
        if (!isdigit(character)){
            cerr << "NON_NUMERIC_CHARACTER" << endl;
            exit(4);
        }else{
            in >> number;
            
            if (number < 0 || number > 25){
                cerr << "INVALID_INDEX" << endl;
                exit(3);
            }
            position.push_back(number);
        }
    }
    
    int length = position.size();
    if (length < num_rotor){
        cerr << "NO_ROTOR_STARTING_POSITION" << endl;
        exit(8);
    }
    return position;
}

std::string check_message(std::string message){
    int length = message.length();
    string output;
    for (int i = 0; i < length; i++){
        char character = message[i];
        if (!isspace(character)){
            if (character >= 'A' && character <= 'Z'){
                output += character;
            }else{
                cerr << "INVALID_INPUT_CHARACTER" << endl;
                exit(2);
            }
        }
    }
    return output;
}
