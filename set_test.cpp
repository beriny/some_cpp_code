/************************************************************************/
/* set 的内部元素会自动排序，但是每个元素值只能出现一次                 */
/************************************************************************/

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

int main(void)
{
	typedef set<int> IntSet;
	ostream_iterator<int> output(cout, " ");

	const unsigned int Size = 100;
	const unsigned int length = 12;
	srand(time(NULL));

	IntSet col;

	cout << "随机数据：";
	for (size_t i = 0; i < length; i++)
	{
		int num = rand() % Size;
		col.insert(num);
		cout << num << " ";
	}
	cout << endl;
	
	cout << "set输出：";
	copy(col.begin(), col.end(), output);
	cout << endl;

	system("pause");
	return 0;
}
