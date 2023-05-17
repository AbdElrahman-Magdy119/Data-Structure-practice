#ifndef QUEUE_H
#define QUEUE_H
#define max 5
typedef struct queue
{
    int item[max];
    int front ,rear;

}queue;
void enqueue (queue *q,int data)
{
    if( (q->rear == max-1 && q->front == 0) || q->front == q->rear+1 )
        return;

    if(q->front == -1)
    {
        q->front++;
    }
    q->rear++;
   q->item[q->rear]=data;
   if(q->rear == max-1)
     q->rear= -1 ;
}
int dequeue (queue *q,int *num)
{
    if( (q->front == -1 ) && (q->rear == -1 ))
        return 0;
    *num = q->item[q->front];
    if( q->front == q->rear)
     {
         q->front=q->rear=-1;
     }
   else
      {
           q->front++;
          if(q->front == max)
            q->front = -1;
          return 1;
      }





}



#endif // QUEUE_H
