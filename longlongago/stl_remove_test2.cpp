/*
 * ubuntu g++ 环境
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	list<int> list_int;
	int element;

	while(cin >> element)
	{
		list_int.push_front(element);
		list_int.push_back(element);
	}

	cin.clear();
	cin.ignore(); 	
	
	cout << "pre:";
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	cout << "please input a num to remove: ";
	cin >> element;
	list<int>::iterator end=remove(list_int.begin(), list_int.end(), element);
	
	cout << "post1 :";
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "post2 :";
	copy(list_int.begin(), end, ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
