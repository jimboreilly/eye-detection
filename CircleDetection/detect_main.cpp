#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Image.h"
#include "Circle.h"
#include "VotingData.h"

using namespace std;

#define MAX_DEG 360
#define PI 3.14159265358979

void voting(VotingData & data, int minRad, Image & im){
  int a=0, b=0, d=0, x=0, y=0, r=0;
  VotingData lookup(data.getHeight(),data.getWidth(),data.getRange());
  VotingData blank(data.getHeight(),data.getWidth(),data.getRange());
  
  for(y=0; y<data.getHeight(); y++){
    for(x=0; x<data.getWidth(); x++){
      if(im.getVal(x,y)==1){
        for(r=0; r<data.getRange(); r++){
          lookup=blank;
          for(d=0; d<MAX_DEG; d++){
            a = x - (r+minRad) * cos(d * PI / 180);
            b = y - (r+minRad) * sin(d * PI / 180);
            if((a+r+1)>=data.getWidth() || (a-r+1)<0 || (b+r+1)>=data.getHeight() || (b-r+1)<0) { continue; }
            if(a<data.getHeight() && a>0 && b<data.getWidth() && b>0){
              if(lookup.getVal(a,b,r)!=0){ continue; }
              data.setVal(a,b,r,data.getVal(a,b,r)+1); // increment data entry
              lookup.setVal(a,b,r,lookup.getVal(a,b,r)+1);
            }
          }
        }
      }
    }
  }
}


Circle bestCircle(VotingData & v, int minRad){
  unsigned int i=0, j=0, k=0;
  int bestH=0, bestW=0, bestR=0, bestScore=0;
  for(i=0; i<v.getHeight(); i++){
    for(j=0; j<v.getWidth(); j++){
      for(k=0; k<v.getRange(); k++){
        if(bestScore < v.getVal(i,j,k)){
          bestH = i;
          bestW = j;
          bestR = k;
          bestScore = v.getVal(i,j,k);
        }
      }
    }
  }
  Circle out(bestH,bestW,bestR+minRad);
  return(out);
}

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
  
  VotingData data(height,width,range);

  Image im(width,height);
  im.readImage(filename);

  voting(data,minRadius,im);

  Circle out = bestCircle(data,minRadius);
  
  strcpy(outfilename,"out.csv");
  outfile.open(outfilename);
  if(outfile.is_open()){
    outfile << out.getOriginX() << "," << out.getOriginY() << "," << out.getRadius() << std::flush;
    outfile.close();
  } else cout<< "Unable to write to "<< filename<<"\n";
  
  return 0;
}
