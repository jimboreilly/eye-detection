#include "stdafx.h"
#include <stdio.h>


// Jim

//opens file, loads float data into given array
void readInputFileIntoArray(char* fileName, float *pixels, int n) {
    FILE *fp;
    fp = fopen(fileName, "r");
    for (int i = 0; i < n; i++) { fscanf(fp, "%f", &pixels[i]); }
    fclose(fp);
}
