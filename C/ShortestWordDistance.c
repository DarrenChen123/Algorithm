// Subscription
// LinkedIn
/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

int shortestDistance(char** words, int wordsSize, char* word1, char* word2) {
    int position1 = -1;
    int position2 = -1;
    int ret = INT_MAX;
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word1) == 0) {
            position1 = i;
        }
        if (strcmp(words[i], word2) == 0) {
            position2 = i;
        }
        if (position1 != -1 && position2 != -1) {
            int distance = abs(position1 - position2);
            ret = ret < distance ? ret : distance;
        }
    }
    return ret;
}
