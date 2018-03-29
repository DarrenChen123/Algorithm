/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

//1
void merge(int* nums1, int m, int* nums2, int n) {
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }
    if (n == 0) {
        return;
    }
    int* ret = (int *)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, index = 0;
    while(i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            ret[index++] = nums1[i++];
        } else {
            ret[index++] = nums2[j++];
        }
    }
    if (i == m) {
        while(j < n) {
            ret[index++] = nums2[j++];
        }
    }
    if (j == n) {
        while(i < m) {
            ret[index++] = nums1[i++];
        }
    }
    for (i = 0; i < m + n; i++) {
        nums1[i] = ret[i];
    }
    nums1 = ret;
}

//2
void merge(int* nums1, int m, int* nums2, int n) {
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }
    if (n == 0) {
        return;
    }
    for (int i = 0; i < m; i++) {
        if (nums1[i] > nums2[0]) {
            nums1[i] = nums1[i] ^ nums2[0];
            nums2[0] = nums1[i] ^ nums2[0];
            nums1[i] = nums1[i] ^ nums2[0];
            for (int j = 0; j < n - 1; j++) {
                if (nums2[j] > nums2[j + 1]) {
                    nums2[j] = nums2[j] ^ nums2[j + 1];
                    nums2[j + 1] = nums2[j] ^ nums2[j + 1];
                    nums2[j] = nums2[j] ^ nums2[j + 1];
                } else {
                    break;
                }
            }
        }
    }
    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }
}
