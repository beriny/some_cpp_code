#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int partition(int* arr, int low, int high) 
{
        int temp = arr[low];
        while(low<high) {
                while( low<high && arr[high]>=temp ) --high;                
                arr[low] = arr[high];            
                while( low < high && arr[low]<temp ) ++low;                
                arr[high] = arr[low];
        }
        arr[low] = temp;
        return low;
}

void recursion(int* arr,int start,int end) 
{
        int mid = 0;
        if(start < end) 
		{
                mid = partition(arr, start, end);
               // mid = partition(arr, start, end);
                recursion(arr, start, mid-1);
		recursion(arr, mid+1, end);
        }
}

void display(int* arr, int length, const char* str) 
{
	printf("%s\n", str);  
        for (int i = 0; i < length; ++i)
	{
		int a;	
		printf("%-2d ", arr[i]);
		a=i+1;
		if(a%20==0)
			printf("\n");
				
        }
        printf("\n");
}

void extremeMin(int* arr,int low, int length)
{
	 int  mid;
	 mid = partition(arr, low, length);
	 if(mid==0)
	 {
		 printf("数组的最小值是:%d\n",arr[mid]);
	 }
	 else
	 {	 
		 printf("计算min值的中间量：arr[%d]=%d\n", mid, arr[mid]);
		 extremeMin(arr, 0,mid-1);
	 }
    
}


void extremeMax(int* arr,int low, int length)
{
	 int mid ;
	 mid = partition(arr, low, length);
	 if(mid==length)
	 {
		 printf("数组的最大值是:%d\n",arr[mid]);
	 }
	 else
	 {
		printf("计算max值的中间量：arr[%d]=%d\n", mid, arr[mid]);
		extremeMax(arr, mid+1,length);   
	 }
}

void  extremeK(int* arr,int low, int length,int k)
{
	
	int  mid;
	mid = partition(arr, low, length);
	if(mid==k)
		printf("数组的第K小值:%d\n",arr[mid]);
	else
	{
		printf("计算K值的中间量：arr[%d]=%d\n", mid, arr[mid]);
	    	if(mid>k)
			extremeK(arr,low, mid-1,k);
		else
			extremeK(arr,mid+1, length,k);
	}
    
}

void show()
{
	printf("\n");
	printf("===================== 随机数组的问题求解================\n\n");
	printf("**********************1.数组的最大值 *******************\n\n");
	printf("**********************2.数组的最小值 *******************\n\n");
	printf("**********************3.数组的第K小值*******************\n\n");
	printf("**********************4.退  出       *******************\n\n");
}

void print(int *arr,int k)
{
	printf("%d\n",arr[k]);
}

int main()
{
	    show();
        int length,k; 
		int ch;
		char n;
        printf("请输入数组长度： ");  
        scanf("%d", &length);        
        int min = 0, max = 100;
		int *arr = (int *)malloc(length * sizeof(int));
		if(arr == NULL) 
		{
			printf("Memory Error!\n");
			exit(-1);			
		}               
        srand((int)time(0));        
        for (int i = 0;i < length; ++i)
                arr[i] = min + rand()%(max - min);                          
        display(arr, length, "自动生成数组如下： ");
		while(1)
		{
			printf("请输入你的选择:");
			scanf("%d",&ch);
			switch(ch)
			{
			case 1:    
				extremeMax(arr,0,length-1);
				system("cls"); 
				show(); 
				recursion(arr, 0, length-1);
				display(arr, length, "排序后结果如下： ");
				printf("最大值为:");
				print(arr,length-1);
				break;
			case 2:   
				extremeMin(arr,0,length-1);
				system("cls"); 
				show(); 
				recursion(arr, 0, length-1);
				display(arr, length, "排序后结果如下： ");
				printf("最小值为:");
				print(arr,0);
				break;
			case 3:   
				printf("输入K值:");
				scanf("%d",&k);
				if(k>length||k<=0)
				{
					printf("Memory Error!\n");
					exit(-1);			
				}
				extremeK(arr,0, length-1,k-1);
				system("cls"); 
				show();
				printf("第%d小的值为:",k);
				print(arr,k-1);
				recursion(arr, 0, length-1);
				display(arr, length, "排序后结果如下： ");
				break;
			case 4:		
				system("cls"); 
				show();
				break;
			default: 
				system("cls"); 
				show();
				printf("你的输入有误!请重新输入你的选择\n");
				display(arr, length, "随机数组: ");
				break;
			}
			printf("是否要停止此次操作？退出 请输入Y/y,不退出 请任意输入:");
	
			
			while((n=getchar())!='\n' && n!=EOF);
			n = getchar();
			
			printf ("n=%d\n", (int)n);
			printf ("n=%c\n", n);

			if(n=='Y' || n=='y') 
			{
				break;
			}
		   system("cls");
		   show();
		}
        free(arr);

		return 0;
}

