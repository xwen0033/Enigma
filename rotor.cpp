#include "rotor.h"

using namespace std;

Rotor::Rotor(vector <int> config, int topp){
    notch = NULL;

    //initialise wiring
    for (int i = 0; i < 26; i++){
        wiring[0][i]=i;
        wiring[1][i]=config[i];
    }
    
    num_notch = config.size() - 26;
    top = topp;
    
    if (num_notch > 0){
        notch = new int[num_notch];
        for (int i = 0; i < num_notch; i++){
            notch[i] = config[26+i];
        }
    }
    
    
}

//destructor
Rotor::~Rotor(){
    delete [] notch; //avoid memory leak
}

char Rotor::forward_encrypt(const char input){
    char output = wiring[1][input-'A'] + 'A';
    return output;
}


char Rotor::backward_encrypt(const char input){
    //reverse
    for (int i = 0; i < 26; i++){
        if (wiring[1][i] == input - 'A'){
            char output = wiring[0][i] + 'A';
            return output;
        }
    }
    return input;
}

void Rotor::rotate(){
    top = wiring[1][1];
    //tem copy
    int tmp[2][26];
    tmp[0][25] = wiring[0][0];
    tmp[1][25] = wiring[1][0];
    for (int i = 0; i < 25; i++){
        tmp[0][i]=wiring[0][i+1];
        tmp[1][i]=wiring[1][i+1];
    }
    
    //change wiring
    for (int i = 0; i < 26; i++){
        wiring[0][i]=tmp[0][i];
        wiring[1][i]=tmp[1][i];
    }
    
}

