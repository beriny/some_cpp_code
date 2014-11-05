/*************************************************************************
	>    File Name: ksmallvalue.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Sun 12 Oct 2014 08:09:27 PM CST
	>   OS Version: CentOS
 ************************************************************************/

#include <stdio.h>
#include "ksmallvalue.h"

int findvalue(unsigned k, int* a,unsigned start, unsigned end)
{
    	unsigned low=start;
    	unsigned high=end;
    	int x=a[start];
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
            		for (unsigned j=low; j<=high; j++)
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


int ksmallvalue(unsigned k, int* arr, unsigned length)
{
	return findvalue(k, arr, 0, length-1);
}
