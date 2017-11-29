#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N = 1000000;
int B = 1000000000;
int Max = 1000000;

int main() {
    freopen("PowerOverwhelming_gen.txt", "w", stdout);

    cout << N << " " << B << endl;
    for (int i = 0; i < N; i++) cout << rand() % Max << endl;

    return 0;
}