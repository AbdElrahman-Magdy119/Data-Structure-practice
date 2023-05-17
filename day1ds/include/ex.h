#ifndef EX_H
#define EX_H
typedef struct Node Node;
 struct Node
{
    int data;
    Node *pre, *next;
};
typedef struct linkedlist
{
    Node *head,*tail;

}linkedlist;

//Node *head=NULL,*tail = NULL;

void add(linkedlist * l,int data)
{
    Node *n=malloc(sizeof(Node));
    n->next=n->pre=NULL;
    n->data=data;

    if(l->head == NULL)
    {
        l->head = l->tail = n;
    }
    else
    {
        n->pre=l->tail;
        l->tail->next=n;
        l->tail=n;
    }

}


void display (linkedlist * l)
{
    Node *current;
    current = l->head;
    while(current != NULL)
    {
        printf("%i\t",current->data);
        current = current->next;
    }
}
Node* GetNodeByData(linkedlist * l,int data)
{
    Node *current= l->head;

    while(current != NULL)
    {
        if(current->data == data)
            return current;

        current = current->next;
    }

    return NULL;
}

void Remove( linkedlist * l,int data)
{
    Node *n = GetNodeByData(l,data);
    if(n == NULL)
    {
        printf("this item is not found in list \n");
        return;
    }
    else if( n == l->head)
    {
       if( l->head == l->tail )
       {
           l->head=l->tail=NULL;
       }
       else
       {
           l->head=l->head->next;
           l->head->pre=NULL;
       }
    }
    else if( n == l->tail)
    {
        l->tail=l->tail->pre;
        l->tail->next=NULL;
    }
    else
    {
        n->pre->next=n->next;
        n->next->pre=n->pre;
    }




}

void InsertAfter(linkedlist *l,int data, int afterData)
{
    Node *n= GetNodeByData(l,afterData);
    if(n == l->tail)
    {
        add(l,data);
        return;
    }
    else
    {
        Node *newn=malloc(sizeof(Node));
        newn->next=newn->pre=NULL;
        newn->data=data;

        newn->next=n->next;
        newn->pre=n;
        n->next=newn;
        newn->next->pre=newn;

    }
}
int GetDataByIndex(linkedlist *l,int index)
{
    int counter=0;
    Node *current=l->head;
    while(current != NULL)
    {
        if(index == counter)
        {
            return current->data;
        }
        current=current->next;
        counter++;
    }



}

int GetCount(linkedlist *l)
{
    Node *current=l->head;
    int counter=0;
    while( current!= NULL )
    {
        counter++;
        current=current->next;
    }
    return counter;
}
void InPlaceReverse(linkedlist *l)
{
   Node *current=l->tail;
   Node *temp;
   while( current != NULL)
   {
       temp=current->pre;
       current->pre=current->next;
       current->next=temp;
       current=current->next;
   }
   temp=l->head;
  l->head=l->tail;
  l->tail=temp;
}
void Reverse(linkedlist *l,linkedlist *l1)
{
    Node *current=l->tail;
    while(current !=NULL)
    {
        add(l1,current->data);
        current=current->pre;
    }

}
void swap (int *x ,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort (linkedlist *l)
{
    int sort=0;
    Node *current = l->head;
    int count = GetCount(l);

   for (int i=0;i<count-1&&sort==0;i++)
   {
       sort=1;
    while (current->next != NULL)
    {
        if(current->data > current->next->data)
        {
            swap(&current->data,&current->next->data);
            sort=0;
        }
        current=current->next;
    }
    current = l->head;

   }

}

int binarysearch (linkedlist *l, int items )
{
    int count = GetCount(l);
    int min =0,max=count-1,mid;
    while (min <= max)
    {
        mid = (min+max)/2;
        if(items == GetDataByIndex(l,mid))
            return mid;
         if(items > GetDataByIndex(l,mid) )
            min = mid+1;
        else
            max= mid-1;
    }

    return -1;
}



#endif // EX_H
