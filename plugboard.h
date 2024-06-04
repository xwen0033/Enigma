#ifndef PLUGBOARD_H
#define PLUGBOARD_H

using namespace std;
class Plugboard {
    int swap[26];
public:
    Plugboard();
    int check_config(char** argv);
    int encrypt(int input);
};


#endif
