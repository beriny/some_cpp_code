/*
 * 将s中的字符串按照字典顺序，降序排列
 */

#include <iostream>
#include <set>
#include <functional>
#include <string>

using namespace std;

template <typename T>
void printCollection(const T& t)
{
	typename T::const_iterator itr;
	for ( itr = t.begin(); itr != t.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
}

int main(void)
{
	typedef greater<string> greater_str;
	
	set<string, greater_str> s;
	string str;
	
	int i=0;
	const int Size = 10;
	
	while (cin >> str && i < Size)
	{
		i++;	
		s.insert(str);
	}
	
	printCollection(s);
	
	return 0;
}

