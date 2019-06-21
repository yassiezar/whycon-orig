#ifndef __CNECKLACE_H__
#define __CNECKLACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int id;
    int rotation;
    int hamming;
}SNecklace;

class CNecklace{
    public:
    CNecklace(int bits,int minimalHamming);
    ~CNecklace();
    SNecklace get(int sequence);
	SNecklace get(int sequence, float conf);
    int printAll(int a[]);
	int verifyHamming(int a[],int bits,int len);
	int getEstimatedID();
	float observationEstimation(float confidence);


    private:
	bool debug;
    SNecklace *idArray;
    SNecklace unknown;
	int length;
	int idLength;
	int maxID;
    int* finalList;
	int getHamming(int a, int b);
	int getMinimalHamming(int a,int len);
	float* probArray;
};
#endif
