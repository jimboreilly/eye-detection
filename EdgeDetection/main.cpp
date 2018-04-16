#include <cstring>
#include <iostream>
#include "Image.h"
#include "Filter.h"
#include "EdgeDetection.h"

#define HOOD_N 3
#define HOOD_M 3

Image runEdgeDetection(Image img);

int main(void){
    char iFile[50]="lab5_spatial_image.bin";
    char oFileXY[50]="edgeDetection_output_XY.bin";
    Image im(256,256);

    //read in image
    im.readImage(iFile);
    
    //run edge detection
    Image im_xy = runEdgeDetection(im);
    im_xy.writeImage(oFileXY);
    
    return 0;
}


Image runEdgeDetection(Image im){
    float imageThreshold=0;
    
    //kernel x
    Image kernel(HOOD_M,HOOD_N);
    kernel.setVal(0,0,-1);
    kernel.setVal(0,1,0);
    kernel.setVal(0,2,1);
    kernel.setVal(1,0,-2);
    kernel.setVal(1,1,0);
    kernel.setVal(1,2,2);
    kernel.setVal(2,0,-1);
    kernel.setVal(2,1,0);
    kernel.setVal(2,2,1);
    
    EdgeDetection gX(kernel);
    Image imX=gX.process(im,HOOD_M,HOOD_N);
    
    //kernel y
    kernel.setVal(0,0,1);
    kernel.setVal(0,1,2);
    kernel.setVal(0,2,1);
    kernel.setVal(1,0,0);
    kernel.setVal(1,1,0);
    kernel.setVal(1,2,0);
    kernel.setVal(2,0,-1);
    kernel.setVal(2,1,-2);
    kernel.setVal(2,2,-1);
    
    EdgeDetection gY(kernel);
    Image imY=gY.process(imX,HOOD_M,HOOD_N);
    
    //sum X and Y kernel outputs
    int rows = imX.getNumRows();
    int cols = imX.getNumCols();
    Image ImgXY = Image(rows, cols);
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double sum = imX.getVal(i, j) + imY.getVal(i, j);
            ImgXY.setVal(i, j, sum);
        }
    }
    
    //determine threshhold
    imageThreshold=ImgXY.getAverageValue();
    
    //create binary edge map
    ImgXY.createEdgeMap(imageThreshold);
    
    return ImgXY;
}
