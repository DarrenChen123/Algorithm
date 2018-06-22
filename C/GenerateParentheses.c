// Medium Collection
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void generate(char** parenthesis, int* returnSize, char* result, int left, int right, int index) {
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        result[index] = '\0';
        parenthesis[*returnSize] = (char *)malloc(sizeof(strlen(result)));
        strcpy(parenthesis[*returnSize], result);
        (*returnSize)++;
    }
    if (left == right) {
        result[index] = '(';
        generate(parenthesis, returnSize, result, left - 1, right, index + 1);
    }
    if (left < right && left == 0) {
        result[index] = ')';
        generate(parenthesis, returnSize, result, left, right - 1, index + 1);
    }
    if (left < right && left > 0) {
        result[index] = '(';
        generate(parenthesis, returnSize, result, left - 1, right, index + 1);
        result[index] = ')';
        generate(parenthesis, returnSize, result, left, right - 1, index + 1);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** ret = (char**) malloc (sizeof(char*) * 10000);
    char* resultStr = (char *) malloc (sizeof(2 * n + 1));
    *returnSize = 0;
    generate(ret, returnSize, resultStr, n, n, 0);
    return ret;
}
