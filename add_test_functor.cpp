/*
 * 运行环境 ubuntu linux g++
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class AddValue{
private:
	int  theValue;
public:
	AddValue(int v):theValue(v){
	
	}
	
	void operator() (int& elem) const{
		elem += theValue;
	}
};

ostream_iterator<int> out(cout, " ");

template<typename T>
void output(list<T> intlist, string str, T t=T())
{
	T _t=T();
	
	if (t != _t)
	{
		cout << str << t << " : " << endl;	
	}
	else
	{
		cout << str << endl;
	}
	
	copy(intlist.begin(), intlist.end(), out);
	cout << endl;		
}

int main(void)
{
	
	list<int> intlist;
	int element;
	
	while (cin >> element)
	{
		intlist.push_back(element);
	}
	cin.clear();
	cin.ignore();	

	output(intlist, "the intlist is :");
	
	cout << "please input a num : ";
	cin >> element;
	for_each(intlist.begin(), intlist.end(), AddValue(element));
	
	output(intlist, "after adding ", element);
	
	for_each(intlist.begin(), intlist.end(), AddValue(*intlist.begin()));
	
	output(intlist, "after adding the first element : ");
			
	return 0;
}
