// Weekly Contest 96
/*
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)



Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/

void sort(int* nums, int left, int right) {
	int i, j, key;
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	key = nums[left];

	while (i < j) {
		while (nums[j] >= key && i < j) {
			j--;
		}
		nums[i] = nums[j];
		while (nums[i] <= key && i < j) {
			i++;
		}
		nums[j] = nums[i];
	}

	nums[i] = key;

	sort(nums, left, i - 1);
	sort(nums, i + 1, right);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    int* rescued = (int*) malloc (sizeof(int) * peopleSize);
    memset(rescued, 0, sizeof(int) * peopleSize);
    sort(people, 0, peopleSize - 1);
    int ret = 0;
    int minIndex = 0;
    for (int i = peopleSize - 1; i >= 0; i--) {
        if (rescued[i]) {
            continue;
        }
        rescued[i] = 1;
        ret++;
        int available = limit - people[i];
        for (int j = minIndex; j <= i; j++) {
            if (people[j] > available) {
                break;
            }
            if (rescued[j]) {
                continue;
            }
            rescued[j] = 1;
            available -= people[j];
            if (minIndex < i) {
                minIndex = j + 1;
            } else {
                return ret;
            }
            break;
        }
    }
    return ret;
}
