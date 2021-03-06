// https://www.hackerrank.com/challenges/contacts/
// http://www.geeksforgeeks.org/trie-insert-and-search/

// C++ implementation of search and insert
// operations on Trie
#include <iostream>
#include <string>
using namespace std;
 
const int ALPHABET_SIZE = 26;
const bool debug = false;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int childCount;
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
    pNode->childCount = 0;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    
    pCrawl->childCount++;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
        pCrawl->childCount++;
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

int prefixCount(struct TrieNode *root, string key) {
    if (debug) cout << "prefix count [" << key << "] : ";
    struct TrieNode *p = root;

    // move cursor to the end of the prefix
    bool isPrefix = true;
    for (int i = 0; i < key.length() && isPrefix; i++) {
        int index = key[i] - 'a';
        if (!p->children[index]) isPrefix = false;
        p = p->children[index];
        
        if (debug) { char aChar = 'a' + index; cout << "." << aChar;}
    }

    if (isPrefix) return p->childCount;
    else return 0;
}
 
// Driver
int main()
{
    struct TrieNode *root = getNode();

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int cc;
        char parameter[22];
        cin >> cc >> parameter;

        if (cc == 0) insert(root, parameter);
        else cout << prefixCount(root, parameter) << endl;
    }

    return 0;
}