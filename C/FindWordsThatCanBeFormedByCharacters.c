int countCharacters(char ** words, int wordsSize, char * chars){
	int length = strlen(chars);
	if (length <= 0) {
		return 0;
	}
	int *characters = (int *)malloc(sizeof(int) * 26);
	memset(characters, 0, sizeof(int) * 26);
	for (int i = 0; i < length; i++) {
		characters[chars[i] - 'a']++;
	}
	int ret = 0;
	for (int i = 0; i < wordsSize; i++) {
		int curLength = strlen(words[i]);
		int canCount = true;
		int *curCharacters = (int *)malloc(sizeof(int) * 26);
		memcpy(curCharacters, characters, sizeof(int) * 26);
		for (int j = 0; j < curLength; j++) {
			curCharacters[words[i][j] - 'a']--;
			if (curCharacters[words[i][j] - 'a'] < 0) {
				canCount = false;
				break;
			}
		}
		if (canCount) {
			ret += curLength;
		}
		free(curCharacters);
	}
	free(characters);
	return ret;
}