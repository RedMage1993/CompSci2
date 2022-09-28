// Fritz Ammon
// Assignment No. 8
// File: imageType.cpp
// Description: imageType class definition

#include "imageType.h"

imageType::imageType(string inFileName, int inWidth, int inHeight, string inTitle)
    : bitmapImage(inWidth, inHeight)
{
   if (inFileName != "")
   {
       if (!loadFromBitmapFile(inFileName.c_str()))
           cout << "Error, no such file.\n";
   }
   
   fileName = inFileName;
   title = inTitle;
}
    
void imageType::colorToBW()
{
    int w = getWidth(), h = getHeight();
    int c; // RGB color.

    if (!((w | 0) && (h | 0))) // If either is 0, error.
        cout << "Error, invalid bitmap.\n";
    else
    {
       for (int y = 0; y < h; y++)
       {
           for (int x = 0; x < w; x++)
           {
               c = getPixel(x, y); // Only need one value since all the same.
               c = (getRed(c) + getGreen(c) + getBlue(c)) / 3;
               setPixelRGB(x, y, c, c, c);
           }
       }
    }
}
    
void imageType::resize(double percentage)
{
    percentage /= 100.0;

    resize(getWidth() * percentage,
	getHeight() * percentage);
}
    
void imageType::resize(int newWidth, int newHeight)
{
	bitmapImage tempImage;
	int w = getWidth(), h = getHeight();
	double xRatio, yRatio;

	 if (!((w | 0) && (h | 0)))
		cout << "Error, no image to convert to resize.\n";
	 else if (!((newWidth | 0) && (newHeight | 0)) ||
		 (newWidth > W_MAX || newHeight > H_MAX) ||
		 (newWidth < 0 || newHeight < 0))
		cout << "Error, invalid resize parameters.\n";
	else
	{
		tempImage.setSize(newWidth, newHeight);
		xRatio = static_cast<double> (w) / newWidth;
		yRatio = static_cast<double> (h) / newHeight;

		// Determine new x,y colors.
		for (int y = 0; y < newHeight; y++)
		{
			for (int x = 0; x < newWidth; x++)
			{
				tempImage.setPixel(x, y,
					getPixel(floor(x * xRatio), floor(y * yRatio)));
			}
		}

		setSize(newWidth, newHeight); // Set current image to new size.
		
		// Replace current image with previously determined pixels.
		for (int y = 0; y < newHeight; y++)
		{
			for (int x = 0; x < newWidth; x++)
				setPixel(x, y, tempImage.getPixel(x, y));
		}
	}
}
    
void imageType::smooth()
{
    int w = getWidth(), h = getHeight();
    int c;
    int sr, sg, sb;
	bitmapImage tempImage(w, h);
    
    if (!((w | 0) && (h | 0)))
		cout << "Error, no image to convert to smooth.\n";
	else
	{
		w -= 5;
		h -= 5;

		//tempImage.fillRect(0, 0, 4, 2, 0) for those weird pixels at top left

		for (int y = 5; y < h; y++)
		{
			for (int x = 5; x < w; x++)
			{
				sr = sg = sb = 0;
				for (int sy = y - 5; sy < y - 5 + 11; sy++)
				{ // Take average of all 121 pixels around target pixel.
					for (int sx = x - 5; sx < x - 5 + 11; sx++)
					{
						c = getPixel(sx, sy);

						sr += getRed(c);
						sg += getGreen(c);
						sb += getBlue(c);
					}
				}

				tempImage.setPixelRGB(x, y, sr / 121.0, sg / 121.0, sb / 121.0);
			}
		}

		w += 5;
		h += 5;

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
				setPixel(x, y, tempImage.getPixel(x, y));
		}
	}
}
    
void imageType::brightness(double percentage)
{
    int w = getWidth(), h = getHeight();
    int c;
    
    if (!((w | 0) && (h | 0)))
        cout << "Error, no image to convert to brighten.\n";
	else if (abs(percentage) > 100.0)
		cout << "Error, invalid brightness percentage.\n";
    else
    {
        percentage /= 100.0;
		percentage += 1.0;

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            { // Brighten all pixels by percentage.
                c = getPixel(x, y);
                
                setPixelRGB(x, y,
                    max(0.0, min(255.0, getRed(c) * percentage)),
                    max(0.0, min(255.0, getGreen(c) * percentage)),
                    max(0.0, min(255.0, getBlue(c) * percentage)));
            }
        }
    }
}
    
void imageType::RGBshift(color targetColor)
{
    typedef int (bitmapImage::*getColorFn) (int) const;
    getColorFn target, colorA, colorB;
    int w = getWidth(), h = getHeight();
    int c;
    int shiftAmt; // Where target needs to be in hex.
    
    if (!((w | 0) && (h | 0)))
    	cout << "Error, no image to convert to color shift.\n";
    else
    {  
    	// Determine which function needs to be called here and
    	// create a function pointer to avoid checking yet another
    	// conditional width * height times. :D
    
    	switch (targetColor)
    	{
    	case RED:
    		target = &bitmapImage::getRed;
    		colorA = &bitmapImage::getGreen;
    		colorB = &bitmapImage::getBlue;
    		shiftAmt = 16; // 2 bytes
    		break;
    	case GREEN:
    		target = &bitmapImage::getGreen;
    		colorA = &bitmapImage::getRed;
    		colorB = &bitmapImage::getBlue;
    		shiftAmt = 8; // 1 byte
    		break;
    	case BLUE:
    		target = &bitmapImage::getBlue;
    		colorA = &bitmapImage::getRed;
    		colorB = &bitmapImage::getGreen;
    		shiftAmt = 0; // no shift
    		break;
    	}
    
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				c = getPixel(x, y);
				setPixel(x, y,
				    max(0, min(255,
				    (2 * (this->*target)(c) - (this->*colorA)(c) -
				    (this->*colorB)(c)))) << shiftAmt);
			}
		}
    }
}
    
void imageType::rotate(double degrees, int background)
{
	double radians;
	int bmWidth, bmHeight;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int minx, miny;
	int maxx, maxy;
	double cosine, sine;
	int sourceX, sourceY;
	int w, h;
	bitmapImage tempImage;

	bmWidth = getWidth();
	bmHeight = getHeight();

	if (!((bmWidth | 0) && (bmHeight | 0)))
		cout << "Error, no image to convert to rotate.\n";
	else if (abs(degrees) > 180.0)
		cout << "Error, invalid rotation percentage.\n";
	else if (background < 0 || background > 0xFFFFFF)
		cout << "Error, background color.\n";
	else
	{
		radians = 3.14159265358 * degrees / 180.0;

		cosine = cos(radians);
		sine = sin(radians);

		// We could have saved calculation time here but let's
		// stay consistent and precise.
		x1 = static_cast<int> (-bmHeight * sine);
		y1 = static_cast<int> (bmHeight * cosine);
		x2 = static_cast<int> (bmWidth * cosine - bmHeight * sine);
		y2 = static_cast<int> (bmHeight * cosine + bmWidth * sine);
		x3 = static_cast<int> (bmWidth * cosine);
		y3 = static_cast<int> (bmWidth * sine);

		minx = min(0, min(x1, min(x2, x3)));
		miny = min(0, min(y1, min(y2, y3)));
		maxx = max(x1, max(x2, x3));
		maxy = max(y1, max(y2, y3));

		w = maxx - minx;
		h = maxy - miny;

		tempImage.setSize(w, h);
		tempImage.fillWith(background); // Cover pixels that will be empty.

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				// Calculate and perform reverse-wise coordinate finding.
				sourceX = static_cast<int> ((x + minx) * cosine + (y + miny) * sine);
				sourceY = static_cast<int> ((y + miny) * cosine - (x + minx) * sine);

				if (sourceX >= 0 && sourceX < bmWidth &&
				    sourceY >= 0 && sourceY < bmHeight)
				{
					tempImage.setPixel(x, y,
						getPixel(sourceX, sourceY));
				}
			}
		}

		setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
				setPixel(x, y, tempImage.getPixel(x, y));
		}
	}
}
    
void imageType::crop(int x1, int y1, int x2, int y2)
{
	int w = getWidth(), h = getHeight();
	int nw, nh;
	bitmapImage tempImage;

	if (!((x1 | 0) && (y1 | 0)) &&
		x2 == w && y2 == h)
		return; // Same size, no need to modify.

	if (x1 >= x2 || y1 >= y2)
		cout << "Error, invalid crop points.\n";
	else if (x1 < 0 || x2 > w || y1 < 0 || y2 > h)
		cout << "Error, crop parameters.\n";
	else
	{
		// Calculate new dimensions.
		nw = x2 - x1;
		nh = y2 - y1;

		tempImage.setSize(nw, nh);
		for (int y = y1 - 1; y < y2; y++)
		{
			for (int x = x1 - 1; x < x2; x++)
			{ // Only grab what user asks for.
				tempImage.setPixel(x - (x1 - 1), y - (y1 - 1),
					getPixel(x, y));
			}
		}		

		setSize(nw, nh);
		for (int y = 0; y < nh; y++)
		{
			for (int x = 0; x < nw; x++)
			{
				setPixel(x, y, tempImage.getPixel(x, y));
			}
		}
	}
}
