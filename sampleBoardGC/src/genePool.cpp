#include "genePool.h"

genePool::genePool()
{
    //ctor
}

void genePool::setup()
{
    popsize=100;
    icount=0;
    generation=0;
    for (int i=0;i<popsize;i++){
        Individual in;
        in.setup();
        individuals.push_back(in);
    }
}

Individual genePool::getNext()
// return the next individual in the pool.
{
    Individual in=individuals[icount];
    icount++;
    if (icount>=popsize) {
            nextGen();
    }
    return in;
}

void genePool::nextGen()
{
    generation++;
    icount=0;
    // Add genetic selection and mating process here.
}
