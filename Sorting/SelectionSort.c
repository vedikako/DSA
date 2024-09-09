#include <stdio.h>

void bubblesort(int arr[], int n){
  
  for(int i = 0; i< n-1; i++){
      int min_index = i;
      for(int j = i+1; j< n; j++){
          if(arr[j] < arr[min_index]){
              min_index = j;
          }
      }
       int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
  }
  
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1}, n = 10, i;
    selectionSort(arr,n);
    
    for(i=0;i<n-1;i++){
        printf("%d \n", arr[i]);
    }

    return 0;
}
