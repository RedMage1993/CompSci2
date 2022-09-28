// Fritz Ammon
// Assignment No. 8
// File: imageType.h
// Description: imageType class declaration

#ifndef IMAGETYPE_H
#define IMAGETYPE_H

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "bitmapImage.h"

using namespace std;

enum color {RED, GREEN, BLUE};

class imageType : public bitmapImage
{
public:
	// Constructor
	// fileName, width, height, and title
    imageType(string="", int=0, int=0, string="");
    
	// Converts a bitmap image's pixel values to B & W
    void colorToBW();
    
	// Resizes a bitmap based on percentage (retains aspect ratio)
    void resize(double);
    
	// Resizes a bitmap to new width and height
    void resize(int, int);
    
	// Blurs bitmap
    void smooth();
    
	// Brightens or darkens bitmap based on percentage
    void brightness(double);
    
	// Converts bitmap's pixels to intensify target color
    void RGBshift(color);
    
	// Rotates bitmap to an angle and sets background color
    void rotate(double=0, int=0);
    
	// Zooms into bitmap and removes rectangles
    void crop(int, int, int, int);
private:
    static const int H_MAX = 10000;
    static const int W_MAX = 10000;

    string fileName; // Name of file with bitmap data
    string title; // Title of bitmap image
};

#endif // IMAGETYPE_H