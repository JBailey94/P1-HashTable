/**
 * @file PasswordGenerator.hpp
 * @author Jesse Lynn-Bailey (jjl47@students.uwf.edu)
 * @brief Handles password generation and encryption
 * @version 0.1
 * @date 2022-09-13
 */

#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

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