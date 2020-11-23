#include "rotor.h"

using namespace std;

Rotor::Rotor(const char* path){
    notch = NULL;
    num_notch = 0;
    top = 0;
    
//    if (num_notch > 0){
//        notch = new int[num_notch];
//        for (int i = 0; i < num_notch; i++){
//            notch[i] = config[26+i];
//        }
//    }
    
    
}

//destructor
Rotor::~Rotor(){
    delete [] notch; //avoid memory leak
}


int install_rotor(Rotor **rotor, int num_rotor, const char* path){
    return 1;
}

char Rotor::forward_encrypt(const char input){
    int num_input = input - 'A';
    return config[num_input] + 'A';
}


char Rotor::backward_encrypt(const char input){
    //reverse
    int num_input = input - 'A';
    vector<int>::iterator itr = find(config.begin(), config.end(), num_input);
    int index = distance(config.begin(), itr);
    return index +'A';
}

void Rotor::rotate(){
    //rotate
    int tmp = config[0];
    config.erase (config.begin());
    vector<int>::iterator it;
    it = config.end()-num_notch;
    config.insert (it, tmp);
    top = config[0];
}
