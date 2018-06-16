/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

int leastInterval(char* tasks, int tasksSize, int n) {
   int* map = (int*) malloc (sizeof(int) * 26);
    memset(map, 0, sizeof(int) * 26);
    for (int i = 0; i < tasksSize; i++) {
        map[tasks[i] - 'A']++;
    }
    char key = 'A';
    int count = map[0];
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (map[i] > count) {
            key = 'A' + i;
            count = map[i];
            maxCount = 1;
        } else if (map[i] == count) {
            maxCount++;
        }
    }
    int partCount = count - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int taskLeft = tasksSize - count * maxCount;
    int idles = emptySlots - taskLeft > 0 ? emptySlots - taskLeft : 0;

    return tasksSize + idles;
}
