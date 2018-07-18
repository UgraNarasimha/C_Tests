#include <stdio.h>
#include <string.h>

void main()
{

int x;
char answer[20]={};
char U[4]={'I','X','C','M'};
char F[3]={'V','L','D'}; 

int factors[3];
int rem;
int length,index=0,l,i,a;
//printf("--check U %s \n\r",U);
//printf("--check F %s \n\r",F);

check_false: printf("Enter a number between 1 and 1000: ");

scanf("%d",&x);

if( (x>1000) || (x<1) )
{ printf("You entered a wrong number, try again! \n\r");
  goto check_false;
}

// start of splitting
if(x==1000)
{
  strcat(answer,"M");
  printf("--Ans %d - %s \n\r",x,answer);
  return;
}
else if (x>=100)
{   factors[0]=x/100;
    rem= x%100;
    factors[1]=rem/10;
    factors[2]=rem%10;
    l=3;
}
else if( x>=10)
{   factors[0]=x/10;
    rem= x%10;
    factors[1]=rem;
    l=2;
}
else
{
    factors[0]=x; l=1;      
}

//start of interpreting
length=l;
for(i=0;i<length;i++)
{
    if(factors[i]==9)
    {
      answer[index++]= U[l-1];
      answer[index++]= U[l];
      goto end;
    }
    else if (factors[i]>=5)
    {     
      a=factors[i]-5;
      answer[index++]=F[l-1];
      while(a!=0)
      {
        answer[index++]=U[l-1];
        a--;
      }   
      goto end;
    }
    else if( factors[i]==4)
    {     
      answer[index++]=U[l-1];
      answer[index++]=F[l-1];
      goto end;
    }
    else
    {
      a=factors[i];
      while(a!=0)
      {
        answer[index++]=U[l-1];
        a--;
      } 
    }
    end:  l--;
}//end for

printf("--Ans %d - %s \n\r",x,answer);
}//end main