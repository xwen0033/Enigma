/* error codes  */
#ifndef ERRORS_H
#define ERRORS_H

#define INSUFFICIENT_NUMBER_OF_PARAMETERS         1
#define INVALID_INPUT_CHARACTER                   2
#define INVALID_INDEX                             3
#define NON_NUMERIC_CHARACTER                     4
#define IMPOSSIBLE_PLUGBOARD_CONFIGURATION        5
#define INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS  6
#define INVALID_ROTOR_MAPPING                     7
#define NO_ROTOR_STARTING_POSITION                8
#define INVALID_REFLECTOR_MAPPING                 9
#define INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS  10
#define ERROR_OPENING_CONFIGURATION_FILE          11
#define NO_ERROR                                  0

using namespace std;

std::vector <int> check_general(const char* path);
std::vector <int> check_plugboard(const char* path);
std::vector <int> check_reflector(const char* path);
std::vector <int> check_rotor(const char* path);
std::vector <int> check_rotor_pos(int num_rotor,const char* path);

#endif
