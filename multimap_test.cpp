#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	typedef multimap<int, string> IntStrMap;

	IntStrMap ism;
	ism.insert(make_pair(5, "tagged"));
	ism.insert(make_pair(2, "a"));
	ism.insert(make_pair(1, "this"));
	ism.insert(make_pair(4, "of"));
	ism.insert(make_pair(6, "strings"));
	ism.insert(make_pair(1, "is"));
	ism.insert(make_pair(3, "multimap"));

	IntStrMap::iterator pos;

	for (pos = ism.begin(); pos != ism.end();++pos)
	{
		cout << pos->second << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
