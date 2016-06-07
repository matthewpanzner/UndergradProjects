#include "LinkedList.hpp"
#include "ItemType.hpp"
#include "Bunny.hpp"
#include "RandNumGen.hpp"
#include "MathFunctions.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int tot;
int num;

void Process();

int main()
{
  std::srand(unsigned int(time(NULL))); // Seed 

  tot = 0;
  num = 0;
  bool done = false;
  
  int numt = 0;
  int numf = 0;
  int count = 0;

  while(true)
  {
    if(math::Probability(4))
	  numt++;
	else
	  numf++;

	count++;

	if(count % 10000000 == 0)
	{
	  cout << "True: " << numt << endl;
	  cout << "False: " << numf << endl;
	  cout << "Proportion: " << float(numt) / numf << endl;
	  cout << endl;
	}
  }

  /*
  while(!done)
  {
  

    Process();

    char request;

    std::cin >> request;

    if(request != 'y')
	  done = true;
  }*/


  std::cout << std::endl << std::endl << std::endl;

  std::cout << "Average life: " << float(tot)/num << std::endl;

  system("PAUSE");
  return 0;
}

void Process()
{

  List<Bunny> list;

  for(int i = 0; i < 25; i++)
  {
    Bunny bunny;
	bunny.SetId(i + 1);
	list.Add(bunny);
  }

  int totalAge = 0;

  while(list.lengthIs() > 0)
  {
	Bunny bunny;

	list.Reset();

	int listLength = list.lengthIs();

    for(int i = 0; i < (listLength); i++)
	{ 
	  list.GetNext(bunny);

	  if(!bunny.stillAlive())
	  {
		std::cout << "Bunny # " << bunny.GetId() << " died at age " << bunny.GetAge() << std::endl;

		list.Delete(bunny);

		totalAge += bunny.GetAge();
	  }
	  else
	  {
		bunny.Birthday();
		list.UpdateCurrent(bunny);
	  }

	  
	}

  }

  std::cout << std::endl << std::endl;
  std::cout << "Average life: " << totalAge / 25.00 << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "Again? [y/n]" << std::endl;

  num += 25;
  tot += totalAge;
}