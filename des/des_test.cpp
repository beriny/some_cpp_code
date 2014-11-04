// des test
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
}
