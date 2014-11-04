/*
 *             File Name: main.c
 * Operating Environment: ubuntu linux
 *                Author: Jiang
 *                 Email: ligelaige@gmail.com
 *          Created Time: 2014年05月10日 星期六 11时58分58秒 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stof.c"

#define BUFFSIZE 128

int main ()
{

	FILE *in= NULL;
	FILE *out= NULL;
	        
        if((in = fopen("infile.txt", "r")) == NULL)
        {
                printf("fopen error\n");
                return 0;
        }
        if((out = fopen("outfile.txt", "w")) == NULL)
        {
                printf("fopen error\n");
                return 0;
        }
        
        char str[BUFFSIZE];
	double result;	
        
        while(fgets(str, BUFFSIZE, in))
        {
        	printf("str    : %s", str);
		result = stolf(str);
		printf("result : %lf\n", result);
		fprintf(out, "%lf\n", result);
        }
        
        
        fclose(in);
        fclose(out);
	return 0;
}

