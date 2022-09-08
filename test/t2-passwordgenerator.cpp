#include "catch/catch_amalgamated.hpp"
#include "../PasswordGenerator.h"

TEST_CASE("Test getRandomLetter()") {
    PasswordGenerator pg;
    
    char c;

    for (int i = 0; i < 50; i++) {
        REQUIRE(c >= 0 && c <= 122);
    }
}