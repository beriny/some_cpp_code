#include <iostream>

using namespace std;

bool isPrime(const unsigned int& n)
{
	for (unsigned int i = 3; i*i < n; i += 2)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
