/*************************************************************************
	>    File Name: list_test.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: 2014年03月16日 星期日 21时18分54秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void Output(const list<T>& l1, const list<T>& l2)
{
		ostream_iterator<T> out(cout, " ");
		cout << "list1: ";
		copy(l1.begin(), l1.end(), out);
		cout << endl << "list2: ";
		copy(l2.begin(), l2.end(), out);
		cout << endl;
}

int main(void)
{
	list<int> list1,list2;
	int count = 10;

	for(int i=0; i<count; ++i){
		list1.push_back(i);
		list2.push_front(i);
	}

	Output(list1, list2);

	list2.splice(find(list2.begin(), list2.end(), 3), list1);

	Output(list1, list2);

	list2.splice(list2.end(), list2, list2.begin());

	Output(list1, list2);

	list2.sort();
	list1 = list2;
	list2.unique();
	
	Output(list1, list2);

	list1.merge(list2);

	Output(list1, list2);

	return 0;
}
