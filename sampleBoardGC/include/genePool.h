#ifndef GENEPOOL_H
#define GENEPOOL_H
#include "ofMain.h"
#include "Individual.h"

class genePool
{
    public:
        genePool();
        void setup();
        void nextGen();
        Individual getNext();
        int generation;
        int popsize;
        int icount;
    protected:
    private:
        vector<Individual> individuals;
};

#endif // GENEPOOL_H
