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

using namespace std;

template <class T = int >
T findvalue(unsigned k, vector<T>& a,unsigned start, unsigned end)
{
    
    unsigned low=start;
    unsigned high=end;
    T x=a[start];
    int flag=0;
    while (low!=high)
    {
        if (flag==0)
        {
            for (unsigned j=high;j>=low;j--)
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
            for (unsigned j=low;j<=high;j++)
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
        return findvalue(k,a,start,low-1);
    }
    else
    {
        return findvalue(k-(low-start)-1,a,low+1,end);
    }
    
}


template <class T = int >
T ksmallvalue(unsigned k, vector<T>& arr)
{
	return findvalue(k, arr, 0, arr.size()-1);
}
