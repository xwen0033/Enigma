#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <vector>
#include <cstdio>
#include "errors.h"

using namespace std;
class Plugboard {
    vector <int> config;
public:
    int error;
    Plugboard(const char* path);
    char encrypt(const char input);
};


#endif
