#include<stdio.h>


void Swap(int* a , int* b)
{
  int x;
  x = (*a);
  (*a) = (*b);
  (*b) = x;
}


void Selectionsort(int* ar , int len)
{
  int i;
  int start=0;
  int i_min;
  while(start <= len-1)
  {
    i_min = start;
    for(i = start+1 ; i<len ; i++)
    {
        if(ar[i_min] > ar[i])
      {
          i_min = i;

      }
    }
  Swap(&ar[start] , &ar[i_min]);
  start++;
  }
}


int main()
{
    int n,i;
    printf("Enter no. of Elements in array :: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in the array ::\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Selectionsort(arr,n);
    printf("Sorted array :: ");
    for(i=0;i<n;i++)
    {
        printf("%d | " , arr[i]);
    }
    return 0;
}
