/*
 * 运行环境 ubuntu linux g++
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#include <deque>

using namespace std;

template<typename T>
void myOutput(set<T> s, string str = string(), T t = T())
{
	ostream_iterator<T> out(cout, " ");
	string _s = string();
	if (_s != str)
	{
		T _t = T();
		if (t != _t)
		{
			cout << str << t << " : "<< endl;
		}
		else
		{
			cout << str << " : " << endl;
		}
	}

	copy(s.begin(), s.end(), out);
	cout << endl;
}

template<typename T>
void myOutput(deque<T> q, string str = string(), T t = T())
{
	ostream_iterator<T> out(cout, " ");
	string _s = string();
	if (_s != str)
	{
		T _t = T();
		if (t != _t)
		{
			cout << str << t << " : "<< endl;
		}
		else
		{
			cout << str << " : " << endl;
		}
	}

	copy(q.begin(), q.end(), out);
	cout << endl;
}

int main(void)
{
	set<int, less<int> > intset;
	deque<int> intdeque;
	int element;
	
	while (cin >> element)
	{
		intset.insert(element);
	}
	cin.clear();
	cin.ignore();
	
	myOutput(intset, "intset is");
	
	transform(intset.begin(), intset.end(),
		back_inserter(intdeque),
		bind2nd(multiplies<int>(), 10));
	
	myOutput(intdeque, "intdeque is");			
	
	replace_if(intdeque.begin(), intdeque.end(),
		bind2nd(less<int>(), 45),
		45);
	
	myOutput(intdeque, "less intdeque:");
	
	intdeque.erase(remove_if(intdeque.begin(), intdeque.end(), 
			bind2nd(greater<int>(), 60)),
			intdeque.end());
	
	myOutput(intdeque, "greater intdeque:");
	
	return 0;
}
