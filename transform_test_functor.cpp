/************************************************************************/
/* 运行环境 VS 2013                                                      */
/************************************************************************/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

class Pow2
{
public:
	int operator()(int a) const
	{
		return int(pow(a, 2));
	}
};

int main(void)
{
	ostream_iterator<int> out(cout, " ");
	multiset<int> imset;
	vector<int> ivct;
	int element;

	while (cin >> element)
	{
		imset.insert(element);
	}
	cin.clear();
	cin.ignore();

	copy(imset.begin(), imset.end(), out);
	cout << endl;

	transform(imset.begin(), imset.end(), back_inserter(ivct), Pow2());

	copy(ivct.begin(), ivct.end(), out);
	cout << endl;

	system("pause");
	return 0;
}
