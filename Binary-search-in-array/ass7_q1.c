#include<stdio.h>

void Binarysearch(int* ar , int lb , int ub , int x )
{
  int mid = (lb+ub)/2;

  if(ar[mid] == x)
  {  
   printf("\nIndex Found :: %d\n" , mid);
   return;
  }

 else if(ar[mid] > x)
  {
    Binarysearch(ar , lb , mid-1 , x);
  }

  else
  {
   Binarysearch(ar , mid+1 , ub ,x);
  }
}


Sort(int* ar , int len)
{
 int i , j;
 for(i=0; i<len ; i++)
 {
   for(j = i ; j<len ; j++)
   {
     if(ar[i]>ar[j])
     {
       int y;
       y = ar[i];
       ar[i] = ar[j];
       ar[j] = y;
     }
   }
 }
}

int main(void)
{

int i,n,a;
printf("Enter no. of elements ::");
scanf("%d" , &n);

int arr[n];

printf("Enter elemnts in the array ::\n");
for(i = 0; i<n ; i++)
{
  scanf("%d" , &arr[i]);
}

printf("Enter the element to search :: ");
scanf("%d" , &a);

Sort(arr , n);
Binarysearch(arr , 0 , n , a);
}
