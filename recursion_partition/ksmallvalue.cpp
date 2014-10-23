/*************************************************************************
	>    File Name: ksmallvalue.cpp
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


template <class T = int >
void extreme(vector<T>& arr, unsigned start, unsigned end, unsigned& min, unsigned& max)
{
	if (end < start)
	{
		printf("Array Error!");
		exit(-2);
	}

	if (end == start)
	{
		return;
	}

	if (end - start == 1)
	{		
		arr[start] < arr[min] ? min = start : (arr[end] < arr[min] ? min = end : min);
		arr[start] > arr[max] ? max = start : (arr[end] > arr[max] ? max = end : max);
		return;
	}

        extreme(arr, start, (start+end)/2, min, max);
        extreme(arr, (start+end+1)/2, end, min, max);
}


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

int findValue(int k,int* a,int start,int end)
{
    
    int low=start;
    int high=end;
    int x=a[start];
    int flag=0;
    while (low!=high)
    {
        if (flag==0)
        {
            for (int j=high;j>=low;j--)
            {
                if (a[j]<x)
                {
                    a[low]=a[j];
                    high=j;
                    flag=1;
                    break;
                } 
                else
                {
                    if(j==low) high=low;
                }
            }
        } 
        else
        {
            for (int j=low;j<=high;j++)
            {
                if (a[j]>x)
                {
                    a[high]=a[j];
                    low=j;
                    flag=0;
                    break;
                } 
                else
                {
                    if(j==high) low=high;
                }
            }
        }
    }
    a[low]=x;
    if ((low-start+1)==k)
    {
        return a[low];
    }
    else if ((low-start+1)>k)
    {
        return findValue(k,a,start,low-1);
    }
    else
    {
        return findValue(k-(low-start)-1,a,low+1,end);
    }
    
}
