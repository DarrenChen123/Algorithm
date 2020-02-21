// Facebook
// Array and String
/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

char * addBinary(char * a, char * b){
	int lengthA = strlen(a);
	int lengthB = strlen(b);
	int length = lengthA > lengthB ? lengthA : lengthB;
	char *ret = (char *)malloc(sizeof(char) * (length + 2));
	int carry = 0, i = 0, k = 0;
	while (i < lengthA && i < lengthB) {
		int numA = a[lengthA - 1 - i] - '0';
		int numB = b[lengthB - 1 - i] - '0';
		int num = (numA ^ numB) ^ carry;
		ret[k++] = num + '0';
		carry = (numA & numB) || (numA & carry) || (numB & carry);
		i++;
	}
	while (i < lengthA) {
		int numA = a[lengthA - 1 - i] - '0';
		int num = numA ^ carry;
		ret[k++] = num + '0';
		carry = (numA & carry);
		i++;
	}
	while (i < lengthB) {
		int numB = b[lengthB - 1 - i] - '0';
		int num = numB ^ carry;
		ret[k++] = num + '0';
		carry = (numB & carry);
		i++;
	}
	if (carry) {
		ret[k++] = '1';
	}
	for (int j = 0;j < k / 2;j++) {
		char t = ret[j];
		ret[j] = ret[k - j - 1];
		ret[k - j - 1] = t;
	}
	ret[k] = '\0';
	return ret;
}
