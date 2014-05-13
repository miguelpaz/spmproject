#include "genePool.h"

genePool::genePool()
{
    //ctor
}

void genePool::setup()
{
    popsize=15;
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

bool comphelper(Individual i, Individual j)
// helper function for sorting
{
    return (i.averageScore() > j.averageScore());
}

void genePool::nextGen()
{

    generation++;
    icount=0;
    // Add genetic selection - find the top 10 individuals...
    sort(individuals.begin(),individuals.end(),comphelper);
    while(individuals.size()>10)
        {individuals.erase(individuals.begin() +10);};
    cout << individuals.size() << endl;
}



