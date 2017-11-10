#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N = 50000;
int M = 50000;
int Max = 15007*2;

int main() {
    freopen("MaxSubArray_gen.in", "w", stdout);

    cout << N << endl;
    for (int i = 0; i < N; i++) cout << rand() % Max - (Max/2) + 1 << " ";
    cout << endl;

    cout << M << endl;
    for (int i = 0; i < M; i++) {
        int x = rand() % N + 1;
        int y = rand() % N + 1;
        if (y < x) {
            int z = y;
            y = x;
            x = z;
        }
        cout << x << " " << y << endl;
    }

    return 0;
}