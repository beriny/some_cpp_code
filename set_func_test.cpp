/*************************************************************************
	>    File Name: set_test.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: 2014年03月17日 星期一 13时08分44秒
 ************************************************************************/

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	set<int> c;

	for(int i=1; i<7; ++i)
	{
		c.insert(i);
	}

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << endl;

	cout << endl;
	cout << "lower_bound(3): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << endl;

	return 0;
}
