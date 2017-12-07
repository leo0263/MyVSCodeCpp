////#ifndef _CRT_SECURE_NO_WARNINGS
////#define _CRT_SECURE_NO_WARNINGS
////#endif
////
////#include <stdio.h>
////#include <string.h>
////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////
////extern void Init();
////extern void NewAccount(char id[11], char password[11], int defaulttime);
////extern void Logout(char id[11]);
////extern void Connect(char id[11], char password[11]);
////extern int Tick();
////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////
////#define MAX_ACCOUNT 50000
////#define MAX_TIME 30000
////
////typedef enum {
////	INIT,
////	NEWACCOUNT,
////	LOGOUT,
////	CONNECT,
////	TICK
////}STATE;
////
////typedef struct {
////	char id[11];
////	char password[11];
////	int defaulttime;
////}ACCOUNT;
////static ACCOUNT account[MAX_ACCOUNT];
////
////static int mSeed;
////static int mrand(int num)
////{
////	mSeed = mSeed * 1103515245 + 12345;
////	return (((mSeed >> 16) & 0x7FFF) % num);
////}
////
////static void make_account(int cnt)
////{
////	for (int i = 0; i < cnt; i++) {
////		int idl = 5 + mrand(6);
////		for (int k = 0; k < idl; k++) {
////			int ch = mrand(36);
////			if (ch < 10) account[i].id[k] = ch + '0';
////			else account[i].id[k] = ch - 10 + 'a';
////		}
////		account[i].id[idl] = '\0';
////
////		int pal = 5 + mrand(6);
////		for (int k = 0; k < pal; k++) {
////			int ch = mrand(36);
////			if (ch < 10) account[i].password[k] = ch + '0';
////			else account[i].password[k] = ch - 10 + 'a';
////		}
////		account[i].password[pal] = '\0';
////
////		int max_time = cnt;
////		if (max_time > MAX_TIME) max_time = MAX_TIME;
////		account[i].defaulttime = 1 + mrand(max_time);
////	}
////}
////
////static void init(int num)
////{
////	Init();
////
////	make_account(num);
////	for (int i = 0; i < num / 3; i++) {
////		char id[11], password[11];
////		int defaulttime;
////		strcpy(id, account[i].id);
////		strcpy(password, account[i].password);
////		defaulttime = account[i].defaulttime;
////		NewAccount(id, password, defaulttime);
////	}
////}
////
////static int run()
////{
////	int ret = 1;
////	int cmd, param1, param2, num, cmdcnt;
////
////	char id[11], password[11];
////	int defaulttime;
////
////	scanf("%d %d %d %d", &cmd, &mSeed, &num, &cmdcnt);
////	init(num);
////
////	for (int i = 0; i < cmdcnt; i++) {
////		scanf("%d", &cmd);
////		if (cmd == NEWACCOUNT) {
////			scanf("%d %d", &param1, &param2);
////			strcpy(id, account[param1].id);
////			strcpy(password, account[param1].password);
////			defaulttime = param2;
////			NewAccount(id, password, defaulttime);
////		}
////		else if (cmd == LOGOUT) {
////			scanf("%d", &param1);
////			strcpy(id, account[param1].id);
////			Logout(id);
////		}
////		else if (cmd == CONNECT) {
////			scanf("%d %d", &param1, &param2);
////			strcpy(id, account[param1].id);
////			strcpy(password, account[param2].password);
////			Connect(id, password);
////		}
////		else if (cmd == TICK) {
////			scanf("%d", &param1);
////			int result = Tick();
////			if (result != param1)
////				ret = 0;
////		}
////	}
////
////	return ret;
////}
////
////int main()
////{
////	setbuf(stdout, NULL);
////	//freopen("sample_input.txt", "r", stdin);
////
////	int T;
////	scanf("%d", &T);
////
////	for (int tc = 1; tc <= T; tc++)
////	{
////		int Score = 100;
////		if (run() == 0)
////			Score = 0;
////
////		printf("#%d %d\n", tc, Score);
////	}
////
////	return 0;
////}
////
////
////void Init()
////{
////}
////
////void NewAccount(char id[11], char password[11], int defaulttime)
////{
////}
////
////void Logout(char id[11])
////{
////}
////
////void Connect(char id[11], char password[11])
////{
////}
////
////int Tick()
////{
////	return 0;
////}
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////import java.util.Scanner;
////
////public class Solution {
////	private static Scanner sc;
////
////	private final static int MAX_ACCOUNT = 50000;
////	private final static int MAX_TIME = 30000;
////	private final static int MAX_STR = 11;
////	
////	private final static int INIT = 0;
////	private final static int NEWACCOUNT = 1;
////	private final static int LOGOUT = 2;
////	private final static int CONNECT = 3;
////	private final static int TICK = 4;
////	
////	private static class ACCOUNT {
////        public char id[];
////		public char password[];
////		public int defaulttime;
////		
////		ACCOUNT() {
////			id = new char[MAX_STR];
////			password = new char[MAX_STR];
////		}
////    }
////	
////	private static UserSolution user = new UserSolution();
////	private static ACCOUNT account[] = new ACCOUNT[MAX_ACCOUNT];
////	
////	private static int mSeed;
////	private static int mrand(int num)
////	{
////		mSeed = mSeed * 1103515245 + 12345;
////		return (((mSeed >> 16) & 0x00007FFF) % num);
////	}
////	
////	static {
////		for (int i = 0; i < MAX_ACCOUNT; i++)
////			account[i] = new ACCOUNT();
////	}
////	
////	static void make_account(int cnt)
////	{
////		for (int i = 0; i < cnt; i++) {
////			int idl = 5 + mrand(6);
////			for (int k = 0; k < idl; k++) {
////				int ch = mrand(36);
////				if (ch < 10) account[i].id[k] = (char)(ch + '0');
////				else account[i].id[k] = (char)(ch - 10 + 'a');
////			}
////			account[i].id[idl] = '\0';
////
////			int pal = 5 + mrand(6);
////			for (int k = 0; k < pal; k++) {
////				int ch = mrand(36);
////				if (ch < 10) account[i].password[k] = (char)(ch + '0');
////				else account[i].password[k] = (char)(ch - 10 + 'a');
////			}
////			account[i].password[pal] = '\0';
////
////			int max_time = cnt;
////			if (max_time > MAX_TIME) max_time = MAX_TIME;
////			account[i].defaulttime = 1 + mrand(max_time);
////		}
////	}
////	
////	static void init(int num)
////	{
////		user.Init();
////
////		make_account(num);
////		for (int i = 0; i < num / 3; i++) {
////			user.NewAccount(account[i].id, account[i].password, account[i].defaulttime);
////		}
////	}
////
////	static int run()
////	{
////		int ret = 1;
////		int cmd, num, cmdcnt, param1, param2;
////
////		cmd = sc.nextInt();
////		mSeed = sc.nextInt();
////		num = sc.nextInt();
////		cmdcnt = sc.nextInt();
////
////		init(num);
////
////		for (int i = 0; i < cmdcnt; i++) {
////			cmd = sc.nextInt();
////			if (cmd == NEWACCOUNT) {
////				param1 = sc.nextInt();
////				param2 = sc.nextInt();				
////				user.NewAccount(account[param1].id, account[param1].password, param2);
////			}
////			else if (cmd == LOGOUT) {
////				param1 = sc.nextInt();				
////				user.Logout(account[param1].id);
////			}
////			else if (cmd == CONNECT) {
////				param1 = sc.nextInt();
////				param2 = sc.nextInt();
////				user.Connect(account[param1].id, account[param2].password);
////			}
////			else if (cmd == TICK) {
////				param1 = sc.nextInt();
////				int result = user.Tick();
////				if (result != param1)
////					ret = 0;
////			}
////		}
////
////		return ret;
////	}	
////
////	public static void main(String[] args) throws Exception {
////		// System.setIn(new java.io.FileInputStream("sample_input.txt"));
////		sc = new Scanner(System.in);		
////				
////		int T;
////		T = sc.nextInt();
////		for (int tc = 1; tc <= T; ++tc) {
////			int Score = 100;
////			if (run() == 0)
////				Score = 0;
////			System.out.println("#" + tc + " " + Score);
////		}
////		sc.close();
////	}
////}
////
////public class UserSolution {
////	
////	public void Init()
////	{
////	}
////
////	public void NewAccount(char id[], char password[], int defaulttime)
////	{
////	}
////
////	public void Logout(char id[])
////	{
////	}
////
////	public void Connect(char id[], char password[])
////	{
////	}
////
////	public int Tick()
////	{
////		return 0;
////	}
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////PM> type ransomnote_hash.cpp
////// https://www.hackerrank.com/challenges/ctci-ransom-note/problem
////// leo.0263
////
////#include <iostream>
////using namespace std;
////
////    const int maxWords = 30000;
////    const int maxHashTable = maxWords * 10;
////    const int maxStr = 5;
////    const bool isDebug = false;
////
////    struct t_data { 
////        bool isVoid;
////        int count;
////        char magazine[maxStr+1];
////
////		t_data() {
////            isVoid = true;
////            count = 0;
////			magazine[0] = '\0';
////		}
////    };
////
////    int Mag, Ran;
////    char magazine[maxWords+1][maxStr+1];
////    char ransom[maxWords+1][maxStr+1];
////    t_data data[maxHashTable+1];
////
////    unsigned long doHash(char *str)
////    {
////        unsigned long hash = 5381;
////        int c;
////
////        while (c = *str++)
////            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
////
////        return hash;
////    }
////
////
////void stringCopy(char* toStr, char* fromStr) {
////    int i = 0;
////    while (fromStr[i] != '\0') {
////        toStr[i] = fromStr[i];
////        i++;
////    }
////    toStr[i] = '\0';
////}
////
////bool stringCompare(char* str1, char* str2) {
////    bool isSame = true;
////    bool notEOS = true;
////    int i = 0;
////
////    while (notEOS && isSame) {
////        if (str1[i] != str2[i])  isSame = false;
////        if (str1[i] == '\0') notEOS = false;
////        if (str2[i] == '\0') notEOS = false;
////        i++;
////    }
////
////    return isSame;
////}
////       
////bool checkRansomNotes() {
////    //cout << "insert the magazine words into hash table\n";
////    for (int i = 0; i < Mag; i++) {
////        int index = doHash(magazine[i]) % maxHashTable;
////        
////        bool isCollition = true;
////        bool isAlreadyThere = false;
////        while (!data[index].isVoid && isCollition) {
////            if (data[index].isVoid) isCollition = false;
////            else if (stringCompare(data[index].magazine, magazine[i])) {
////                isCollition = false;
////                isAlreadyThere = true;
////                data[index].count++;
////            } else index = (index+1) % maxHashTable;
////        } 
////        
////        if (!isAlreadyThere) {
////            data[index].isVoid = false;
////            data[index].count++;
////            stringCopy(data[index].magazine, magazine[i]);
////        }
////
////        if (isDebug) {
////		    cout << "mag[" << magazine[i] << "] di masukin ke data [" << index << "] via doHash()\n";            
////        }
////
////    }
////
////    //cout << "foreach ransom words, check if the words exists in the hash table\n";
////    // if even one ransom word dont exists, return false!
////    for (int i = 0; i < Ran; i++) {
////        int index = doHash(ransom[i]) % maxHashTable;
////		while((stringCompare(data[index].magazine, ransom[i]) == false) && (data[index].isVoid == false)) {
////			index = (index+1) % maxHashTable;
////        }
////        
////        if (data[index].isVoid) {
////            if (isDebug) cout << "ransom word [" << ransom[i] << "] ketemu VOID <- NOT FOUND!";
////            return false;
////        } else {
////            data[index].count--;
////            if (data[index].count < 0) {
////                if (isDebug) {
////                    cout << "returning false because cannot find this ransom [" << ransom[i] << "]\n";
////                    cout << "last accessed hash table = data[" << index << "].[" << data[index].magazine << "]\n";
////                }
////
////                return false;
////            }
////
////            if (isDebug) cout << "ransom word [" << ransom[i] << "] found at data[" << index << "].[" << data[index].magazine << "]\n";
////        }
////        
////        // // debug!
////        // if (stringCompare(data[index].magazine, ransom[i])) 
////        //     cout << "\nransom word [" << ransom[i] << "] found at data[" << index << "]";
////    }
////
////    return true;
////}
////
////int main(){
////	// setbuf(stdout, NULL);
////	// freopen("input.txt", "r", stdin);
////
////    
////    cin >> Mag >> Ran;
////    //cout << "mag:" << Mag << " ran:" << Ran << endl;
////
////    for(int i = 0; i < Mag; i++) {
////        cin >> magazine[i];
////        // cout << "\nbarusan baca mag: " << magazine[i];
////    }
////    
////    for(int i = 0; i < Ran; i++) {
////        cin >> ransom[i];
////        /*cout << "\nbarusan baca ran: " << ransom[i];*/
////    }
////    
////    //cout << "sapi!";
////
////    //// debug
////    //for(int i = 0; i < Mag; i++) cout << "magazine : [" << magazine[i] << "]\n";
////    //for(int i = 0; i < Ran; i++) cout << "ransom : [" << ransom[i] << "]\n";
////    //for (int i = 0; i < maxWords; i++) if (data[i].isVoid != true) cout << "data[" << i << "] is not properly initialized!\n";
////
////    if(checkRansomNotes()) cout << "Yes\n";
////    else cout << "No\n";
////    
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//PM> type .\JesseAndCookies.cpp
//// https://www.hackerrank.com/contests/srin-pro-i-1/challenges/jesse-and-cookies
//
//// A C++ program to demonstrate common Binary Heap Operations
//#include <iostream>
//#include <climits>
//using namespace std;
//
//const bool debug = true;
// 
//// Prototype of a utility function to swap two integers
//void swap(long *x, long *y);
// 
//// A class for Min Heap
//class MinHeap
//{
//    long *harr; // pointer to array of elements in heap
//    long capacity; // maximum possible size of min heap
//    long heap_size; // Current number of elements in min heap
//public:
//    // Constructor
//    MinHeap(long capacity);
// 
//    // to heapify a subtree with root at given index
//    void MinHeapify(long );
// 
//    long parent(long i) { return (i-1)/2; }
// 
//    // to get index of left child of node at index i
//    long left(long i) { return (2*i + 1); }
// 
//    // to get index of right child of node at index i
//    long right(long i) { return (2*i + 2); }
// 
//    // to extract the root which is the minimum element
//    long extractMin();
// 
//    // Decreases key value of key at index i to new_val
//    void decreaseKey(long i, long new_val);
// 
//    // Returns the minimum key (key at root) from min heap
//    long getMin() { return harr[0]; }
// 
//    // Deletes a key stored at index i
//    void deleteKey(long i);
// 
//    // Inserts a new key 'k'
//    void insertKey(long k);
//
//    long getSize() { return heap_size; }
//};
// 
//// Constructor: Builds a heap from a given array a[] of given size
//MinHeap::MinHeap(long cap)
//{
//    heap_size = 0;
//    capacity = cap;
//    harr = new long[cap];
//}
// 
//// Inserts a new key 'k'
//void MinHeap::insertKey(long k)
//{
//    if (heap_size == capacity)
//    {
//        cout << "\nOverflow: Could not insertKey\n";
//        return;
//    }
// 
//    // First insert the new key at the end
//    heap_size++;
//    long i = heap_size - 1;
//    harr[i] = k;
// 
//    // Fix the min heap property if it is violated
//    while (i != 0 && harr[parent(i)] > harr[i])
//    {
//       swap(&harr[i], &harr[parent(i)]);
//       i = parent(i);
//    }
//}
// 
//// Decreases value of key at index 'i' to new_val.  It is assumed that
//// new_val is smaller than harr[i].
//void MinHeap::decreaseKey(long i, long new_val)
//{
//    harr[i] = new_val;
//    while (i != 0 && harr[parent(i)] > harr[i])
//    {
//       swap(&harr[i], &harr[parent(i)]);
//       i = parent(i);
//    }
//}
// 
//// Method to remove minimum element (or root) from min heap
//long MinHeap::extractMin()
//{
//    if (heap_size <= 0)
//        return INT_MAX;
//    if (heap_size == 1)
//    {
//        heap_size--;
//        return harr[0];
//    }
// 
//    // Store the minimum value, and remove it from heap
//    long root = harr[0];
//    harr[0] = harr[heap_size-1];
//    heap_size--;
//    MinHeapify(0);
// 
//    return root;
//}
// 
// 
//// This function deletes key at index i. It first reduced value to minus
//// infinite, then calls extractMin()
//void MinHeap::deleteKey(long i)
//{
//    decreaseKey(i, INT_MIN);
//    extractMin();
//}
// 
//// A recursive method to heapify a subtree with root at given index
//// This method assumes that the subtrees are already heapified
//void MinHeap::MinHeapify(long i)
//{
//    long l = left(i);
//    long r = right(i);
//    long smallest = i;
//    if (l < heap_size && harr[l] < harr[i])
//        smallest = l;
//    if (r < heap_size && harr[r] < harr[smallest])
//        smallest = r;
//    if (smallest != i)
//    {
//        swap(&harr[i], &harr[smallest]);
//        MinHeapify(smallest);
//    }
//}
// 
//// A utility function to swap two elements
//void swap(long *x, long *y)
//{
//    long temp = *x;
//    *x = *y;
//    *y = temp;
//}
// 
//// Driver program to test above functions
//int main()
//{
//    MinHeap h(1000001);
//
//    long N, K;
//    
//    
//    cin >> N >> K;
//    for (long i = 0; i < N; i++) {
//        long data; cin >> data;
//        h.insertKey(data);
//    }
//
//    long total = 0;
//    long count = 0;
//    while ((h.getSize() > 1) && (h.getMin() < K)) {
//        long firstPick = h.extractMin();
//        long secondPick = 2 * h.extractMin();
//        h.insertKey(firstPick + secondPick);
//        count++;
//    }
//
//    if ((h.getSize() <= 1) && (h.getMin() < K)) {
//        cout << "-1\n";
//    } else {
//        cout << count << endl;
//    }
//
//    return 0;
//}
//PM> 















//
//	if (!gotInterrupt) {
//		interrupt = extractMinHeap();
//		if (interrupt.nextTick != -1) gotInterrupt = true;
//	}
//
///*	gotSameInterrupt = true;
//	while (gotInterrupt && gotSameInterrupt) {
//		if (data[interrupt.index].isLoggedIn && (now == data[interrupt.index].nextTick)) {
//			timedOutUsers++;
//
//			interrupt = extractMinHeap();
//
//			if (interrupt.nextTick != -1) {
//				if (interrupt.nextTick == now) gotSameInterrupt = true;
//				else gotSameInterrupt = false;
//				gotInterrupt = true;
//			} else {
//				gotInterrupt = false;
//			}
//		} else if  gotSameInterrupt = false;
//	}*/ 
//
//	while (gotInterrupt && (now == data[interrupt.index].nextTick)) {
//		if (data[interrupt.index].isLoggedIn && (now == data[interrupt.index].nextTick)) timedOutUsers++;
//
//		interrupt = extractMinHeap();
//
//		if (interrupt.nextTick != -1) {
//			gotInterrupt = true;
//		} else {
//			gotInterrupt = false;
//		}
//	}