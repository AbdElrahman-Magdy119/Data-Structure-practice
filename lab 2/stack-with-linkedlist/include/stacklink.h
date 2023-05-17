#ifndef STACKLINK_H
#define STACKLINK_H
typedef struct node node;
typedef struct node
{
    int data;
    node *next;


}node;
typedef struct stack
{

    node *tail;

}stack;

 void push (stack *s,int data)
 {
     node *n =malloc(sizeof(node));
     n->data=data;
     n->next=s->tail;
     s->tail=n;

 }

 int pop (stack * s,int *num)
 {

     if(s->tail == NULL)
        return 0;
     *num = s->tail->data;
      s->tail=s->tail->next;

     return 1;

 }




#endif // STACKLINK_H
