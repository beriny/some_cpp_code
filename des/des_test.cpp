/*************************************************************************
	>    File Name: des_test.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Tue 04 Nov 2014 11:27:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "des.h"

#define SIZE 128

unsigned getaline(char* str)
{
	char c='\n';
	unsigned i = 0;
	do
	{
		c = getchar();
		str[i++] = c;
	} while(c != '\n');
	
	str[i-1] = '\0';
	return i-1;
}

void writeline(const char a[], const char b[])
{
	printf("%s: [", a);
	printf("%s", b);
	printf("]\n");
}

int main(void)
{
	char key[8]={1,9,8,0,9,1,7};
	char str[SIZE];
	Des_SetKey(key);
	
	printf("Enter a string(<=128): ");
	unsigned length = getaline(str);

	writeline("Before encrypting", str);

	for (int i=0; i<length; i+= 8)
	{
		Des_Run(str+i, str+i, ENCRYPT);
	}
	writeline("After  encrypting", str);

	for (int i=0; i<length; i+= 8)
	{
		Des_Run(str+i, str+i, DECRYPT);
	}
	writeline("After  decrypting", str);

	return 0;
}
