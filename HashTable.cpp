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
        vector<HashNode> currentBucket = this->getBucket(key);
        HashNode node(key, value);
        currentBucket.push_back(node);
        this->size++;
        return true;
    }

    return false;
}

bool HashTable::remove(string key) {
    vector<HashNode> currentBucket = this->getBucket(key);

    if (currentBucket.size() > 0) {
        for (auto iterator = currentBucket.begin(); iterator != currentBucket.end(); iterator++) {
            if (iterator->key == key) {
                currentBucket.erase(iterator);
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
    vector<HashNode> currentBucket = this->getBucket(key);

    if (currentBucket.size() > 0) {
        for (HashNode node : currentBucket) {
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

/**
 * @brief returns the bucket of a hash
 * @param key the key to obtain bucket
 * @return vector<HashNode> bucket 
 */
vector<HashNode> HashTable::getBucket(string key) {
    int hash = this->hash(key);
    vector<HashNode> bucket = buckets.at(hash);
    return bucket;
}