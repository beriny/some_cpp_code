/*************************************************************************
	>    File Name: main.c
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "recursion_partition.h"
#include "extreme.h"
#include "ksmallvalue.h"

void display(int* arr, unsigned length, char* str)
{
        printf("%s\n", str);
	
	for (unsigned i=0; i<length; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(void)
{
	printf ("数组的序列规则如下：\n");
	printf ("    -1 (降序) \n");
	printf ("     0 (随机) \n");
	printf ("     1 (升序) \n");
	printf ("请输入数值： ");
        int flag = 0;
	scanf("%d", &flag);

	unsigned length = 0; 
	printf ("请输入数组长度： ");
	scanf("%d", &length);
        
        unsigned min = 0, max = 100;

	int* arr = (int *)malloc(length * sizeof(int));

	if (arr == NULL)
	{
		printf ("Memory Error!");
		exit(-1);
	}
                
        srand((unsigned)time(0)); 
	
	if( flag > 0) 
	{
                arr[0] = min + rand()%(max - min);
        	for (unsigned i = 1;i < length; ++i)
                	arr[i] = arr[i-1] + rand()%(max - min);
	        display(arr, length, "自动生成数组如下： ");
	        printf ("数组的最小值min：%d\n", arr[0]);
	        printf ("数组的最大值max：%d\n", arr[length-1]);
	        
       	
	        printf ("计算第k小的数\n");
		printf ("请输入k的值(1 <=k<= %d): ", length);
	        unsigned k = 1;
		scanf("%d", &k);
		if (k <= length && k > 0)
		{
		        printf ("第%d小的数，array[%d]: %d\n", k, k-1, arr[k-1]);
		}

		return 0;
	} 
	else if (flag < 0) 
	{
                
		arr[length-1] = min + rand()%(max - min);
        	for (unsigned i = 1; i < length; ++i)
                	arr[length-i-1] = arr[length-i] + rand()%(max - min);
        	display(arr, length, "自动生成数组如下： ");
	        printf ("数组的最小值min：%d\n", arr[length-1]);
	        printf ("数组的最大值max：%d\n", arr[0]);
	        
       	
	        printf ("计算第k小的数\n");
		printf ("请输入k的值(1 <=k<= %d): ", length);
	        unsigned k = 1;
		scanf("%d", &k);
		if (k <= length && k > 0)
		{
		        printf ("第%d小的数，array[%d]: %d\n", k, k-1, arr[length-k]);
		}
		
		return 0;
	} 
	else 
	{
        	for (unsigned i = 0;i < length; ++i)
                	arr[i] = min + rand()%(max - min);
	}
 
        display(arr, length, "自动生成数组如下： ");
       	extreme(arr, 0, length-1, &min, &max); 

	printf ("数组的最小值min：%d\n", arr[min]);
	printf ("数组的最大值max：%d\n", arr[max]);
        
	display(arr, length, "检索后数组如下： ");
       

	printf ("计算第k小的数\n");
	printf ("请输入k的值(1 <=k<= %d): ", length);

        unsigned k = 1;


	scanf("%d", &k);
	if (k <= length && k > 0)
	{
	        printf ("第%d小的数，array[%d]: %d\n", k, k-1, ksmallvalue(k, arr, length));
	}

	recursion(arr, 0, length-1); 
        display(arr, length, "排序后结果如下： ");

        return 0;
}

