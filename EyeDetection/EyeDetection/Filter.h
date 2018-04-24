
#include "Image.h"

class Filter{
protected:
    virtual float updatePixel(Image & hood){ return 0;}
public:
    Image process(Image & im, int m, int n);
private:
    void checkThatDimensionsAreOdd(int m, int n);
};


