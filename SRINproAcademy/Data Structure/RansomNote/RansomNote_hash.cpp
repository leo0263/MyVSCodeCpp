// https://www.hackerrank.com/challenges/ctci-ransom-note/problem
// leo.0263

#include <iostream>
using namespace std;

    const int maxWords = 30000;
    const int maxHashTable = maxWords * 10;
    const int maxStr = 5;
    const bool isDebug = false;

    struct t_data { 
        bool isVoid;
        int count;
        char magazine[maxStr+1];

		t_data() {
            isVoid = true;
            count = 0;
			magazine[0] = '\0';
		}
    };

    int Mag, Ran;
    char magazine[maxWords+1][maxStr+1];
    char ransom[maxWords+1][maxStr+1];
    t_data data[maxHashTable+1];

    unsigned long doHash(char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
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
    //cout << "insert the magazine words into hash table\n";
    for (int i = 0; i < Mag; i++) {
        int index = doHash(magazine[i]) % maxHashTable;
        
        bool isCollition = true;
        bool isAlreadyThere = false;
        while (!data[index].isVoid && isCollition) {
            if (data[index].isVoid) isCollition = false;
            else if (stringCompare(data[index].magazine, magazine[i])) {
                isCollition = false;
                isAlreadyThere = true;
                data[index].count++;
            } else index = (index+1) % maxHashTable;
        } 
        
        if (!isAlreadyThere) {
            data[index].isVoid = false;
            data[index].count++;
            stringCopy(data[index].magazine, magazine[i]);
        }

        if (isDebug) {
		    cout << "mag[" << magazine[i] << "] di masukin ke data [" << index << "] via doHash()\n";            
        }

    }

    //cout << "foreach ransom words, check if the words exists in the hash table\n";
    // if even one ransom word dont exists, return false!
    for (int i = 0; i < Ran; i++) {
        int index = doHash(ransom[i]) % maxHashTable;
		while((stringCompare(data[index].magazine, ransom[i]) == false) && (data[index].isVoid == false)) {
			index = (index+1) % maxHashTable;
        }
        
        if (data[index].isVoid) {
            if (isDebug) cout << "ransom word [" << ransom[i] << "] ketemu VOID <- NOT FOUND!";
            return false;
        } else {
            data[index].count--;
            if (data[index].count < 0) {
                if (isDebug) {
                    cout << "returning false because cannot find this ransom [" << ransom[i] << "]\n";
                    cout << "last accessed hash table = data[" << index << "].[" << data[index].magazine << "]\n";
                }

                return false;
            }

            if (isDebug) cout << "ransom word [" << ransom[i] << "] found at data[" << index << "].[" << data[index].magazine << "]\n";
        }
        
        // // debug!
        // if (stringCompare(data[index].magazine, ransom[i])) 
        //     cout << "\nransom word [" << ransom[i] << "] found at data[" << index << "]";
    }

    return true;
}

int main(){
	// setbuf(stdout, NULL);
	// freopen("input.txt", "r", stdin);

    
    cin >> Mag >> Ran;
    //cout << "mag:" << Mag << " ran:" << Ran << endl;

    for(int i = 0; i < Mag; i++) {
        cin >> magazine[i];
        // cout << "\nbarusan baca mag: " << magazine[i];
    }
    
    for(int i = 0; i < Ran; i++) {
        cin >> ransom[i];
        /*cout << "\nbarusan baca ran: " << ransom[i];*/
    }
    
    //cout << "sapi!";

    //// debug
    //for(int i = 0; i < Mag; i++) cout << "magazine : [" << magazine[i] << "]\n";
    //for(int i = 0; i < Ran; i++) cout << "ransom : [" << ransom[i] << "]\n";
    //for (int i = 0; i < maxWords; i++) if (data[i].isVoid != true) cout << "data[" << i << "] is not properly initialized!\n";

    if(checkRansomNotes()) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}