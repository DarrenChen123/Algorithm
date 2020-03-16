char* compressString(char* S){

	int size = strlen(S);
	if (size <= 2) return S;
	char* str = (char*)malloc(sizeof(char) * (2 * size));
	str[0] = S[0];
	int count = 1, index = 1;
	for (int i = 1; i < size + 1; i++) {
		if (S[i] == S[i - 1]) {
			count++;
		}
		else {
			int num = (int)log10(count) + index;
			index = num;
			while (count) {
				str[num--] = count % 10 +'0';
				count /= 10;
			}
			str[++index] = S[i];
			count = 1;
			++index;
		}
	}
	if (index >= size + 1) return S;
	return str;
}