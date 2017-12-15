#include <iostream>
using namespace std;

#define isDebug true

const int inputan = 312051;
const int centerX = 500; 
const int centerY = 500;
const int maxMap = 1000;
int inputanX, inputanY;
int map[maxMap][maxMap];

// direction : right, up, left, down (repeat)
const int dirX[4] = { +1,  0, -1,  0 };
const int dirY[4] = {  0, -1,  0, +1 };

// neighbors : counter clockwise : east, northeast, north, northwest, west, etc..
const int neighborX[8] = { +1, +1, +0, -1, -1, -1, -0, +1 };
const int neighborY[8] = { +0, -1, -1, -1, +0, +1, +1, +1 };

    int absolutDiff(int a, int b) {
        int diff = a - b;
        if (diff < 0) diff *= -1;

        return diff;
    }

    int sumNeighbors(int y, int x) {
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            if (map[y + neighborY[i]][x + neighborX[i]] != -1) {
                sum += map[y + neighborY[i]][x + neighborX[i]];
                //if (isDebug) cout << "sum now is : " << sum << " at (" << x + neighborX[i] << ", " << y + neighborY[i] << ")" << endl;
            }
        }
        return sum;
    }

int main() { 
    int X = centerX;
    int Y = centerY;
    int jumpDistance = 1;
    int direction = 0;
    int directionCount = 2;
    int index = 1;

    // part 01
    // X = 0;
    // Y = 0;
    // while (index < inputan) {
    //     if (directionCount == 0) {
    //         jumpDistance++;
    //         directionCount = 2;
    //     }
        
    //     for (int i = 0; i < jumpDistance; i++) {
    //         index++;
    //         X += dirX[direction];
    //         Y += dirY[direction];
    //         if (index == inputan) {
    //             inputanX = X;
    //             inputanY = Y;
    //         }
    //         if (isDebug) cout << index << " : (" << X << ", " << Y << ")" << endl;
    //     }

    //     direction++;
    //     direction %= 4;
    //     directionCount--;
    // }

    // int manhattanDistance = absolutDiff(inputanX, 0) + absolutDiff(inputanY, 0);

    // cout << "inputan [" << inputan << "] is written at (" << inputanX << ", " << inputanY << ")" << endl;
    // cout << "it's distance to (0, 0) is : " <<  manhattanDistance << endl;


    // part 02
    for (int y = 0; y < maxMap; y++)
        for (int x = 0; x < maxMap; x++)
            map[y][x] = -1;
    int firstMax = 0;
    bool firstMaxFound = false;
    map[Y][X] = 1;

    while (!firstMaxFound) {
        if (directionCount == 0) {
            jumpDistance++;
            directionCount = 2;
        }
        
        for (int i = 0; i < jumpDistance; i++) {
            index++;
            X += dirX[direction];
            Y += dirY[direction];

            map[Y][X] = sumNeighbors(Y, X);
            if (isDebug) cout << "writing sum of : " << map[Y][X] << " at (" << X << ", " << Y << ")" << endl;

            if (map[Y][X] > inputan && !firstMaxFound) {
                firstMaxFound = true;
                firstMax = map[Y][X];
                cout << "firstMax = " << firstMax << " at (" << X << ", " << Y << ")" << endl;
            }            
        }

        direction++;
        direction %= 4;
        directionCount--;
    }    

    return 0;
}