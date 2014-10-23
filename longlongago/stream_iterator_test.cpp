#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	vector<string> strs;

	cout << "键盘输入，结束时,按Enter，然后 Ctrl + Z:" << endl;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(strs));	

	sort(strs.begin(), strs.end());

	copy(strs.begin(), strs.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}

