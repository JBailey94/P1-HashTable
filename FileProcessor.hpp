/**
 * @file FileProcessor.hpp
 * @author Jesse Lynn-Bailey jjl47@students.uwf.edu
 * @brief Handles password file generation and loading.
 * @version 0.1
 * @date 2022-09-13
 */

#ifndef FILEPROCESSOR_HPP
#define FILEPROCESSOR_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "PasswordGenerator.hpp"
#include "HashTable.hpp"

using namespace std;

class FileProcessor {
    public:
        int genRawDataFile(string inputFilePath, string rawDataFilePath);
        int genEncryptedDataFile(string rawDataFilePath, string encryptedFileDataPath);
        HashTable getDataFromFile(string rawDataFilePath);
};
    
#endif