#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "errors.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

using namespace std;

class Enigma{
    Plugboard *plugboard;
    Reflector *reflector;
    Rotor **rotor;
    int num_rotor;
public:
    int error;
    Enigma(int argc, char **argv);
    char encrypt(const char character);
};

#endif
