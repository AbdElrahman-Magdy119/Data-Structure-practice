#include <stdio.h>
#include <stdlib.h>
void swap (int *x,int *y)
{
    int temp= *x;
    *x=*y;
    *y=temp;
}
void bublesort(int *a,int size )
{
    int count=0;
    for(int j=0;j<size-1&&count==0;j++)
    {
        count=1;
        for(int i=0;i<size-1-j;i++)
          {
            if(a[i] > a[i+1])
              swap(&a[i],&a[i+1]);
              count=0;
          }

    }


}
void display(int *a,int size )
{
    for(int i=0;i<size;i++)
    {
        printf("%i \t",a[i]);
    }
}
void selectionsort(int *a,int size )
{
    int min;
    for(int j=0;j<size-1;j++)
    {
        min=j;
        for(int i=j+1;i<size;i++)
         {
              if(a[i] < a[min])
                   min =i;
         }
         swap(&a[j],&a[min]);

    }

}
int binarysearch(int *a,int size,int item)
{
    int min=0,mid;
    int max=size-1;
    while(min <= max)
    {
        mid= (min+max)/2;
        if(item == a[mid])
            return mid;
         else if( item > a[mid])
            min=mid+1;
        else
            max=mid-1;

    }
    return -1;
}
void insertionsort (int *a,int size)
{
    int key;
    for(int i=1;i<size;i++)
    {
        key=a[i];
        while(key <a[i-1] && i>0)
        {
            a[i]=a[i-1];
            i--;

        }
        a[i]=key;
    }

}



int main()
{
    int a[]={4,2,3,8,6};
    //bublesort(a,6);
   // display(a,6);
   // selectionsort(a,6);
      insertionsort(a,5);
    display(a,5);
    int x= binarysearch(a,6,6);
    printf("\n %i \n",x);
    return 0;
}
