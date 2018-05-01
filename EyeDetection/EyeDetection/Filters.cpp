#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Filters.h"

//validates that the given kernel dimensions are odd else exits
void Filter::checkThatDimensionsAreOdd(int m, int n) {
    if (m % 2 == 0) {
        std::cout << "Number of rows must be odd\n";
        exit(EXIT_FAILURE);
    }
    if (n % 2 == 0) {
        std::cout << "Number of columns must be odd\n";
        exit(EXIT_FAILURE);
    }
}

//iterates through image and runs abstract updatePixel on each pixel for given filter
Image Filter::process(Image & im, int m, int n) {
    checkThatDimensionsAreOdd(m, n);

    int border_nr = (m - 1) / 2;
    int border_nc = (n - 1) / 2;

    //output image
    Image out(im);

    //kernel of m/n dimensions
    Image hood(m, n);

    int i = 0, j = 0, hood_m = 0, hood_n = 0, x = 0, y = 0;
    float val = 0;

    //zero the columns on left and right of image
    for (int row = 0; row < out.getNumRows(); row++) {
        for (int col = 0; col < border_nc; col++) {
            out.setVal(row, col, 0);
            int rightEndCol = out.getNumCols() - 1 - col;
            out.setVal(row, rightEndCol, 0);
        }
    }

    //zero the rows on top and bottom of image
    for (int col = 0; col < out.getNumCols(); col++) {
        for (int row = 0; row < border_nr; row++) {
            out.setVal(row, col, 0);
            int bottomRow = out.getNumRows() - 1 - row;
            out.setVal(bottomRow, col, 0);
        }
    }
    //for each row, each column, each kernel dimension
    for (i = border_nr; i < out.getNumRows() - border_nr; i++) {
        for (j = border_nc; j < out.getNumCols() - border_nc; j++) {
            //for the selected row/column pixel, run convolute with the kernel
            for (x = -border_nr, hood_m = 0; x <= border_nr; x++, hood_m++) {
                for (y = -border_nc, hood_n = 0; y <= border_nc; y++, hood_n++) {
                    hood.setVal(hood_m, hood_n, im.getVal(i + x, j + y));
                }
            }
            val = updatePixel(hood);
            out.setVal(i, j, val);
        }
    }
    return(out);
}

