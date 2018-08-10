// Easy Collection
// Amazon
// Microsoft
// LinkedIn
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// DP:
int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        max = max > sum ? max : sum;
        if (sum < 0) {
            sum = 0;
        }
    }
    return max;
}

// Divide and Conquer
int divide(int* nums, int left, int right, int tmax) {
    if (left > right) {
        return INT_MIN;
    }
    int mid = left + (right - left) / 2;
    int lmax = divide(nums, left, mid - 1, tmax);
    int rmax = divide(nums, mid + 1, right, tmax);

    tmax = tmax > lmax ? tmax : lmax;
    tmax = tmax > rmax ? tmax : rmax;

    int sum = 0;
    int mlmax = 0;
    for (int i = mid - 1; i >= left; i--) {
        sum += nums[i];
        mlmax = mlmax > sum ? mlmax : sum;
    }

    sum = 0;
    int mrmax = 0;

    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        mrmax = mrmax > sum ? mrmax : sum;
    }

    tmax = tmax > (nums[mid] + mlmax + mrmax) ? tmax : (nums[mid] + mlmax + mrmax);
    return tmax;
}

int maxSubArray(int* nums, int numsSize) {
    return divide(nums, 0, numsSize - 1, INT_MIN);
}
