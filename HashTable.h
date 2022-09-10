#ifndef HASHTABLE_H
#define HASHTABLE_H

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