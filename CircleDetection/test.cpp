#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "CircleDetection.h"
#include "Circle.h"
#include "Image.h"

using namespace std;

int main(int argc, char** argv){
  if(argc!=6){
    cout<<"Error: enter 5 arguments with the call to this functionality\n";
    exit(EXIT_FAILURE);
  }
  
  unsigned int i=0, j=0;
  ofstream outfile;
  char outfilename[100];

  char *filename = argv[1];
  int height = atoi(argv[2]);
  int width = atoi(argv[3]);
  int minRadius = atoi(argv[4]);
  int maxRadius = atoi(argv[5]);
  int range = maxRadius - minRadius;

  Image im(width,height);
  im.readImage(filename);
  
  CircleDetection circDet;

  Circle out = circDet.detectCircle(im,height,width,minRadius,range);

  cout<<"circle dimensions: ("<<out.getOriginX()<<","<<out.getOriginY()<<","<<out.getRadius()<<")\n";
  
  strcpy(outfilename,"out.csv");
  outfile.open(outfilename);
  if(outfile.is_open()){
    outfile << out.getOriginX() << "," << out.getOriginY() << "," << out.getRadius() << std::flush;
    outfile.close();
  } else cout<< "Unable to write to "<< outfilename<<"\n";
  
  return 0;
}
