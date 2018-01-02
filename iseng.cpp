#include <iostream>
using namespace std;

int main() {
    int a = 0^1^2^3^4^5^6^7^8^9^10^11^12^13^14^15;
    int b = 65 ^ 27 ^ 9 ^ 1 ^ 4 ^ 3 ^ 40 ^ 50 ^ 91 ^ 7 ^ 6 ^ 0 ^ 2 ^ 5 ^ 68 ^ 22;
    cout << a << endl;
    cout << b << endl;

    return 0;
}


// #define limit 100

// int main() {
//     cout << 100 % limit << endl;
//     cout << -100 % limit << endl;
//     cout << 101 % limit << endl;
//     cout << -101 % limit << endl;
//     cout << 210 % limit << endl;
//     cout << -210 % limit << endl;
//     cout << 1 % limit << endl;
//     cout << -1 % limit << endl;

//     return 0;
// }








// int n = 5;
// int price[5] = { 2, 3, 5, 1, 4 };
// int kiri = 0;
// int kanan = n-1;
// int profit = 0;

// int maksimum(int a, int b) { if (a > b) return a; else return b; }

// int jual(int kiri, int kanan, int tahun) {
//     if (kiri > kanan) return 0;
//     if (tahun > n) return 0;

//     if (jawaban[kiri][kanan] != -1) return jawaban[kiri][kanan];
//     else return jawaban[kiri][kanan] = (maksimum (
//         (price[kiri] * tahun) + jual(kiri + 1, kanan, tahun + 1),
//         (price[kanan] * tahun) + jual(kiri, kanan - 1, tahun + 1)
//     ));
// }

// int main() {
//     cout << jual(0, n-1, 1);

//     return 0;
// }




// int n = 5;
// int price[5] = { 2, 3, 5, 1, 4 };
// int kiri = 0;
// int kanan = n-1;
// int profit = 0;

// int main() {
//     for (int i = 1; i <= n; i++) {
//         if (price[kiri] <= price[kanan]) {
//             profit += price[kiri] * i;
//             kiri++;
//         } else {
//             profit += price[kanan] * i;
//             kanan--;
//         }
//     }

//     cout << profit;

//     return 0;
// }





// int n = 100;
// int ans[1000];

// int fib(int i) {
//     if (i <= 2) return 1;

//     if (ans[i] != -1) return ans[i];
//     else return ans[i] = (fib (i-1) + fib(i-2));
// }

// int main() {
//     for (int i = 0; i <= n; i++) ans[i] = -1;
//     cout << fib(n);

//     return 0;
// }




// int n = 5;
// int price[5] = { 2, 3, 5, 1, 4 };

// int main() {

//     return 0;
// }



// int n = 3;
// int z = 5;
// int data[10];
// bool used[10];

// void rekursif(int digit) {
//     if (digit >= n) {
//         for (int i = 0; i < n; i++) cout << data[i];
//         cout << endl;
//         return;
//     }

//     for (int i = 1; i <= z; i++) {
//         if (!used[i]) {
//             used[i] = true;
//             data[digit] = i;
//             rekursif(digit + 1);
//             used[i] = false;
//         }
//     }
// }

// int main() {
//     rekursif(0);

//     return 0;
// }

// int n = 3;
// int data[10];

// void rekursif(int digit) {
//     if (digit >= n) {
//         for (int i = 0; i < n; i++) cout << data[i];
//         cout << endl;
//         return;
//     }

//     for (int i = 1; i <= n; i++) {
//         data[digit] = i;
//         rekursif(digit + 1);
//     }
// }

// int main() {
//     rekursif(0);

//     return 0;
// }



// int N = 5;

// int fib(int a) {
//     if (a <= 2) return 1;
//     return (fib(a-1) + fib(a-2));
// }

// int main() {
//     cout << fib(N);

//     return 0;
// }




















// int N;
// int data[4][5] = {
//     0, 0, 1, 1, 1,
//     1, 0, 0, 0, 0,
//     1, 0, 0, 0, 1,
//     0, 1, 1, 0, 1
// };

// int main() {
//     N = 3;

//     for (int i = 1; i <= N; i++) {
//         cout << i << endl;
//     }

//     for (int y = 0; y < 4; y++) {
//         for (int x = 0; x < 5; x++) {
//             cout << data[y][x];
//         }
//         cout << endl;
//     }

//     return 0;
// }





// int data[5] = { 2, 3, 5, 1, 4 };
// int result[100][100];
// int n;

//     int profit(int year, int left, int right) {
//         if (left > right) return 0;

//         if (result[left][right] != -1) return result[left][right];

//         return result[left][right] = max(
//             data[left] * year + profit(year+1, left+1, right),
//             data[right] * year + profit(year+1, left, right-1)
//         );
//     }


// int main() {
//     // cin >> n;
//     // for (int i = 0; i < n; i++) cin >> data[i];
//     n = 5;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             result[i][j] = -1;
    
//     cout << profit(1, 0, n-1);
// }

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