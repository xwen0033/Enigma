#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "enigma.h"
#include "errors.h"


using namespace std;

int main(int argc, char **argv){
    
    Enigma myenigma(argc, argv);
    
    switch(myenigma.error) {
    case 1:
        cerr << "INSUFFICIENT_NUMBER_OF_PARAMETERS" << endl;
        exit(1);
        //return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    case 3:
        cerr << "INVALID_INDEX" << endl;
        exit(3);
        //return INVALID_INDEX;
    case 4:
        cerr << "NON_NUMERIC_CHARACTER" << endl;
        exit(4);
        //return NON_NUMERIC_CHARACTER;
    case 5:
        cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION" << endl;
        exit(5);
        //return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
    case 6:
        cerr << "INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS" << endl;
        exit(6);
        //return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    case 7:
        cerr << "INVALID_ROTOR_MAPPING" << endl;
        exit(7);
        //return INVALID_ROTOR_MAPPING;
    case 8:
        cerr << "NO_ROTOR_STARTING_POSITION" << endl;
        exit(8);
        //return NO_ROTOR_STARTING_POSITION;
    case 9:
        cerr << "INVALID_REFLECTOR_MAPPING" << endl;
        exit(9);
        //return INVALID_REFLECTOR_MAPPING;
    case 10:
        cerr << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS" << endl;
        exit(10);
        //return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    case 11:
        cerr << "ERROR_OPENING_CONFIGURATION_FILE" << endl;
        exit(11);
        //return ERROR_OPENING_CONFIGURATION_FILE;
    default:
        break;
      }
    
    //prompt input message to enrypt/decrypt
    char input;
    char output;
    string message;
    cout << "Please enter a message in uppercase to encrypt/decrypt: " << endl;
    cin >> ws;
    
    while (cin >> ws >> input) {
        if (input >= 'A' && input <= 'Z'){
            output = myenigma.encrypt(input);
            message += output;
        }else{
            cerr << endl;
            cerr << "INVALID_INPUT_CHARACTER" << endl;
            exit(2);
        }
        
    }
    cout << "The encrypted/decrypted message is: " << endl;
    cout << message << endl;
    
    cout << "NO_ERROR" << endl;
    return 0;
}
