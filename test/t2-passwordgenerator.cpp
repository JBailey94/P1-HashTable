#include "catch/catch_amalgamated.hpp"
#include "../PasswordGenerator.h"
#include <iostream>

using namespace std;

TEST_CASE("Test getRandomLetter()") {
    PasswordGenerator pg;
    
    // letters must be a lower case between 97 and 122 for lower case ASCII values
    bool outOfRange = false;
    
    char c;

    for (int i = 0; i < 50; i++) {
        c = pg.getRandomLetter();
        if(c < 'a' && c > 'z') {
            outOfRange = true;
        }
    }
    
    REQUIRE(outOfRange == false);
}

TEST_CASE("Test generateRawPwd()") {
    PasswordGenerator pg;
    REQUIRE(pg.generateRawPwd().length() == 9);
}

TEST_CASE("Test encrypt()") {
    PasswordGenerator pg;
    string encrypted = pg.encrypt("thecatjumpedoverthemoon", "jesse");
    CHECK_THAT(encrypted, Catch::Matchers::Equals("clwuecnmetnhgniaxzwqxsf"));
}

