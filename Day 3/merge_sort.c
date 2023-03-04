#include <stdio.h>
#include <stdlib.h>
void merge(int* nums, int left, int mid, int right){
    int barr[right-left+1];
    int k = 0;
    int i = left;
    int j = mid+1;
    while(i<=mid && j<=right){
        if(nums[i] < nums[j]){
            barr[k++] = nums[i++];
        }
        else{
            barr[k++] = nums[j++];
        }
    }
    while(i<=mid){
        barr[k++] = nums[i++];
    }
    while(j<=right){
        barr[k++] = nums[j++];
    }
    for(i=0; i<k; i++){
        nums[left+i] = barr[i];
    }
}

void mergeSort(int* nums, int left, int right){
    int mid = (left+right)/2;
    if(left < right){
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    mergeSort(nums, 0, numsSize-1);
    returnSize = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        returnSize[i] = nums[i];
    }
    return returnSize;
}

int main(){
    int nums[] = {5,2,3,1};
    int numsSize = 4;
    int* returnSize;
    returnSize = sortArray(nums, numsSize, returnSize);
    for(int i=0;i<numsSize;i++){
        printf("%d ", returnSize[i]);
    }
    return 0;
 }