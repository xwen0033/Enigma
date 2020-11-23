#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <cstdio>
#include "errors.h"

using namespace std;

class Rotor {
    vector <int> config;
public:
    int *notch;
    int num_notch;
    int top;
    Rotor(const char* path);
    ~Rotor();
    char forward_encrypt(const char input);
    char backward_encrypt(const char input);
    void rotate();
};

#endif
