/*************************************************************************
	>    File Name: main.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include "recursion_partition.cpp"
#include "extreme.cpp"
#include "ksmallvalue.cpp"

using namespace std;

template <class T = int >
void display(vector<T>& arr, string str = "")
{
        if (str.length() > 0)
        {
              cout << str << endl;  
        }
        copy(arr.begin(),arr.end(),ostream_iterator<T>(cout, " "));
        cout << endl;
}


int main(void)
{
	cout << "数组的序列规则如下：" << endl;
	cout << "    -1 (降序) " << endl;
	cout << "     0 (随机) " << endl;
	cout << "     1 (升序) " << endl;
	cout << "请输入数值： ";
        int flag = 0;
	cin >> flag;	

	unsigned length = 0; 
        cout << "请输入数组长度： ";
        cin >> length;
        
        unsigned min = 0, max = 100;
        vector<int> arr(length);
                
        srand(unsigned(time(0))); 
	
	if( flag > 0) 
	{
                arr[0] = min + rand()%(max - min);
        	for (unsigned i = 1;i < length; ++i)
                	arr[i] = arr[i-1] + rand()%(max - min);
	        display(arr, "自动生成数组如下： ");
	        cout << "数组的最小值min：" << arr[0] << endl;
	        cout << "数组的最大值max：" << arr[length-1] << endl;
	        
       	
	        cout << "计算第k小的数"<< endl;
		cout << "请输入k的值（" << 1 << "<=k<=" << arr.size() << "）：";
	        unsigned k = 1;
	       	cin >> k;
		if (k <= length && k > 0)
		{
		        cout << "第" << k << "小的数，array[" << (k-1) << "]: " << arr[k-1] << endl;
		}

		return 0;
	} 
	else if (flag < 0) 
	{
                arr[length-1] = min + rand()%(max - min);
        	for (unsigned i = 1; i < length; ++i)
                	arr[length-i-1] = arr[length-i] + rand()%(max - min);
        	display(arr, "自动生成数组如下： ");
	        cout << "数组的最小值min：" << arr[length-1] << endl;
	        cout << "数组的最大值max：" << arr[0] << endl;
        
       	
	        cout << "计算第k小的数"<< endl;
		cout << "请输入k的值（" << 1 << "<=k<=" << arr.size() << "）：";
	        unsigned k = 1;
	        cin >> k;
		if (k <= length && k > 0)
		{
		        cout << "第" << k << "小的数，array[" << (k-1) << "]: " << arr[length - k] << endl;
		}

		return 0;
	} 
	else 
	{
        	for (unsigned i = 0;i < length; ++i)
                	arr[i] = min + rand()%(max - min);
	}
 
        display(arr, "自动生成数组如下： ");
       	extreme(arr, 0, length-1, min, max);        
        cout << "数组的最小值min：" << arr[min] << endl;
        cout << "数组的最大值max：" << arr[max] << endl;
        
	display(arr, "检索后数组如下： ");
       	
        cout << "计算第k小的数"<< endl;
	cout << "请输入k的值（" << 1 << "<=k<=" << arr.size() << "）：";
        unsigned k = 1;
        cin >> k;
	if (k <= length && k > 0)
	{
	        cout << "第" << k << "小的数，array[" << (k-1) << "]: " << ksmallvalue(k, arr) << endl;
	}

	recursion(arr, 0, length-1); 
        display(arr, "排序后结果如下： ");

        return 0;
}

