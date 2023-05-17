#ifndef QUEUELINKED_H
#define QUEUELINKED_H
typedef struct node node;
typedef struct node
{
    int data;
    node *next;

}node;
typedef struct queue
{
    node *tail,*head;


}queue;

void enqueue (queue * q ,int data)
{
    node *n =malloc(sizeof(node));
    if (q->head == NULL)
    {

         q->head = q->tail = n;
         n->data=data;
    }

    q->tail->next=n;
    q->tail=n;
    n->data=data;
}
int dequeue (queue *q,int *num)
{
    if(q->head == NULL)
     return 0;

    *num = q->head->data;
    node *temp=q->head;
    q->head=q->head->next;
    free(temp);
    return 1;

}


#endif // QUEUELINKED_H
