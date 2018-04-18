#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Image.h"

void Image::init(int nr, int nc){
//set properties
  num_rows = nr;
  num_cols = nc;
//allocate
  data = new float[num_rows*num_cols]();  //initialize to 0
}

void Image::areIndecesValid(int row, int col){
  if(row<0 || row>=num_rows){
    std::cerr<<"row out of range\n";
    exit(EXIT_FAILURE);
  }
  if(col<0 || col>=num_cols){
    std::cerr<<"col out of range\n";
    exit(EXIT_FAILURE);
  }
}

Image::Image(int nr, int nc){  init(nr,nc);  }

Image::~Image(){  delete[] data;  }

Image::Image(const Image & im){
  //init(im.num_rows,im.num_cols);  // this might do desired func
  num_rows = im.num_rows;
  num_cols = im.num_cols;
  data = new float[num_rows*num_cols];
  // copy contents of im.data to this.data
  for(int i=0; i<num_rows*num_cols;++i){
    data[i]=im.data[i];
  }
}

Image & Image::operator=(const Image & im){
  if(this==&im) return *this;  //checks to make sure you didn't call im=im
  delete[] data;
  init(im.num_rows,im.num_cols);
  for(int i=0; i<num_rows*num_cols;++i){
    data[i]=im.data[i];
  }
  return *this;
}

int Image::getNumRows(){
  return num_rows;
}

int Image::getNumCols(){
  return num_cols;
}

float Image::getVal(int row, int col){
  areIndecesValid(row,col);
  return (data[col*num_cols+row]);
}

void Image::setVal(int row, int col, float val){
  areIndecesValid(row,col);
  data[col*num_cols+row]=val;
}


void Image::readImage(char* filename){
  std::ifstream infile(filename, std::ios::in|std::ios::binary);
  if(infile.is_open()){
    infile.read((char*)data, num_rows*num_cols*4);
    infile.close();
  } else std::cout<< "Unable to read " << filename << "\n";
}

void Image::writeImage(char* filename){
  std::ofstream outfile(filename, std::ios::out|std::ios::binary);
  if(outfile.is_open()){
    outfile.write((char*)data, num_rows*num_cols*4);
    outfile.close();
  } else std::cout<< "Unable to write to "<< filename<<"\n";
}

void Image::printImage(){
  unsigned int i=0,j=0;
  for(i=0;i<num_rows;i++){
    for(j=0;j<num_cols;j++){
      std::cout<<getVal(i,j);
    }
    std::cout<<"\n";
  }
}

float Image::getAverageValue(){
  unsigned int i=0;
  float sum=0, avg=0;
  for(i=0;i<num_rows*num_cols;i++){
    sum+=data[i];
  }
  avg=sum/(num_rows*num_cols);
}
