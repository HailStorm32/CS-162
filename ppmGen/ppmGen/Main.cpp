/*
Author: Demetri Van Sickle
Course: CS-162-02
Program: ppmGen
Date: 1/20/17
Description:
	Creates a .ppm image file of a multicolored background with a yellow circle
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int COLOR_PAGE = 3;
const int ROWS = 1000; //Height
const int COLS = 900; //Width

//Center point(pixel) of the image
const int CENTER_POINT_X = ((COLS / 2) + 1);
const int CENTER_POINT_Y = ((ROWS / 2) + 1);

const int BOX_SIDE = ((((COLS - 50) * 2) - COLS) / 2);//We do this calculation so that the if the image is larger than 200x300, the 50x50 box will scale accordingly 

//Find the bottom left corner of the box
const int BOX_START_POINT_X = (CENTER_POINT_X - (BOX_SIDE / 2));
const int BOX_START_POINT_Y = (CENTER_POINT_Y - (BOX_SIDE / 2));

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;

void setBackground(int imagePixels[][ROWS][COLS]);
void drawSquare(int imagePixels[][ROWS][COLS]);
void createImage(int imagePixels[][ROWS][COLS]);
void saveImage(const int imagePixels[][ROWS][COLS]);


void main()
{
	static int imagePixels[COLOR_PAGE][ROWS][COLS] = {};

	cout << "Creating image...\n" << endl;

	createImage(imagePixels);

	cout << "Image created!\n\nSaving to .ppm file..." << endl;

	saveImage(imagePixels);

	cout << "Image saved!" << endl;
}


//===============================================================
// Function: setBackground
// Description:
//		Divide the background into three equal sections
//		and color each section red, green & blue respectively  
//
// Arguments:
//		imagePixels (O) -- 3D array that holds the image
// Return Values:
//		NONE
//===============================================================
void setBackground(int imagePixels[][ROWS][COLS])
{
	int sectionSize = ROWS / 3;

	//color each section
	for (int sectionIndx = 0; sectionIndx != 3; sectionIndx++)
	{
		for (int rowIndx = (sectionIndx * sectionSize); rowIndx < (sectionSize * (sectionIndx + 1)); rowIndx++)//start each new section where the last one left off
		{
			for (int colIndx = 0; colIndx < COLS; colIndx++)
			{
				imagePixels[sectionIndx][rowIndx][colIndx] = 255;
			}
		}
	}
}


//===============================================================
// Function: drawSquare
// Description: Create a square pixel by pixle and store it in
//				the given 3D array
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
// Return Values:
//		NONE
//================================================================
void drawSquare(int imagePixels[][ROWS][COLS])
{
	
	//for (int colorIndx = 0; colorIndx < COLOR_PAGE; colorIndx++)
	//{
		for (int rowIndx = 0; rowIndx != BOX_SIDE; rowIndx++)//will print from left to right, bottom to top
		{
			for (int colIndx = 0; colIndx != BOX_SIDE; colIndx++)
			{
				imagePixels[RED][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 255;
				imagePixels[GREEN][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 255;
				imagePixels[BLUE][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 0;
			}
		}
	//}
}


//===============================================================
// Function: createImage
// Description: Create an image pixel by pixle and store it in
//				the given 3D array
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
// Return Values:
//		NONE
//================================================================
void createImage(int imagePixels[][ROWS][COLS])
{
	setBackground(imagePixels);

	drawSquare(imagePixels);

}


//================================================================
// Function: saveImage
// Description: Save image to disk by creating a .ppm file
//
// Arguments:
//		imagePixels (I) -- 3D array that holds the image data
// Return Values:
//		NONE
//================================================================
void saveImage(const int imagePixels[][ROWS][COLS])
{
	ofstream fileWrite;

	bool newlineFlag = false;

	fileWrite.open("ppm_Image.ppm");

	fileWrite << "P3" << endl;
	fileWrite << COLS << " " << ROWS << endl;
	fileWrite << "255" << "\n\n";

	for (int rowIndx = 0; rowIndx < ROWS; rowIndx++)
	{
		for (int colIndx = 0; colIndx < COLS; colIndx++)
		{
			for (int colorIndx = 0; colorIndx < COLOR_PAGE; colorIndx++)
			{
				fileWrite <<  imagePixels[colorIndx][rowIndx][colIndx] << " ";
			}
			fileWrite << "  ";
		}
		fileWrite << "\n";
	}

}