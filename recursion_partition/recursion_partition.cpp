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
void recursion(vector<T>& arr, unsigned low, unsigned high)
{
        unsigned mid = 0;
        if(low < high)
		{
                mid = partition(arr, low, high);
                recursion(arr, low, mid-1);
                recursion(arr, mid+1, high);
        }
}

template <class T = int >
int recursion_k(vector<T>& arr, unsigned low, unsigned high, unsigned k)
{
        unsigned mid = 0;
        
        if(low < high)
        {
                if(k == mid)
                        return arr[mid];
                else if(k < mid)
                        return recursion_k(arr, low, mid-1, k);
                else 
                        return recursion_k(arr, mid+1, high, k);
        }
        return arr[mid];
}


