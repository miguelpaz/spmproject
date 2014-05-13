#include "Individual.h"

Individual::Individual()
{
    //ctor
}

void Individual::setup()
{
    averagescore=-1;
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

void Individual::addScore(float s)
{
    score.push_back(s);
}

float Individual::averageScore()
// a memoized calculation of the average score...
{
    if (averagescore<0)
        {
            float sum=0;
            for(int i=0;i<score.size();i++)
            {
                sum+=score[i];
            }
            averagescore=sum/score.size();
        }
    return averagescore;
}

