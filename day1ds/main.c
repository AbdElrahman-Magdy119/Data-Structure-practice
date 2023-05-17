#include <stdio.h>
#include <stdlib.h>
#include "ex.h"

int main()
{
    linkedlist l={NULL,NULL};

    add(&l,4);
    add(&l,5);
    add(&l,3);
    add(&l,6);
    add(&l,2);
    add(&l,1);
    display (&l);
    bubblesort(&l);
    printf("\n");
    display (&l);
      printf("\n");

      printf("enter number want to search \n");
      int number;
      scanf("%i",&number);
   int index= binarysearch (&l,number);

     if(index == -1)
         printf("\n number not found  \n");
     else
         printf("\n index of number = %i is  %i \n",number,index);

    return 0;
}
