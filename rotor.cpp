#include "rotor.h"

using namespace std;

Rotor::Rotor(const char* path){
    error = 0;
    notch = NULL;
    num_notch = 0;
    top = 0;
    
    vector<int> tmp;
    tmp = check_general(path);
    error = check_error();
    
    int length = tmp.size();
    num_notch = length - 26;
    
    //if does not provide a mapping for some input or no notch
    if (num_notch <= 0){
        error = 7;
    }
    //situation where more than one input is mapped to the same output
    // was already accounted for during check general
    
    if (error == 0){
        //update config
        for (int i = 0; i < length; i++){
            config.push_back(tmp[i]);
        }
        
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


int install_rotor(Rotor **rotor, int num_rotor, const char* path){
    ifstream in;
    in.open(path);
    
    if (in.fail()||!in.is_open()){
        return 11;
    }
    
    int number;
    vector <int> position;
    while (!in.eof()) {
        char character;
        in >> ws;
        character = in.peek();
        
        if (character == EOF) {
            break;
        }
        
        if (!isdigit(character)){
            return 4;
        }else{
            in >> number;
            
            if (number < 0 || number > 25){
                return 3;
            }
            position.push_back(number);
        }
    }
    
    int length = position.size();
    if (length < num_rotor){
        return 8;
    }
    
    //set rotor position(s) if passed all checks
    for (int i = 0; i < num_rotor; i++){
        rotor[i]->top = position[i];
        
        //calculate distance from top to original file configuration
        vector<int>::iterator itr = find(rotor[i]->config.begin(),rotor[i]->config.end(), rotor[i]->top);
        int index = distance(rotor[i]->config.begin(), itr);
        
        //move around the first 26 digits in vector to create rotation to the top
        for (int x = 0; x < index; x++){
            int tmp = rotor[i]->config[0];
            rotor[i]->config.erase(rotor[i]->config.begin());
            //insert back into the file
            vector<int>::iterator it;
            it = rotor[i]->config.end()-rotor[i]->num_notch;
            rotor[i]->config.insert (it, tmp);
        }
    }
    
    return 0;
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

void Rotor::on_notch_top(){
    //rotate
    int tmp = config[0];
    config.erase (config.begin());
    vector<int>::iterator it;
    it = config.end()-num_notch;
    config.insert (it, tmp);
    top = config[0];
}
