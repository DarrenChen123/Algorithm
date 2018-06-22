// Weekly Contest 84
/*
To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the original S, so we do nothing.
Notes:

0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
All characters in given inputs are lowercase letters.
*/

void sort(int* nums, char** sources, char** targets, int left, int right) {
	int i, j, key;
    char* keySource, *keyTarget;
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	key = nums[left];
    keySource = sources[left];
    keyTarget = targets[left];

	while (i < j) {
		while (nums[j] >= key && i < j) {
			j--;
		}
		nums[i] = nums[j];
        sources[i] = sources[j];
        targets[i] = targets[j];
		while (nums[i] <= key && i < j) {
			i++;
		}
		nums[j] = nums[i];
        sources[j] = sources[i];
        targets[j] = targets[i];
	}

	nums[i] = key;
	sources[i] = keySource;
    targets[i] = keyTarget;

	sort(nums, sources, targets, left, i - 1);
	sort(nums, sources, targets,  i + 1, right);
}

char* findReplaceString(char* S, int* indexes, int indexesSize, char** sources, int sourcesSize, char** targets, int targetsSize) {
    int length = strlen(S);
    char* ret = malloc (sizeof(char) * 2 * length);
    int retIndex = 0;
    int current = 0;
    sort(indexes, sources, targets, 0, indexesSize - 1);
    for (int i = 0; i < length; i++) {
        if (i != indexes[current]) {
            ret[retIndex++] = S[i];
        } else {
            int sourceLeng = strlen(sources[current]);
            int targetLeng = strlen(targets[current]);
            if (strncmp(S + i, sources[current], sourceLeng) != 0) {
                ret[retIndex++] = S[i];
                current++;
            } else {
                if (strncmp(S + i, sources[current], sourceLeng) == 0) {
                    strncpy(ret + retIndex, targets[current], targetLeng);
                    i += sourceLeng - 1;
                    retIndex += targetLeng;
                    current++;
                }
            }
        }
    }
    ret[retIndex] = '\0';
    return ret;
}
