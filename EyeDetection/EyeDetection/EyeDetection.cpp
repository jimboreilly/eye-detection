// EyeDetection.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Image.h"

void validateInputArguments(int argc, char *argv[], int *width, int *height) {
    if (argc != 4) {
        printf("ERROR: EyeDetection.exe usage -> <input.bin> <int width> <int height>\n");
        exit(1);
    }
    if (sscanf(argv[2], "%i", width) != 1) {
        fprintf(stderr, "error - argv[1] width not an integer");
        exit(-1);
    }
    if (sscanf(argv[3], "%i", height) != 1) {
        fprintf(stderr, "error - argv[2] height not an integer");
        exit(-1);
    }
}

void validateFileExists(char* fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("ERROR: file not found exception\n");
        exit(1);
    }

    else return;
}

void readInputFileIntoArray(char* fileName, float *pixels, int n) {
    FILE *fp;
    fp = fopen(fileName, "r");

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%f", &pixels[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *inputFile = argv[1];
    int width, height;

    validateInputArguments(argc, argv, &width, &height);
    validateFileExists(inputFile);

    float *pixels = (float *)calloc(sizeof(float), width * height);
    int size = width * height;
    readInputFileIntoArray(inputFile, pixels, size);

    Image im(width, height, pixels);
    printf("width of image: %u \n", im.getNumRows());
    printf("height of image: %u \n", im.getNumCols());
    system("pause");
}

