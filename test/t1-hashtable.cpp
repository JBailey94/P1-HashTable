#include "catch/catch_amalgamated.hpp"
#include "../HashTable.h"

#include <iostream>
using namespace std;

TEST_CASE("Test hash table size and capacity") {
    HashTable ht(64);
    REQUIRE(ht.getSize() == 0);
    REQUIRE(ht.getCapacity() == 64);
}

TEST_CASE("Test the hash function") {
    HashTable ht(4);
    string keys[4] = {"test", "hello", "alpha", "shark"};

    for (string key : keys) {
        REQUIRE(ht.hash(key) < 4);
    }
}

TEST_CASE("Test inserting and removing nodes") {
    HashTable ht(8);

    ht.insert("test", 123);
    ht.insert("test2", 456);
    ht.insert("test3", 789);

    REQUIRE(ht.getSize() == 3);

    ht.remove("test");
    ht.remove("test2");
    ht.remove("test3");

    REQUIRE(ht.getSize() == 0);
}