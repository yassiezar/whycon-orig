#ifndef CIMAGE_H
#define CIMAGE_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <fstream>

/**
@author Tom Krajnik
*/
namespace Whycon
{
    class CRawImage
    {
    public:
        CRawImage(size_t, size_t);
        CRawImage(size_t, size_t, unsigned char*);
        ~CRawImage();

        void saveBmp(const char* name);
        void saveBmp();
        bool loadBmp(const char* name);

        void swap();
        void swapRGB();

        void plotLine(size_t x, size_t y);
        void plotCenter();

        int  getSaveNumber();

        double getOverallBrightness(bool upperHalf);

        int palette;

    private:
        const std::vector<unsigned char> sth = {66,77,54,16,14,0,0,0,0,0,54,0,0,0,40,0,0,0,128,2,0,0,224,1,0,0,1,0,24,0,0,0,0,0,0,16,14,0,18,11,0,0,18,11,0,0,0,0,0,0,0,0,0,0};
        std::vector<unsigned char> header;

        size_t width;
        size_t height;
        size_t size;
        const int bpp = 3;
        unsigned char* imgData;

        bool ownData;
        int numSaved;

    };
}

#endif
