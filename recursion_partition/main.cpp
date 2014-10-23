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
        unsigned length = 55; 
        cout << "请输入数组长度： ";
        cin >> length;
        
        unsigned min = 0, max = 100;
        vector<int> arr(length);
                
        srand(unsigned(time(0)));        
        for (unsigned i = 0;i < arr.size(); ++i)
                arr[i] = min + rand()%(max - min);
 
        display(arr, "自动生成数组如下： ");
       	extreme(arr, 0, length-1, min, max);        
        cout << "数组的最小值min：" << arr[min] << endl;
        cout << "数组的最大值max：" << arr[max] << endl;
        
	display(arr, "检索后数组如下： ");
        
	recursion(arr, 0, length-1); 
        display(arr, "排序后结果如下： ");

        return 0;
}

