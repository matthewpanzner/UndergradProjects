#include <iostream>
#include <fstream>

using namespace std;

void printHeading();
void highestNum(int num1, int num2, int& dividend, int& divisor);
void DivisorDividendSwap (int& divisor, int& dividend);
void DivisionAlgorithm (int dividend, int divisor, int quotient, int remainder);
void invalidInputs (int divisor, int dividend);
void relativelyPrime (int quotient, int num1, int num2);
void continueProgram (bool& inProgram, char& inLoop);
void inputFailureCheck (bool& inputFailure);
void abosluteValueConversion(int& num1, int& num2, int& num1_zero, int& num2_zero);
void saveProgram(ofstream &outFile, int divisor);
void encrypt(ifstream &inFile, ofstream &outFile);

int main()
{
	ifstream inFile;
	ofstream outFile;

	outFile.open("out.data");
	inFile.open("in.data");

	int num1, num2, num1_zero, num2_zero, quotient, dividend, divisor;
	
	bool inProgram = true;

	while (inProgram == true)
	{ 
	  bool declaredVariables = false;
	  bool inputFailure = false;
	  int  remainder = 0;
	  char inLoop; 
	
	  while (declaredVariables == false)
	  { 
		  system ("CLS");

	  	  printHeading();
		
		  cout << "What is a? ";

		  cin >> num1;

		  inputFailureCheck(inputFailure);

		  if (inputFailure == true )
			  return 0;

		  cout << "What is b? "; 

		  cin >> num2;

		  inputFailureCheck (inputFailure);
		  abosluteValueConversion (num1, num2, num1_zero, num2_zero);

		  cout << endl << endl;

		  highestNum( num1, num2, dividend, divisor);

		  if (divisor == 0)
			  DivisorDividendSwap (divisor, dividend);

		  if ( (divisor > 0) && ( dividend >= 0) )
		  {
			 quotient = dividend/divisor;
			 remainder = dividend%divisor;
			 declaredVariables = true;

		   	 DivisionAlgorithm (dividend, divisor, quotient, remainder);
		   }
		   else
		      invalidInputs (divisor, dividend);

		   while (remainder > 0)
		   {
			  dividend = divisor;
			  divisor = remainder;
			  quotient = dividend/divisor;
			  remainder = dividend%divisor;

			  DivisionAlgorithm (dividend, divisor, quotient, remainder);
		   }  
	  }
	
	  cout << endl;

	  cout << "gcd(" << num1_zero << "," << num2_zero << ") = " << divisor
		   << endl << endl;

	  outFile << divisor;

	  relativelyPrime (quotient, num1, num2);
	  continueProgram (inProgram, inLoop);
     
    }
	
	  inFile.close();
	  outFile.close();

	  remove("in.data");
	  rename("out.data", "in.data");

	  inFile.open("in.data");
	  outFile.open("out.data");

	  encrypt(inFile, outFile);

	  inFile.close();
	  outFile.close();

	return 0;
}	

void printHeading()
{
	cout << "********************************************************************************";
	cout << endl;
	cout << "gcd(a,b) , where a and b are both integers"
		 << " and both not zero" << endl << endl;
}
void highestNum (int num1, int num2, int& dividend, int& divisor)
{
	if( num1 > num2 )
	{
		dividend = num1;
		divisor = num2;
	}
	else
	{
		dividend = num2;
		divisor = num1;
	}
}
void DivisorDividendSwap (int& divisor, int& dividend)
{
	int temp = divisor;
	divisor = dividend;
	dividend = temp;
}
void DivisionAlgorithm (int dividend, int divisor, int  quotient, int  remainder)
{
	cout << dividend << " = " << divisor << "*" << quotient << " + " << remainder
		 << endl;
}
void invalidInputs (int  divisor, int  dividend)
{
	if (divisor <= 0)
		cout << "**INVALID DIVISOR**" << endl;
	if (dividend < 0)
		cout << "**INVALID DIVIDEND**" << endl;

	cout << endl;
	cout << "********************************************************************************" << endl
		 << endl;

	system ("pause");
}
void relativelyPrime (int  quotient, int  num1, int  num2)
{
	if (quotient == 1)
		cout << num1 << " and " << num2 << " are relatively prime numbers!"
		     << endl << endl;
	else 
		cout << num1 << " and " << num2 << " are not relatively prime numbers!"
		     << endl << endl;
}
void continueProgram (bool& inProgram, char& inLoop)
{
	bool validResponse = false;
	int loopCount = 0;

	while (validResponse == false)
	{
		++loopCount;

		cout << "Do you want to compute another? [y/n] ";

		cin >> inLoop;

		if (loopCount == 5)
			inLoop = 'n';

		if ( !cin.fail() && (inLoop == 'y' || inLoop == 'Y'))
		{
			inProgram = true;
			validResponse = true;
		}
		else if ( !cin.fail() && (inLoop == 'n' || inLoop == 'N'))
		{
			inProgram = false;
			validResponse = true;
		}
		else
			cout << endl << "invalid input, please re-enter" << endl << endl;
	}
}
void inputFailureCheck (bool& inputFailure)
{
	if ( cin.fail() )
	{
		inputFailure = true;

		cout << endl;
		cout << "******INPUT*ERROR********" << endl << endl;
		cout << "ENDING*PROGRAM***********" << endl;
			  
		system ("pause");
	 }
}
void abosluteValueConversion(int& num1, int& num2, int& num1_zero, int& num2_zero)
{
	num1_zero = num1;
	num2_zero = num2;

	if (num1 < 0)
		num1 = num1*-1;
	if (num2 < 0)
		num2 = num2*-1;
}
void saveProgram(ofstream &outFile, int divisor)
{
	outFile << divisor;
}
void encrypt(ifstream &inFile, ofstream &outFile)
{
	int i = 0;
	int encryptNum;
	char ch[20];

	i++;
	inFile.get(ch[i]);

	while(inFile)
	{
		switch (ch[i])
		{
		case '1':
			encryptNum = (5*1 + 7) % 9;
			break;
		case '2':
			encryptNum = (5*2 + 7) % 9;
			break;
		case '3':
			encryptNum = (5*3 + 7) % 9;
			break;
		case '4': 
			encryptNum = (5*4 + 7) % 9;
			break;
		case '5': 
			encryptNum = (5*5 + 7) % 9;
			break;
		case '6':
			encryptNum = (5*6 + 7) % 9;
			break;
		case '7':
			encryptNum = (5*7 + 7) % 9;
			break;
		case '8':
			encryptNum = (5*8 + 7) % 9;
			break;
		case '9':
			encryptNum = (5*9 + 7) % 9;
			break;
		default:
			ch[i] = 'Z';
		}
		switch (encryptNum)
		{
		case 1:
			ch[i] = '!';
			break;
		case 2:
			ch[i] = '@';
			break;
		case 3:
			ch[i] = '#';
			break;
		case 4: 
			ch[i] = '$';
			break;
		case 5: 
			ch[i] = '%';
			break;
		case 6:
			ch[i] = '^';
			break;
		case 7:
			ch[i] = '&';
			break;
		case 8:
			ch[i] = '*';
			break;
		case 0:
			ch[i] = '(';
			break;
		default:
			ch[i] = ')';
		}

	outFile << ch[i];

	i++;
	inFile.get(ch[i]);

	}
}