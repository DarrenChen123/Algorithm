/*
  灰度图片旋转90度。
*/

char* rotateImage(char* input, int width, int height) {
    char * output = (char *) malloc(sizeof(char) * (width * height));
    for (int i = 0; i < width * height; i++) {
        output[]
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            output[i * height + j] = input[j * width + (height - 1  - i)];
        }
    }
    return output;
}
