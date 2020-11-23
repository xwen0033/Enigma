#include "errors.h"

using namespace std;

char find_pair(std::vector <int> config, char input){
    char output;
    int num_input = input-'A';
    vector<int>::iterator itr = find(config.begin(), config.end(), num_input);
    
    // input swapped in plugboard config; will always find input in reflector config
    if (itr != config.end()){
        int index = distance(config.begin(), itr);
        int pair;
        if (index%2 == 1){ // odd index: find its connection an element before
            pair = config[index-1];
        } else{ // even index: find its connection an element after
            pair = config[index+1];
        }
        output = pair + 'A';
    }else {
        output = input;
    }
    return output;
}


static int errorstatus = 0;

/* checks while reading the file that applies to all config files*/
std::vector <int> check_general(const char* path){
    
    ifstream in;
    in.open(path);
    
    if (in.fail()||!in.is_open()) {
        errorstatus = 11;
    }
    
    int number;
    vector <int> config; //save each number into a config vector
    // check while reading the file until eof is reached
    while (!in.eof() && errorstatus == 0){
        char character;
        in >> ws;
        character = in.peek();
        
        if (character == EOF) {
            break;
        }
        
        if (!isdigit(character)){
            errorstatus = 4;
        }else{
            in >> number;
            
            if (number < 0 || number > 25){
                errorstatus = 3;
            }
            // if number already exists in config
            // sth mapped twice
            if ( find(config.begin(), config.end(), number) != config.end() ){
                if (strchr(path,'plug')!= NULL){
                    errorstatus = 5;
                }
                
                if (strchr(path,'refl')!= NULL){
                    errorstatus = 9;
                }
                //the first 26 numbers cannot repeat in roto config
                if (config.size() < 26 && strchr(path,'roto')!= NULL){
                        errorstatus = 7;
                    }
                }
            config.push_back(number);
        }
}
    
    in.close();
    return config;
}
    
int check_error(){
    return errorstatus;
}

