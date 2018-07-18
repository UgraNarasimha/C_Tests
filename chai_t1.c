#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	//initialization
	int A,B;												//input numbers
	char Astring[20], Bstring[20];	//converted to char array or string(?!)
	char des[20];										//Destination array to gather the digits
	long int final_number;					//Final number
	int nA=0,nB=0;											//Length of array
	int i, index=0;

	//macro template for max of 2 numbers
	#define MAX(a,b) ({ \
		typeof(a) _a_temp_; \
		typeof(b) _b_temp_; \
		_a_temp_ = (a); \
		_b_temp_ = (b); \
		_a_temp_ = _a_temp_ < _b_temp_ ? _b_temp_ : _a_temp_; \
	})
	//macro template for max of 2 numbers
	#define MIN(a,b) ({ \
		typeof(a) _a_temp_; \
		typeof(b) _b_temp_; \
		_a_temp_ = (a); \
		_b_temp_ = (b); \
		_a_temp_ = _a_temp_ > _b_temp_ ? _b_temp_ : _a_temp_; \
	})

	printf("Hello World! int size: %ld\n\r", sizeof(int));
	// printf("The smaller number is %i\n\r",MIN(A,B));

	// Lass uns es tun!
	printf("Enter 2 numbers : "); scanf("%d%d",&A,&B);

	//step 1 convert int to array of char i.e string
	sprintf(Astring,"%d",A);
	printf("A is %s\n\r",Astring);

	sprintf(Bstring,"%d",B);
	printf("B is %s\n\r",Bstring);

	// calculate the Length of array
	//nA = sizeof(Astring)/sizeof(Astring[0]);
	//nB = sizeof(Bstring)/sizeof(Bstring[0]); // gives 20 Ah!
	for(i=0;i<20;i++)
	{
		if (Astring[i] != '\0')
		nA++;
		else
		break;
	}
	for(i=0;i<20;i++)
	{
		if (Bstring[i]!='\0')
		nB++;
		else
		break;
	}

	printf("len of A %d len of B %d\n\r",nA,nB);

	// concatenation loop
	for(i=0;i<MIN(nA,nB);i++)
	{
		des[index]=Astring[i];
		des[index+1]=Bstring[i];
		index+=2; printf(" %d ",index);
	}
	printf("\n loop end i=%d \n",i);
	//to handle the rest of the dings left in the bigger array
	if (nA > nB)
	{ printf("case 1  \n");
		while (i != nA)
		{ printf(". ");
			des[index++]=Astring[i++];
		}
	}
	else if(nB>nA)
	{
		printf("case 2  \n");
		while (i != nB)
		{ printf(". ");
			des[index++]=Bstring[i++];
		}
	}

	//to convert string into int.
	sscanf(des, "%ld", &final_number);
	printf("\n---The number is : %ld ---\n", final_number);
}
