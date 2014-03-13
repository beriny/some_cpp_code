/*
 * priority_queue 是STL中的优先队列
 */
 
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <class T>
void Output(const string& name, T& t)
{
	cout << name << ":" << endl;
	while (!t.empty())
	{
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
}

int main(void)
{
	typedef vector<int> vector_int;
	typedef greater<int> greater_int;
	typedef less<int> less_int;
	
	priority_queue<int, vector_int,  greater_int> minPQ;
	priority_queue<int, vector_int, less_int>     maxPQ;
	
	int element;
	
	while (cin >> element)
	{
		minPQ.push(element);
		maxPQ.push(element);
	}
	
	Output("minPQ", minPQ);
	Output("maxPQ", maxPQ);
	
	return 0;
}

