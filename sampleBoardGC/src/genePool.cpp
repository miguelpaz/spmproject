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
    repopool=10;
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
    vector<Individual> reproducers;

    generation++;
    icount=0;
    // Add genetic selection - find the top 10 individuals...
    sort(individuals.begin(),individuals.end(),comphelper);
    for(int i = 0; i<repopool; i++) {
        reproducers.push_back(individuals[i]);
    }
    while(individuals.size()>0) {
            individuals.erase(individuals.begin());
    }
    for (int i = 0; i<popsize; i++) {
        int a = ofRandom(repopool);
        int b = ofRandom(repopool);
        individuals.push_back(reproducers[a].reproduce_with(reproducers[b]));
    }
}



