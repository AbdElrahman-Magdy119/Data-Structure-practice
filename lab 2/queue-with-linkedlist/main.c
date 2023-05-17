#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"

int main()
{
    int x;
    queue q ={.tail = NULL , .head = NULL};
    enqueue(&q,10);
    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);

     while(dequeue(&q,&x))
    {
        printf("%i \t",x);
    }

/*
      if(dequeue(&q,&x))
      {
           printf("%i \t",x);
      }
      else
        printf("empty \n");

     if(dequeue(&q,&x))
      {
           printf("%i \t",x);
      }
      else
        printf("empty \n");

       if(dequeue(&q,&x))
      {
           printf("%i \t",x);
      }
      else
        printf("empty \n");

*/

     return 0;
}
