/*
 * 运行环境 ubuntu linux g++
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(int element)
{
	cout << element << " ";
}

int main(void)
{
	vector<int> array;
	int  element;
	
	while(cin >> element)
	{
		array.push_back(element);
	}
	
	for_each(array.begin(), array.end(), output);
	cout << endl;
	
	return 0;
}
