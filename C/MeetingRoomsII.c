/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
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

int minMeetingRooms(struct Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 0) {
        return 0;
    }
    sort(intervals, 0, intervalsSize - 1);
    int* ended = (int*) malloc (sizeof(int) * intervalsSize);
    ended[0] = intervals[0].end;
    int count = 1;
    for (int i = 1; i < intervalsSize; i++) {
        int j = 0;
        int located = 0;
        while (j < count && !located) {
            if (ended[j] > intervals[i].start) {
                j++;
            } else {
                located = 1;
                ended[j] = intervals[i].end;
            }
        }
        if (j == count) {
            count++;
            ended[j] = intervals[i].end;
        }
    }
    return count;
}
