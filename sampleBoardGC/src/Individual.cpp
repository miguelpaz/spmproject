#include "Individual.h"

Individual::Individual()
{
    //ctor
    averagescore=-1;
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

void Individual::addScore(float s)
{
    score.push_back(s);
}

float Individual::averageScore()
// a memoized calculation of the average score...
{
    if (averagescore<0)
        averagescore = 0;
        {
            float sum=0;
            if (score.size() > 0 ){
                for(int i=0;i<score.size();i++)
                {
                    sum+=score[i];
                }
                averagescore=sum/score.size();
            }
            else {
                averagescore = 0;
            }
        }
    return averagescore;
}

Individual Individual::reproduce_with(Individual other) {
    Individual ni = Individual();
    int op = ofRandom(64);
    int64_t mask = INT64_MAX << op;
    for (int i; i<IND_SIZE; i++) {
        ni.dna[i] = (dna[i] & mask) | (other.dna[i] & ~mask);
    }
    return ni;
    }
