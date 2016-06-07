#include <iostream>

using namespace std;

int main()
{
	unsigned long int num, temp_num;
	unsigned long int p[20];
	
	int i = -1;
	unsigned long int j = 1;
	bool done = false;

	cin >> num;
	cout << sizeof (num) << endl;
	while(!done)
	{
		++j;
		temp_num = num % j;

		if(temp_num == 0)
		{
			++i;
			p[i] = j;
			num = num / j;
			j = 1;
		}
		if(num == 1)
		{
			done = true;
		}
	}

	j = i;
	i = 0;

	while(i != (j+1))
	{
		cout << p[i] << "*";
		++i;
	}

	system("PAUSE");

	return 0;
}