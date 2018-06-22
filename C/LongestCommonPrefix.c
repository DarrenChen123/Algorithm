// Easy Collection
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    int i = 0;
    char * ret = (char *) malloc (sizeof(char) * 1024);
    while (1) {
        for (int j = 0; j < strsSize - 1; j++) {
            if (strs[j][i] != strs[j + 1][i] || strs[j][i] == '\0') {
                ret[i] = '\0';
                return ret;
            }
        }
        ret[i] = strs[0][i];
        i++;
    }
    ret[i] = '\0';
    return ret;
}
