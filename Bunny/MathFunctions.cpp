#include "MathFunctions.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <time.h> //For seeding

#define PI 3.141591

namespace math
{


//***************************************
//NORMAL DISTRUBITION CLASS
//
//_______________________________________

NormalDistribution::NormalDistribution(float mean, float sd)
{
  if(sd < 0)
	this->sd = 1;
  else
	this->sd = sd;

  this->mean = mean;
}


double NormalDistribution::probability(float x)
/*
  All computations revolves around this summation

  Σ (-1)^n * (x-mean)^(2n+1) / ((n! * 2^n * σ^2n * (2n + 1)) 

  it is centered at 0, and finds the appropriate upper bound.

  This is a power series of the integral of e^(-(x - mean)^2/(2*σ^2))


  A lot of the variables are used so I dont' have to repeat computations
  such as 2 then 2*2 then 2*2*2 and so on, it keeps track of the previous,
  and just multiples once to that.  Saving time.




*/
{
  float zScore = (x - mean) / sd;  //zScore of the normal distribution

  if(zScore == 0)
	return .5; // 0 standard deviations away from the mean

  //Because the taylor series is very innaccurate past 3 without an absurd
  //  amount of iterations, I will manually account for those ones

  /* For faster computations, but less accurate
  if(zScore >= 4)
	return 1.00;
  else if(zScore > 3)
	return 1.00 - .001;


  if(zScore <= -4)
	return 0.0;
  else if(zScore < -3)
	return .005;
  */

  double lastVal = 0;    //Keeps track of the previous estimation
  int loopCount = 0;     //For summing
  double sumOfVals = 0;  //Keeps track of the sum of the values
  int estimateCount = 0; //Keeps track of how many comparisons were close

  float powersOfTwo = 1; //Keeps track of the power of two so it's not repeated calcs
  float nFactorial = 1;  //Keeps track of the n!
  float zPowers = 1;     //Keeps track of the powers of z

  do
  {
  
	lastVal = sumOfVals;
	
	double tempSum = ( zPowers * (x - mean) ) /
	               (nFactorial * powersOfTwo * (2 * loopCount + 1));
	
	//The summation
	if(loopCount % 2 == 0) //(-1)^n
      sumOfVals += tempSum;
	else
	  sumOfVals -= tempSum;



	powersOfTwo *= 2;
	nFactorial *= loopCount + 1;
	zPowers *= zScore * zScore;


	if(abs(lastVal - sumOfVals) < .000001)
	  estimateCount++;
	else
	  estimateCount = 0;




    loopCount++;

   std::cout << sumOfVals << std::endl;
   system("PAUSE");
	//if(loopCount > 10000)
	  //return (zScore / (-zScore) + .5);  //If it needs this many iterations, it's either 100 or 0, so return 50
	                                     //  and subtract or add accordingly

  }while(estimateCount < 3);

 
  if(zScore > 0)
    return (sumOfVals / (sqrt(PI * 2 ) * sd) + .50);
  else 
    return .5 + (sumOfVals / (sqrt(PI * 2 ) * sd));
}


}