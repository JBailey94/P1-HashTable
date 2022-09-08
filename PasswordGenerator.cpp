#include "PasswordGenerator.h"

PasswordGenerator::PasswordGenerator() {
    srand(time(NULL));
}

/**
 * @brief Encrypts a password using Vignere method
 * @param rawPwd the password to encrypt
 * @return string the encrypted password
 */
string PasswordGenerator::encrypt(string rawPwd, string key) {
    string encryptedPwd = rawPwd;
    int keyIndex = 0;
    int sum = 0;
    
    for (int i = 0; i < rawPwd.length(); i++) {
        if (keyIndex >= key.length()) {
            keyIndex = 0;
        }

        sum = key[keyIndex] + rawPwd[i];
        if (sum - 'a' <= 'z') {
            encryptedPwd[i] = sum - 'a';
        } else if (sum - 'a' > 'z') {
            encryptedPwd[i] = sum - ('a' + 26);
        }

        keyIndex++;
    }
    return encryptedPwd;
}

/**
 * @brief randomly generates a 9 character password
 * @return string a randomly generated 9 chracter password
 */
string PasswordGenerator::generateRawPwd() {
    string pwd = "";

    for (int i = 0; i < 9; i++) {
        pwd += getRandomLetter();
    }

    return pwd;
}

char PasswordGenerator::getRandomLetter() {
    char c = 'a' + rand() % 26;
    return abs(c);
}