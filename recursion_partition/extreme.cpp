/*************************************************************************
	>    File Name: extreme.cpp
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

