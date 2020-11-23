#include "reflector.h"

using namespace std;

Reflector::Reflector(vector <int> config){
    //initialise reflector that all letters maps to itself
    for (int i=0; i<26; i++) {
        reflectsto[i]=i;
    }
    
    //reflector must have 13 pairs
    for (int i = 0; i < 13; i++){
        reflectsto[config[2*i]] = config[2*i+1];
        reflectsto[config[2*i+1]] = config[2*i];
    }
}

char Reflector::encrypt(const char input){
    char output = reflectsto[input-'A']+ 'A';
    return output;
}
