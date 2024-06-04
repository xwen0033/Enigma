#include "reflector.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

Reflector::Reflector(){}

int Reflector::check_config(char** argv){
    ifstream in;
    in.open(argv[2]);
    int number;
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
            if (find(config.begin(), config.end(), number) != config.end()){
                return INVALID_REFLECTOR_MAPPING;
            }
            config.push_back(number);
        }
    }

    in.close();

    int length = config.size();
    // reflector require 13 pairs
    if (length/2 != 13){
        return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }

    //set the reflector mapping according to the .rf file
    for (int i = 0; i < 26; i=i+2){
        int num1 = config[i];
        int num2 = config[i + 1];
        reflectsto[num1] = num2;
        reflectsto[num2] = num1;
    }

    return NO_ERROR;
}

int Reflector::encrypt(int input){
    return reflectsto[input];
}
