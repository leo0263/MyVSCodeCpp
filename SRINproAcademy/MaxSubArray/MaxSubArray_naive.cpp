#include <iostream>
using namespace std;

int N, M;
int data[50000+1];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> data[i];

    int x, y;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> x >> y;

        int max = data[x];
        for (int z = x; z <= y; z++) 
            if (data[z] > max) max = data[z];

        cout << max << endl;
    }


    return 0;
}