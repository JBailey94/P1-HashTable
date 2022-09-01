#include "HashTable.h"

HashTable::HashTable(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->buckets.resize(capacity);
}

int HashTable::hash(string key) {
    int hashValue = 0;
    for (long unsigned i = 0; i < key.length(); i++) {
        hashValue = (key[i] * i + hashValue) % capacity;
    }
    return hashValue;
}

int HashTable::getCapacity() {
    return capacity;
}

int HashTable::getSize() {
    return size;
}