#include <iostream>
#include <string>

#include "FileProcessor.h"
#include "HashTable.h"
#include "PasswordGenerator.h"
#include "iomanip"

using namespace std;

int main(void) {
    FileProcessor fp;
    PasswordGenerator pg;

    // generate raw and encrypted files
    fp.genRawDataFile("names.txt", "rawdata.txt");
    fp.genEncryptedDataFile("rawdata.txt", "encrypteddata.txt");

    string names[5] = {"SMITH", "WILLIAMS", "BROWN", "MILLER", "MOORE"};
    HashTable encryptedData = fp.getDataFromFile("encrypteddata.txt");
    HashTable rawData = fp.getDataFromFile("rawdata.txt");
    string rawPwd, encryptedPwd, illegalRawPwd;
    string match = "No match";

    // test legal matches
    cout
        << "Legal:" << endl
        << left << setw(16) << "UserID"
        << left << setw(16) << "RawPwd"
        << left << setw(16) << "EncPwd"
        << left << setw(16) << "Result"
        << endl;

    for (string name : names) {
        rawPwd = rawData.find(name);
        encryptedPwd = pg.encrypt(rawPwd, name);

        if (encryptedPwd == encryptedData.find(name)) {
            match = "match";
        }

        cout
            << left << setw(16) << name
            << left << setw(16) << rawPwd
            << left << setw(16) << encryptedPwd
            << left << setw(16) << match
            << endl;

        match = "no match";
    }

    // test illegal matches
    cout
        << "\nIllegal:" << endl
        << left << setw(16) << "UserID"
        << left << setw(16) << "RawPwd"
        << left << setw(16) << "EncPwd"
        << left << setw(16) << "Result"
        << endl;

    for (string name : names) {
        rawPwd = rawData.find(name);
        illegalRawPwd = rawPwd + "a";
        encryptedPwd = pg.encrypt(illegalRawPwd, name);

        if (encryptedPwd == encryptedData.find(name)) {
            match = "match";
        }

        cout
            << left << setw(16) << name
            << left << setw(16) << rawPwd
            << left << setw(16) << encryptedPwd
            << left << setw(16) << match
            << endl;
        
        match = "no match";
    }

    return 0;
}