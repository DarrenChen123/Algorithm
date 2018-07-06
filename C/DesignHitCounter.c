// Subscription
// Amazon
/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/

typedef struct {
    int* times;
    int* hits;
} HitCounter;

/** Initialize your data structure here. */
HitCounter* hitCounterCreate() {
    HitCounter* counter = (HitCounter*) malloc (sizeof(HitCounter));
    counter->times = (int*) malloc (sizeof(int) * 300);
    memset(counter->times, 0, sizeof(int) * 300);
    counter->hits = (int*) malloc (sizeof(int) * 300);
    memset(counter->hits, 0, sizeof(int) * 300);
    return counter;
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
    int time = timestamp % 300;
    if (obj->times[time] == timestamp) {
        obj->hits[time]++;
    } else {
        obj->hits[time] = 1;
        obj->times[time] = timestamp;
    }
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {
    int hits = 0;
    for (int i = 0; i < 300; i++) {
        if (timestamp - obj->times[i] < 300) {
            hits += obj->hits[i];
        }
    }
    return hits;
}

void hitCounterFree(HitCounter* obj) {
    free(obj->times);
    free(obj->hits);
    free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * struct HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 * int param_2 = hitCounterGetHits(obj, timestamp);
 * hitCounterFree(obj);
 */
