/*************************************************************************
	>    File Name: recursion_partition.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
	>      Compile: g++ -o recursion_partition recursion_partition.cpp -std=c++11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

template <class T = int >
void recursion(vector<T>& arr, unsigned start, unsigned end, unsigned& min, unsigned& max)
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

        recursion(arr, start, (start+end)/2, min, max);
        recursion(arr, (start+end+1)/2, end, min, max);
}

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
        unsigned length = 55; 
        cout << "请输入数组长度： ";
        cin >> length;
        
        unsigned min = 0, max = 100;
        vector<int> arr(length);
                
        srand(unsigned(time(0)));        
        for (unsigned i = 0;i < arr.size(); ++i)
                arr[i] = min + rand()%(max - min);
                            
        display(arr, "自动生成数组如下： ");
       
       	recursion(arr, 0, length-1, min, max);        
        cout << "数组的最小值min：" << arr[min] << endl;
        cout << "数组的最大值max：" << arr[max] << endl;
        
	display(arr, "检索后数组如下： ");

        return 0;
}

