// Subscription
// Google
/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/

char* addBoldTag(char* S, char** words, int wordsSize) {
	char *res;

	int len = strlen(S);
	int *bold = (int *)calloc(len,sizeof(int));

	for (int i = 0; i<wordsSize; i++)
	{
		char *tmp = strstr(S, words[i]);
		if (tmp != NULL)
		{
			int ind = tmp-S;

			int tmp_len = strlen(words[i]);
			while (ind<len && ind >= 0)
			{

				for (int j = ind; j < ind + tmp_len; j++)
				{
					bold[j] = 1;
				}
				tmp = strstr(&S[ind + 1], words[i]);
                if(tmp!=NULL)
				    ind =  tmp-S;
                else
                    break;
			}
		}
	}
	int pre = 0;

	res = (char *)calloc(1,sizeof(char));
	int size = 1;
	for (int i = 0; i<len; i++)
	{

		if (bold[i] && !pre)
		{
			res = realloc(res, size +  3);
			size += 3;
			strcat(res, "<b>");
			pre = 1;
		}
		else if (!bold[i] && pre)
		{
			res = realloc(res, size +  4);
			size += 4;
			strcat(res, "</b>");
			pre = 0;
		}
		res = realloc(res, size + 1);
		res[size - 1] = S[i];
		res[size] = '\0';
		size += 1;
	}

	if (pre)
	{
		res = realloc(res, size +  4);
		size += 4;
		strcat(res, "</b>");
	}
	res[size-1] = '\0';
    free(bold);
    return res;
}
