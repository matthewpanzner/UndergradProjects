#include "ItemType.hpp"

ItemType::ItemType()
{
  id = -1111;
}

ComparisonType ItemType::comparedTo(const ItemType otherItem)
//Compares two ItemType objects 
// returns EQUAL if both share the same id
// returns LESS if this object is less than the other
// returns GREATER if this object is greater than the other
{
  if(this->id < otherItem.id)
	return LESS;
  else if(this->id > otherItem.id)
	return GREATER;

  return EQUAL;
}