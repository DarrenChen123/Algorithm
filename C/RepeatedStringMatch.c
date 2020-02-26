// Google
/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

int repeatedStringMatch(char * A, char * B){
	char *buf = NULL;
	char *start = NULL;
	int aLen, bLen;
	int cnt = 1;
	int i;
	aLen = strlen(A);
	bLen = strlen(B);
	start = strstr(A, B);
	if (start != NULL) {
		return cnt;
	}
	do {
		cnt++;
	} while (aLen * cnt < bLen);
	
	buf = (char*)calloc((cnt + 1) * aLen + 1, sizeof(char));
	if (buf == NULL) {
		return -1;
	}
	for (i = 0; i < cnt; i++) {
		memcpy(&buf[i * aLen], A, aLen);
	}
	
	start = strstr(buf, B);
	if (start != NULL) {
		return cnt;
	}
	memcpy(&buf[cnt * aLen], A, aLen);
	start = strstr(buf, B);
	free(buf);
	return start == NULL ? -1 : cnt + 1;
}