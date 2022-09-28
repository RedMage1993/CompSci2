// Fritz Ammon
// Section 1002
// Assignment #9
// File: complexPlot.cpp
// Description: The complexPlot class definition.
// Is able to graph/plot complex images using RGB
// triplets from HSV based on a complex number.

#include "complexPlot.h"

const double complexPlot::PI = 3.14159265358;
const double complexPlot::E = 2.71828182845;

complexPlot::complexPlot() :
	bitmapImage(0, 0)
{
	fileName = "";
	funcNumber = 0;
}

complexPlot::complexPlot(int w, int h, int fnNo, string fName) :
	bitmapImage() // Initialize width and height to 0.
{
	double aspRat;

	fileName = ""; // Set to empty for now.

	if (w < W_MIN || w > W_MAX)
		cout << "Error, width must be between " << W_MIN
			 << " and " << W_MAX << ".\n";
	
	if (h < H_MIN || h > H_MAX)
		cout << "Error, height must be between " << H_MIN
			 << " and " << H_MAX << ".\n";

	if (h != 0)
	{
		aspRat = w / h;

		if (aspRat < 0.50 || aspRat > 2.0)
			cout << "Error, invalid aspect ratio.  Must be between 0.5 and 2.0\n";
	}

	if (fName != "")
	{
		if (fName.size() <= 4)
			cout << "Error, invalid file name.\n";
		else if (fName.substr(fName.size() - 4, 4) != ".bmp") // Compare last four chars.
			cout << "Error, file name must be '.bmp' extension.\n";
		else
		{
			setSize(w, h);
			fileName = fName;
		}
	}

	funcNumber = fnNo;
}

complexPlot::complexPlot(const complexPlot& copy)
{
	int w = copy.getWidth(), h = copy.getHeight();

	setSize(w, h);

	// Execute deep copy of BMP.
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
			setPixel(x, y, copy.getPixel(x, y));
	}
}

void complexPlot::readFileName()
{
	string fName;
	bool done = false;

	do
	{
		cout << "Enter Output File Name: ";
		cin >> fName;

		if (fName.size() <= 4)									// Make sure not empty
			cout << "Error, invalid file name.\n";				// before taking substring.
		else if (fName.substr(fName.size() - 4, 4) != ".bmp")
			cout << "Error, file name must be '.bmp' extension.\n";
		else
		{
			fileName = fName;
			cout << endl;
			break;
		}

		cout << "Please re-enter.\n";
	} while (!done); // I prefer not to use true as an expression.
}

void complexPlot::setFileName(string fName)
{
	if (fName.size() <= 4)
		cout << "Error, invalid file name.\n";
	else if (fName.substr(fName.size() - 4, 4) != ".bmp")
		cout << "Error, file name must be '.bmp' extension.\n";
	else
		fileName = fName;
}

string complexPlot::getFileName() const
{
	return fileName;
}

void complexPlot::readImageSize()
{
	int w, h;
	double aspRat;
	bool done = false;

	do
	{
		cout << "Enter image size (width, height): ";
		cin >> w >> h;

		if (w < W_MIN || w > W_MAX)
		{
			cout << "Error, width must be between " << W_MIN
				 << " and " << W_MAX << ".\n";
			cout << "Please re-enter.\n";
		}
		
		if (h < H_MIN || h > H_MAX)
		{
			cout << "Error, height must be between " << H_MIN
				 << " and " << H_MAX << ".\n";
			cout << "Please re-enter.\n";
		}
		
		if (h != 0)
		{
			aspRat = w / h;

			if (aspRat < 0.50 || aspRat > 2.0)
			{
				cout << "Error, invalid aspect ratio.  Must be between 0.5 and 2.0\n";
				cout << "Please re-enter.\n";
			}
			else
			{
				setSize(w, h);
				cout << endl;
				break;
			}
		}
	} while (!done); // I prefer not to use true as an expression.
}

void complexPlot::setImageSize(int w, int h)
{
	double aspRat;

	if (w < W_MIN || w > W_MAX)
		cout << "Error, width must be between " << W_MIN
				<< " and " << W_MAX << ".\n";
	else if (h < H_MIN || h > H_MAX)
		cout << "Error, height must be between " << H_MIN
				<< " and " << H_MAX << ".\n";
	
	if (h != 0)
	{ // Don't try to do division by zero.
		aspRat = w / h;

		if (aspRat < 0.50 || aspRat > 2.0)
			cout << "Error, invalid aspect ratio.  Must be between 0.5 and 2.0\n";
		else
			setSize(w, h);
	}
}

int complexPlot::functionCount()
{
	return FUNC_LIMIT;
}

int complexPlot::getFunctionNumber()
{
	return funcNumber;
}

void complexPlot::setFunctionNumber(int fnNo)
{
	if (fnNo < 0 || fnNo > FUNC_LIMIT)
		cout << "Error, function number must be between 0 and "
			 << FUNC_LIMIT << ".\n";
	else
		funcNumber = fnNo;
}

void complexPlot::readFunctionNumber()
{
	int fnNo;
	bool done = false;

	do
	{
		cout << "Enter Function Number (1 - 11): "; // PDF said (1 - 11)...why?
		cin >> fnNo;

		if (fnNo < 0 || fnNo > FUNC_LIMIT)
			cout << "Error, function number must be between	0 and "
				 << FUNC_LIMIT << ".\n";
		else
		{
			funcNumber = fnNo;
			cout << endl;
			break;
		}

		cout << "Please re-enter.\n";
	} while (!done); // I prefer not to use true as an expression.
}

void complexPlot::createComplexPlotImage()
{
	int w = getWidth(), h = getHeight();
	int divW = w - 1, divH = h - 1;
	double im, re;
	complexType c, v;
	double hue = 0.0, sat = 0.0, val = 0.0;
	int r = 0, g = 0, b = 0;

	// Go through every pixel and compute that pixel's
	// color based on an algorithm.
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			im = 3.0 - 6.0 * y / divH;
			re = 3.0 - 6.0 * x / divW;

			c.setComplex(re, im);
			v = c;

			switch (funcNumber)
			{
			case 1: v = func1(v, c);
				break;
			case 2: v = func2(v, c);
				break;
			case 3: v = func3(v, c);
				break;
			case 4: v = func4(v);
				break;
			case 5: v = func5(v);
				break;
			case 6: v = func6(v);
				break;
			case 7: v = func7(v);
				break;
			case 8: v = func8(v);
				break;
			case 9: v = func9(v);
				break;
			case 10: v = func10(v);
				break;
			case 11: v = func11(v);
				break;
			}

			setHSV(v, hue, sat, val); // Get HSV.
			setRGB(hue, sat, val, r, g, b); // HSV to RGB.
			setPixelRGB(x, y, r, g, b); // Set pixel to RGB.
		}
	}
}

void complexPlot::createImageFile()
{
	saveToBitmapFile(fileName, 24);
}

complexType complexPlot::func1(complexType z, complexType c)
{
	return z * z + c;
}

complexType complexPlot::func2(complexType z, complexType c)
{
	return func1(z, z) + c;
}

complexType complexPlot::func3(complexType z, complexType c)
{
	return func2(z, z) + c;
}

complexType complexPlot::func4(complexType z)
{
	return (complexType(PI) * z).cose();
}

complexType complexPlot::func5(complexType z)
{
	return z * z + complexType(1.0);
}

complexType complexPlot::func6(complexType z)
{
	return (z * z * z - complexType(1.0)).sine() / z;
}

complexType complexPlot::func7(complexType z)
{
	return func6(func8(z) + complexType(1.0) / func8(z));
}

complexType complexPlot::func8(complexType z)
{
	complexType two(2.0);
	complexType ima(0.0, 1.0);
	complexType zSq = z * z;

	return func9(((zSq - complexType(1.0)) *
		(z - two - ima) *
		(z - two - ima)) /
		(zSq + two + two * ima));
}

complexType complexPlot::func9(complexType z)
{
	return z + complexType(1.0) / z;
}

complexType complexPlot::func10(complexType z)
{
	return z.cSqrt();
}

complexType complexPlot::func11(complexType z)
{
	complexType one(1.0);
	complexType zSq = z * z;

	return (zSq + one) / (zSq - one);
}

void complexPlot::setHSV(complexType v, double& hue, double& sat, double& val)
{
	double dPi = 2.0 * PI, dK;
	double m, k;
	double ranges = 0.0, rangee = 1.0;

	hue = v.angle();
	while (hue < 0.0)
		hue += dPi;
	hue /= dPi;

	m = v.abs();
	while (m > rangee)
	{
		ranges = rangee;
		rangee *= E;
	}

	k = (m - ranges) / (rangee - ranges);
	dK = 2.0 * k;

	if (k < 0.5)
		sat = val = dK;
	else
		sat = val = 1.0 - 2.0 * (k - 0.5);

	sat = 1.0 - pow(1.0 - sat, 3.0);
	sat = 0.4 + 0.6 * sat;

	val = 1.0 - val;
	val = 1.0 - pow(1.0 - val, 3.0);
	val = 0.6 + 0.4 * val;
}

void complexPlot::setRGB(double hue, double sat, double val, int& r, int& g, int& b)
{
	double z, f, p, q, t;
	double red, green, blue;
	double hueSix;

	if (sat == 0.0)
		r = g = b = val;
	else
	{
		if (hue == 1.0)
			hue = 0.0;

		hueSix = 6.0 * hue;
		z = floor(hueSix);
		f = hueSix - z;
		p = val * (1.0 - sat);
		q = val * (1.0 - sat * f);
		t = val * (1.0 - sat * (1.0 - f));

		switch (static_cast<int> (z))
		{
		case 0:
			red = val;
			green = t;
			blue = p;
			break;
		case 1:
			red = q;
			green = val;
			blue = p;
			break;
		case 2:
			red = p;
			green = val;
			blue = t;
			break;
		case 3:
			red = p;
			green = q;
			blue = val;
			break;
		case 4:
			red = t;
			green = p;
			blue = val;
			break;
		case 5:
			red = val;
			green = p;
			blue = q;
		}

		// Scale RGB.
		red *= 256.0;
		green *= 256.0;
		blue *= 256.0;

		// Make sure valid RGB.
		r = min(red, 255.0);
		g = min(green, 255.0);
		b = min(blue, 255.0);
	}
}