/*************************************************************************
	>    File Name: recursion_partition.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
 ************************************************************************/

#include "recursion_partition.h"

unsigned partition(int* arr, unsigned low, unsigned high)
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

void recursion(int* arr, unsigned start, unsigned end)
{
        unsigned mid = 0;
        if(start < end)
	{
                mid = partition(arr, start, end);
                recursion(arr, start, mid-1);
                recursion(arr, mid+1, end);
        }
}


