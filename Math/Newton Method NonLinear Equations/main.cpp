/*
  AUTHOR : Matthew Panzner
  ASSIGNMENT: Final Exam #1.a
  LANGUAGE: C++
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Equations equal to zero
float f(float x, float y);
float g(float x, float y);

//Partial Derivatives
float Fx(float x, float y);
float Fy(float x, float y);
float Gx(float x, float y);
float Gy(float x, float y);

//Change in x and change in y
float deltaX(float x, float y);
float deltaY(float x, float y);

int main()
{
  cout.precision(8);
  cout.setf(ios::fixed);

  float x = 1.0;
  float y = 1.0;
  float prevX;
  float prevY;

  int iterations = 0;

  cout << left;
  cout << setw(12) << "x" << "y" << endl;
  cout << setw(12) << "---" << "---" << endl;

  do
  {
    prevX = x;
	prevY = y;

	x = x + deltaX(x,y);
	y = y + deltaY(x,y);

	cout << setw(12) << x << y << endl;

    iterations++;

  }while( (abs(x - prevX) > .0000001) && (abs(y - prevY) > .0000001) && iterations < 500);


  cout << endl << endl;

  cout << "Solutions: " << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl << endl;

  if(iterations >= 500)
    cout << "Reached maximum iterations, solution may be off, or non-existant." << endl << endl;
  
  cout << "Error" << endl;
  cout << "-----" << endl;

  cout << "f(x,y): " << abs(f(x,y)) << endl;
  cout << "g(x,y): " << abs(g(x,y)) << endl << endl;

  system("PAUSE");

  return 0;
}

//********************
//FUNCTION DEFINITIONS
//********************

float f(float x, float y)
{
  return x*x * (y*y - 1) - 2;
}

float g(float x, float y)
{
  return y*y * sin(x) - 1;
}

//************************
//PARTIAL DERIVATIVES*****
//************************

float Fx(float x, float y)
{
  return 2*x * (y*y - 1);
}

float Fy(float x, float y)
{
  return 2*y * x*x;
}

float Gx(float x, float y)
{
  return y*y * cos(x);
}

float Gy(float x, float y)
{
  return 2*y * sin(x);
}

//****************************
//CHANGE IN X AND Y VALUES****
//****************************

float deltaX(float x, float y)
{
  float determinant = 1 / (Fx(x,y)*Gy(x,y) - Fy(x,y)*Gx(x,y));

  return (determinant * (-Gy(x,y) * f(x,y) + Fy(x,y) * g(x,y)));
}

float deltaY(float x, float y)
{
  float determinant = 1 / (Fx(x,y)*Gy(x,y) - Fy(x,y)*Gx(x,y));

  return (determinant * (Gx(x,y) * f(x,y) - Fx(x,y) * g(x,y)));
}
