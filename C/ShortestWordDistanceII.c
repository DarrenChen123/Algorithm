// Subscription
// LinkedIn
/*
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

typedef struct {
    char** words;
    int wordsSize;
} WordDistance;

WordDistance* wordDistanceCreate(char** words, int wordsSize) {
    WordDistance* obj = (WordDistance*) malloc (sizeof(WordDistance));
    obj->words = words;
    obj->wordsSize = wordsSize;
    return obj;
}

int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    int position1 = -1;
    int position2 = -1;
    int ret = INT_MAX;
    for (int i = 0; i < obj->wordsSize; i++) {
        if (strcmp(obj->words[i], word1) == 0) {
            position1 = i;
        }
        if (strcmp(obj->words[i], word2) == 0) {
            position2 = i;
        }
        if (position1 != -1 && position2 != -1) {
            int distance = abs(position1 - position2);
            ret = ret < distance ? ret : distance;
        }
    }
    return ret;
}

void wordDistanceFree(WordDistance* obj) {
    free(obj);
}

/**
 * Your WordDistance struct will be instantiated and called as such:
 * struct WordDistance* obj = wordDistanceCreate(words, wordsSize);
 * int param_1 = wordDistanceShortest(obj, word1, word2);
 * wordDistanceFree(obj);
 */
