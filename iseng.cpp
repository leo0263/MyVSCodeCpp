#include <iostream>
using namespace std;

int data[5] = { 2, 3, 5, 1, 4 };
int result[100][100];
int n;

    int profit(int year, int left, int right) {
        if (left > right) return 0;

        if (result[left][right] != -1) return result[left][right];

        return result[left][right] = max(
            data[left] * year + profit(year+1, left+1, right),
            data[right] * year + profit(year+1, left, right-1)
        );
    }


int main() {
    // cin >> n;
    // for (int i = 0; i < n; i++) cin >> data[i];
    n = 5;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = -1;
    
    cout << profit(1, 0, n-1);
}

// 5
// 2 3 5 1 4



// int fibo[1000];

//     int fibonacci(int n) {
//         if (n <= 2) return 1;
        
//         if (fibo[n] != -1) return (fibo[n]);

//         return fibo[n] = (fibonacci(n-1) + fibonacci(n-2));
//     }

// int main() {
//     int N = 100;
//     for (int i = 0; i <= N; i++) fibo[i] = -1;
//     cout << fibonacci(N);
// }

// fibonacci(5)
// 1 1 2 3 5 8 13 = 12
// 1 2 3 4 5 6 7