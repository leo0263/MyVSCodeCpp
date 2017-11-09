#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS    // Ignore build errors when using unsafe functions in Visual Studio.
#endif

#include <stdio.h>

typedef enum{
	CMD_INIT,
	CMD_ADD,
	CMD_MODIFY,
	CMD_DELETE,
	CMD_SEARCH
} COMMAND;

typedef enum{
	SEARCH_TYPE_TITLE,
	SEARCH_TYPE_LOCATION,
	SEARCH_TYPE_DATE
} SEARCH_TYPE;

typedef struct{
	int count;
	int id_list[10000];
} RESULT;

extern void Init();
extern void Add(int id, char* title, char* location, char* start_date, char* end_date);
extern int Modify(int id, char* title, char* location, char* start_date, char* end_date);
extern int Delete(int id);
extern RESULT Search(SEARCH_TYPE type, char* str);

static int Score, ScoreIdx;
static bool isDebug = true;

static void cmd_init(){
	Score = 1000;
	scanf("%d", &ScoreIdx);
	Init();
}

static void cmd_add(){
	int newid;
	char newTitle[20], newLocation[20], newStartDate[13], newEndDate[13];
	scanf("%d %s %s %s %s", &newid, newTitle, newLocation, newStartDate, newEndDate);
	Add(newid, newTitle, newLocation, newStartDate, newEndDate);
}

static void cmd_modify(){
	int modifyid, check, result;
	char newTitle[20], newLocation[20], newStartDate[13], newEndDate[13];
	scanf("%d %s %s %s %s %d", &modifyid, newTitle, newLocation, newStartDate, newEndDate, &check);

	result = Modify(modifyid, newTitle, newLocation, newStartDate, newEndDate);
	if (result != check) {
		Score -= ScoreIdx;
		if (isDebug)
			printf("error MODIFY : %d %s %s %s %s %d\n", modifyid, newTitle, newLocation, newStartDate, newEndDate, check);
	}
}

static void cmd_delete(){
	int modifyid, check, result;
	scanf("%d %d", &modifyid, &check);

	result = Delete(modifyid);
	if (result != check) {
		Score -= ScoreIdx;
		if (isDebug)
			printf("error DELETE : %d %d\n", modifyid, check);
	}
}

static void cmd_search(){
	int searchType, checkCnt, check;
	char str[20];
	scanf("%d %s %d %d", &searchType, str, &checkCnt, &check);

	RESULT result = Search((SEARCH_TYPE)searchType, str);

	if (result.count != checkCnt) {
		Score -= ScoreIdx;
		if (isDebug)
			printf("error SEARCH CNT :%d %s %d %d\n", searchType, str, checkCnt, check);
	}
	else{
		int checkSum = 0;
		for (int i = 0; i < result.count; ++i)
			checkSum += result.id_list[i];
		if (checkSum != check) {
			Score -= ScoreIdx;
			if (isDebug)
				printf("error SEARCH CHK :%d %s %d %d\n", searchType, str, checkCnt, check);
		}
	}
}

static void run(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int cmd;
		scanf("%d", &cmd);
		switch (cmd){
		case CMD_INIT:   cmd_init();   break;
		case CMD_ADD:    cmd_add();    break;
		case CMD_MODIFY: cmd_modify(); break;
		case CMD_DELETE: cmd_delete(); break;
		case CMD_SEARCH: cmd_search(); break;
		default: break;
		}
	}
}

int main(){
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	int TotalScore = 0;
	for (int tc = 1; tc <= T; tc++){
		run();
		if (Score < 0)	Score = 0;

		TotalScore += Score;
		printf("#%d %d\n", tc, Score);
	}
	printf("Total Score = %d\n", TotalScore);

	return 0;
}

// ----------------------------


//typedef enum{
//	SEARCH_TYPE_TITLE,
//	SEARCH_TYPE_LOCATION,
//	SEARCH_TYPE_DATE
//} SEARCH_TYPE;
//
//typedef struct{
//	int count;
//	int id_list[10000];
//} RESULT;

struct t_data {
	bool isDeleted;
	int id;
	char title[20];
	char location[20];
	char start_date[20];
	char end_date[20];
	int startDate;
	int startTime;
	int stopDate;
	int stopTime;
};

t_data data[10001];
int maxData;

void purgeData() {
	maxData = 0;
	for (int i = 0; i < 10001; i++) data[i].isDeleted = true;
}

void stringCopy(char* toStr, char* fromStr, int length) {
	for (int i = 0; i < length; i++) {
		//if (fromStr[i] == '\0') {
		//	toStr[i] = '\0';
		//	break;
		//} else 
		toStr[i] = fromStr[i];
	}
	toStr[length] = '\0';
}

int power[13] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000 };

int toInt(char* str, int start, int length) {
	int total = 0;
	int pow = 1;

	for (int i = (length + start) - 1; i >= start; i--) {
		total += (str[i] - 48) * (power[pow]);
		pow++;
	}

	return total;
}

int charsLength(char* str) {
	int length = 0;
	while (str[length] != '\0') length++;
	return length;
}

int stringCompare(char* str1, char* str2) {
	bool isSame = true;
	bool EOS = false;
	int i = 0;

	while (!EOS && isSame) {
		if (str1[i] != str2[i])  isSame = false;
		if (str1[i] == '\0') EOS = true;
		if (str2[i] == '\0') EOS = true;
		i++;
	}

	if (EOS && isSame) return 0;
	else if (!EOS && !isSame) {
		if (str1 > str2) return 1;
		else return -1;
	}
	else {
		int lStr1 = charsLength(str1);
		int lStr2 = charsLength(str2);
		if (lStr1 > lStr2) return 1;
		else return -1;
	}
}

void Init(){
	purgeData();
}

RESULT result;

void Add(int id, char* title, char* location, char* start_date, char* end_date){
	if (id > maxData) maxData = id;

	data[id].id = id;
	data[id].isDeleted = false;

	stringCopy(data[id].title, title, 19);
	stringCopy(data[id].location, location, 19);
	stringCopy(data[id].start_date, start_date, 19);
	stringCopy(data[id].end_date, end_date, 19);

	//// convert date to int
	data[id].startDate = toInt(start_date, 0, 8);
	data[id].stopDate = toInt(end_date, 0, 8);
	data[id].startTime = toInt(start_date, 8, 4);
	data[id].stopTime = toInt(end_date, 8, 4);

	// check if this "add" intersect with other data
	result = Search(SEARCH_TYPE::SEARCH_TYPE_TITLE, title);
	if (result.count != 0) {
		for (int i = 0; i < result.count; i++) {
			int resultID = result.id_list[i];
			if ((id == resultID) || (data[resultID].isDeleted) || (stringCompare(data[resultID].location, location) < 0)) {
				result.id_list[i] = -1;
			}
		}
	}

	//int intersectData = 0;
	//for (int i = 0; i < result.count; i++) if (result.id_list[i] != -1) intersectData++;
	//printf("add is intersect with (%d) data\n ", intersectData);
	
	int startDate = data[id].startDate;
	int startTime = data[id].startTime;
	int stopDate = data[id].stopDate;
	int stopTime = data[id].stopTime;
	bool isRelated;

	do {
		isRelated = false;

		int relatedToID = -1;
		bool foundRelated = false;

		for (int i = 0; i < result.count; i++) {
			int resultID = result.id_list[i];

			if (foundRelated) continue;
			if (resultID == -1) continue;
			if (data[resultID].isDeleted) continue;


			//// test
			//printf("  isRelated : (%s vs %s) = %d\n ", data[id].start_date, data[resultID].start_date, stringCompare(data[id].start_date, data[resultID].start_date));
			//printf("    isRelated : (%s vs %s) = %d\n ", data[id].start_date, data[resultID].end_date, stringCompare(data[id].start_date, data[resultID].end_date));

			//if (((data[id].startDate >= data[resultID].startDate) && (data[id].startDate <= data[resultID].stopDate)) ||
			//	((data[id].stopDate >= data[resultID].startDate) && (data[id].stopDate <= data[resultID].stopDate))){
			//	
			//	int minDate = data[id].startDate;
			//	int minTime = data[id].startTime;
			//	int maxDate = data[id].stopDate;
			//	int maxTime = data[id].stopTime;

			//}

			if ((startDate == data[resultID].startDate) && (startTime >= data[resultID].startTime)) {
				foundRelated = true;
				relatedToID = resultID;
			}
			else if ((startDate == data[resultID].stopDate) && (startTime <= data[resultID].stopTime)) {
				foundRelated = true;
				relatedToID = resultID;
			}
			else if ((startDate > data[resultID].startDate) && (startDate < data[resultID].stopDate)) {
				foundRelated = true;
				relatedToID = resultID;
			} 
			else if ((stopDate == data[resultID].startDate) && (stopTime >= data[resultID].startTime)) {
				foundRelated = true;
				relatedToID = resultID;
			}
			else if ((stopDate == data[resultID].stopDate) && (stopTime <= data[resultID].stopTime)) {
				foundRelated = true;
				relatedToID = resultID;
			}
			else if ((stopDate > data[resultID].startDate) && (stopDate < data[resultID].stopDate)) {
				foundRelated = true;
				relatedToID = resultID;
			}
		}

		if (foundRelated) {
			isRelated = true;

			bool startDateSmallest;
			bool stopDateSmallest;

			if ((startDate == data[relatedToID].startDate) && (startTime >= data[relatedToID].startTime)) {
				startDateSmallest = false;
			}
			else if ((startDate == data[relatedToID].stopDate) && (startTime <= data[relatedToID].stopTime)) {
				startDateSmallest = true;
			}
			else if ((startDate > data[relatedToID].startDate) && (startDate < data[relatedToID].stopDate)) {
				startDateSmallest = false;
			}

			if ((stopDate == data[relatedToID].startDate) && (stopTime >= data[relatedToID].startTime)) {
				stopDateSmallest = false;
			}
			else if ((stopDate == data[relatedToID].stopDate) && (stopTime <= data[relatedToID].stopTime)) {
				stopDateSmallest = true;
			}
			else if ((stopDate > data[relatedToID].startDate) && (stopDate < data[relatedToID].stopDate)) {
				stopDateSmallest = false;
			}

			int smallestID = id;
			if (smallestID < relatedToID) {
				Delete(relatedToID);
			}
			else {
				Delete(smallestID);
				smallestID = relatedToID;
			}

			if ()
		}


	} while (isRelated);
	
	//// test 
	//printf("input : %d %s %s %s %s\n", id, title, location, start_date, end_date);
	//printf("saved : %d %s %s %s %s\n", data[id].id, data[id].title, data[id].location, data[id].start_date, data[id].end_date);
	////printf("cnvrt : start(%l:%d) stop(%l:%d)\n", data[id].startDate, data[id].startTime, data[id].stopDate, data[id].stopTime);

	
}

int Modify(int id, char* title, char* location, char* start_date, char* end_date){
	if (!data[id].isDeleted) {
		Add(id, title, location, start_date, end_date);



		return 0;
	} else return 1;
}

int Delete(int id){
	if (!data[id].isDeleted) {
		data[id].isDeleted = true;
		return 0;
	}
	else return 1;
}

RESULT Search(SEARCH_TYPE type, char* str){
	RESULT result;
	result.count = -1;

	int found = 0;

	switch (type) {
	case 0 :
		for (int i = 0; i < maxData+1; i++) {
			if (!data[i].isDeleted)
				if (stringCompare(data[i].title, str) == 0) {
					result.id_list[found] = i;
					found++;
				}
		}
		break;

	case 1:
		for (int i = 0; i < maxData+1; i++) {
			if (!data[i].isDeleted)
				if (stringCompare(data[i].location, str) == 0) {
					result.id_list[found] = i;
					found++;
				}
		}
		break;

	case 2:
		int searchDate = toInt(str, 0, 8);
		for (int i = 0; i < maxData+1; i++) {
			if (!data[i].isDeleted) {		
				if ((searchDate >= data[i].startDate) && (searchDate <= data[i].stopDate)) {
					result.id_list[found] = i;
					found++;
				}
				//printf("mySearch DATE : (%d) vs (%d - %d) -> %d\n", searchDate, data[i].startDate, data[i].stopDate, found);
			}
		}
		break;
	}

	result.count = found;

	/*printf("mySearch : (%s) -> %d\n", str, found);*/

	return result;
}

