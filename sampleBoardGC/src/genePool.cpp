#include "genePool.h"

genePool::genePool()
{
    //ctor
}

void genePool::setup()
{
    popsize=20;
    repopool=10;
    icount=-1;
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
    icount++;
    if (icount>=popsize) {
            nextGen();
    }
    return individuals[icount];
}

bool comphelper(Individual i, Individual j)
// helper function for sorting
{
    return (i.averageScore() > j.averageScore());
}

Individual genePool::weightedRandomIndividual(vector<Individual> r) {
    float total_score = 0;
    float cs = 0;
    float ts;
    int ci = 0;
    Individual in;

    for (int i=0; i<r.size(); i++) {

        total_score = total_score + r[i].averageScore();
    }

    ts = ofRandom(total_score);

    while(cs<ts) {
        in = r[ci];
        cs = cs + in.averageScore();
        ci++;
    }

    return in;
    };

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
        Individual a = weightedRandomIndividual(reproducers);
        Individual b = weightedRandomIndividual(reproducers);
        Individual in = a.reproduce_with(b);
        in.mutate();
        individuals.push_back(in);
    }
}

void genePool::addScore(float s) {
    individuals[icount].addScore(s);
    }



