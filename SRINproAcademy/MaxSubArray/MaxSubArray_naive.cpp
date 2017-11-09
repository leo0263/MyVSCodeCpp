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
        int total = data[x];
        bool isPositiveJump = false; int jumpIndex;

        if (total < 0) {
            for (int z = x+1; z <= y; z++) {
                if (isPositiveJump) break;
                if (data[z] >= 0) {
                    isPositiveJump = true;
                    jumpIndex = z;
                    total = data[jumpIndex];
                } else {
                    if (data[z] > total) total = data[z];
                }
            }
        }

        for (int z = x+1; z <= y; z++) {
            if (isPositiveJump && (z == jumpIndex)) continue;
            else if (total + data[z] > total) total += data[z];
        }

        cout << total << endl;
    }


    return 0;
}