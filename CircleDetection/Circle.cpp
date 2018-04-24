#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"

void Circle::init(double x, double y, double rad){
//set properties
  origin_x = x;
  origin_y = y;
  radius = rad;
}

Circle::Circle(double x, double y, double rad){  init(x,y,rad);  }

Circle::~Circle(){}

Circle::Circle(const Circle & circ){  init(circ.origin_x,circ.origin_y,circ.radius);  }

Circle & Circle::operator=(const Circle & circ){
  if(this==&circ) return *this;
  init(circ.origin_x,circ.origin_y,circ.radius);
  return *this;
}

double Circle::getOriginX(){
  return origin_x;
}

double Circle::getOriginY(){
  return origin_y;
}

double Circle::getRadius(){
  return radius;
}
