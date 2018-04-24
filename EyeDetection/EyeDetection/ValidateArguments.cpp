
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "ValidateArguments.h"

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
        exit(2);
    }

    else return;
}