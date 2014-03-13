#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ten = 10;

bool compare(const int& a, const int& b)
{
	return a%ten > b%ten;
}

int main(void)
{
	vector<int> num;
	int element;
	
	while (cin >> element)
	{
		num.push_back(element);
	}
	
	sort(num.begin(), num.end(), compare);
	
	for (unsigned int i = 0; i < num.size(); i += 1)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	
	return 0;
}

