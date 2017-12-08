#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define isDebug true

    struct t_fTree {
        string name;
        int weight;
        struct t_fTree *child, *next;
    };

    int dataCount = 0;

int main() {
    cin.clear();
    ifstream inputFile("RecursiveCircus.txt");

    unordered_map
    
    string lines;
    while (getline(inputFile, lines)) {
        if (isDebug) cout << "[" << lines << "]" << endl;
    
        int count = 0;
        istringstream stringStream(lines);
        string str;
        while (stringStream >> str) { 
            if (isDebug) cout << "[" << str << "] ";

            if (count == 0) {

            }

            count++;
        } if (isDebug) cout << endl;

        dataCount++;
    }

    return 0;
}