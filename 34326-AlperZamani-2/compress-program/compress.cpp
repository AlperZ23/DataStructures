#include "Hashtable.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct DictEntry {
    string key;
    int code;
    DictEntry() : key(""), code(-1) {}
    DictEntry(const string &k, int c) : key(k), code(c) {}
    bool operator==(const DictEntry &other) const {
        return key == other.key;
    }
    bool operator!=(const DictEntry &other) const {
        return !(*this == other);
    }
};


int hashfunc(const DictEntry &obj, int tableSize) {
    return hashfunc(obj.key, tableSize);
}

int main() {
    ifstream inFile("compin.txt", ios::binary);
    ofstream outFile("compout.txt");
    if (!inFile.is_open() || !outFile.is_open()) {

        return 0;
    }

    DictEntry notFound("", -1);

    const int initialSize = 10007;
    HashTable<DictEntry> dictionary(notFound, initialSize);

    for (int i = 0; i < 256; ++i) {
        string s;
        s.push_back(static_cast<char>(i));
        dictionary.insert(DictEntry(s, i));
    }


    int nextCode = 256;

    int cInt = inFile.get();
    if (cInt == EOF) {
        return 0;
    }
    char c = static_cast<char>(cInt);

    string current;
    current.push_back(c);

    while (true) {
        cInt = inFile.get();
        if (cInt == EOF) {

            DictEntry found = dictionary.find(DictEntry(current, 0));
            if (found.code != -1) {
                outFile << found.code << " ";
            }
            break;
        }
        c = static_cast<char>(cInt);
        string candidate = current;
        candidate.push_back(c);

        DictEntry entry = dictionary.find(DictEntry(candidate, 0));
        if (entry.code != -1) {

            current = candidate;
        } else {
            DictEntry currentEntry = dictionary.find(DictEntry(current, 0));
            if (currentEntry.code != -1) {
                outFile << currentEntry.code << " ";
            }
            if (nextCode < 4096) {
                dictionary.insert(DictEntry(candidate, nextCode));
                ++nextCode;
            }
            current.clear();
            current.push_back(c);
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}