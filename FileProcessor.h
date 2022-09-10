#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "PasswordGenerator.h"
#include "HashTable.h"

using namespace std;

class FileProcessor {
    public:
        int genRawDataFile(string inputFilePath, string rawDataFilePath);
        int genEncryptedDataFile(string rawDataFilePath, string encryptedFileDataPath);
        HashTable getDataFromFile(string rawDataFilePath);
};
    
#endif