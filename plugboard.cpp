#include "plugboard.h"

using namespace std;

Plugboard::Plugboard(vector <int> config){
    //initialise to no swaps
    for (int i = 0; i < 26; i++){
        swap[i] = i;
    }
    
    int pair = config.size();
    for (int i = 0; i < pair; i++){
        swap[config[2*i]] = config[2*i+1];
        swap[config[2*i+1]] = config[2*i];
    }
}

char Plugboard::encrypt(const char input){
    char output = swap[input-'A'] + 'A';
    return output;
}
    
