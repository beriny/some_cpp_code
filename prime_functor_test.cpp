/*
 * 运行环境 ubuntu linux g++
 * 为什么要写C++代码，原因很简单，我喜欢C，但又想偷懒
 * g++ prime_functor_test.cpp -o prime_functor -std=c++11
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

class isPrime{
public:
	bool operator() (int num) const{
		if (num < 2)
		{
			return false;
		}
		
		if (num == 2)
		{
			return true;
		}
		
		if (num % 2 == 0)
		{
			return false;
		}
		
		for (unsigned int i = 3; i*i < num+1; i += 2)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		
		return true;
	}
};

template<typename T>
void Output(list<T> tlist, string str, T t=T())
{
	ostream_iterator<T> out(cout, " ");
	T _t = T();
	if (t != _t)
	{
		cout << str << t << " : " << endl;
	}
	else
	{
		cout << str << endl;
	}
	
	copy(tlist.begin(), tlist.end(), out);
	cout << endl;
}

int main(void)
{
	list<int> intlist;
	srand(time(NULL));
	int element = rand() % 20 + 4;
	const int max = 100;
	
	for (int i = 0; i < element; i += 1)
	{
		intlist.push_back(rand() % max + i);
	}
	
	Output(intlist, "the intlist is ");
	
	list<int> intl;
	
	list<int>::iterator pos = intlist.begin();	
	while (pos != intlist.end())
	{
		pos = find_if(pos, intlist.end(), isPrime());
		if (pos != intlist.end())
		{
			intl.push_back(*pos);		
			++pos;
		}
		else
		{
			break;
		}
		
	}
	
	Output(intl, "the Primes in intlist is here : ");	
		
	return 0;
}
