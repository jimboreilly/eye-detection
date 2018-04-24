#ifndef CIRCLEDETECTION_H
#define CIRCLEDETECTION_H
  #include "Image.h"
  #include "Circle.h"
  #include "VotingData.h"
  #include <math.h>
  #include <cstdlib>
  #include <iostream>

  #define MAX_DEG 360
  #define PI 3.14159265358979
  
  class CircleDetection {
    public:
      CircleDetection();
      ~CircleDetection();
      Circle detectCircle(Image & im, int height, int width, int minRad, int range);
    private:
      void voting(VotingData & data, int minRad, Image & im);
      Circle bestCircle(VotingData & v, int minRad);
  };
#endif
