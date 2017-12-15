#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

#define isDebug false
#define BLOCKS 16

int memory[BLOCKS];
unordered_map<string, int> hashMap;

string genChecksum() {
    string checksum = "";
    for (int i = 0; i < BLOCKS; i++) {
        string str = to_string(memory[i]) + ".";
        checksum += str;
    }
    if (isDebug) cout << "generate checksum : [" << checksum << "]" << endl;
    return checksum;
}

int main() {
    ifstream inputFile("MemoryReallocation.txt");
    for (int i = 0; i < BLOCKS; i++) {
        inputFile >> memory[i];
    }
    hashMap[genChecksum()] = 1;

    bool sameFound = false;
    bool duplicateFound = false;
    string duplicateChecksum = "";
    int cycle = 0;
    int duplicateCycle = 1;
    while (!duplicateFound) {
        // find max data (if same, use smallest index)
        int maxPos = 0;
        for (int i = BLOCKS-1; i >= 0; i--) if (memory[maxPos] <= memory[i]) maxPos = i;

        // distribute this data
        int num = memory[maxPos];
        memory[maxPos] = 0;
        while (num--) {
            maxPos++;
            maxPos %= BLOCKS;
            memory[maxPos]++;            
        }
        
        string checksum = genChecksum();
        
        if (sameFound) { // duplicate check
            if (checksum == duplicateChecksum) duplicateFound = true;
            else duplicateCycle++;
            if (isDebug) cout << "[" << checksum << "] vs [" << duplicateChecksum << "]" << endl;
        } else { // record the checksum
            cycle++;
            if (hashMap.find(checksum) == hashMap.end()) hashMap[checksum] = 1;
            else {
                sameFound = true;
                duplicateChecksum = checksum;
            }     
        }   
    }

    cout << "redistribution cycle = " << cycle << endl;
    cout << "duplicate cycle = " << duplicateCycle << endl;

    return 0;
}
