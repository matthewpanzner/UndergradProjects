#ifndef ITEMTYPE_HPP
#define ITEMTYPE_HPP

/*
  ItemType.hpp
  v 1.0.0

  DevLog:      9/30/2013  ---- Started object
                          ---- Tested object
						  ---- Finished object, should not be breakable
			   10/1/2013  ---- Added id to protected

  Notes :

    A very generic object type that just holds an id with comparison functions

    Ids are expected to not have negative values, thus the default constructor is
      -1111 signalling when there is an identification error

*/

enum ComparisonType {
// The results from comparing two types of ids

LESS,      // Compared less in value
GREATER,   // Greater in value
EQUAL      // Bot have equal ids

};

class ItemType
{
  public:
	ItemType();
	//Default constructor

	inline void SetId(int id) {this->id = id;}
	//Sets id of object

	inline int GetId() const {return id;}
	//Returns id value of item

	ComparisonType comparedTo(const ItemType otherItem);
	//Compares two ItemType objects 
	// returns EQUAL if both share the same id
	// returns LESS if this object is less than the other
	// returns GREATER if this object is greater than the other

  protected:
    int id;
};

#endif