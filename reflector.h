#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
    int reflectsto[26];
public:
    Reflector();
    int check_config(char** argv);
    int encrypt(int input);
};

#endif
