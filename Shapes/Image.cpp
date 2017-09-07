#include "stdafx.h"
#include "Image.h"

Image::Image(int width, int height, Color fillColor) {
    initializeFileHeader(width, height);
    initializeInfoHeader(width, height);

    pixels = new Color[infoHeader.pixelCount];

    int i = 0;
    for (unsigned int row = 0; row < infoHeader.biHeight; row++) {
        for (unsigned int column = 0; column < infoHeader.biWidth; column++ , i++) {
            pixels[i] = fillColor;
        }

    }
}

void Image::setPixelColor(int x, int y, Color color) {
    if (x < infoHeader.biWidth && y < infoHeader.biHeight) {
        int index = y * infoHeader.biWidth + x;
        pixels[index] = color;
    }
}

void Image::addLine(int xStart, int yStart, int xEnd, int yEnd, Color color) {
    //y = mx + b
    //y - y0 = m( x - x0 )
    //m=(y-y0)/(x-x0)
    //x = (y-b)/m;
    if (xStart != xEnd) {
        double m = ((double)yStart - (double)yEnd) / ((double)xStart - (double)xEnd);
        double b = yStart - (m * xStart);
        if (abs(yStart - yEnd) < abs(xStart - xEnd)) {
            int x1 = (xStart < xEnd) ? xStart : xEnd;
            int x2 = (xStart < xEnd) ? xEnd : xStart;
            //change in x is greater than change in y
            for (int x = x1; x <= x2; x++) {
                int y = floor((m * x) + b);
                setPixelColor(x, y, color);
            }
        } else {
            //change in y is greater than change in x
            int y1 = (yStart < yEnd) ? yStart : yEnd;
            int y2 = (yStart < yEnd) ? yEnd : yStart;
            //change in x is greater than change in y
            for (int y = y1; y <= y2; y++) {
                int x = floor((y - b) / m);
                setPixelColor(x, y, color);
            }
        }
    } else {
        int y1 = (yStart < yEnd) ? yStart : yEnd;
        int y2 = (yStart < yEnd) ? yEnd : yStart;
        int x = xStart;
        for (int y = y1; y <= y2; y++) {
            setPixelColor(x, y, color);
        }
    }
}

void Image::initializeFileHeader(int width, int height) {
    int paddedSize = height * (width / 8 + (4 - (width / 8 % 4)));

    fileHeader.fileType[0] = 'B';
    fileHeader.fileType[1] = 'M';
    fileHeader.bfSize = paddedSize + 54;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = 54;
}

void Image::initializeInfoHeader(int width, int height) {
    infoHeader.biSize = 40;
    infoHeader.biWidth = width;
    infoHeader.biHeight = height;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = 0;
    infoHeader.biXPixelsPerMeter = 2834;
    infoHeader.biYPixelsPerMeter = 2834;
    infoHeader.biClrUsed = 0;
    infoHeader.biClrImportant = 0;

    infoHeader.pixelCount = infoHeader.biHeight * infoHeader.biWidth;
}


void Image::writeToFile(const char* FileName) const {
    ofstream fout;
    fout.open(FileName, ios_base::binary); //destroys the old file

    writeFileHeader(fout);
    writeInfoHeader(fout);

    fout.seekp(fileHeader.bfOffBits); //should be 54
    int i = 0;
    for (unsigned int row = 0; row < infoHeader.biHeight; row++) {
        for (unsigned int column = 0; column < infoHeader.biWidth; column++ , i++) {
            fout.write((char*)&(pixels[i]), 3);
        }

        unsigned int b = infoHeader.biWidth * 3;
        unsigned char junk = 0;

        while (b % 4 != 0) {
            fout.write((char*)&junk, 1);
            b = b + 1;
        }
    }
    fout.close();
}

void Image::writeFileHeader(ofstream& fout) const {
    fout.seekp(0);
    fout.write(fileHeader.fileType, 2);
    fout.write((char*)&fileHeader.bfSize, 4);
    fout.write((char*)&fileHeader.bfReserved1, 2);
    fout.write((char*)&fileHeader.bfReserved2, 2);
    fout.write((char*)&fileHeader.bfOffBits, 4);
}

void Image::writeInfoHeader(ofstream& fout) const {
    fout.seekp(14);
    fout.write((char*)&infoHeader.biSize, 4);
    fout.write((char*)&infoHeader.biWidth, 4);
    fout.write((char*)&infoHeader.biHeight, 4);
    fout.write((char*)&infoHeader.biPlanes, 2);
    fout.write((char*)&infoHeader.biBitCount, 2);
    fout.write((char*)&infoHeader.biCompression, 4);
    fout.write((char*)&infoHeader.biSizeImage, 4);
    fout.write((char*)&infoHeader.biXPixelsPerMeter, 4);
    fout.write((char*)&infoHeader.biYPixelsPerMeter, 4);
    fout.write((char*)&infoHeader.biClrUsed, 4);
    fout.write((char*)&infoHeader.biClrImportant, 4);
}

int Image::width() {
    return infoHeader.biWidth;
}

int Image::height() {
    return infoHeader.biHeight;
}
