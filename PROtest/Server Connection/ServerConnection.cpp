#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define isDebug false

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

extern void Init();
extern void NewAccount(char id[11], char password[11], int defaulttime);
extern void Logout(char id[11]);
extern void Connect(char id[11], char password[11]);
extern int Tick();

int tick_now;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#define MAX_ACCOUNT 50000
#define MAX_TIME 30000

typedef enum {
	INIT,
	NEWACCOUNT,
	LOGOUT,
	CONNECT,
	TICK
}STATE;

typedef struct {
	char id[11];
	char password[11];
	int defaulttime;
}ACCOUNT;
static ACCOUNT account[MAX_ACCOUNT];

static int mSeed;
static int mrand(int num)
{
	mSeed = mSeed * 1103515245 + 12345;
	return (((mSeed >> 16) & 0x7FFF) % num);
}

static void make_account(int cnt)
{
	for (int i = 0; i < cnt; i++) {
		int idl = 5 + mrand(6);
		for (int k = 0; k < idl; k++) {
			int ch = mrand(36);
			if (ch < 10) account[i].id[k] = ch + '0';
			else account[i].id[k] = ch - 10 + 'a';
		}
		account[i].id[idl] = '\0';

		int pal = 5 + mrand(6);
		for (int k = 0; k < pal; k++) {
			int ch = mrand(36);
			if (ch < 10) account[i].password[k] = ch + '0';
			else account[i].password[k] = ch - 10 + 'a';
		}
		account[i].password[pal] = '\0';

		int max_time = cnt;
		if (max_time > MAX_TIME) max_time = MAX_TIME;
		account[i].defaulttime = 1 + mrand(max_time);
	}
}

static void init(int num)
{
	tick_now = 0;
	Init();

	make_account(num);
	for (int i = 0; i < num / 3; i++) {
		char id[11], password[11];
		int defaulttime;
		strcpy(id, account[i].id);
		strcpy(password, account[i].password);
		defaulttime = account[i].defaulttime;
		NewAccount(id, password, defaulttime);
	}
}

static int run()
{
	int ret = 1;
	int cmd, param1, param2, num, cmdcnt;

	char id[11], password[11];
	int defaulttime;

	scanf("%d %d %d %d", &cmd, &mSeed, &num, &cmdcnt);
	init(num);

	for (int i = 0; i < cmdcnt; i++) {
		scanf("%d", &cmd);
		if (cmd == NEWACCOUNT) {
			scanf("%d %d", &param1, &param2);
			strcpy(id, account[param1].id);
			strcpy(password, account[param1].password);
			defaulttime = param2;
			NewAccount(id, password, defaulttime);
			//printf("NEWACCOUNT at tick(%d), id(%s) pass(%s) deftime(%d)\n", tick_now, id, password, defaulttime);
		}
		else if (cmd == LOGOUT) {
			scanf("%d", &param1);
			strcpy(id, account[param1].id);
			Logout(id);
			if(isDebug) printf("LOGOUT at tick(%d), id(%s)\n", tick_now, id);
		}
		else if (cmd == CONNECT) {
			scanf("%d %d", &param1, &param2);
			strcpy(id, account[param1].id);
			strcpy(password, account[param2].password);
			Connect(id, password);
			if(isDebug) printf("CONNECT at tick(%d), id(%s)\n", tick_now, id);
		}
		else if (cmd == TICK) {
			tick_now++;
			scanf("%d", &param1);
			int result = Tick();
			if (result != param1) {
				ret = 0;
				if(isDebug) printf("ERROR at TICK(%d), must be(%d) but got (%d)\n", tick_now, param1, result);
			} else {
				if(isDebug) printf("GOOD! at TICK(%d), must be(%d) but got (%d)\n", tick_now, param1, result);
			}
		}
	}

	return ret;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int Score = 100;
		if (run() == 0)
			Score = 0;

		printf("#%d %d\n", tc, Score);
	}

	return 0;
}


//-------------------------------------------------------------------------------------
// by.0263
//-------------------------------------------------------------------------------------
	//#include <iostream>
	//using namespace std;

	#define MAX_ACCOUNT 50000
	#define MAX_TIME 30000

    const int maxHashTable = MAX_ACCOUNT * 10;
	const int maxHeapSize = MAX_ACCOUNT * 1000;
    const int maxStr = 11;

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

	unsigned long doHash(char *str) {
        unsigned long hash = 5381;
        int c;

        while (c = *str++) hash = ((hash << 5) + hash) + c;

        return hash;
    }

    struct t_data {
		bool isVoid;
		bool isLoggedIn;
        char id[11];
		char password[11];
		int nextTick;
		int defaultTime;

		void initialize(char in_id[11], char in_password[11], int in_defaulttime, int tickTime) {
			stringCopy(id, in_id);
			stringCopy(password, in_password);
			defaultTime = in_defaulttime;
			nextTick = tickTime + defaultTime;
			isVoid = false;
			isLoggedIn = true;

			if(isDebug) printf("at (%d) initializing id(%s) pass(%s) deftime(%d) nexttick(%d)\n", tickTime, id, password, defaultTime, nextTick);
		}

		void reset() {
			//initialize("\0", "\0", 0, 0);
			isVoid = true;
			isLoggedIn = false;
		}

		t_data() {
			reset();
		}
    };

	struct t_minHeap {
		int nextTick;
		int index;
	};

	int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }







	int now;
	t_data data[maxHashTable];
	int heapSize;
	t_minHeap minHeap[maxHeapSize];
	bool firstTick;
	t_minHeap interrupt;


	int getHashIndex(char id[11]) {
		int index = doHash(id) % maxHashTable;
		while((stringCompare(data[index].id, id) == false) && (data[index].isVoid == false)) {
			index = (index+1) % maxHashTable;
        }

		return index;
	}

	void swapMinHeap(int x, int y) {
		t_minHeap temp;
		temp = minHeap[x];
		minHeap[x] = minHeap[y];
		minHeap[y] = temp;
		
		//temp.index = minHeap[x].index;
		//temp.nextTick = minHeap[x].nextTick;
		//minHeap[x].index = minHeap[y].index;
		//minHeap[x].nextTick = minHeap[y].nextTick;
		//minHeap[y].index = temp.index;
		//minHeap[y].nextTick = temp.nextTick;
	}

	void insertMinHeap(int nextTick, int index) {
		heapSize++;
		int i = heapSize - 1;
		minHeap[i].nextTick = nextTick;
		minHeap[i].index = index;
 
		while (i != 0 && minHeap[parent(i)].nextTick > minHeap[i].nextTick) {
		   swapMinHeap(i, parent(i));
		   i = parent(i);
		}
	}

	void minHeapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heapSize && minHeap[l].nextTick < minHeap[i].nextTick) smallest = l;
		if (r < heapSize && minHeap[r].nextTick < minHeap[smallest].nextTick) smallest = r;
		if (smallest != i) {
			swapMinHeap(i, smallest);
			minHeapify(smallest);
		}
	}

	t_minHeap extractMinHeap() {
		if (heapSize <= 0) {
			t_minHeap blank;
			blank.index = -1;
			blank.nextTick = -1;
			return blank;
		}

		if (heapSize == 1) {
			heapSize--;
			return minHeap[0];
		}
 
		t_minHeap root = minHeap[0];
		minHeap[0] = minHeap[heapSize-1];
		heapSize--;
		minHeapify(0);

		if(isDebug) printf("extractMinHeap at tick(%d) got id(%s) nextTick(%d)\n", now, data[root.index].id, data[root.index].nextTick);
 
		return root;
	}













void Init()
{
	now = 0;
	heapSize = 0;
	for (int i = 0; i < maxHashTable; i++) data[i].reset();
	firstTick = true;
}

void NewAccount(char id[11], char password[11], int defaulttime)
{
	    int index = doHash(id) % maxHashTable;
        
        bool isCollition = true;
        while (!data[index].isVoid && isCollition) {
            if (data[index].isVoid) isCollition = false;
            else index = (index+1) % maxHashTable;
        } 
        
		data[index].initialize(id, password, defaulttime, now);
		
		if (!firstTick && interrupt.nextTick > data[index].nextTick) {
			insertMinHeap(interrupt.nextTick, interrupt.index);

			interrupt.index = index;
			interrupt.nextTick = data[index].nextTick;
			
		} else insertMinHeap(data[index].nextTick, index);
}

void Logout(char id[11])
{
	int index = getHashIndex(id);
	if (!data[index].isVoid) {
		data[index].isLoggedIn = false;
	}
}

void Connect(char id[11], char password[11])
{
	int index = getHashIndex(id);
	if (!data[index].isVoid && data[index].isLoggedIn == true && (data[index].nextTick > now)) {
		if (data[index].nextTick != now + data[index].defaultTime) {
			//data[index].isLoggedIn = true;
			data[index].nextTick = now + data[index].defaultTime;
			insertMinHeap(data[index].nextTick, index);

			if (isDebug)
				printf("get connect at(%d) with id(%s) nextTick(%d)\n", now, data[index].id, data[index].nextTick);
		}
	}
}


//bool gotInterrupt = false;
//bool gotSameInterrupt = true;
//t_minHeap interrupt;

int Tick()
{
	int timedOutUsers = 0;
	now++;

	if (firstTick) {
		interrupt = extractMinHeap();
		firstTick = false;
	}

	while (now == interrupt.nextTick) {
		if (data[interrupt.index].isLoggedIn && (now == data[interrupt.index].nextTick)) timedOutUsers++;

		interrupt = extractMinHeap();
	}
	
	return timedOutUsers;
}