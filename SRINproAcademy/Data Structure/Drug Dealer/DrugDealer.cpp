#include <iostream>
using namespace std;

int n;
int drugs[100000+1];
int top;

int main() {
    cin >> n;
    top = 0;

    int query;
    for (int i = 0; i < n; i++) {
        cin >> query;
        if (query == 2) {
            cin >> drugs[top++];
        } else {
            if (top > 0) cout << drugs[--top] << endl;
            else cout << "No Drug" << endl;
        }
    }

    return 0;
}