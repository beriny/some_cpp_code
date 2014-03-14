/*
 * VS 环境
 */

#include <iostream>
#include <list>
#include <algorithm>

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
	cin.sync();

	cout << "pre:  ";
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "please input remove element: "; 	
	cin >> element;
	remove(list_int.begin(), list_int.end(), element);

	cout << "post: ";
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
