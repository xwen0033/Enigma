#include "plugboard.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

Plugboard::Plugboard(){ }

int Plugboard::check_config(char** argv){
    ifstream in;
    in.open(argv[1]);
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
                return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
            }
            config.push_back(number);
        }
    }

    in.close();

    int length = config.size();
    // plugboard require even number of parameters
    if (length%2 != 0){
        return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }

    //set the plugboard according to the pd configure file
    for (int i = 0; i < length; i = i + 2)
    {
        int num1 = config[i];
        int num2 = config[i + 1];
        swap[num1] = num2;
        swap[num2] = num1;
    }
    return NO_ERROR;
}

int Plugboard::encrypt(int input){
    return swap[input];
}
    
