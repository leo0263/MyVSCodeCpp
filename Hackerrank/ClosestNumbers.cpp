// https://www.hackerrank.com/challenges/closest-numbers/problem
// by leo.0263

#include <iostream>
using namespace std;

const int arrLength = 200000 + 1;
int N;
int data[arrLength];

int absolutDiff(int a, int b) {
    int diff = a - b;
    if (diff < 0) diff *= -1;

    return diff;
}

// as expected, this makes it time out!
void doBubbleSort() {
    for (int x = 0; x < N-1; x++)
    for (int y = x+1; y < N; y++)
        if (data[x] > data[y]) {
            int z = data[x];
            data[x] = data[y];
            data[y] = z;
        }
}

void merge(int A[], int start, int mid, int end)
{
    //stores the starting position of both parts in temporary variables.
    int p = start, q = mid + 1;
    int Arr[end - start + 1], k = 0;

    for (int i = start; i <= end; i++)
    {
        if (p > mid) //checks if first part comes to an end or not .
            Arr[k++] = A[q++];

        else if (q > end) //checks if second part comes to an end or not
            Arr[k++] = A[p++];

        else if (A[p] < A[q]) //checks which part has smaller element.
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }

    for (int p = 0; p < k; p++)
    {
        // Now the real array has elements in sorted manner including both parts.
        A[start++] = Arr[p];
    }
}

void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2; // defines the current array in 2 parts .
        merge_sort(A, start, mid);   // sort the 1st part of array .
        merge_sort(A, mid + 1, end); // sort the 2nd part of array.

        // merge the both parts by comparing elements of both the parts.
        merge(A, start, mid, end);
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    //doBubbleSort();
    merge_sort(data, 0, N-1);

    // start the logic
    int minDist = absolutDiff(data[N], data[N-1]);
    for (int i = 0; i < N-1; i++) {
        int dist = absolutDiff(data[i], data[i+1]);
        if (dist < minDist) minDist = dist;
    }

    // print the answer
    for (int i = 0; i < N-1; i++) {
        int dist = absolutDiff(data[i], data[i+1]);
        if (dist == minDist) cout << data[i] << " " << data[i+1] << " ";
    }

    return 0;
}