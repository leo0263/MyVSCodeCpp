#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int T = 100;
int R ;
int C ;
int Max = 1000;

int main() {
    freopen("RottenApple_gen.txt", "w", stdout);

    cout << T << endl;
    for (int t = 1; t < T; t++) { 
        R = rand() % Max;
        C = rand() % Max;
        cout << R << " " << C << endl;
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++)
                cout << rand() % 3 << " ";
            cout << endl;
        }
    }

    return 0;
}