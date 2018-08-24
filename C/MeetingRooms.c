// Subscription
// 252. Meeting Rooms
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
int compare(struct Interval intervalA, struct Interval intervalB) {
    if (intervalA.start > intervalB.start || (intervalA.start == intervalB.start && intervalA.end > intervalB.end)) {
        return 1;
    }
    if (intervalA.start < intervalB.start || (intervalA.start == intervalB.start && intervalA.end < intervalB.end)) {
        return -1;
    } else {
        return 0;
    }
}

void sort(struct Interval* intervals, int left, int right) {
    int i, j;
    struct Interval key;
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	key = intervals[left];

	while (i < j) {
		while (compare(intervals[j], key) >= 0 && i < j) {
			j--;
		}
		intervals[i] = intervals[j];
		while (compare(intervals[i], key) <= 0 && i < j) {
			i++;
		}
		intervals[j] = intervals[i];
	}

	intervals[i] = key;

	sort(intervals, left, i - 1);
	sort(intervals, i + 1, right);
}

bool canAttendMeetings(struct Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 0) {
        return true;
    }
    sort(intervals, 0, intervalsSize - 1);
    for (int i = 0; i < intervalsSize - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return false;
        }
    }
    return true;
}
