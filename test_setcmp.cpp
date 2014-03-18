/*
 * 运行环境 ubuntu linux g++
 */
 

#include <iostream>
#include <set>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

template<typename T>
class RuntimeCmp{
public:
	enum cmp_mode{normal, reverse};
	
	RuntimeCmp(cmp_mode m = normal):mode(m){}
	bool operator() (const T& t1, const T& t2)const {
		return mode == normal ? t1<t2 : t1>t2;		
	}
	bool operator== (const RuntimeCmp& rc){
		return mode == rc.mode;
	}
		
private:
	cmp_mode mode;
};

typedef set<int, RuntimeCmp<int> > IntSet;

void fill(IntSet& values, unsigned int count = 10, int max = 10, int min = 0)
{
	srand(unsigned(time(NULL)));
	for (unsigned int i = 0; i < count; i += 1)
	{
		values.insert(rand()%(max-min)+min);
	}
}

void Output(IntSet& set, string str)
{
	ostream_iterator<int> out(cout, " ");
	cout << str << endl;
	copy(set.begin(), set.end(), out);
	cout << endl;
}


int main(void)
{
	IntSet coll1;
	fill(coll1);
	Output(coll1, "coll1: ");
	
	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);
		
	IntSet coll2(reverse_order);
	fill(coll2);
	Output(coll2, "coll2: ");
	
	coll1 = coll2;
	
	coll1.insert(3);
	Output(coll1, "coll1: ");
	if (coll1 == coll2)
	{
		cout << "Same sorting criterion" << endl;
	}
	else
	{
		cout << "Different sorting criterion" << endl;
	}
	
	return 0;
}
