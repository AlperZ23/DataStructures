#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int main() {
    ifstream inFile("compout.txt");
    ofstream outFile("decompout.txt", ios::binary);
    if (!inFile.is_open() || !outFile.is_open()) {
        return 0;
    }


    vector<string> dictionary(4096);
    for (int i = 0; i < 256; ++i) {

        dictionary[i].push_back(static_cast<char>(i));
    }

    int nextCode = 256;

    int code;

    if (!(inFile >> code)) {
        return 0;
    }

    string previous = dictionary[code];
    outFile << previous;


    while (inFile >> code) {
        string entry;
        if (code < nextCode && !dictionary[code].empty()) {

            entry = dictionary[code];
        } else {

            entry = previous;
            entry.push_back(previous[0]);
        }
        outFile << entry;

        if (nextCode < 4096) {

            dictionary[nextCode] = previous + entry[0];
            ++nextCode;
        }
        previous = entry;
    }

    inFile.close();
    outFile.close();
    return 0;
}