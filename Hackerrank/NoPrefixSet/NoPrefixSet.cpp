#include <iostream>
using namespace std;

int N;
bool isBadSet;
bool isDebug = false;

struct t_trie {
    t_trie *node[10];
    bool isEnd;
    t_trie() {
        for (int i = 0; i < 10; i++) node[i] = NULL;
        isEnd = false;
    }
};

void insertToTrie(t_trie *point, char *str) {
    if (isDebug) cout << "now processing : [" << str << "]\n";

    int strIndex = 0;
    while (str[strIndex]) {
        int index = str[strIndex] - 'a';
        if (point->node[index] == NULL) {
            t_trie *newNode = new t_trie();
            point->node[index] = newNode;
            point = newNode;
        } else if (point->node[index]->isEnd) {
            if (isDebug) cout << "found isEnd at [" << strIndex << "] : " <<  str[strIndex] << endl;       
            isBadSet = true;
            return;
        } else {
            point = point->node[index];
        }
        
        strIndex++;
    }

    point->isEnd = true;

    // ok, we've reach the end, check if this end has childs, if it is then this is also a case of prefix!
    bool hasChild = false;
    for (int i = 0; i < 10; i++) {       
        if (point->node[i]) {
            isBadSet = true;
            if (isDebug) cout << "found that [" << str << "] is a prefix!" << endl;
        }
    }


}

int main() {
    t_trie *head = new t_trie();
    
    cin >> N;
    
    isBadSet = false;
    char inputan[61];
    for (int t = 0; t < N && !isBadSet; t++) {
        cin >> inputan;
        insertToTrie(head, inputan);
        if (isBadSet)  cout << "BAD SET\n" << inputan;
    }
    
    if (!isBadSet) cout << "GOOD SET";
    
    return 0;
}
