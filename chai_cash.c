//  Always deliver the lowest number of possible notes;
// 	It’s possible to get the amount requested with available notes;
// 	The client balance is infinite;
// 	Amount of notes is infinite;
// 	Available notes $ 100,00; $ 50,00; $ 20,00 e $ 10,00

#include <stdio.h>
#include <string.h>

void main()
{

int x; // input number
//int answer[200]={};
int U[4]={100,50,20,10};
int factors[4]={0};
int rem;
int i,j,a;

// false if money in not divisible by 10

printf("Enter a number between 10 and 10000: ");

scanf("%d",&x);

if (x % 10 != 0)
{
  printf("You entered a wrong number, try again! \n\r");
  return;
}

if( (x>10000) || (x<10)  )
{
  printf("You entered a wrong number, try again! \n\r");
  return;
}

// start of splitting
if (x>=100)
{
  factors[0]=x/100;
  rem= x%100;  printf("1--check rem %i \n\r",rem);
  x=rem;
}

if( x>=50)
{
  factors[1]=x/50;
  rem= x%50; printf("2--check rem %i \n\r",rem);
  x=rem;
}

if( x>=20)
{
  factors[2]=x/20;
  rem= x%20;printf("3--check rem %i \n\r",rem);
  x=rem;
}

factors[3]=x/10;

//start of interpreting
for(i=0;i<4;i++)
{
  a = factors[i]; //printf("a=%i",a);

  for(j=0;j<a;j++)
    printf("%.2f  ",(float)U[i]);

}//end for

//printf("--Ans %d - %s \n\r",x,answer);
}//end main
