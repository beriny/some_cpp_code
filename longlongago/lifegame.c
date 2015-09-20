/*
 * lifegame.c
 * Copyright (C) 2014 - Jiang
 *
 * lifegame.c is free software; you can redistribute it and/or modify
 * it under the terms of the Just-For-Fun Public License  or How Casually License as published 
 *
 * lifegame.c is distributed while I don't know whether it is useful.  
 *
 * See the Just-For-Fun Public License for more details, 
 * BUT You may not receive a copy of the Just-For-Fun Public License
 * along with lifegame.c. So, please see <http://www.ligelaige.com/just-for-fun/license/>.
 */


/*
 *    File Name: lifegame.c
 *       Author: Jiang
 *        Email: ligelaige@gmail.com
 * Created Time: 2014-04-08 14:31:06.228457 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEAD 0
#define ALIVE 1

int ** InitCell(int RowLength, int ColLength, int sum)
{
	int** cell = (int **)malloc(sizeof(int *) * RowLength); 		
	
	int row, col;
	for (row = 0; row < RowLength; ++row)
	{
		cell[row] = (int *)malloc(sizeof(int) * ColLength); 
		
		for (col = 0; col < ColLength; ++col)
		{
			cell[row][col] = DEAD;
		}
	}	
	
	int num = 0;
	
	srand((int)time(0));
	
	while (num < sum)
	{
		row = rand() % RowLength;
		col = rand() % ColLength; 
		if(cell[row][col] == DEAD)
		{	
			cell[row][col] = ALIVE;
			num ++;
		}	
	}
	
	return cell;	
}

int LinSum(int row, int col, int** cell, int RowLength, int ColLength)
{
	int count = 0, c, r;
	
	for (r = row-1; r < row+2; ++r)
	{
		for (c = col-1; c < col+2; ++c)
		{
			count += cell[(r+RowLength) % RowLength][(c+ColLength) % ColLength];
		}
	}
	
	return count - cell[row][col];	
}

void OutCell(int** cell, int RowLength, int ColLength)
{
	int row, col;	
	char* status[2] = {"○ ", "● "};
	
	for(row = 0; row < RowLength; ++row)
	{
		for(col = 0; col < ColLength; ++col)
		{
			printf("%s", status[cell[row][col]]); 
		}
		printf("\n");
	}
}

int CellFunc(int** cell, int RowLength, int ColLength, int** celltemp)
{
	int row, col;
	int count = 0;

	for(row = 0; row < RowLength; ++row)
	{
		for(col = 0; col < ColLength; ++col)
		{
			celltemp[row][col] = DEAD;
			
			switch(LinSum(row, col, cell, RowLength, ColLength))
			{
				case 2:
					celltemp[row][col] = cell[row][col];
					break;
				case 3:
					celltemp[row][col] = ALIVE;
					break;
				default:					
				celltemp[row][col] = DEAD;
					break;					
			}
			
			count += celltemp[row][col];
		}
	}
		
	for(row = 0; row < RowLength; ++row)
	{
		for(col = 0; col < ColLength; ++col)
		{
			cell[row][col] = celltemp[row][col];			
		}
	}
	
	return count;
}

int main (int argc, char *argv[])
{
	int RowLength = 30, ColLength = 79;	
	int num = RowLength * ColLength / 4;
	
	int** cell = InitCell(RowLength, ColLength, num);
	int** celltemp = InitCell(RowLength, ColLength, 0);		
	
	printf("\nCell Stute\n");	
	printf("the num of cell: %d\n", num);
	OutCell(cell, RowLength, ColLength);
		
	while(num != 0)
	{
	        system("clear");

		//getchar();
		fflush(stdin);
		num = CellFunc(cell, RowLength, ColLength, celltemp);	
		
		printf("the num of cell: %d\n", num);
		OutCell(cell, RowLength, ColLength);
	        sleep(1);		
	}
		
	return 0;
}
