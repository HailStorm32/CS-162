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
#include <cmath>

using namespace std;

const int COLOR_PAGE = 3;
const int ROWS = 800; //Height
const int COLS = 1000; //Width

//Center point(pixel) of the over all image
const int CENTER_POINT_X = (COLS / 2);
const int CENTER_POINT_Y = (ROWS / 2);


const int BOX_SIDE = ((((COLS - 50) * 2) - COLS) / 2);//We do this calculation so that if the image is larger than 200x300, the 50x50 box or circle will scale accordingly 
const int CIRCLE_RADIUS = 250;

//Find the bottom left corner of the box
const int BOX_START_POINT_X = (CENTER_POINT_X - (BOX_SIDE / 2));
const int BOX_START_POINT_Y = (CENTER_POINT_Y - (BOX_SIDE / 2));

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
const float PI = 3.14159265;

//Function protoypes
void setBackground(int imagePixels[][ROWS][COLS], char choice);
void drawCircle(int imagePixels[][ROWS][COLS]);
void drawSquare(int imagePixels[][ROWS][COLS]);
void createImage(int imagePixels[][ROWS][COLS], char backgroundChoice, char shapeChoice);
void saveImage(const int imagePixels[][ROWS][COLS]);


void main()
{
	static int imagePixels[COLOR_PAGE][ROWS][COLS] = {};
	char backgroundChoice = ' ';
	char imageChoice = ' ';

	do
	{
		cout << "\nDo you want: A) a gradient background OR B) a RGB background?\n" << "Please enter A OR B" << endl;
		cin >> backgroundChoice;
	} while (toupper(backgroundChoice) != 'A' && toupper(backgroundChoice) != 'B');

	do
	{
		cout << "\n\nDo you want draw a: [S]quare OR [C]ircle?\n" << "Please enter S OR C" << endl;
		cin >> imageChoice;
	} while (toupper(imageChoice) != 'S' && toupper(imageChoice) != 'C');

	cout << "Creating image...\n" << endl;

	createImage(imagePixels, backgroundChoice, imageChoice);

	cout << "Image created!\n\nSaving to .ppm file..." << endl;

	saveImage(imagePixels);

	cout << "Image saved!" << endl;
}


//===============================================================
// Function: setBackground
// Description:
//		Divide the background into three equal sections
//		and color each section red, green & blue respectively 
//		OR color it gradient
//
// Arguments:
//		imagePixels (O) -- 3D array that holds the image
//		choice (I) -- background type
// Return Values:
//		NONE
//===============================================================
void setBackground(int imagePixels[][ROWS][COLS], char choice)
{
	int pixelIntensity = 0;

	if (toupper(choice) == 'A')
	{
		int sectionSize = ROWS / 255;//Because 255 is smaller than the amout of rows we have, we have to fit that value evenly into size of ROWS

		for (int sectionIndx = 0; sectionIndx != round((ROWS / sectionSize)); sectionIndx++)
		{
			for (int rowIndx = (sectionIndx * sectionSize); rowIndx < (sectionSize * (sectionIndx + 1)); rowIndx++)//start each new section where the last one left off
			{
				for (int colIndx = 0; colIndx < COLS; colIndx++)
				{
					imagePixels[RED][rowIndx][colIndx] = pixelIntensity;
					imagePixels[GREEN][rowIndx][colIndx] = 40;
					imagePixels[BLUE][rowIndx][colIndx] = 255 - pixelIntensity;
				}
			}
			pixelIntensity = pixelIntensity + 1;
			if (pixelIntensity > 255) pixelIntensity = 255;
		}
	}
	else
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
}


//===============================================================
// Function: drawCircle
// Description: Create a circle pixel by pixel and store it in
//				the given 3D array
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
// Return Values:
//		NONE
//===============================================================
void drawCircle(int imagePixels[][ROWS][COLS])
{
	int xCord = 0;
	int yCord = 0;

	//Bar length idea...
	/*int xCord = CENTER_POINT_X;
	int yCord = CENTER_POINT_Y + CIRCLE_RADIUS;
	int barLength = 1;


	for (int radIndx = 0; radIndx != (CIRCLE_RADIUS); radIndx++)
	{
		for (int colIndx = 0; colIndx != barLength; colIndx = colIndx++)
		{
			imagePixels[RED][yCord][xCord + colIndx] = 255;
			imagePixels[GREEN][yCord][xCord + colIndx] = 255;
			imagePixels[BLUE][yCord][xCord + colIndx] = 0;
		}
		xCord--;
		yCord--;
		barLength = barLength + 2;
	}

	barLength = barLength - 2;
	xCord++;
	yCord++;

	for (int radIndx = 0; radIndx != (CIRCLE_RADIUS); radIndx++)
	{
		for (int colIndx = 0; colIndx != barLength; colIndx = colIndx++)
		{
			imagePixels[RED][yCord][xCord + colIndx] = 255;
			imagePixels[GREEN][yCord][xCord + colIndx] = 255;
			imagePixels[BLUE][yCord][xCord + colIndx] = 0;
		}
		xCord++;
		yCord++;
		barLength = barLength - 2;
	}*/


	// 2pi CIRCLE OPTION #1
	for (int radIndx = CIRCLE_RADIUS; radIndx != 0; radIndx--)//Shrink the radius by one each pass so we eventual fill the circle
	{
		for (float radian = 0; radian < (2.0*PI); radian = radian + .0001)
		{

			//x = cx + r * cos(a)
			//y = (cy + r * sin(a)) + cy

			xCord = abs(round(((0 + static_cast<float>(radIndx)) * cos(radian))) + CENTER_POINT_X);
			yCord = abs(round(((0 + static_cast<float>(radIndx)) * sin(radian))) + CENTER_POINT_Y);

			imagePixels[RED][yCord][xCord] = 255;
			imagePixels[GREEN][yCord][xCord] = 255;
			imagePixels[BLUE][yCord][xCord] = 0;
		}
	}
}


//===============================================================
// Function: drawSquare
// Description: Create a square pixel by pixel and store it in
//				the given 3D array
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
// Return Values:
//		NONE
//===============================================================
void drawSquare(int imagePixels[][ROWS][COLS])
{
	//Will print from left to right, bottom to top (starting at the bottom left corner of the box)
	for (int rowIndx = 0; rowIndx != BOX_SIDE; rowIndx++)
	{
		for (int colIndx = 0; colIndx != BOX_SIDE; colIndx++)
		{
			imagePixels[RED][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 255;
			imagePixels[GREEN][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 255;
			imagePixels[BLUE][BOX_START_POINT_Y + rowIndx][BOX_START_POINT_X + colIndx] = 0;
		}
	}
}


//===============================================================
// Function: createImage
// Description: Create an image pixel by pixel and store it in
//				the given 3D array
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
//		backgroundChoice (I) -- background type
//		shapeChoice (I) -- what shape will be drawn
// Return Values:
//		NONE
//================================================================
void createImage(int imagePixels[][ROWS][COLS], char backgroundChoice, char shapeChoice)
{
	setBackground(imagePixels, backgroundChoice);

	if (toupper(shapeChoice) == 'S')
	{
		drawSquare(imagePixels);
	}
	else
	{
		drawCircle(imagePixels);
	}
}


//================================================================
// Function: saveImage
// Description: Save image to disk by creating a .ppm file
//
// Arguments:
//		imagePixels (I) -- 3D array that holds the image data to write
// Return Values:
//		NONE
//================================================================
void saveImage(const int imagePixels[][ROWS][COLS])
{
	ofstream fileWrite;

	fileWrite.open("ppm_Image.ppm");

	//Write the .ppm file header
	fileWrite << "P3" << endl;
	fileWrite << COLS << " " << ROWS << endl;
	fileWrite << "255" << "\n\n";

	//Write to the file in RGB groups seperated by two spaces
	for (int rowIndx = 0; rowIndx < ROWS; rowIndx++)
	{
		for (int colIndx = 0; colIndx < COLS; colIndx++)
		{
			for (int colorIndx = 0; colorIndx < COLOR_PAGE; colorIndx++)
			{
				fileWrite << imagePixels[colorIndx][rowIndx][colIndx] << " ";
			}
			fileWrite << "  ";
		}
		fileWrite << "\n";
	}

	fileWrite.close();
}