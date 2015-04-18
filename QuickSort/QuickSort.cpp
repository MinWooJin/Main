#include <stdio.h>
#include <stdlib.h>

void sor(int [], int, int);

int main(){
    int arr[10] = {74, 52, 62, 15, 7, 34, 77, 23, 99, 2}; //정렬할 배열 
    int left = 0, right = 9;
    int i;
    sor(arr, left, right);    
    for(i=0; i<10; i++)
             printf("%d ",arr[i]);
    printf("\n");
    system("pause");
    return 0;
}

//pivot을 기준으로 재귀함수로 구현 
void sor(int arr[], int left, int right) {
     int pivot;
     int i=left;
     int j=right;
     
     pivot = arr[left];
     for(;left<right;)
     {
                      for(;arr[right]>=pivot && left<right;) right--;
                      if(left != right)
                              arr[left] = arr[right];
                      for(;arr[left]<=pivot && left<right;) left++;
                      if(left != right) {
                              arr[right] = arr[left];
                              right--;
                      }
     }
     
     arr[left] = pivot;
     
    for(int i=0; i<10; i++)
             printf("%d ",arr[i]);
    printf("\n");
     
     pivot = left;
     left=i;
     right=j;
     
     if(left<pivot) sor(arr, left, pivot-1);
     if(pivot<right) sor(arr, pivot+1, right);
}
