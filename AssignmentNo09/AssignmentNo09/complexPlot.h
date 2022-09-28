// Fritz Ammon
// Section 1002
// Assignment #9
// File: complexPlot.h
// Description: The complexPlot class declaration.
// Is able to graph/plot complex images using RGB
// triplets from HSV based on a complex number.

#ifndef COMPLEXPLOT_H
#define COMPLEXPLOT_H

#include <algorithm>
#include <cmath>
#include <string>
#include "bitmapImage.h"
#include "complexType.h"

using std::string;
using std::pow;
using std::floor;
using std::min;

class complexPlot : public bitmapImage
{
public:
	// Constructors
	// Initialize data members.
	complexPlot();
	complexPlot(int, int, int=0, string=""); // Makes sure arguments are valid.
	complexPlot(const complexPlot&); // Copy constructor to perform deep copy of BMP.

	void readFileName(); // Prompt user for name of file.
	void setFileName(string);
	string getFileName() const;

	void readImageSize(); // Prompt user for image dimensions (width x height).
	void setImageSize(int, int);

	int functionCount(); // The number of functions available.

	int getFunctionNumber(); // This complex plot's associated plotting algorithm.
	void setFunctionNumber(int);
	void readFunctionNumber(); // Prompt user for function number.

	void createComplexPlotImage(); // Runs the plotting algorithm.

	void createImageFile(); // Creates the file holding the BMP.

private:
	// The different complex plotting functions available.
	complexType func1(complexType, complexType);
	complexType func2(complexType, complexType);
	complexType func3(complexType, complexType);
	complexType func4(complexType);
	complexType func5(complexType);
	complexType func6(complexType);
	complexType func7(complexType);
	complexType func8(complexType);
	complexType func9(complexType);
	complexType func10(complexType);
	complexType func11(complexType);

	void setHSV(complexType, double&, double&, double&); // Sets hue, saturation, and brightness.

	void setRGB(double, double, double, int&, int&, int&); // Converts hue, sat, and  val to RGB.

	static const int W_MIN = 300, W_MAX = 12000;
	static const int H_MIN = 300, H_MAX = 12000;
	static const int FUNC_LIMIT = 11; // How many limits currently available.
	static const double PI;
	static const double E;

	string fileName; // What the file will be named.
	int funcNumber;
};

#endif