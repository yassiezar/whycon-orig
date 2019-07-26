#ifndef __CNECKLACE_H__
#define __CNECKLACE_H__

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

namespace Whycon
{
    typedef struct
    {
        int id, rotation, hamming;
    }SNecklace;

    class CNecklace{
    public:
        CNecklace(size_t bits, int minimalHamming);
        SNecklace get(int sequence);
        int printAll(int a[]);
        int verifyHamming(int a[],int bits,int len);
        int getHamming(int a, int b);
        int getMinimalHamming(int a,int len);

    private:
        std::vector<SNecklace> ids;
        SNecklace unknown;
        int* finalList;
    };
}

#endif
