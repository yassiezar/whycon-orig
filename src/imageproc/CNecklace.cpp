#include <whycon/imageproc/CNecklace.hpp>

namespace Whycon
{
    CNecklace::CNecklace(size_t bits, int minimalHamming = 1) : ids(static_cast<size_t>(pow(2, bits), 0))
    {
        int currentID = 0;
        int tempID,bit,rotations;
        int minHam = 1000;
        int hamindex = 1000;
        int ham = 1000;

        /*for every possible id*/
        for(size_t id = 0; id < ids.size(); id++)
        {
            /*check if there is a lower number that could be created by bitshifting it*/
            tempID  = id;
            rotations = 0;
            int cached [bits - 1];
            bool isSymmetrical = false;
            minHam = 1000;
            do{
                hamindex = getMinimalHamming(tempID,id);
                ham = getHamming(tempID,hamindex);
                if (minHam > ham){
                    minHam = ham;
                    if (minHam == 0){
                        ids[id].id = ids[hamindex].id;
                        ids[id].rotation = ids[hamindex].rotation + rotations;
                    }
                }
                bit = tempID%2;
                tempID=tempID/2+bit*pow(2, bits - 1);

                if(bit || id == 0)
                {
                    for (int i = 0; i < rotations && !isSymmetrical; i++)
                    {
                        // check for symmetry
                        if (cached[i] == tempID){
                            isSymmetrical = true;
                        }
                    }
                }
                cached[rotations] = tempID;
            }while (rotations++ < bits - 1 && !isSymmetrical);
            if (minHam >= minimalHamming && !isSymmetrical)
            {
                ids[id].id = currentID++;
                ids[id].rotation = 0;
                ids[id].hamming = minHam;
            }
            else if (minHam > 0)
            {
                ids[id].id = -1;
                ids[id].rotation = -1;
                ids[id].hamming = minHam;
            }
            if(isSymmetrical)
            {
                ids[id].id = -1;
                ids[id].rotation = -1;
            }
        }

        unknown.id = -1;
        unknown.rotation = -1;
    }

    int CNecklace::getHamming(int a, int b)
    {
        int aa = a;
        int bb = b;
        int ham = 0;
        do {
            if (a%2 != b%2) ham++;
            a = a/2;
            b = b/2;
        }while (a > 0 || b > 0);
        return ham;
    }

    int CNecklace::getMinimalHamming(int a,int len)
    {
        int minDist = 10000;
        int mindex = 10000;
        for (int i = 1;i<len;i++)
        {
            if (get(i).rotation == 0)
            {
                int m = getHamming(a,i);
                if (minDist > m){
                    minDist = m;
                    mindex = i;
                    //if (minDist < 3) printf("%i is same as %i\n",a,i);
                }

            }
        }
        return mindex;
    }

    int CNecklace::verifyHamming(int a[],int bits,int len)
    {
        int overAll = 10000;
        for (int i = 0;i<len;i++){
            for (int j = 0;j<len;j++)
            {
                int minimal = 10000;
                if (i!=j)
                {
                    int bit;
                    int tempID = a[j];
                    int distance;
                    for (int r = 0;r<bits;r++){
                        distance = getHamming(a[i],tempID);
                        if (minimal > distance) minimal = distance;
                        bit = tempID%2;
                        tempID=tempID/2+bit*pow(2, bits - 1);
                    }
                }
                if (overAll > minimal) overAll = minimal;
            }
        }
        return overAll;
    }

    SNecklace CNecklace::get(int sequence)
    {
        if (sequence > 0 && sequence < ids.size()) return ids[sequence];
        return unknown;
    }
}
