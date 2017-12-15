#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("MazeOfTwistyTrampolines.txt");

    int count = 0;
    int inputan;
    int data[10000];
    while (inputFile >> inputan) {
        data[count] = inputan;
        count++;
    }

    int now = 0;
    int jumpCount = 0;
    while ((now >= 0) && (now < count)) {
        int jump = data[now];
        
        // day 01
        //else data[now]++;

        // day 02
        if (data[now] >= 3) data[now]--;
        else data[now]++;
        
        now += jump;
        jumpCount++;
    }

    cout << "Jump count = " << jumpCount << endl;

    return 0;
}