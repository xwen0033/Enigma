#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdio>
//#include "enigma.h"
#include "errors.h"


using namespace std;

int main(int argc, char **argv){
    
    if (argc < 4){ // if no rotor, stil 4 arguments needed
        cerr << "INSUFFICIENT_NUMBER_OF_PARAMETERS" << endl;
        exit(1);
    }
    
    vector <int> plugboard_config = check_plugboard(argv[1]);
    vector <int> reflector_config = check_reflector(argv[2]);
    
    int num_rotor = argc - 4;
    vector <vector <int> > rotor_config;
    if (num_rotor > 0){
        for (int i = 0; i < num_rotor; i++){
            vector <int> row = check_rotor(argv[3+i]);
            rotor_config.push_back(row);
        }
    }
    
    vector <int> position = check_rotor_pos(num_rotor,argv[argc-1]);

    //Enigma(plugboard_config, reflector_config, num_rotor, rotor_config);
    
    
    //prompt input message to enrypt/decrypt
    char input;
    //char output;
    string message;
    cout << "Please enter a message in uppercase to encrypt/decrypt: " << endl;
    cin >> ws;
    
    while (cin >> ws >> input) {
        if (input >= 'A' && input <= 'Z'){
            //output = myenigma.encrypt(input);
            //message += output;
            message += input;
        }else{
            cerr << endl;
            cerr << "INVALID_INPUT_CHARACTER" << endl;
            exit(2);
        }
        cout << message << endl;
    }
    //cout << "The encrypted/decrypted message is: " << endl;
    //cout << "You entered: " << message << endl;
    
    
    cout << "NO_ERROR" << endl;
    return 0;
}
