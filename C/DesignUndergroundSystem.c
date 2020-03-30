/*
Implement the class UndergroundSystem that supports three methods:

1. checkIn(int id, string stationName, int t)

A customer with id card equal to id, gets in the station stationName at time t.
A customer can only be checked into one place at a time.
2. checkOut(int id, string stationName, int t)

A customer with id card equal to id, gets out from the station stationName at time t.
3. getAverageTime(string startStation, string endStation) 

Returns the average time to travel between the startStation and the endStation.
The average time is computed from all the previous traveling from startStation to endStation that happened directly.
Call to getAverageTime is always valid.
You can assume all calls to checkIn and checkOut methods are consistent. That is, if a customer gets in at time t1 at some station, then it gets out at time t2 with t2 > t1. All events happen in chronological order.

 

Example 1:

Input
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Output
[null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.0. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.0
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 12.0
 

Constraints:

There will be at most 20000 operations.
1 <= id, t <= 10^6
All strings consist of uppercase, lowercase English letters and digits.
1 <= stationName.length <= 10
Answers within 10^-5 of the actual value will be accepted as correct.
*/

typedef struct {
	int id;
	int startTime;
	int endTime;
	char *startStation;
	char *endStation;
} Guest;

typedef struct List {
	Guest* val;
	struct List *next;
} List;

typedef struct {
	List *completeGuestsList;
	List *uncompleteGuestsList;
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
	UndergroundSystem *system = (UndergroundSystem*) malloc(sizeof(UndergroundSystem));
	system->completeGuestsList = NULL;
	system->uncompleteGuestsList = NULL;
	return system;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
	Guest *guest = (Guest *)malloc(sizeof(Guest));
	guest->id = id;
	guest->startTime = t;
	guest->endTime = -1;
	guest->startStation = stationName;
	List *node = (List *)malloc(sizeof(List));
	node->val = guest;
	node->next = NULL;
	if (obj->uncompleteGuestsList) {
		List *temp = obj->uncompleteGuestsList;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = node;
	} else {
		obj->uncompleteGuestsList = node;
	}
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
	List *temp = obj->uncompleteGuestsList;
	if (temp->val->id == id) {
		Guest *guest = temp->val;
		obj->uncompleteGuestsList = obj->uncompleteGuestsList->next;
		temp->next = NULL;
		guest->endTime = t;
		guest->endStation = stationName;
		if (obj->completeGuestsList) {
			List *curTemp = obj->completeGuestsList;
			while (curTemp->next) {
				curTemp = curTemp->next;
			}
			curTemp->next = temp;
		} else {
			obj->completeGuestsList = temp;
		}
	} else {
		while (temp && temp->next) {
			if (temp->next->val->id == id) {
				Guest *guest = temp->next->val;
				List *current = temp->next;
				temp->next = temp->next->next;
				current->next = NULL;
				guest->endTime = t;
				guest->endStation = stationName;
				if (obj->completeGuestsList) {
					List *curTemp = obj->completeGuestsList;
					while (curTemp->next) {
						curTemp = curTemp->next;
					}
					curTemp->next = current;
				} else {
					obj->completeGuestsList = current;
				}
			}
			temp = temp->next;
		}
	}
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
	List *temp = obj->completeGuestsList;
	double total = 0;
	int count = 0;
	while (temp) {
		if (strcmp(startStation, temp->val->startStation) == 0 && strcmp(endStation, temp->val->endStation) == 0) {
			total += (temp->val->endTime - temp->val->startTime);
			count++;
		}
		temp= temp->next;
	}
	if (count > 0) {
		return total / count;
	} else {
		return -1;
	}
}

void undergroundSystemFree(UndergroundSystem* obj) {
	while (obj->uncompleteGuestsList) {
		List *temp = obj->uncompleteGuestsList;
		obj->uncompleteGuestsList = obj->uncompleteGuestsList->next;
		free(temp);
	}
	while (obj->completeGuestsList) {
		List *temp = obj->completeGuestsList;
		obj->completeGuestsList = obj->completeGuestsList->next;
		free(temp);
	}
	free(obj);
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);
 
 * undergroundSystemCheckOut(obj, id, stationName, t);
 
 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);
 
 * undergroundSystemFree(obj);
*/