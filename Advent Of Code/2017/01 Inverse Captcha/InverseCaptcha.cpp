#include <iostream>
using namespace std;

#define isDebug true

int main() {
    char captcha[10000];
    int sum;
    int length;

    sum = 0;
    length = 0;
    cin >> captcha;
    while (captcha[length]) length++;

    if (isDebug) cout << "[" << captcha << "] : " << length << endl;

    // // part 1
    // for (int i = 0; i < length-1; i++) 
    //     if (captcha[i] == captcha[i+1])
    //         sum += captcha[i] - '0';
    // if (captcha[length-1] == captcha[0]) sum += captcha[0] - '0';

    // part 2
    int half = length / 2;
    for (int i = 0; i < length-1; i++)
        if (captcha[i] == captcha[(i + half) % length])
            sum += captcha[i] - '0';


    cout << sum << endl;

    return 0;
}