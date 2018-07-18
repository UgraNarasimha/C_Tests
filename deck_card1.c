// case study into deck of cards
// C program to deal me a random card in a standard Deck
// A 2 3 4 5 6 7 8 9 10 J Q K
// H D S C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min_num, int max_num);

int main(void)
{
  int factor,remain;
  //char key[12]={'A','2','3','4','5','6','7','8','9','10','J','Q'}; // there is a fault in this... find out
  char *key[]={"A","2","3","4","5","6","7","8","9","10","J","Q"};
  int card_n = random_number(1,52);
  printf("The card is %d\n",card_n);

  //for (int i = 1; i < 53; i++) {
    //card_n = i;
    //-----------------------
    factor=card_n/13;
    remain=card_n%13; //printf("%i ", remain);

    if (remain != 0)
    {
      switch (factor) {
        case 0:
        printf("H %s\n",key[remain-1]);
        //printf("H %i\n",remain);
        break;

        case 1:
        printf("D %s\n",key[remain-1]);
        //printf("D %i\n",remain);
        break;

        case 2:
        printf("S %s\n",key[remain-1]);
        //printf("S %i\n",remain);
        break;
        case 3:
        printf("C %s\n",key[remain-1]);
        //printf("C %i\n",remain);
        break;
      }
    }
    else
    {
      switch (factor) {
        case 1:
        printf("H K\n");
        break;

        case 2:
        printf("D K\n");
        break;

        case 3:
        printf("S K\n");
        break;
        case 4:
        printf("C K\n");
        break;
      }
    }
    //-----------------------

  //}//end of loop

  return 0;
}

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
