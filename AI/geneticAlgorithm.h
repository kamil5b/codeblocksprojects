#ifndef GENETICALGORITHM_H_INCLUDED
#define GENETICALGORITHM_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

const float PI = 3.14159265;
const int MAX_POPULATION = 100;
const int MAX_CHILD = 200;

struct Chromosome{ //DESIGN CHROMOSOME INTEGER
    int genes[10];
    /*0-4 for x, 5-9 for y
    if the x is negative, then index 0 will be -1, otherwise it was 1
    index 1 is for the whole unsigned number of x which are : {0,1,2}
    index 2-4 are for the decimal number x
    if the y is negative, then index 5 will be -1, otherwise it was 1
    the 6th index is for the whole usigned number of y which are : {0,1}
    index 7-9 are for the decimal number of y
    */
    float x,y,fitness;
};

struct Generation{
    Chromosome bestChromosome;
    Chromosome population[MAX_POPULATION];
    Chromosome matingPool[MAX_POPULATION + MAX_CHILD];
    int populationCount,child,matingProcess;
    float mutationChance;
};

void printChromosomeInfo(Chromosome);
Chromosome createChromosome(float x,float y);
float fitnessing(float x,float y);
Generation createGeneration(int populationCount,int matingProcess,float mutationChance);
Chromosome selectParent(Generation); //ROULETTE WHEEL
void recombinationChromosome(Generation &g); //CROSSOVER
void selectSurvivor(Generation &g); //SORT AND DELETE
void sortPopulation(Chromosome arr[MAX_POPULATION],int n); //INSERTION SORT
void sortMatingPool(Chromosome arr[MAX_POPULATION + MAX_CHILD], int n); //INSERTION SORT
void generateGeneration(Generation &g, int populationCount,int matingProcess,float mutationChance,int numberOfGeneration);
void encode(float x, float y, int genes[10]);
void decode(float &x, float &y, int genes[10]);
#endif // GENETICALGORITHM_H_INCLUDED
