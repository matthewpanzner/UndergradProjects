#ifndef RANDNUMGEN_HPP
#define RANDNUMGEN_HPP

/*
  Random Number Generator object

  A basic random number generator class


  Works as wanted
*/

class RandNumGen
{
  public:
	RandNumGen();
	//Default constructor
	// Default upperbound 9, lowerbound 0

	RandNumGen(int lowerBound, int upperBound);
	//Initialize RandNumGen with a lower and upperbound

	int GetRandNum();
	//Returns a random number

	inline void SetLowerBound(int bound) {lowerBound = bound;}
	//Set lower bound manually

	inline void SetUpperBound(int bound) {upperBound = bound;}
	//Set lower bound manually

	inline void SetBounds(int lower, int upper) {SetLowerBound(lower); SetUpperBound(upper);}
	//Sets both bounds

  private:
    int lowerBound;    // Upperbound for random number
	int upperBound;    // Lowerbound for random number

};

#endif