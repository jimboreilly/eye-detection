#ifndef EDGE_DETECTION_H
#define EDGE_DETECTION_H
#include "Image.h"
#include "Filter.h"
class EdgeDetection : public Filter {
    Image kernel;
protected:
    virtual float updatePixel(Image & hood);;
public:
    EdgeDetection(const Image & k) : kernel(k){};
};
#endif

