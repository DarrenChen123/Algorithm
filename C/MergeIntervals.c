// Medium Collection
// Yelp
// Facebook
// Google
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
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

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    *returnSize = 0;
    if (intervalsSize <= 0) {
        return intervals;
    }
    sort(intervals, 0, intervalsSize - 1);
    struct Interval* ret = (struct Interval*) malloc (sizeof(struct Interval) * intervalsSize);
    ret[(*returnSize)++] = intervals[0];
    for (int i = 0;  i < intervalsSize; i++) {
        if (ret[*returnSize - 1].end >= intervals[i].end) {
            continue;
        } else if (ret[*returnSize - 1].end >= intervals[i].start) {
            ret[*returnSize - 1].end = intervals[i].end;
        } else {
            ret[(*returnSize)++] = intervals[i];
        }
    }
    return ret;
}
