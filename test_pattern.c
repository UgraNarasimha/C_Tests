#include "stdio.h"

int main()
{
	printf("Enter a Number: ");
	int num;
	int i,j;
	scanf("%d",&num);

	for (i = 1; i <= num; i++)
	{
		//blank for loop
		for (j = 0; j < num-i; j++)
		{
			printf(" ");
		}
		//# for loop
		for (j = 0; j < i; j++)
		{
			printf("#");
		}
		printf("\n\r");		
	}

	return 0;
}