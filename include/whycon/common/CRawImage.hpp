#ifndef CIMAGE_H
#define CIMAGE_H

#include <cstdlib>
#include <cstdio>
#include <cstring>

/**
@author Tom Krajnik
*/
namespace Whycon
{
    typedef struct
    {
        size_t width, height, bpp, size;
    } ImageParams;

    class CRawImage
    {
    public:

        CRawImage(size_t wi, size_t he);
        CRawImage(ImageParams params);
        CRawImage(ImageParams params, unsigned char* datai);
        CRawImage(size_t wi, size_t he, unsigned char* data);
        ~CRawImage();

/*
        void saveBmp(const char* name);
        void saveBmp();
        bool loadBmp(const char* name);
*/
        void swap();
        void swapRGB();

        void plotLine(int x,int y);
        void plotCenter();

        int  getSaveNumber();

        double getOverallBrightness(bool upperHalf);

    private:
        size_t width, height, size, bpp, numSaved;
        int palette;

        unsigned char header[122];
        unsigned char* data;

        bool ownData;

        const unsigned char sth[122] = {66,77,54,16,14,0,0,0,0,0,54,0,0,0,40,0,0,0,128,2,0,0,224,1,0,0,1,0,24,0,0,0,0,0,0,16,14,0,18,11,0,0,18,11,0,0,0,0,0,0,0,0,0,0};
    };
}

#endif
