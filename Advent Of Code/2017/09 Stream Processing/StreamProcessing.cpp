#include <iostream>
#include <fstream>
using namespace std;

#define isDebug false

    int streamLength(char chars[]) {
        int len = 0;
        while (chars[len]) {
            len++;
        }
        return len;
    }

    void printStream(char chars[], int len) {
        cout << len << " : [";
        for (int i = 0; i < len; i++) cout << chars[i];
        cout << "]" << endl;
    }

int main() {
    ifstream inputFile("StreamProcessing.txt");

    int length;
    char charStream[50000];
    while (inputFile >> charStream) {
        cout << "original charStream = [" << charStream << "]" << endl;
        length = streamLength(charStream);

        // process !
        for (int i = 0; i < length; i++) if (charStream[i] == '!') {
            length -= 2;
            for (int j = i; j < length; j++) charStream[j] = charStream[j+2];
            i--;
        }
        if (isDebug) cout << " after ! : ";
        if (isDebug) printStream(charStream, length);

        // remove anything between < and >
        int totalGarbage = 0;
        for (int i = 0; i < length; i++) if (charStream[i] == '<') {
            int endPos = i;
            while (charStream[endPos] != '>') endPos++;
            endPos += 1;
            int delCount = endPos - i;

            for (int j = 0; j < length-endPos; j++) charStream[i + j] = charStream[endPos + j];
            length -= delCount;
            totalGarbage += delCount - 2;

            i--;
        }
        if (isDebug) cout << " after <> : ";
        if (isDebug) printStream(charStream, length);

        // count the total score
        long score = 0;
        int level = 0;
        for (int i = 0; i < length; i++) {
            if (charStream[i] == '{') level++;
            else if (charStream[i] == '}') {
                score += level;
                level--;
            }
        }

        cout << "score = " << score << endl;
        cout << "garbage = " << totalGarbage << endl;
    }

    return 0;
}