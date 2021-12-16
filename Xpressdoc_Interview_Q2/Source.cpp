//write a function steps(k) that return an integer representing the least number of steps a "k" needs to be reduced to 1 under the constraints written above
//	a) +1	
//	b) -1
//	c) divide by 2 if even

#include<iostream>
using namespace std;
bool isPowerOfTwo(int n)//This is what was needed instead of a sqrt. The previous check literally did nothing as a "check" and is not the opposite of an exponent.
{
	//n being the modified k + 1
	cout << "Checking if factor of 2 " << n << endl;
	if (n == 0)
		return false;

	cout << "Ceiling " <<  ceil(log2(n)) <<"| Floor " << floor(log2(n)) << endl;
	return (ceil(log2(n)) == floor(log2(n)));//this check determines if k a whole number or not.
}

void NumberOfSteps(int steps, int k) //function for computing which constraint should be executed
{
	cout << "The number given was " << k << endl;
	cout << "Calculating steps" << endl;
	while (k != 1)
	{
		if (k % 2 == 0)//check if k is an odd or even number
		{
			cout << "k is even \n" << "Initializing step c) \n";
			k = k / 2;
			steps += 1;
			cout << k << "\n";
		}
		else
		{
			if (isPowerOfTwo(k + 1) == true)//check if adding/subtracting will result in k being an exponent/radical of 2		This step only matters if the number will require 1 fewer step by adding first or subtracting.
			{
				cout << "Initializing step a) \n";
				k = k + 1;
				cout << k << "\n";
				steps += 1;
			}
			else
			{
				cout << "Initializing step b) \n";
				k = k - 1;
				cout << k << "\n";
				steps += 1;
			}
		}

	}
	cout << "k has been reduced to 1." << endl << "The number of steps needed for k to reach 1 is " << steps;
}

int main()
{
	cout << "Write a function steps(k) that return an integer representing the least number of steps a k needs to be reduced to 1 under the constraints \n" << "a) k + 1\n" << "b) k - 1\n" << "c) k / 2 (if even)" << endl;
	//int k = 0;	//initialize local variable
	int steps = 0;	//initialize local variable
	int y;
	cout << "Pick your own number." << endl;
	cin >> y;
	//cout << k << endl;	//testing
	NumberOfSteps(0, y);	//setting the parameters of the NumberOfSteps function

	return 0;
}
