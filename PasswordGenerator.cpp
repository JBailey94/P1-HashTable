#include "PasswordGenerator.h"

PasswordGenerator::PasswordGenerator() {
    srand(time(NULL));
}

/**
 * @brief Encrypts a password
 * @param rawPwd the password to encrypt
 * @return string the encrypted password
 */
string PasswordGenerator::encrypt(string rawPwd) {

}

/**
 * @brief randomly generates a 9 character password
 * @return string a randomly generated 9 chracter password
 */
string PasswordGenerator::generateRawPwd() {
    char pwd[9];

    for (char c : pwd) {
        c = getRandomLetter();
    }

    return pwd;
}

char getRandomLetter() {
    char c = rand() % 97 + 122;
}