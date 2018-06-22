// Medium Collection
/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

int getSum(int a, int b) {
    int ret = 0;
    int temp = 0;
    int current = 0;
    for (int i = 0; i < 32; i++) {
        current = (a ^ b) >> i & 1;
        ret |= ((temp ^ current) << i);
        if ((current == 0 && (((a & (1 << i)) >> i) == 1)) || (current == 1 && temp == 1)) {
            temp = 1;
        } else {
            temp = 0;
        }
    }
    return ret;
}
