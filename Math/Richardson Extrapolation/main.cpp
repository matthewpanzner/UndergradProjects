//By: Matthew Panzner
//Homework 10 - Richardson Extrapolation 

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

vector<double> ValueList;

int power(int base, int exponent);
double R(int n, int m);

int main()
{
  cout.precision(5);
  cout.setf(ios::fixed);

  int maxN;

  cout << "Amount of function values: " ;
  cin >> maxN;

  ValueList.reserve(maxN);

  for(int i = 0; i < maxN; i++) // Assuming h/2^n has no gaps in n.
  {
	double temp;
    cout << "What is R(" << i << ",0)?  y value :" << endl;

	cin >> temp;
	ValueList.push_back(temp);
  }

  cout << endl;
  cout << "R(" << maxN - 1 << "," << maxN - 1 << ") is: ";
  cout << R(maxN - 1, maxN - 1) << endl;

  system("PAUSE");

  return 0;
}

double R(int n, int m)
{
  if(m == 0)
    return ValueList.at(n);

  return ( (double(power(2,m)) / (double(power(2,m)) - 1)) * R(n, m-1)
	       - ((1 / (double(power(2,m)) - 1)) * R(n-1,m-1)));
}

int power(int base, int exponent) // since for whatever reason, <cmath> 
{                                 // dislikes integer powers.
  if(exponent == 0)
	return 1;

  return base * power(base, exponent - 1);
}