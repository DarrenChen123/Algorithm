// Subscription
// 296. Best Meeting Point
/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input:

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance
             of 2+2+2=6 is minimal. So return 6.
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


int minTotalDistance(int** grid, int gridRowSize, int gridColSize) {
    int* rows = (int*) malloc (sizeof(int) * gridRowSize * gridColSize);
    int rowCount = 0;
    int* cols = (int*) malloc (sizeof(int) * gridRowSize * gridColSize);
    int colCount = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                rows[rowCount++] = i;
                cols[colCount++] = j;
            }
        }
    }
    sort(cols, 0, colCount - 1);
    int res = 0;
    int i = 0;
    int j = rowCount - 1;
    while (i < j) {
        res += rows[j] - rows[i] + cols[j--] - cols[i++];
    }
    free(cols);
    free(rows);
    return res;
}
