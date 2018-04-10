/***************************************************************************/
/*                                                                         */
/*  File: main.cpp                                                         */
/*  Autor: bkenwright@xbdev.net                                            */
/*  URL: www.xbdev.net                                                     */
/*                                                                         */
/***************************************************************************/
/*
	Jpeg File Format Explained
*/
/***************************************************************************/

#include <windows.h>
#include <stdio.h>		// sprintf(..), fopen(..)
#include <stdarg.h>     // So we can use ... (in dprintf)=
#include "loadjpg.h"	// ConvertJpgFile(..)
#include "savejpg.h"    // SaveJpgFile(..)

/***************************************************************************/
/*                                                                         */
/* FeedBack Data                                                           */
/*                                                                         */
/***************************************************************************/
void rgb2gray(char **, char *, int, int);
void EdgeDetect(char *);
result HoughTransform(char *, int, int);
//Saving debug information to a log file
void dprintf(const char *fmt, ...) 
{
	va_list parms;
	char buf[256];

	// Try to print in the allocated space.
	va_start(parms, fmt);
	vsprintf (buf, fmt, parms);
	va_end(parms);

	// Write the information out to a txt file
	FILE *fp = fopen("output.txt", "a+");
	fprintf(fp, "%s", buf);
	fclose(fp);

}// End dprintf(..)
 
/***************************************************************************/
/*                                                                         */
/* Entry Point                                                             */
/*                                                                         */
/***************************************************************************/
struct result{
	int Cx;
	int Cy;
	int Radius;
};

int main(int argc, char[] *argv) // They had something different origially, not sure if this main will work
{
	if(argc < 3 || argc > 3){
		return -1;
	}
	
	stJpegData temp;
	unsigned char* buf;
	int sizeBuf;
	unsigned char** rgbpix;
	unsigned char* graypix;
	unsigned int* width;
	unsigned int* height;
	FILE *fp;
	char *filename,*output;
	result info;
	string x, y, r;
	// Set up filename arguments
	filename = argv[1];
	output = argv[2];
	
	// Get filesize
	fp = fopen(filename,"r");
	sizeBuf = FileSize(fp);
	fclose(fp);
	
	// Get file stream and read into char array
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if(!file.is_open()){std::cout << "File does not exist.\n"; return -1;}
	if(!file.is_open()){std::cout << "File does not exist.\n"; return -1;} //Check if Jpeg?
	file.read(buf,sizeBuf);
	file.close();
	
	// Decode jpeg
	int DecodeJpgFileData(	buf, 		// Jpg file in memory
							sizeBuf,	// Size jpg in bytes in memory
							rgbpix,		// Output rgb pixels
							width,		// Output image width
							height);		// Output image height
	
	graypix = (char*)malloc(sizeof(char)*height*width);
	rgb2gray(rgbpix, graypix, *width, *height);
	
	// Detect edges
	EdgeDetect(graypix); 
	// Hough Transform
	info = HoughTransform(graypix, width, height);
	
	std::ofstream out(output, std::ios::out | std::ios::binary);
	if(!file.is_open()){std::cout << "File not created.\n"; return -1;}
	x = toString(info->Cx);
	y = toString(info->Cy);
	r = toString(info->Radius);
	string outputInfo = x + "," y + "," + r;
	out << outputInfo;
	out.close();
	delete[] rgbpix;
	delete[] graypix;

	return 0;
}// End WinMain(..)

void rgb2gray(char **rgbpix, char *graypix, int width, int height) {
	int i;
	for (i = 0; i < height*width; i++) {
		graypix[i] = (rgbpix[i])*.299 + (rgbpix[i+1])*.587 + (rgbpix[i+2])*.114;
	}
}