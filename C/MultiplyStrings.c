// Yelp
// Facebook
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

char * multiply(char * num1, char * num2){
	int length1 = strlen(num1);
	int length2 = strlen(num2);
	int lengthRes = length1 + length2;
	
	int charIndex = 0;
	int valueIndex = 0;
	
	int *value = (int*)malloc(sizeof(int) * lengthRes);
	memset(value, 0, sizeof(int) * lengthRes);
	
	char *ret = (char*)malloc(sizeof(char) * (lengthRes + 1));
	memset(ret, 0, sizeof(char) * lengthRes);
	int carry = 0;
	for (int i = length1 - 1;i >= 0;i--) {
		for (int j = length2 - 1;j >= 0;j--) {
			value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
		}
	}
	
	for (int i = lengthRes - 1;i > 0;i--) {
		value[i - 1] += value[i] / 10;
		value[i] %= 10;
	}
	
	while (value[valueIndex] == 0 && valueIndex < lengthRes - 1) {
		valueIndex++;
	}
	while (valueIndex < lengthRes) {
		ret[charIndex++] = value[valueIndex++] + '0';
	}
	ret[charIndex] = '\0';
	return ret;
}