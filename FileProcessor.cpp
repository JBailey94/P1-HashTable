#include "FileProcessor.hpp"

int FileProcessor::genRawDataFile(string inputFilePath, string rawDataFilePath)
{
    ifstream inputFile(inputFilePath);
    ofstream rawDataFile(rawDataFilePath);

    PasswordGenerator pg;
    stringstream ss;
    string line, name;

    if (inputFile.is_open() && rawDataFile.is_open())
    {
        while (getline(inputFile, line))
        {
            ss.str(line);
            ss >> name;
            rawDataFile
                << name
                << " "
                << pg.generateRawPwd()
                << endl;
        }
        inputFile.close();
        rawDataFile.close();
    } else {
        return 1;
    }

    return 0;
}

int FileProcessor::genEncryptedDataFile(string rawDataFilePath, string encryptedDataFilePath)
{ 
    ifstream rawDataFile(rawDataFilePath);
    ofstream encryptedDataFile(encryptedDataFilePath);
    PasswordGenerator pg;
    stringstream ss;
    string line, name, pwd;

    if (rawDataFile.is_open() && encryptedDataFile.is_open())
    {
        while (getline(rawDataFile, line))
        {
            ss.str(line);
            ss >> name >> pwd;
            encryptedDataFile
                << name
                << " "
                << pg.encrypt(pwd, name)
                << endl;
            ss.clear();
            ss.seekg(0);
        }
        rawDataFile.close();
        encryptedDataFile.close();
    } else {
        return 1;
    }

    return 0;
}

HashTable FileProcessor::getDataFromFile(string rawDataFilePath) {
    HashTable data(1024);
    ifstream rawDataFile(rawDataFilePath);
    string line, key, pwd;
    stringstream ss;

    if(rawDataFile.is_open()) {
        while(getline(rawDataFile, line)) {
            ss.str(line);
            ss >> key >> pwd;
            data.insert(key, pwd);
            ss.clear();
            ss.seekg(0);
        }
        rawDataFile.close();
    }

    return data;
}
