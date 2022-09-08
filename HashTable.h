#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class HashNode {
public:
    string key;
    int value;
    HashNode(string key, int value);
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
    bool insert(string key, int value);
    bool remove(string key);
    bool exist(string key);
};

#endif