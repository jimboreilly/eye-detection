#ifndef IMAGE_H
#define IMAGE_H
class Image {
    int num_rows;
    int num_cols;
    float *data;
public:
    Image(int nr, int nc);
    ~Image();                           //destructor
    Image(const Image & im);            //copy constructor
    Image & operator=(const Image & im); //assignment
    int getNumRows();
    int getNumCols();
    float getVal(int row, int col);
    void setVal(int row, int col, float val);
    void readImage(char* filename);
    void writeImage(char* filename);
    void printImage();
    void createEdgeMap(double threshold);
    float getAverageValue();
private:
    void init(int nr, int nc);
    void areIndecesValid(int row, int col);
};
#endif

