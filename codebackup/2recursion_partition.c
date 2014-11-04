/*************************************************************************
	>    File Name: recursion_partition.c
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
	>      Compile: gcc -o 2recursion_partition 2recursion_partition.c -std=c99
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned partition(int* arr, unsigned low, unsigned high) 
{
        int pivot = arr[low];
        while(low<high) {
                while( low<high && arr[high]>=pivot ) --high;                
                arr[low] = arr[high];            
                while( low < high && arr[low]<=pivot ) ++low;                
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

int recursion_k(int *arr, unsigned low, unsigned high, unsigned k)
{
        unsigned mid = 0;
        if(low < high)
        {
                mid = partition(arr, low, high);

                if(k == mid)
                        return arr[mid];
                else if(k > mid)
                        return recursion_k(arr, mid+1, high, k);
                else 
                        return recursion_k(arr, low, mid-1, k);
        }
        return arr[mid];
}

void display(int* arr, unsigned length, char* str) 
{
		printf("%s\n", str);  
        for (unsigned i = 0; i < length; ++i)
		{
				printf("%d ", arr[i]);
        }
        printf("\n");
}

void extreme(int* arr, unsigned start, unsigned end, unsigned* min, unsigned* max)
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
		arr[start] < arr[*min] ? *min = start : (arr[end] < arr[*min] ? *min = end : *min);
		arr[start] > arr[*max] ? *max = start : (arr[end] > arr[*max] ? *max = end : *max);
		return;
	}

        extreme(arr, start, (start+end)/2, min, max);
        extreme(arr, (start+end+1)/2, end, min, max);
}

int main(void)
{
        int flag = 0;
        unsigned length = 0, k = 1;
        int min = 0, max = 100;        
                
        printf ("数组的序列规则如下：\n");
	printf ("    -1 (降序) \n");
	printf ("     0 (随机) \n");
	printf ("     1 (升序) \n");
	printf ("请输入数值： ");
	scanf ("%d", &flag);	
	
        printf ("请输入数组长度： ");
        scanf ("%d", &length);                
        
	int* arr = (int *) malloc (length * sizeof(int));
	int* arrtmp = (int *) malloc (length * sizeof(int));
		
	if(arr == NULL || arrtmp == NULL) 
	{
		printf("Memory Error!\n");
		exit(-1);			
	}
                
        srand((unsigned)time(0));  
                
        if( flag > 0) 
	{
                arr[0] = min + rand()%(max - min);
                for (unsigned i = 1; i<length; ++i)
                        arr[i] = arr[i-1] + rand()%(max - min);
                        
	        display(arr, length, "自动生成数组如下： ");	        
	        printf ("数组的最小值min：%d\n", arr[0]);
	        printf ("数组的最大值max：%d\n", arr[length-1]);	        
       	
	        printf ("计算第k小的数\n");
		printf ("请输入k的值(1 <=k<= %d): ", length);	      
		scanf("%d", &k);
		
		if (k <= length && k > 0)
		{
		        printf ("第%d小的数，array[%d]: %d\n", k, k-1, arr[k-1]);
		}
	} 
	else if (flag < 0) 
	{
                
		arr[length-1] = min + rand()%(max - min);
                for (unsigned i = 1; i<length; ++i)
                        arr[length-i-1] = arr[length-i] + rand()%(max - min);
                        
                display(arr, length, "自动生成数组如下： ");
	        printf ("数组的最小值min：%d\n", arr[length-1]);
	        printf ("数组的最大值max：%d\n", arr[0]);
	               	
	        printf ("计算第k小的数\n");
		printf ("请输入k的值(1 <=k<= %d): ", length);	
		scanf("%d", &k);
		
		if (k <= length && k > 0)
		{
		        printf ("第%d小的数，array[%d]: %d\n", k, k-1, arr[length-k]);
		}
	} 
	else
	{	                      
                for (unsigned i = 0; i<length; ++i) 
                {
                        arr[i] = min + rand()%(max - min);
                        arrtmp[i] = arr[i];
                }                

                display(arr, length, "自动生成数组如下： ");
                extreme(arr, 0, length-1, &min, &max);
                printf ("数组的最小值min：%d\n", arr[min]);
                printf ("数组的最大值max：%d\n", arr[max]);

                display(arr, length, "检索后数组如下： ");

                printf ("计算第k小的数\n");
                printf ("请输入k的值(1 <=k<= %d): ", length);
                scanf("%d", &k);
                                
                if (k <= length && k > 0)
                        printf ("第%d小的数，array[%d]: %d\n", k, k-1, recursion_k(arrtmp, 0, length - 1, k-1));
                                
                //recursion(arr, 0, length-1); 
                display(arr, length, "排序后结果如下： ");                                
	}
	
	free(arr);
	free(arrtmp);	
        return 0;
}

