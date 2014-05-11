#include "Individual.h"

Individual::Individual()
{
    //ctor
}

void Individual::setup()
{
    for(int i=0;i<IND_SIZE;i++)
    {
        dna[i]=0;
        for(int j=0;j<64;j++){
            float rnd=ofRandom(100);
            dna[i]=dna[i]<<1;
            if (rnd<=SMP_PROB) {
                    dna[i]=dna[i]|1;
            }
        }
    }
}

