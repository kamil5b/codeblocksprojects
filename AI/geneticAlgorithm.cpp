#include "geneticAlgorithm.h"

void printChromosomeInfo(Chromosome c){

    cout << "Chromosome : ";
    for(int i=0;i<10;i++){
        cout << "[" << c.genes[i] <<"]";
    }
    cout << endl;
    cout << "Chromosome X : ";
    for(int i=0;i<5;i++){
        cout << "[" << c.genes[i] << "]";
    }
    cout << endl;
    cout << "Chromosome Y : ";
    for(int i=5;i<10;i++){
        cout << "[" << c.genes[i] << "]";
    }
    cout << endl;
    cout << "x : " << c.x << endl;
    cout << "y : " << c.y << endl;
    cout << "h(x,y) : " << c.fitness << endl;
}

void encode(float x, float y, int genes[10]){
    int temp;
    //ENCODE X
    //exmp x : -1.034
    //check if x < 0 -> index 0 is -1 and change the x to unsigned otherwise its 1
    //-1.034 -> index 0 = -1 -> -1.034 = 1.034
    //1.034 * 1000 = 1034
    //1034 % 10 = 4 -> index 4 = 4-> 1034 / 10 = 103
    //103 % 10 = 3 -> index 3 = 3 -> 103 / 10 = 10
    //10 % 10 = 0 -> index 2 = 0 -> 10/10 = 1
    //1 % 10 = 1 -> index 1 = 1.
    //therefore, the half chromosome will be : [-1][1][0][3][4]
    temp = (int)(x*1000);
    if(temp < 0){
        genes[0]=-1;
        temp = temp * -1;
    }else{
        genes[0]=1;
    }
    for(int i=0;i<4;i++){
        genes[4-i] = temp % 10;
        temp = temp / 10;
    }
    //ENCODE Y
    temp = (int)(y*1000);
    if(temp < 0){
        genes[5]=-1;
        temp = temp * -1;
    }else{
        genes[5]=1;
    }
    for(int i=0;i<4;i++){
        genes[9-i] = temp % 10;
        temp = temp / 10;
    }
}
void decode(float &x, float &y, int genes[10]){

    x=0;
    y=0;
    for(int i=1;i<5;i++){
        x=x+(genes[i]*pow(10,-i));
        y=y+(genes[i+5]*pow(10,-i));
    }
    x=x*genes[0];
    y=y*genes[5];
}


Chromosome createChromosome(float x,float y){
    Chromosome c;
    c.x=x;
    c.y=y;
    c.fitness = fitnessing(x,y);
    encode(x,y,c.genes);
    return c;
}

float fitnessing(float x,float y){
    return ((cos(pow(x,2) * PI / 180.0)) * (sin(pow(y,2) * PI / 180.0))) + (x+y);
}

Generation createGeneration(int populationCount,int matingProcess,float mutationChance){

    Generation g;
    float x,y;
    g.populationCount=populationCount;
    g.matingProcess=matingProcess;
    g.mutationChance=mutationChance;
    g.child=0;
    for(int i=0;i<populationCount;i++){
        for(int j=0;j<10;j++){
            //-1 <= x <= 2
            x = ((float)(rand()%3000)/1000)-1.0;
            //-1 <= y <= 1
            y = ((float)(rand()%2000)/1000)-1.0;
        }
        g.population[i] = createChromosome(x,y);
    }
    sortPopulation(g.population,g.populationCount);
    g.bestChromosome=g.population[0];
    return g;
}
Chromosome selectParent(Generation g) //ROULETTE WHEEL
{
    Chromosome c=g.population[0];
    bool stop=false;
    float pick,temp,rouletteWheel[MAX_POPULATION],totalFitness=0;

    if(g.population[0].fitness<0){
        rouletteWheel[0]=g.population[0].fitness * -1;
    }else{
        rouletteWheel[0]=g.population[0].fitness;
    }
    totalFitness = totalFitness + g.population[0].fitness;

    for(int i=1;i<g.populationCount;i++){
        if(g.population[i].fitness<0){
            rouletteWheel[i]=rouletteWheel[i-1] + g.population[i].fitness * -1;
        }else{
            rouletteWheel[i]=rouletteWheel[i-1] + g.population[i].fitness;
        }
        totalFitness = totalFitness + g.population[i].fitness;
    }
    for(int i=0;i<10;i++){
        pick = (float(rand())/float((RAND_MAX))*totalFitness);
    }
    for(int i=0;i<g.populationCount&&!stop;i++) {
        temp = temp + rouletteWheel[i];
        if(pick <= temp) {
            c = g.population[i];
            stop=true;
        }
    }
    return c;
}

void selectSurvivor(Generation &g) //SORT AND DELETE
{
    sortMatingPool(g.matingPool,g.populationCount+g.child);
    for(int i=0;i<g.populationCount;i++){
        g.population[i]=g.matingPool[i];
    }
    g.child=0;
    g.bestChromosome=g.population[0];
}

void recombinationChromosome(Generation &g) //CROSSOVER
{
    Chromosome p1,p2,c1,c2;
    int temp;
    float mutate;
    /*
    2 children will be created per mating cycle
    c1 will have index 0-1 and 5-6 of p2 and index 2-4 and 7-9 of p1
    c2 will have index 0-1 and 5-6 of p1 and index 2-4 and 7-9 of p2
    The maximum children of this program is constant 200.
    therefore, the maximum matingProcess is 100.
    */
    for(int i=0;i<g.populationCount;i++){
        g.matingPool[i]=g.population[i];
    }
    for(int i=0;i<g.matingProcess;i++){
        p1=selectParent(g);
        p2=selectParent(g);

        c1=p1;
        c2=p2;

        for(int j=0;j<2;j++){
            temp = c1.genes[i];
            c1.genes[j]=c2.genes[j];
            c2.genes[j]=temp;

            temp = c1.genes[i+5];
            c1.genes[j+5]=c2.genes[j+5];
            c2.genes[j+5]=temp;
        }
        //MUTATION CHANCE
        if((float(rand())/float((RAND_MAX))*1)<g.mutationChance){
            mutate = (float(rand())/float((RAND_MAX))*99.6);
            if(mutate < 8.3){
                c1.genes[2]=rand()%10;
            }else if(mutate < 2*8.3){
                c1.genes[3]=rand()%10;
            }else if(mutate < 3*8.3){
                c1.genes[4]=rand()%10;
            }else if(mutate < 4*8.3){
                c1.genes[7]=rand()%10;
            }else if(mutate < 5*8.3){
                c1.genes[8]=rand()%10;
            }else if(mutate < 6*8.3){
                c1.genes[9]=rand()%10;
            }else if(mutate < 7*8.3){
                c2.genes[2]=rand()%10;
            }else if(mutate < 8*8.3){
                c2.genes[3]=rand()%10;
            }else if(mutate < 9*8.3){
                c2.genes[4]=rand()%10;
            }else if(mutate < 10*8.3){
                c2.genes[7]=rand()%10;
            }else if(mutate < 11*8.3){
                c2.genes[8]=rand()%10;
            }else if(mutate < 12*8.3){
                c2.genes[9]=rand()%10;
            }
        }
        decode(c1.x,c1.y,c1.genes);
        c1.fitness = fitnessing(c1.x,c1.y);
        decode(c2.x,c2.y,c2.genes);
        c2.fitness = fitnessing(c2.x,c2.y);

        g.matingPool[g.populationCount+g.child]=c1;
        g.matingPool[g.populationCount+g.child+1]=c2;

        g.child = g.child+2;
    }
    selectSurvivor(g);
}
void sortPopulation(Chromosome arr[MAX_POPULATION], int n) //INSERTION SORT
{
    int i, j;
    Chromosome key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].fitness < key.fitness)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void sortMatingPool(Chromosome arr[MAX_POPULATION + MAX_CHILD], int n) //INSERTION SORT
{
    int i, j;
    Chromosome key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].fitness < key.fitness)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generateGeneration(Generation &g, int populationCount,int matingProcess,
                        float mutationChance,int numberOfGeneration) {
    g = createGeneration(populationCount,matingProcess,mutationChance);
    for(int i=1;i<numberOfGeneration;i++){
        recombinationChromosome(g);
    }
}
