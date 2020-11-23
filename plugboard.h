#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <vector>
#include <cstdio>
#include "errors.h"

using namespace std;
class Plugboard {
    int swap[26];
public:
    Plugboard(vector <int> config);
    char encrypt(const char input);
};


#endif
