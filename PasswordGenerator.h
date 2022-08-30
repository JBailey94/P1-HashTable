#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>

class PasswordGenerator {
    public:
        std::string encrypt(std::string rawPwd);
        std::string generatePwd();
};

#endif