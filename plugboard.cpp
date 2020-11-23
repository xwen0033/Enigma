#include "plugboard.h"

using namespace std;

Plugboard::Plugboard(const char* path){
    error = 0;
    
    vector<int> tmp;
    tmp = check_general(path);
    error = check_error();
    
    int length = tmp.size();
    // plugboard require even number of parameters
    if (length%2 != 0){
        error = 6;
    }
    
    if (error == 0){
        //update config
        for (int i = 0; i < length; i++){
            config.push_back(tmp[i]);
        }
    }
}

char Plugboard::encrypt(const char input){
    return find_pair(config,input);
}
    
