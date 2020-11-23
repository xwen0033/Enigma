#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "errors.h"

using namespace std;

class Reflector {
    vector <int> config;
public:
    int error;
    Reflector(const char* path);
    char encrypt(const char input);
};

#endif
