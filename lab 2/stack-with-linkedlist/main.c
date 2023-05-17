#include <stdio.h>
#include <stdlib.h>
#include "stacklink.h"
int main()
{
    int x;
    stack s={.tail=NULL};
    push(&s,10);
    push(&s,11);
    push(&s,12);
    push(&s,13);

   while(pop(&s,&x))
    {
        printf("%i \t",x);

    }
      printf("\n\n\n");
     push(&s,20);
     push(&s,21);
     push(&s,22);
     push(&s,23);
    while(pop(&s,&x))
    {
        printf("%i \t",x);

    }
    return 0;
}
