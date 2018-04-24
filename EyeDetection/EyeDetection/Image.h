#ifndef IMAGE_H
#define IMAGE_H
class Image{
  int num_rows;
  int num_cols;
  float* data;
private:
	int getIndex(int, int);
public:
  Image(int, int);
  Image(int, int, float*);
  Image(const Image&);
	~Image();
  int getNumRows();
  int getNumCols();
	float* getData();
  float getVal(int, int);
  void setVal(int, int, float);
  void readImage(char* fileName);
  void writeImage(char* fileName);
  void createEdgeMap(double threshold);
  float getAverageValue();
};
#endif

