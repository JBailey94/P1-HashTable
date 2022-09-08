#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class PasswordGenerator {
    public:
        PasswordGenerator();
        string encrypt(string rawPwd);
        string generateRawPwd();
        char getRandomLetter();
};

#endif