#ifndef MATHFUNCTIONS_HPP
#define MATHFUNCTIONS_HPP

#include <iostream>

namespace math
{

class NormalDistribution
{
  public:
    NormalDistribution(float mean, float sd);
	//NormalDistribution default constructor

	double probability(float x);
	//Find the probability on bell curve if given x
	// This probability is an estimation using a Taylor Series
	// with the the bell curve function

  private:
    float sd;    // Standard deviation
	float mean;  // Mean of data
};

}


#endif