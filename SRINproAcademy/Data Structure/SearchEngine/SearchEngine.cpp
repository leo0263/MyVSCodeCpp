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
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
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
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int crawlPrefixChilds(struct TrieNode *root) {
    if (root == NULL) return 0;

    int count = 0;
    if (root->isEndOfWord) count++;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        count += crawlPrefixChilds(root->children[i]);
    }

    return count;
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

     int count = 0;
     if (isPrefix) {
        count += crawlPrefixChilds(p);
     }

     if (debug) cout << endl;
     return count;
}
 
// Driver
int main()
{
    struct TrieNode *root = getNode();

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char command[22], parameter[22];
        cin >> command >> parameter;

        if (command[0] == 'a') insert(root, parameter);
        else cout << prefixCount(root, parameter) << endl;
    }

    return 0;
}