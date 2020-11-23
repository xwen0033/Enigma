#include "enigma.h"

using namespace std;

Enigma::Enigma(std::vector <vector <int> > config){
    plugboard = new Plugboard(config[0]);
    reflector = new Reflector(config[1]);
    *rotor = NULL;
    num_rotor = config.size()-3;
    if (num_rotor > 0){
        for (int i = 0; i < num_rotor; i++){
            int top = config[num_rotor+3][i];
            rotor[i] = new Rotor(config[2+i],top);
        }
    }
}

char Enigma::encrypt(char input){
    //right most rotor rotates after typing each input letter
    if (num_rotor > 0) {
        rotor[num_rotor-1]->rotate();
        //ignore the notch for the left most rotor
        for (int i = num_rotor-1; i > 0; i--){
            for (int x = 0; x < (rotor[i]->num_notch); x++ ){
                //when notch at the top the rotor to its left rotates
                if (rotor[i]->top == rotor[i]->notch[x]){
                    rotor[i-1]->rotate();
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

