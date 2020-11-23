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
    int wiring[2][26];
public:
    int *notch;
    int num_notch;
    int top;
    Rotor(vector <int> config, int topp);
    ~Rotor();
    char forward_encrypt(const char input);
    char backward_encrypt(const char input);
    void rotate();
};

#endif
