/*
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 

Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.
*/

typedef struct trie {
	bool hasVisited;
	bool hasChildren;
	struct trie* children[26];
} Trie;

Trie* trieCreate()
{
	Trie *root;
	root = (Trie *)malloc(sizeof(Trie));
	memset(root, 0, sizeof(*root));
	root->hasVisited = false;
	root->hasChildren = false;
	return root;
}

void trieInsert(Trie* obj, char* word)
{
	int length = strlen(word);
	
	for (int i = length - 1; i >= 0; i--) {
		char c = word[i];
		if (obj->children[c - 'a'] == NULL) {
			obj->children[c - 'a'] = trieCreate();
			obj->hasChildren = true;
		}
		obj = obj->children[c - 'a'];
	}
}

void trieFree(Trie* obj)
{
	if (!obj) {
		return;
	}
	for (int i = 0; i < 26; i++){
		if (obj->children[i]){
			trieFree(obj->children[i]);
		}
	}
	free(obj);
}

void dfs(Trie* trie, int level, int *count) {
	if (!trie) {
		return;
	}
	
	Trie* ptr = trie;

	if (!trie->hasChildren) {
		*count += (level + 1);
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (trie->children[i]) {
			dfs(trie->children[i], level + 1, count);
		}
	}
}

int minimumLengthEncoding(char ** words, int wordsSize){
	if (!words || wordsSize <= 0) {
		return 0;
	}

	Trie* trie = trieCreate();

	for (int i = 0; i < wordsSize; i++) {
		trieInsert(trie, words[i]);
	}

	int count = 0;
	dfs(trie, 0, &count);
	trieFree(trie);

	return count;
}