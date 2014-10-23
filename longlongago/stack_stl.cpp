#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	typedef vector<int> int_vector;
	stack<int, int_vector> s;
	
	int element;
	
	while (cin >> element)
	{
		s.push(element);
	}
	
	cout << "Contents are:" << endl;
	for ( ;  !s.empty() ;  s.pop() )
	{
		cout << s.top() << endl;
	}
	
	return 0;
}
