#include <stdio.h>

#define n 50

void shift_element(int* arr, int i){
for(int k=i; k>0; k--)
   *(arr+k)=*(arr+k-1);
}

void insertion_sort(int* arr , int len){
 for (int i=1; i<len; i++){   
  int j=i-1, count=0,temp=*(arr+i);
    while (j>=0 && temp<*(arr+j)) 
    {
     j--;  
     count++;
    }
   shift_element(arr+i-count,count);
   *(arr+i-count)=temp;
  }  

}

int main(){
int arr[n];
printf("enter %d numbers\n", n);
fgets(arr, n , stdin);
// for(int i=0; i<n; i++)
//   scanf(" %d", (arr+i));
insertion_sort(arr,n);
for(int i=0; i<n-1; i++)
printf("%d,",*(arr+i));
printf("%d\n", *(arr+n-1));
    return 0;
}