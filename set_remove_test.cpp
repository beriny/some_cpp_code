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
	set<int> IntSet;
	int element;
	
	while (cin >> element)
	{
		IntSet.insert(element);
	}
	cin.clear();
	cin.ignore();
	
	copy(IntSet.begin(), IntSet.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	cout << "please input a num before you input:";
	cin >> element;
	int num = IntSet.erase(element);
	
	cout << "number of removed elements: " << num << endl;
	
	copy(IntSet.begin(), IntSet.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
		
	return 0;
}
