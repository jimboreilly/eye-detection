
#include "Image.h"
#include "Filters.h"

class EdgeDetection : public Filter {
    Image kernel;
protected:
    virtual float updatePixel(Image & hood);;
public:
    EdgeDetection(const Image & k) : kernel(k) {};
};

