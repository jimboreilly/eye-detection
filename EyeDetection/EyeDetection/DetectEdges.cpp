#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Image.h"
#include "Filters.h"
#include "DetectEdges.h"

float EdgeDetection::updatePixel(Image & hood) {
    unsigned int i = 0, j = 0;
    float sum = 0.0;
    if (kernel.getNumRows() != hood.getNumRows() || kernel.getNumCols() != hood.getNumCols()) {
        std::cout << "kernel and neighborhood dimensions must match \n";
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < hood.getNumRows(); ++i) {
        for (j = 0; j < hood.getNumCols(); ++j) {
            sum += (kernel.getVal(i, j)*hood.getVal(i, j));
        }
    }
    return sum;
}
