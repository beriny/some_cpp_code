/*
 * 运行环境 ubuntu linux g++
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

int pow2(int a)
{
	return pow(a,2);
}

int main(void)
{
	ostream_iterator<int> out(cout, " ");	
	
	set<int> Ints;
	vector<int> Intv;
	int element;
	
	while(cin >> element)
	{
		Ints.insert(element);
	}
	cin.clear();
	cin.ignore();
	
	copy(Ints.begin(), Ints.end(), out);
	cout << endl;
	
	transform(Ints.begin(), Ints.end(), back_inserter(Intv), pow2);
	
	copy(Intv.begin(), Intv.end(), out);
	cout << endl;
	
	return 0;
}
