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
    Enigma(std::vector <vector <int> > config);
    char encrypt(char character);
};

#endif
