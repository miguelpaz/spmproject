#ifndef GENEPOOL_H
#define GENEPOOL_H
#include <algorithm>
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
        int repopool;
    protected:
    private:
        vector<Individual> individuals;
        bool comp(Individual i, Individual j);
};

#endif // GENEPOOL_H
