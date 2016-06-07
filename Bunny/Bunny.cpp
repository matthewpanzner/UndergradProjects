#include "Bunny.hpp"
#include "MathFunctions.hpp"


//Probability Chart

double brown = .5;
double white = .2;
double black = .3;

double vampiric = .000001;
double green = .000001;

float expectedAge = 12;
float sd = 1.5; //standard deviation from expectedAge

//End chart


Bunny::Bunny()
{

  age = 0; 

  randomGenerator.SetBounds(0, 100);

  int colorNum = randomGenerator.GetRandNum();

  if(colorNum >= 0 && colorNum < brown * 100)
	color = BROWN;
  else if(colorNum >= brown * 100 && colorNum < white * 100)
	color = WHITE;
  else if(colorNum >= white * 100 && colorNum < 100)
    color = BLACK;

  randomGenerator.SetBounds(0,1);
  int genderNum = randomGenerator.GetRandNum();

  if(genderNum == MALE)
	gender = MALE;
  else
	gender = FEMALE;

}

bool Bunny::stillAlive() 
{
  math::NormalDistribution norm(expectedAge, sd);


  int percent = (norm.probability(age) * 1000) + .5;

  randomGenerator.SetLowerBound(0);
  randomGenerator.SetUpperBound(1000);

  int rand = randomGenerator.GetRandNum();

  if(rand < percent)
	return false;
  else 
	return true;
}

Bunny Bunny::Breed(Bunny otherBunny)
{
  Bunny baby;

  return baby;
}