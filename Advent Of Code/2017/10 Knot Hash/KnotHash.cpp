#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define isDebug true
#define rounds 64
#define limit 256

int data[limit];
int lengths[1000];
int suffixes[5] = {17, 31, 73, 47, 23};
char inputStr[1000];
int length, pos, skipSize;

    int normalize(int num) {
        //if (isDebug) cout << "normalize " << num << endl;
        while (num < 0) num += limit;
        if (num >= limit) num %= limit;        
        return num;
    }

    void reverse(int start, int stop, int length) {
        //if (isDebug) cout << "reverse " << start << " to " << stop << endl;
        for (int i = 0; i < length / 2; i++) {
            int temp = data[start];
            data[start] = data[stop];
            data[stop] = temp;
            start = normalize(start + 1);
            stop = normalize(stop - 1);
        }
    }

    void printData(int round) {
        cout << "round(" << round << ") : ";
        for (int i = 0; i < limit; i++) cout << data[i] << " ";
        cout << endl;
    }

int main() {
    // initialize
    ifstream inputFile("KnotHash.txt");
    inputFile >> inputStr;
    length = 0; while(inputStr[length]) length++;
    for (int i = 0; i < length; i++) lengths[i] = int(inputStr[i]);
    for (int i = 0; i < 5; i++) lengths[length + i] = suffixes[i];
    for (int i = 0; i < limit; i++) data[i] = i;
    length += 5;
    pos = 0;
    skipSize = 0;

    if (isDebug) { cout << "lengths : "; for (int i = 0; i < length; i++) cout << lengths[i] << " "; cout << endl; }
    if (isDebug) printData(0);

    // do 64 rounds of knots to get a Sparse Hash
    for (int round = 1; round <= rounds; round++) {
        for (int i = 0; i < length; i++) {
            int start = normalize(pos);
            int stop = normalize(pos + lengths[i] - 1);
            reverse(start, stop, lengths[i]);
            pos = normalize (pos + lengths[i] + skipSize);
            skipSize++;
        }

        //if (isDebug) printData(round);
    }

    printData(16);

    // create a Dense Hash
    int denseHash[16];
    int z = 0;
    for (int x = 0; x < limit; x+=16) {
        int xr = data[x];                           if (isDebug) cout << data[x];
        for (int y = x+1; y < x+16; y++) {
            xr = xr ^ data[y];                      if (isDebug) cout << " ^ " << data[y];
        }
        if (isDebug) cout << " --> denseHash[" << z << "] = " << xr << endl;
        denseHash[z] = xr;
        z++;
    }
    
    if (isDebug) { cout << "denseHash : "; for (int i = 0; i < 16; i++) cout << denseHash[i] << " "; cout << endl; }


    // print the Dense Hash as a hexadecimal string;
    cout << "hexadecimal hash string : ";
    for (int i = 0; i < 16; i++) {
        cout << setfill ('0') << setw(sizeof(int)/4) << hex << denseHash[i];
    } cout << endl;

    return 0;
}

// round 1 code -----------------------------------------------------------------------------------
// #define isDebug true
// #define limit 256

// int data[limit];
// int pos, skipSize, reverseLength;

//     int normalize(int num) {
//         //if (isDebug) cout << "normalize " << num << endl;
//         while (num < 0) num += limit;
//         if (num >= limit) num %= limit;        
//         return num;
//     }

//     void reverse(int start, int stop, int length) {
//         if (isDebug) cout << "reverse " << start << " to " << stop << endl;
//         for (int i = 0; i < length / 2; i++) {
//             int temp = data[start];
//             data[start] = data[stop];
//             data[stop] = temp;
//             start = normalize(start + 1);
//             stop = normalize(stop - 1);
//         }
//     }

//     void printData() {
//         cout << "skipSize(" << skipSize << ") : ";
//         for (int i = 0; i < limit; i++) cout << data[i] << " ";
//         cout << endl;
//     }

// int main() {
//     // initialize
//     ifstream inputFile("KnotHash.txt");
//     pos = 0;
//     skipSize = 0;
//     for (int i = 0; i < limit; i++) data[i] = i;
//     if (isDebug) printData();

//     while (inputFile >> reverseLength) {
//         int start = normalize(pos);
//         int stop = normalize(pos + reverseLength - 1);
//         reverse(start, stop, reverseLength);
//         pos = normalize (pos + reverseLength + skipSize);
//         skipSize++;

//         if (isDebug) printData();
//     }

//     cout << "hash code = " << data[0] * data[1] << endl;

//     return 0;
// }