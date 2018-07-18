#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main ()
{
  srand ( time(NULL) );
  int random_number = rand();

  printf("The random number is %i \n\r",random_number);
  return 0;
}
