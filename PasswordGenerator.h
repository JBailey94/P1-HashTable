#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>

using namespace std;

class PasswordGenerator {
    public:
        PasswordGenerator();
        string encrypt(string rawPwd, string key);
        string generateRawPwd();
        char getRandomLetter();
};

#endif