#include "reflector.h"

using namespace std;

Reflector::Reflector(const char* path){
    error = 0;
    
    vector<int> tmp;
    tmp = check_general(path);
    error = check_error();
    
    int length = tmp.size();
    // reflector require 13 pairs
    if (length/2 != 13){
        error = 10;
    }
    
    if (error == 0){
        for (int i = 0; i < length; i++){
            config.push_back(tmp[i]);
        }
    }
}

char Reflector::encrypt(const char input){
    return find_pair(config,input);
}
