/*
 * 运行环境 ubuntu linux g++
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
void Output(vector<T> v, string str, T t=T())
{
	ostream_iterator<T> out(cout, " ");
	T _t = T();
	
	if (t != _t)
	{
		cout << str << t << " : " << endl;
	}
	else
	{
		cout << str << " : " << endl;
	}
	copy(v.begin(), v.end(), out);
	cout << endl;
}

int main(void)
{
	vector<int> intvec;
	int element;
	
	while (cin >> element)
	{
		intvec.push_back(element);
	}
	cin.clear();
	cin.ignore();
	
	Output(intvec, "int vector is");
	
	transform(intvec.begin(), intvec.end(), 
		  intvec.begin(),
		  intvec.begin(),
		  multiplies<int>());
		  
	Output(intvec, "Now vector is :");
	
	transform(intvec.begin(), intvec.end(),
		intvec.begin(),
		bind2nd(multiplies<int>(), 10));	
		
	Output(intvec, "vector after multiplies ", 10);
	
	return 0;
}
