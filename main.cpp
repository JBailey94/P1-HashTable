#include <iostream>
#include "HashTable.h"
#include <string>

using namespace std;

int main(void) {
    HashTable h(128);
    cout << h.getCapacity() << endl;

    return 0;
}