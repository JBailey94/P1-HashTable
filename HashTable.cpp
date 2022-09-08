#include "HashTable.h"

HashNode::HashNode(string key, int value) {
    this->key = key;
    this->value = value;
}

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

bool HashTable::insert(string key, int value) {
    if(!exist(key)) {
        HashNode node(key, value);
        int position = hash(key);
        this->buckets.at(position).push_back(node);
        this->size++;
        return true;
    }

    return false;
}

bool HashTable::remove(string key) {
    int position = this->hash(key);
    if (buckets.at(position).size() > 0) {
        for (auto iterator = buckets.at(position).begin(); iterator != buckets.at(position).end(); iterator++) {
            if (iterator->key == key) {
                buckets.at(position).erase(iterator);
                this->size--;
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Check if a key already exist
 * @param key the key to search for
 * @return true if key does exist
 * @return false if key does not exist
 */
bool HashTable::exist(string key) {
    int position = hash(key);

    if (buckets.at(position).size() > 0) {
        for (HashNode node : buckets.at(position)) {
            if (node.key == key) {
                return true;
            }
        }
    }
    
    return false;
}

int HashTable::getCapacity() {
    return capacity;
}

int HashTable::getSize() {
    return size;
}