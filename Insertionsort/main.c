#include<stdio.h>

void Insertionsort(int* ar , int len)
{
  int i,hole,value;
  for(i=1 ; i<= len-1 ; i++)
  {
      value = ar[i];
      hole = i;
      while(hole>0 && ar[hole-1]>value)
      {
          ar[hole] = ar[hole-1];
          hole = hole - 1;
      }

      ar[hole] = value;
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

    Insertionsort(arr,n);
    printf("Sorted array :: ");
    for(i=0;i<n;i++)
    {
        printf("%d | " , arr[i]);
    }
    return 0;
}
