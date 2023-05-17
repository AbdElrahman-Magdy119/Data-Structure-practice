#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main()
{
    int num;
    queue q ={ .front = -1 , .rear = -1};
    enqueue(&q,10);
    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,15);
 /*  if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");


   if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");


    if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");


    if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");


    if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");


 if(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    else
        printf("empty \n");*/

    while(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }
    enqueue(&q,20);
    enqueue(&q,21);
    while(dequeue(&q,&num))
    {
        printf("%i \t",num);
    }

    return 0;
}
