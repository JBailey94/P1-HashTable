/**
 * @file HashTable.hpp
 * @author Jesse Lynn-Bailey (jjl47@students.uwf.edu)
 * @brief Custom implementation of a hash table
 * @version 0.1
 * @date 2022-09-13
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class HashNode {
public:
    string key;
    string value;
    HashNode(string key, string value);
};

class HashTable {
private:
    int capacity;
    int size;
    vector<vector<HashNode>> buckets;
public:
    HashTable(int capacity);
    int hash(string key);
    int getCapacity();
    int getSize();
    bool insert(string key, string value);
    bool remove(string key);
    bool exist(string key);
    string find(string key);
};

#endif