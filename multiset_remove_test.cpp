/*
 * 运行环境 ubuntu linux g++
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	multiset<int> msInt;
	int element;
	
	while (cin >> element)
	{
		msInt.insert(element);
	}
	cin.clear();
	cin.ignore();
	
	copy(msInt.begin(), msInt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	cout << "please input a num:";
	cin >> element;
	
	int num = msInt.erase(element);
	cout << "numbers of removed elements: " << num << endl;
	
	copy(msInt.begin(), msInt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	return 0;
}
