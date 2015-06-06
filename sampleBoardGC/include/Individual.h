#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "ofMain.h"

#define IND_SIZE 8
#define SMP_PROB 3
class Individual
{
    public:
        Individual();
        void setup();
        void addScore(float s);
        Individual mateWith(Individual other);
        int64_t dna[IND_SIZE];
        float averageScore();
        Individual reproduce_with(Individual other);
    protected:
    private:
        vector<float> score;
        float averagescore;

};

#endif // INDIVIDUAL_H
