#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdio>
#include "enigma.h"
#include "errors.h"


using namespace std;

int main(int argc, char **argv){
    
    if (argc < 4){ // if no rotor, stil 4 arguments needed
        cerr << "INSUFFICIENT_NUMBER_OF_PARAMETERS" << endl;
        exit(1);
    }
    
    vector <vector <int> > config;
    vector <int> plugboard_config = check_plugboard(argv[1]);
    config.push_back(plugboard_config);
    vector <int> reflector_config = check_reflector(argv[2]);
    config.push_back(reflector_config);
    
    int num_rotor = argc - 4;
    if (num_rotor > 0){
        for (int i = 0; i < num_rotor; i++){
            vector <int> rotor_config = check_rotor(argv[3+i]);
            config.push_back(rotor_config);
        }
        vector <int> position = check_rotor_pos(num_rotor,argv[argc-1]);
        config.push_back(position);
    }
    
    
    
    //Enigma myenigma(config);
    
    
    //prompt input message to enrypt/decrypt
    string message;
    cout << "Please enter a message in uppercase to encrypt/decrypt: " << endl;
    getline(cin, message);
    
    message = check_message(message);
    
    //cout << "The encrypted/decrypted message is: " << endl;
    //string output;
    //for (int i = 0; i < message.length(); i++){
        //char character = message[i];
        //char encoded = myenigma.encrypt(character);
        //output += encoded;
    //}
    
    //cout << output << endl;
    
    cout << "NO_ERROR" << endl;
    return 0;
}
