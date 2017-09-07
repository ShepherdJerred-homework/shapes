#pragma once
#include<iostream>
#include<fstream>
#include"Color.h"

using namespace std;

struct FileHeader {
    char fileType[2];
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
};

struct InfoHeader {
    unsigned long biSize;
    unsigned long biWidth;
    unsigned long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    unsigned long biXPixelsPerMeter;
    unsigned long biYPixelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
    unsigned long pixelCount;
};

class Image {
public:
    Image(int width, int height, Color fillColor);
    void writeToFile(const char* FileName) const;
    void setPixelColor(int x, int y, Color color);
    void addLine(int xStart, int yStart, int xEnd, int yEnd, Color color);
    int width();
    int height();
private:
    FileHeader fileHeader;
    InfoHeader infoHeader;
    Color* pixels;

    void initializeFileHeader(int height, int width);
    void initializeInfoHeader(int height, int width);
    void writeFileHeader(ofstream& fout) const;
    void writeInfoHeader(ofstream& fout) const;
};
