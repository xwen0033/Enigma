#ifndef ROTOR_H
#define ROTOR_H


class Rotor {
    int wiring[2][26];
    int notch[26];
    int num_notch;
    int top;
    Rotor* left;
    Rotor* right;
public:
    Rotor();
    int getTop();
    int check_config(int num_roter, int rot_position, char **argv);
    void set_left_rotor(Rotor* left_rotor);
    void set_right_rotor(Rotor* right_rotor);
    void set_position(int pos);
    bool on_notch();
    int indexof(int target);
    int forward_encrypt(int input);
    int backward_encrypt(int input);
    void rotate();
};

#endif
