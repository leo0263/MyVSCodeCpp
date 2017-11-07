#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

    const int maxWords = 30000;
    const int maxStr = 5;

    struct t_data { 
        bool isVoid = true;
        char magazine[maxStr+1];
    };

    int Mag, Ran;
    char magazine[maxWords+1][maxStr+1];
    char ransom[maxWords+1][maxStr+1];
    t_data data[maxWords+1];

    unsigned long doHash(char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c == *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }


void stringCopy(char* toStr, char* fromStr) {
    int i = 0;
    while (fromStr[i] != '\0') {
        toStr[i] = fromStr[i];
        i++;
    }
    toStr[i] = '\0';
}

bool stringCompare(char* str1, char* str2) {
    bool isSame = true;
    bool notEOS = true;
    int i = 0;

    while (notEOS && isSame) {
        if (str1[i] != str2[i])  isSame = false;
        if (str1[i] == '\0') notEOS = false;
        if (str2[i] == '\0') notEOS = false;
        i++;
    }

    return isSame;
}
       
bool checkRansomNotes() {
    cout << "insert the magazine words into hash table";
    for (int i = 0; i < Mag; i++) {
        int index = doHash(magazine[i]) % maxWords;
        while (!data[index].isVoid) index = (index+1) % maxWords;
        
        data[index].isVoid = false;
        stringCopy(magazine[i], data[index].magazine);
    }

    cout << "foreach ransom words, check if the words exists in the hash table";
    // if even one ransom word dont exists, return false!
    for (int i = 0; i < Ran; i++) {
        int index = doHash(ransom[i]) % maxWords;
        while(!stringCompare(data[index].magazine, ransom[i])) index = (index+1) % maxWords;
        if (data[index].isVoid) return false;
        
        // debug!
        if (stringCompare(data[index].magazine, ransom[i])) 
            cout << "ransom word [" << ransom[i] << "] found at data[" << "]\n";
    }

    return true;
}

int main(){
    
    cin >> Mag >> Ran;

    for(int i = 0; i < Mag; i++) cin >> magazine[i];
    for(int i = 0; i < Ran; i++) cin >> ransom[i];

    // // debug
    // for(int i = 0; i < Mag; i++) cout << "magazine : [" << magazine[i] << "]\n";
    // for(int i = 0; i < Ran; i++) cout << "ransom : [" << ransom[i] << "]\n";
    // for (int i = 0; i < 30000; i++) if (data[i].isVoid != true) cout << "data[" << i << "] is not properly initialized!\n";

    if(checkRansomNotes()) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}