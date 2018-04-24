#include "stdafx.h"

#ifndef IMAGE_H
#include "Image.h"
#endif
#include <stdlib.h>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;

//constructor
Image::Image(int r, int c){
  num_rows = r;
  num_cols = c;
  data = new float[r*c];
}

Image::Image(int r, int c, float *pixels) {
    num_rows = r;
    num_cols = c;
    data = new float[r*c];
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            setVal(row, col, pixels[getIndex(row, col)]);
        }
    }
}

//copy constructor
Image::Image(const Image &src) {
	num_rows = src.num_rows;
	num_cols = src.num_cols;

	data = new float[num_rows * num_cols];
	for(int row = 0; row < num_rows; row++) {
		for(int col = 0; col < num_cols; col++) {
			setVal(row,col, src.data[getIndex(row,col)]);
		}
	}
}

//deconstructor
Image::~Image() {
	delete [] data;
}

int Image::getNumRows() {
  return num_rows;
}

int Image::getNumCols() {
  return num_cols;
}

float* Image::getData() {
	return data;
}

//convert row/column into a 1 dimensional matrix index
int Image::getIndex(int r, int c) {
	return (r * num_rows) + c;
}

float Image::getVal(int r, int c) {
	return data[getIndex(r,c)];
}

void Image::setVal(int r, int c, float val) {
	data[getIndex(r,c)] = val;
}

//read a binary file into an image object
void Image::readImage(char* filename) {                 
	std::ifstream infile;         
	infile.open(filename, std::ios::in|std::ios::binary);         
	if (infile.is_open())  {                
		infile.read((char*)data, num_rows*num_cols*4);                 
		infile.close();         
	}  else std::cout<< "Unable to open " << filename<<" for reading \n"; 
}

//write an image object to a binary file
void Image::writeImage(char *filename) {
  std::ofstream file(filename, std::ios::out | std::ios::binary);                
  if(!file){ 
    std::cout << "ERROR: File could not be opened" << std::endl; 
    return;
  }
  file.write((char*)data, num_rows*num_cols*4);
  file.close();
}

float Image::getAverageValue() {
    unsigned int i = 0;
    float sum = 0, avg = 0;
    for (i = 0; i<num_rows*num_cols; i++) {
        double dabs = fabs(data[i]);
        sum += dabs;
    }
    avg = sum / (num_rows*num_cols);
    return avg;
}

void Image::createEdgeMap(double threshold) {
    unsigned int i = 0, j = 0;
    for (i = 0; i<num_rows; i++) {
        for (j = 0; j<num_cols; j++) {
            double x = getVal(i, j);
            if (x > threshold) {
                setVal(i, j, 1);
            }
            else {
                setVal(i, j, 0);
            }
        }
    }
}
