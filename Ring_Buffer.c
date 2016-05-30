/*
	Task to implement ring buffer with following functions.
    Push: Pushes one or more values into the Buffer
    Pop: Pops one or more values out of the Buffer
    Peek: View current value
    Current Size: Current size of values
    Maximum Size: Maximum size of the Buffer
    Empty: Empties the whole buffer
    Full: Sets all values with given value

    By: Supreeth Raghuprakash
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER 1024

//typedef unsigned long int uint32_t

typedef struct _ringBuffer {
    uint32_t currentIndex;
    uint32_t sizeOfBuffer;
    uint32_t data[NUMBER];
} ringBuffer;

// Definition
ringBuffer Push(uint32_t *data, uint32_t dat_size, ringBuffer R);

uint32_t *Pop(uint32_t dat_size, ringBuffer R);

uint32_t Peek(ringBuffer R);

uint32_t CurrentSize(ringBuffer R);

uint32_t MaxSize(ringBuffer R);

ringBuffer Empty(ringBuffer R);

ringBuffer Full(uint32_t data, ringBuffer R);

// Main function
void main()
{
	/* code */
	ringBuffer Circular_buffer;

	uint32_t array[100];
	uint32_t *rec_array;
	uint32_t Output;
	uint32_t c_size;
	uint32_t mx_size;
	int i;

	// Initializing the circular buffer with random value, 1 in this case
	for (i = 0; i < 1024; i++)
	{
	  Circular_buffer.data[i] = 1;
	}
	
	printf("The following set of functions can be used to play with the Ring Buffer\n");

	// initialization test array.
	for (i = 0; i <= 100; i++)
	{
		array[i]=i;
	}
	
	Circular_buffer = Push(array,100,Circular_buffer);
 	printf("Printing last pushed value %i \n\r",(int) Circular_buffer.data[Circular_buffer.currentIndex-1]);

	rec_array = Pop(10, Circular_buffer);

	for (i = 0; i < sizeof(rec_array); i++)
	{
		printf("Printing rec_array %i \n\r",(int) rec_array[i]);
	}
	
	Output = Peek(Circular_buffer);
 	printf("Printing Peek %i \n\r",(int) Output);

	c_size  = CurrentSize(Circular_buffer);
	
	mx_size = MaxSize(Circular_buffer);
    
    Circular_buffer = Empty(Circular_buffer);
	
	Circular_buffer = Full(7, Circular_buffer);
	printf("Printing Circular_buffer %i \n\r", (int) Circular_buffer.data[0]);
}

//----------------------------------------------------------

ringBuffer Push(uint32_t *data, uint32_t dat_size, ringBuffer R)
{	int i;
	for (i = 0; i <= dat_size; i++)
	{
		if (R.currentIndex < NUMBER)
		{
			R.data[R.currentIndex++]= data[i++];
			R.sizeOfBuffer++;
		}
		else
		{
			R.currentIndex=0;
			R.data[R.currentIndex++]= data[i++];
			R.sizeOfBuffer = 0;
		}	
	}
	return (R); 
}

uint32_t *Pop(uint32_t dat_size, ringBuffer R)
{	
	uint32_t *data = malloc(dat_size);
	int i;

	for (i = 0; i <= dat_size; i++)
	{
		if (0 < R.currentIndex)
		{
			data[i]= R.data[R.currentIndex--];
			R.sizeOfBuffer--;
		}
		else
		{
			R.currentIndex=NUMBER;
			data[i]= R.data[R.currentIndex--];
			R.sizeOfBuffer = 0;
		}	
	}
	return (data); 
}

uint32_t Peek(ringBuffer R){
	return(R.data[R.currentIndex]);
}

uint32_t CurrentSize(ringBuffer R){
	return(R.sizeOfBuffer);
}

uint32_t MaxSize(ringBuffer R){
	return(NUMBER);
}

ringBuffer Empty(ringBuffer R){
	memset(R.data,0,NUMBER);
	printf("Printing Empty %i \n\r", (int) R.data[0]);
	return(R);
}

ringBuffer Full(uint32_t data, ringBuffer R){
	int i;
	//memcpy(R.data,data,NUMBER);
	for (i = 0; i < NUMBER; i++)
	{
		R.data[i]=data;
	}
	
	printf("Printing R %i %i\n\r", (int) R.data[0],data);
	return(R);
}