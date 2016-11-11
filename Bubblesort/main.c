#include<stdio.h>

void Swap(int* a , int* b)
{
    int x;
    x = (*a);
    (*a) = (*b);
    (*b) = x;
}

void Bubblesort(int* ar , int len)
{
  int i,j,flag;
  for(i = 1 ; i<=len-1 ; i++)
  {
      flag = 0;
      for(j = 0 ; j <= len-i-1 ; j++)
      {
          if(ar[j] > ar[j+1])
          {
              Swap(&ar[j] , &ar[j+1]);
              flag = 1;
          }
      }

      if(flag == 0)
        break;
  }
}


int main()
{
    int n,i;
    printf("Enter no. of elements in the array :: ");
    scanf("%d" , &n);
    int arr[n];
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d" , &arr[i]);
    }

    Bubblesort(arr , n);
    printf("Sorted Array :: ");
    for(i = 0 ; i<n ; i++)
    {
        printf("%d | " , arr[i]);
    }

    return 0;
}
