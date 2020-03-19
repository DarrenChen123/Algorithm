/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	*returnSize = k;
	int *ret = (int *)malloc(sizeof(int) * (*returnSize));
	int *hash = (int *)malloc(sizeof(int) * 10001);
	memset(ret, 0, sizeof(int) * (*returnSize));
	memset(hash, 0, sizeof(int) * 10001);
	for (int i = 0; i < arrSize; i++) {
		hash[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < 10001 && index < k; i++) {
		if (hash[i] > 0) {
			for (int j = 0; j < hash[i] && index < k; j++) {
				ret[index++] = i;
			}
		}
	}
	free(hash);
	return ret;
}