
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "ValidateArguments.h"

//validate the number of input arguments and type of inputs are correct
void validateInputArguments(int argc, char *argv[], int *width, int *height) {
    if (argc != 5) {
        printf("ERROR: EyeDetection.exe usage -> <input.bin> <int width> <int height> <string output filename >\n");
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

//check that a file exists by trying to open it
void validateFileExists(char* fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        //throws if does not exist
        printf("ERROR: file not found exception\n");
        exit(2);
    }
    //program continues if does
    else return;
}