/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Notes:

Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.
*/

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    int overlap[4];
    overlap[0] = rec1[0] > rec2[0] ? rec1[0] : rec2[0];
    overlap[1] = rec1[1] > rec2[1] ? rec1[1] : rec2[1];
    overlap[2] = rec1[2] < rec2[2] ? rec1[2] : rec2[2];
    overlap[3] = rec1[3] < rec2[3] ? rec1[3] : rec2[3];
    return overlap[0] < overlap[2] && overlap[1] < overlap[3];
}
