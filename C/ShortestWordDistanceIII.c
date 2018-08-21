// Subscription
// 245. Shortest Word Distance III
/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
*/

int shortestWordDistance(char** words, int wordsSize, char* word1, char* word2) {
    int position1 = -1;
    int position2 = -1;
    int ret = INT_MAX;
    for (int i = 0; i < wordsSize; i++) {
        int temp = position1;
        if (strcmp(words[i], word1) == 0) {
            position1 = i;
        }
        if (strcmp(words[i], word2) == 0) {
            position2 = i;
        }
        if (position1 != -1 && position2 != -1) {
            if (strcmp(word1, word2) == 0 && temp != -1 && temp != position1) {
                int distance = abs(temp - position1);
                ret = ret < distance ? ret : distance;
            } else if (position1 != position2) {
                int distance = abs(position1 - position2);
                ret = ret < distance ? ret : distance;
            }
        }
    }
    return ret;
}
