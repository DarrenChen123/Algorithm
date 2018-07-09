// Medium Collection
// Amazon
// Microsoft
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* digitToCharArr(char digit) {
    switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
    }
}

void combine(char* digits, int from, int to, char* result, char** combinations, int* index) {
	if (from <= to) {
	  char *letters = digitToCharArr(digits[from]);
    int length = strlen(letters);
		for (int i = 0; i < length; i++) {
			result[from] = letters[i];
			combine(digits, from + 1, to, result, combinations, index);
		}
	} else {
		result[from] = '\0';
		combinations[*index] = (char *)malloc(sizeof(strlen(result)));
		strcpy(combinations[*index], result);
		(*index)++;
	}
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int length = strlen(digits);
    if (length == 0) {
        return "";
    }
    *returnSize = 1;
    for (int i = 0; i < length; i++) {
        *returnSize *= strlen(digitToCharArr(digits[i]));
    }
    char** ret = (char**) malloc (sizeof(char *) * *returnSize);
    char* resultStr = (char *)malloc(sizeof(length + 1));
    int* index = (int *)malloc(sizeof(int));
    *index = 0;
    combine (digits, 0, length - 1, resultStr, ret, index);
    return ret;
}
