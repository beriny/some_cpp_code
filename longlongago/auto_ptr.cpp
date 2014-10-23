#include <iostream>
#include <memory>

using namespace std;

/*
 * define output operator for auto_ptr 
 * print object value or NULL 
 */
 
template <class T>
ostream& operator<< (ostream& strm, const auto_ptr<T>& p)
{
	// dose p own an object ?
	if (p.get() == NULL)
	{
		strm << "NULL";		//NO: print NULL
	}
	else
	{
		strm << *p;		// YES: print the object
	}
	
	return strm;
}

int main(void)
{
	auto_ptr<int> p(new int(42));
	auto_ptr<int> q;
	
	cout << "after initialization:" << endl;
	cout << " p: " << p << endl;
	cout << " q: " << q << endl;
	
	q = p;
	
	cout << "after assigning auto pointers:" << endl;
	cout << " p: " << p << endl;
	cout << " q: " << q << endl;
	
	*q += 13;
	p = q;
	
	cout << "after change and reassignment:" << endl;
	cout << " p: " << p << endl;
	cout << " q: " << q << endl;
	
	return 0;
}

