#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define isDebug false

int main() {
    cin.clear();
    ifstream inputFile("corruptionChecksum.txt");
    string numbers;
    
    int checkSum = 0;

    // part 01
    // while (getline(inputFile, numbers)) {
    //     if (isDebug) cout << "[" << numbers << "]" << endl;

    //     int number;
    //     int min = -1;
    //     int max = -1;
    //     bool first = true;
    //     istringstream stringStream(numbers);

    //     while (stringStream >> number) {
    //         if (first) {
    //             first = false;
    //             min = number;
    //             max = number;
    //         } else {
    //             if (min > number) min = number;
    //             if (max < number) max = number;
    //         }
    //     }
    
    //     if (isDebug) cout << max << " - " << min << " = " << (max - min) << endl;
    //     checkSum += (max - min);
    // }

    // part 02
    int data[1000];
    while (getline(inputFile, numbers)) {
        if (isDebug) cout << "[" << numbers << "]" << endl;
        istringstream stringStream(numbers);

        int number;
        int col = 0;
        while (stringStream >> number) {
            if (isDebug) cout << "data[" << col << "] = " << number << endl;
            data[col] = number;
            col++;
        }

        bool pairFound = false;
        int division;
        for (int x = 0; x < col-1 && !pairFound; x++)
            for (int y = x+1; y < col && !pairFound; y++) {
                if (data[x] % data[y] == 0) { 
                    if (isDebug) cout << x << ":" << y << " (x,y) " << data[x] << " / " << data[y] << " = " << data[x] / data[y] << endl; 
                    pairFound = true; 
                    division = data[x] / data[y];                     
                }
                if (data[y] % data[x] == 0) { 
                    if (isDebug) cout << x << ":" << y << " (y,x) " << data[y] << " / " << data[x] << " = " << data[y] / data[x] << endl; 
                    pairFound = true; 
                    division = data[y] / data[x];                     
                }
            }

        checkSum += division;
    }

    cout << checkSum << endl;

    return 0;
}