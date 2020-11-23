#include "enigma.h"

using namespace std;

Enigma::Enigma(int argc, char **argv){
    error = 0; // default to no error;
    plugboard = NULL;
    reflector = NULL;
    *rotor = NULL;
    num_rotor = argc - 4;
    
    //Initialise before checking configuration from command file
    if (argc < 4){ // if no rotor, stil 4 arguments needed
        error = 1;
    }
    
    if (error == 0){
        plugboard = new Plugboard(argv[1]);
        error = plugboard->error;
    }
     
    if (error == 0){
        reflector = new Reflector(argv[2]);
        error = reflector->error;
    }
    
    if (error == 0){
        if (num_rotor > 0){
            rotor = new Rotor*[num_rotor];
            
            for (int i = 0; i < num_rotor; i++){
                if (error == 0){
                    rotor[i] = new Rotor(argv[i+3]);
                    error = rotor[i]->error;
                }else{
                    for (int x = 0; x <= i; x++){
                        delete rotor[x];
                    }
                    delete [] rotor;
                }
            }
            //put each rotor into the position specified in the last file
            error = install_rotor(rotor,num_rotor,argv[argc-1]);
        }
    }
}

char Enigma::encrypt(const char input){
    //right most rotor rotates after typing each input letter
    if (num_rotor > 0) {
        rotor[num_rotor-1]->on_notch_top();
        //ignore the notch for the left most rotor
        for (int i = num_rotor-1; i > 0; i--){
            for (int x = 0; x < (rotor[i]->num_notch); x++ ){
                //when notch at the top the rotor to its left rotates
                if (rotor[i]->top == rotor[i]->notch[x]){
                    rotor[i-1]->on_notch_top();
                }
            }
        }
        
    }
    
    //input goes through plugboard
    char output;
    output = plugboard->encrypt(input);
    
    //input goes through each rotor from R to L
    if (num_rotor > 0) {
        for (int i = num_rotor-1; i >= 0; i--){
            output = rotor[i]->forward_encrypt(input);
        }
    }
    
    //input goes through reflector
    output = reflector->encrypt(input);
    
    //input goes back through rotors from L to R
    if (num_rotor > 0) {
        for (int i = 0; i <= num_rotor-1; i++){
            output = rotor[i]->backward_encrypt(input);
        }
    }
    
    //input goes through plugboard again
    output = plugboard->encrypt(input);
    
    return output;
}

