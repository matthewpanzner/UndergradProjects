#ifndef BUNNY_HPP
#define BUNNY_HPP

#include "RandNumGen.hpp"
#include "ItemType.hpp"
#include "LinkedList.hpp"

enum ColorType
//Different types of colors bunny can be
{
  WHITE,     //White rabbit
  BLACK,     //Black rabbit
  BROWN,     //Brown rabbit
  GREEN      //Green rabbit
};

enum MutationType
//Types of mutations
{
  NONE,       //No mutation
  VAMPIRIC,   //Turns vampiric 
  COLOR       //Changes color
};

enum GenderType
{
  MALE,
  FEMALE
};

enum ParentType
{
  MOTHER,
  FATHER
};

class Bunny : public ItemType
{

  public:
	Bunny();

	inline void Birthday() {age++;}
	//Increases age of bunny

	inline int GetAge() const {return age;}
	//Gets age of rabbit

	bool stillAlive();
	//Let's us know if the rabbit is still alive or not
	// true if alive
	// false if dies

	Bunny Breed(Bunny otherBunny);
	//Breed two Bunnies together and return that offspring

  private:
	ColorType color; 
	//List<MutationType> mutation;


	RandNumGen randomGenerator; //Random Number Generator

	int age; //Age of rabbit
	GenderType gender; //Gender of rabbit
	

};

#endif