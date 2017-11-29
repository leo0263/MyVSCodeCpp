#include <iostream>
using namespace std;

#define isDebug false

const int directions = 4;
const int dirX[4] = {  0,  0, -1,  1 }; // up down left right
const int dirY[4] = { -1,  1,  0,  0 };

int t, row, col;
int map[100][100];

    bool hasApple() {
        for (int y = 0; y < row; y++) 
            for (int x = 0; x < col; x++)
                if (map[y][x] == 1) return true;

        return false;
    }

    bool hasRot() {
        for (int y = 0; y < row; y++) 
            for (int x = 0; x < col; x++)
                if (map[y][x] == 2) return true;

        return false;
    }

    void rot(int y, int x) {
        if ((y < 0) || (x < 0) || (y >= row) || (x >= col)) return;
        if (map[y][x] == 1) map[y][x] = 3;
    }

    void doRot() {
        for (int y = 0; y < row; y++) 
            for (int x = 0; x < col; x++)
                if (map[y][x] == 3) map[y][x] = 2;
    }

    void printMap(int day) {
        cout << "map day : " << day << endl;
        for (int y = 0; y < row; y++) {
            for (int x = 0; x < col; x++) {
                cout << map[y][x] << " ";
            }
            cout << endl;
        }
    }


int main() {
    cin >> t;

    while (t--) {
        cin >> row >> col;
        for (int y = 0; y < row; y++) 
            for (int x = 0; x < col; x++)
                cin >> map[y][x];

        int days = 0;
        if (isDebug) printMap(days);
        while (hasApple() && hasRot()) {
            days++;

            for (int y = 0; y < row; y++) 
                for (int x = 0; x < col; x++)
                    if (map[y][x] == 2) {
                        map[y][x] = 4;
                        for (int i = 0; i < directions; i++) rot(y + dirY[i], x + dirX[i]);
                    }
            
            doRot();
            if (isDebug) printMap(days);
        }

        if (hasApple()) cout << -1 << endl;
        //else if (!hasApple() && days == 0) cout << -1 << endl;
        else cout << days << endl;
    }

    return 0;
}