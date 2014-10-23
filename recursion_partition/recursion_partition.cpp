/*************************************************************************
	>    File Name: recursion_partition.cpp
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

using namespace std;

template <class T = int >
unsigned partition(vector<T>& arr, unsigned low, unsigned high)
{
        int pivot = arr[low];
        while (low < high)
	{
                while ( low<high && arr[high]>=pivot ) --high;
                arr[low] = arr[high];                
                while ( low<high && arr[low]<=pivot ) ++low;                
                arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
}

template <class T = int >
void recursion(vector<T>& arr, unsigned start, unsigned end)
{
        unsigned mid = 0;
        if(start < end)
	{
                mid = partition(arr, start, end);
                recursion(arr, start, mid-1);
                recursion(arr, mid+1, end);
        }
}

template <class T = int >
void extreme_display(vector<T>& arr)
{
        T min = arr[0];
        T max = arr[arr.size() - 1];
        cout << "数组的最小值min：" << min << endl;
        cout << "数组的最大值max：" << max << endl;
        cout << "计算第k小的数"<< endl;
		cout << "请输入k的值（" << 0 << "<=k<=" << (arr.size() - 1) << "）：";
        unsigned k = 0;
        cin >> k;
		if (k >= arr.size()) return;

        cout << "第k小的数，array[" << k << "]: " << arr[k]<< endl;
}

