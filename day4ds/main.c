#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree t={.root=NULL};
    add(&t,50);
    add(&t,25);
    add(&t,30);
    add(&t,70);
    add(&t,60);
    add(&t,20);
    add(&t,100);
    add(&t,15);
    add(&t,22);
    display(t.root);
    printf("\n");
 //   removee(&t,15);
  //  removee(&t,60);
    removee(&t,22);
   display(t.root);
    printf("\n");
   int x=GetMaxDepth(t.root);
  printf("%i \n",x);
    return 0;
}
