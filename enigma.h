#ifndef ENIGMA_H
#define ENIGMA_H

#include "errors.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

class Enigma{
    Plugboard plugboard;
    Reflector reflector;
    Rotor *rotors;
    int num_rotor;

public:
    Enigma();
    int check_config(int argc,char** argv);
    char encrypt(char character);
    ~Enigma();
};

#endif
