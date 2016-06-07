#include "RandNumGen.hpp"

#include <time.h> //For seeding
#include <iostream>

RandNumGen::RandNumGen()
//Default constructor
{
  lowerBound = 0;
  upperBound = 9;

  std::srand(unsigned int(time(NULL))); // Seed 
}

RandNumGen::RandNumGen(int lowerBound, int upperBound)
//Initialize RandNumGen with a lower and upperbound
{
  this->lowerBound = lowerBound;
  this->upperBound = upperBound;

  std::srand(unsigned int(time(NULL))); // Seed 
}

int RandNumGen::GetRandNum()
//Returns a random number
{
  return (rand() % (upperBound - lowerBound + 1) + lowerBound);
  //Adjusts to the appropriate bound
}

