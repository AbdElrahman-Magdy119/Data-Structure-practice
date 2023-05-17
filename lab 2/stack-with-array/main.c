#include <stdio.h>
#include <stdlib.h>
#include "stackarray.h"

int main()
{
    int num;
    stack s ={ .top= -1 };
    push(&s,10);
    push(&s,11);
    push(&s,12);
    push(&s,13);
    push(&s,14);
    pop(&s,&num);
    while(pop(&s,&num))
    {
        printf("%i \t",num);

    }



    return 0;
}
