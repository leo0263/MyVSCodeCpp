// taken from : http://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
// apparently the above implementation does not handle duplicate data
// adding code to handle duplicate data
// then adding code to search multiple (if any) data : searchM(int)

#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  new node();
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == nullptr) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != nullptr)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == nullptr) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == nullptr)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is nullptr or key is present at root
    if (root == nullptr || root->key == key)
    return root;
    
    // Key is greater than root's key
    if (root->key < key)
    return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// adding multiple search functions -----------------------------------------
// capable to handle multiple search result, stored in searchResult struct
struct searchResults {
    node *result;
    searchResults *next;

    searchResults() {
        result = nullptr;
        next = nullptr;
    }
};

struct searchResults *multiSearch(node *root, int key) {
    searchResults *multiSearchResult = new searchResults();
    searchResults *p = multiSearchResult;

    node *s = search(root, key);
    while (s != nullptr) {
        if (p->result == nullptr) {
            p->result = s;
        } else {
            searchResults *n = new searchResults();            
            p->next = n;
            p = n;
            p->result = s;    
        }
        s = search(s->right, key);
    }
    cout << "sibabi!\n";
    return multiSearchResult;
}

void printMultiSearchResult(searchResults *s) {
    cout << "multi search result :";
    while (s != nullptr) {
        if (s->result == nullptr) break;
        cout << " " << s->result->key;
        s = s->next;
    }
    cout << endl;
}

  
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
       struct node *root = nullptr;
       root = insert(root, 50);
       root = insert(root, 30);
       root = insert(root, 20);
       root = insert(root, 40);
       root = insert(root, 70);
       root = insert(root, 60);
       root = insert(root, 80);
    
       printf("Inorder traversal of the given tree \n");
       inorder(root);
    
       printf("\nDelete 20\n");
       root = deleteNode(root, 20);
       printf("Inorder traversal of the modified tree \n");
       inorder(root);
    
       printf("\nDelete 30\n");
       root = deleteNode(root, 30);
       printf("Inorder traversal of the modified tree \n");
       inorder(root);
    
       printf("\nDelete 50\n");
       root = deleteNode(root, 50);
       printf("Inorder traversal of the modified tree \n");
       inorder(root);

       printf("\nadd more data : 50, 30, 20, 40, 70, 60, 80\n");
       root = insert(root, 50);
       root = insert(root, 30);
       root = insert(root, 20);
       root = insert(root, 40);
       root = insert(root, 70);
       root = insert(root, 60);
       root = insert(root, 80);
       printf("Inorder traversal of the modified tree (adding duplicates?) \n");
       inorder(root);

       int toSearch;
       struct node *result = nullptr;
       
       toSearch = 20;
       result = search(root, toSearch);
       if (result) printf("try search(%d) -> FOUND!\n", toSearch);
       else printf("try search(%d) -> NOT FOUND!\n", toSearch);

       toSearch = 120;
       result = search(root, toSearch);
       if (result) printf("try search(%d) -> FOUND!\n", toSearch);
       else printf("try search(%d) -> NOT FOUND!\n", toSearch);

       toSearch = 20;
       cout << "\ntrying multi search of " << toSearch << endl;
       printMultiSearchResult(multiSearch(root, toSearch));

       toSearch = 43;
       cout << "\ntrying multi search of " << toSearch << endl;
       printMultiSearchResult(nullptr);

    
       return 0;
}