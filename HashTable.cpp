#include "HashTable.h"

HashNode::HashNode(string key, string value) {
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

bool HashTable::insert(string key, string value) {
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

/**
 * @brief Find and return a value for a corresponding key
 * @param key the key to search for
 * @return Pointer to the HashNode
 * @return nullptr if the HashNode does not exist
 */
string HashTable::find(string key) {
    int position = hash(key);

    if (buckets.at(position).size() > 0) {
        for (HashNode node : buckets.at(position)) {
            if (node.key == key) {
                return node.value;
            }
        }
    }
    
    return "";
}

int HashTable::getCapacity() {
    return capacity;
}

int HashTable::getSize() {
    return size;
}