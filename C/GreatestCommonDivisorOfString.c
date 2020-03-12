int gcd(int num1, int num2) {
    int mod = num1 % num2;
    if (mod == 0) {
        return num2;
    } else {
        return gcd(num2, mod);
    }
}

char * gcdOfStrings(char * str1, char * str2){
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	if (length1 * length2 == 0) {
		return "";
	}
	int totalLength = length1 + length2;
	char *total1 = (char *)malloc(sizeof(char) * (totalLength + 1));
	char *total2 = (char *)malloc(sizeof(char) * (totalLength + 1));
	strcpy(total1, str1);
	strcat(total1, str2);
	total1[totalLength] = '\0';
	strcpy(total2, str2);
	strcat(total2, str1);
	total2[totalLength] = '\0';
	if (strcmp(total1, total2) != 0) {
		return "";
	}
	int length = gcd(length1, length2);
	char *ret = (char *)malloc(sizeof(char) * (length + 1));
	strncpy(ret, str1, length);
	ret[length] = '\0';
	return ret;
}