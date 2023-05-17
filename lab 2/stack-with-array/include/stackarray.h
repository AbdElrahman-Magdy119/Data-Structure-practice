#ifndef STACK_H
#define STACK_H
#define max 5

typedef struct stack
{
    int item[max];
    int top;

}stack;
void push(stack * s,int data)
{
    if(s->top == max )
        return;
    else
       {
           s->top++;
            s->item[s->top]=data;

       }

}
int pop (stack * s,int *num)
{
    if(s->top == -1)
        return 0;
    *num = s->item[s->top];
    s->top--;
    return 1;

}





#endif // STACK_H
