/*************************************************************************
	>    File Name: des_test.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Tue 04 Nov 2014 11:27:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#include <stdio.h>
#include "des.h"

int main(void)
{
	char key[8]={1,9,8,0,9,1,7},str[]="Johnny's DES";

	puts("Before encrypting");
	puts(str);

	Des_SetKey(key);

	Des_Run(str, str, ENCRYPT);
	puts("After encrypting");
	puts(str);

	puts("After decrypting");
	Des_Run(str, str, DECRYPT);
	puts(str);

	return 0;
}
