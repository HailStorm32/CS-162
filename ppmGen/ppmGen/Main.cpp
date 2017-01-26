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
const int ROWS = 800; //Height 800
const int COLS = 1000; //Width 1000

//Center point(pixel) of the over all image
const int CENTER_POINT_X = (COLS / 2);
const int CENTER_POINT_Y = (ROWS / 2);

//Shape sizes
const int BOX_SIDE = ((((COLS - 50) * 2) - COLS) / 2);//We do this calculation so that if the image is larger than 200x300, the 50x50 box or circle will scale accordingly 
const int CIRCLE_RADIUS = 250;

//Find the top left corner of the box
const int BOX_START_POINT_X = (CENTER_POINT_X - (BOX_SIDE / 2));
const int BOX_START_POINT_Y = (CENTER_POINT_Y - (BOX_SIDE / 2));

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
const float PI = 3.14159265;

//Function protoypes
void setBackground(int imagePixels[][ROWS][COLS], char choice);
void drawSunset(int imagePixels[][ROWS][COLS]);
void drawCircle(int imagePixels[][ROWS][COLS]);
void drawSquare(int imagePixels[][ROWS][COLS]);
void createImage(int imagePixels[][ROWS][COLS], char backgroundChoice, char shapeChoice);
void saveImage(const int imagePixels[][ROWS][COLS]);


void main()
{
	static int imagePixels[COLOR_PAGE][ROWS][COLS] = {};
	char backgroundChoice = ' ';
	char imageChoice = ' ';

	//User picks background type
	do
	{
		cout << "\nDo you want: A) a gradient background OR B) a RGB background?\n" << "Please enter A OR B" << endl;
		cin >> backgroundChoice;
	} while (toupper(backgroundChoice) != 'A' && toupper(backgroundChoice) != 'B');

	//User picks image
	do
	{
		cout << "\n\nDo you want draw a: s[Q]uare, [C]ircle? OR [S]unset\n" << "Please enter Q, C OR S" << endl;
		cin >> imageChoice;
	} while (toupper(imageChoice) != 'Q' && toupper(imageChoice) != 'C' && toupper(imageChoice) != 'S');


	//Draw and create the ppm file
	cout << "Creating image...\n" << endl;
	createImage(imagePixels, backgroundChoice, imageChoice);

	cout << "Image created!\n\nSaving to .ppm file..." << endl;
	saveImage(imagePixels);

	cout << "Image saved!\n\n";
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
		int sectionSize = ROWS / 255;//Because 255 is smaller than the amout of rows we have, we have to fit that value evenly into the size of ROWS

		//Draw gradient
		for (int sectionIndx = 0; sectionIndx != round((ROWS / sectionSize)); sectionIndx++)
		{
			for (int rowIndx = (sectionIndx * sectionSize); rowIndx < (sectionSize * (sectionIndx + 1)); rowIndx++)//start each new section where the last one left off
			{
				for (int colIndx = 0; colIndx < COLS; colIndx++)
				{
					imagePixels[RED][rowIndx][colIndx] = 255 - pixelIntensity;
					imagePixels[GREEN][rowIndx][colIndx] = 40;
					imagePixels[BLUE][rowIndx][colIndx] = pixelIntensity;
				}
			}
			pixelIntensity = pixelIntensity + 1;
			if (pixelIntensity > 255) pixelIntensity = 255;
		}
	}
	else
	{
		int sectionSize = ROWS / 3;

		//Draw RGB sections
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
// Function: drawSunset
// Description: Create a sunset
//
// Arguments:
//		imagePixels (O) -- 3D array that image will be put in
// Return Values:
//		NONE
//===============================================================
void drawSunset(int imagePixels[][ROWS][COLS])
{
	int reflectionSize = CIRCLE_RADIUS * 2;
	int reflectionXCord = (CENTER_POINT_X - CIRCLE_RADIUS);

	//Override whatever background was chosen before
	setBackground(imagePixels, 'A');

	//draw the sun
	drawCircle(imagePixels);

	//Draw the cliff
	for (int rowIndx = 0; rowIndx != 350; rowIndx++)
	{
		for (int colIndx = 0; colIndx < COLS; colIndx++)
		{
			imagePixels[RED][(ROWS - 1) - rowIndx][BOX_START_POINT_X + colIndx] = 102;
			imagePixels[GREEN][(ROWS - 1) - rowIndx][BOX_START_POINT_X + colIndx] = 51;
			imagePixels[BLUE][(ROWS - 1) - rowIndx][BOX_START_POINT_X + colIndx] = 0;
		}

	}

	//Draw reflection
	for (int rowIndx = 450; rowIndx < ROWS; rowIndx++)
	{
		for (int colIndx = 0; colIndx != reflectionSize; colIndx++)
		{
			imagePixels[RED][rowIndx][reflectionXCord + colIndx] = 204;
			imagePixels[GREEN][rowIndx][reflectionXCord + colIndx] = 153;
			imagePixels[BLUE][rowIndx][reflectionXCord + colIndx] = 0;
		}
		reflectionSize = reflectionSize + 2;
		reflectionXCord--;
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

	for (int radIndx = CIRCLE_RADIUS; radIndx != 0; radIndx--)//Shrink the radius by one each pass so we eventually fill the circle
	{
		for (float radian = 0; radian < (2.0*PI); radian = radian + .0001)
		{
			//Get the x & y coordinate of each point along the circle
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
	//Print from left to right, top to bottom (starting at the top left corner of the box)
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

	if (toupper(shapeChoice) == 'Q')
	{
		drawSquare(imagePixels);
	}
	else if (toupper(shapeChoice) == 'C')
	{
		drawCircle(imagePixels);
	}
	else if (toupper(shapeChoice) == 'S')
	{
		drawSunset(imagePixels);
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