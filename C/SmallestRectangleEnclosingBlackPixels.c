// Subscription
// 302. Smallest Rectangle Enclosing Black Pixels
/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example:

Input:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2

Output: 6

*/

int binary_search(char** image, bool h, int i, int j, int low, int high, bool opt) {
    while (i < j) {
        int k = low;
        int mid = (i + j) / 2;
        while (k < high && (h ? image[mid][k] : image[k][mid]) == '0') {
            k++;
        }
        if (k < high == opt) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return i;
}
int minArea(char** image, int imageRowSize, int imageColSize, int x, int y) {
    int m = imageRowSize;
    int n = imageColSize;
    int up = binary_search(image, true, 0, x, 0, n, true);
    int down = binary_search(image, true, x + 1, m, 0, n, false);
    int left = binary_search(image, false, 0, y, up, down, true);
    int right = binary_search(image, false, y + 1, n, up, down, false);
    return (right - left) * (down - up);
}
