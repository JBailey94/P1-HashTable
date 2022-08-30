#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

class FileProcessor {
    public:
        FileProcessor();
        void readNames(std::string path);
        bool genRawPwdFile();
        bool genEncryptedPwdFile();
};
    
#endif