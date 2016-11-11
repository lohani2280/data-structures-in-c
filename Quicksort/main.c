#include<stdio.h>

void Swap(int* a,int* b)
{
    int x;
    x = (*a);
    (*a) = (*b);
    (*b) = x;
}

int Partition(int ar[], int start , int end)
{
    int pivot = ar[end];
    int pindex = start;
    int i;
    for(i=start;i<=end-1;i++)
    {
        if(ar[i] <= pivot)
        {
            Swap(&(ar[pindex]),&(ar[i]));
            pindex++;
        }
    }

    Swap(&(ar[pindex]),&(ar[end]));
    return pindex;
}

void Quicksort(int ar[] , int start , int end)
{

  if(start<end)
  {
      int pindex = Partition(ar,start,end);
      Quicksort(ar,start,pindex-1);
      Quicksort(ar,pindex+1,end);
  }
}


int main()
{
    int n,i,k;
    printf("Enter no. of elements :: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in array ::\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Quicksort(arr,0,n-1);

    for(k=0;k<n;k++)
    {
        printf("%d " ,arr[k]);
    }

 return 0;
}
