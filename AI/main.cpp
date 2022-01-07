#include "geneticAlgorithm.h"


int main()
{

    Generation gen;
    /*
    //USER INPUT
    int populationCount,matingProcess,generations;
    float mutationChance;

    do{
        cout << "Input how many Chromosome in a Population : ";
        cin >> populationCount;
    }while(populationCount < 2);
    do{
        cout << "Input how many Mating Process : ";
        cin >> matingProcess;
    }while(matingProcess < 1);
    do{
        cout << "Input mutation chance (less than 1. example : 0.03) : ";
        cin >> mutationChance;
    }while(mutationChance >=1 || mutationChance < 0);

    do{
        cout << "Input how many generations : ";
        cin >> generations;
    }while(generations < 1);

    generateGeneration(gen,populationCount,matingProcess,mutationChance,generations);
    */
    //HARDCODED
    generateGeneration(gen,10,10,0.34,0);

    printChromosomeInfo(gen.bestChromosome);

    return 0;
}
