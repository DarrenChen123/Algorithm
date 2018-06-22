/*
  灰度图片旋转90度。
*/

char* rotateImage(char* input, int width, int height) {
    char * output = (char *) malloc(sizeof(char) * (width * height));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            output[i * height + j] = input[j * width + (height - 1  - i)];
        }
    }
    return output;
}

// Easy Collection
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    for (int i = 0; i< matrixRowSize / 2; i++) {
        for (int j = i; j < matrixRowSize - 1 - i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize - j - 1][i];
            matrix[matrixRowSize - j - 1][i] = matrix[matrixRowSize - i - 1][matrixRowSize - j - 1];
            matrix[matrixRowSize - i - 1][matrixRowSize - j - 1] = matrix[j][matrixRowSize - i - 1];
            matrix[j][matrixRowSize - i - 1] = temp;
        }
    }
}
