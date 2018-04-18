#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"

void Circle::init(int x, int y, int rad){
//set properties
  origin_x = x;
  origin_y = y;
  radius = rad;
}

Circle::Circle(int x, int y, int rad){  init(x,y,rad);  }

Circle::~Circle(){}

Circle::Circle(const Circle & circ){  init(circ.origin_x,circ.origin_y,circ.radius);  }

Circle & Circle::operator=(const Circle & circ){
  if(this==&circ) return *this;
  init(circ.origin_x,circ.origin_y,circ.radius);
  return *this;
}

int Circle::getOriginX(){
  return origin_x;
}

int Circle::getOriginY(){
  return origin_y;
}

int Circle::getRadius(){
  return radius;
}
