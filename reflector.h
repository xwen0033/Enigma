#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "errors.h"

using namespace std;

class Reflector {
    int reflectsto[26];
public:
    Reflector(vector <int> config);
    char encrypt(const char input);
};

#endif
