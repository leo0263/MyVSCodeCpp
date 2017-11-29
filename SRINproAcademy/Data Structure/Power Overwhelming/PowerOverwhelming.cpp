// https://www.hackerrank.com/contests/srin-pro-i-1/challenges/jesse-and-cookies

// A C++ program to demonstrate common Binary Heap Operations
#include <iostream>
#include <climits>
using namespace std;

const bool debug = true;
 
// Prototype of a utility function to swap two integers
void swap(long *x, long *y);
 
// A class for Min Heap
class MinHeap
{
    long *harr; // pointer to array of elements in heap
    long capacity; // maximum possible size of min heap
    long heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(long capacity);
 
    // to heapify a subtree with root at given index
    void MinHeapify(long );
 
    long parent(long i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    long left(long i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    long right(long i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    long extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(long i, long new_val);
 
    // Returns the minimum key (key at root) from min heap
    long getMin() { return harr[0]; }
 
    // Deletes a key stored at index i
    void deleteKey(long i);
 
    // Inserts a new key 'k'
    void insertKey(long k);

    long getSize() { return heap_size; }
};
 
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(long cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new long[cap];
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(long k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    long i = heap_size - 1;
    harr[i] = k;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(long i, long new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
long MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    long root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(long i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(long i)
{
    long l = left(i);
    long r = right(i);
    long smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(long *x, long *y)
{
    long temp = *x;
    *x = *y;
    *y = temp;
}
 
// Driver program to test above functions
int main()
{
    MinHeap h(1000001);

    long N, K;
    
    
    cin >> N >> K;
    for (long i = 0; i < N; i++) {
        long data; cin >> data;
        h.insertKey(data);
    }

    long total = 0;
    long count = 0;
    while ((h.getSize() > 1) && (h.getMin() < K)) {
        long firstPick = h.extractMin();
        long secondPick = 2 * h.extractMin();
        h.insertKey(firstPick + secondPick);
        count++;
    }

    if ((h.getSize() <= 1) && (h.getMin() < K)) {
        cout << "-1\n";
    } else {
        cout << count << endl;
    }

    return 0;
}