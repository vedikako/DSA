#include <stdio.h>

void bubblesort(int arr[], int n){
    int temp, flag;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j = 0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
    
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1}, n = 10, i;
    bubblesort(arr,n);
    
    for(i=0;i<n-1;i++){
        printf("%d \n", arr[i]);
    }

    return 0;
}
