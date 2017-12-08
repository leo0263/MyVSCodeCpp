#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

#define isDebug false

    string query[7];

int main() {
    cin.clear();
    ifstream inputFile("ihylRegisters.txt");

    unordered_map<string, int> hashMap;
    
    int highest = 0;
    string lines;
    while (getline(inputFile, lines)) {
        if (isDebug) cout << "[" << lines << "]" << endl;
    
        int count = 0;
        istringstream stringStream(lines);
        string str;
        while (stringStream >> str) { 
            query[count] = str;
            if (isDebug) cout << "[" << query[count] << "] ";
            count++;
        } if (isDebug) cout << endl;

        // check if register is already registered!
        if (hashMap.find(query[0]) == hashMap.end()) hashMap[query[0]] = 0;
        if (hashMap.find(query[4]) == hashMap.end()) hashMap[query[4]] = 0;

        // check if query condition is met!
        int number = stoi(query[6]);
        bool condition = false;
        if (query[5] == ">") if (hashMap[query[4]] > number) condition = true;
        if (query[5] == "<") if (hashMap[query[4]] < number) condition = true;
        if (query[5] == ">=") if (hashMap[query[4]] >= number) condition = true;
        if (query[5] == "<=") if (hashMap[query[4]] <= number) condition = true;
        if (query[5] == "==") if (hashMap[query[4]] == number) condition = true;
        if (query[5] == "!=") if (hashMap[query[4]] != number) condition = true;

        if (condition) {
            if (query[1] == "inc") hashMap[query[0]] += stoi(query[2]);
            if (query[1] == "dec") hashMap[query[0]] -= stoi(query[2]);
            if (highest < hashMap[query[0]]) highest = hashMap[query[0]];
        }
    }

    // find the largest value in the register
    int max;
    unordered_map<string, int>::iterator iter;
    for (iter = hashMap.begin(); iter != hashMap.end(); iter++) {
        if (iter == hashMap.begin()) max = iter->second;
        else if (max < iter->second) max = iter->second;
    }

    // print the output
    cout << "max val : " << max << endl;
    cout << "highest : " << highest << endl;

    return 0;
}