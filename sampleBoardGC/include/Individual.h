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
        float score;
        Individual mateWith(Individual other);
        int64_t dna[IND_SIZE];
    protected:
    private:
};

#endif // INDIVIDUAL_H
