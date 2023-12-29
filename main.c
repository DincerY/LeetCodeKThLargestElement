#include <stdio.h>
#include <string.h>

int HeapSize = 1;

void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int * arr,int numsSize){
    for (int i = 0; i < numsSize+1; i++) {
        printf("[%d]\n",arr[i]);
    }
}

//eklerken
void heapifyUp(int arr[],int lastIndex){
    int parent = lastIndex/2;
    while (lastIndex > 1 && arr[parent] < arr[lastIndex]){
        swap(&arr[parent],&arr[lastIndex]);
        lastIndex = parent;
        parent = lastIndex/2;
    }
}

//silerken
void heapifyDown(int * arr){
    int currNode = 1;

    while(currNode<HeapSize && arr[currNode] < arr[currNode*2] || arr[currNode] < arr[currNode*2+1]){
        int left = currNode*2;
        int right = currNode*2+1;
        if(arr[left] > arr[right]){
            swap(&arr[currNode],&arr[left]);
            currNode = left;
        } else{
            swap(&arr[currNode],&arr[right]);
            currNode = right;
        }
    }
}

void insert(int arr[],int value){
    arr[HeapSize++] = value;
    heapifyUp(arr,HeapSize-1);
}

int removeMaxElement(int * arr){
    int result = arr[1];
    arr[1] = arr[HeapSize];
    arr[HeapSize] = 0;
    HeapSize--;
    heapifyDown(arr);
    return result;
}



int findKthLargest(int* nums, int numsSize, int k) {
    int arr[numsSize+1];
    memset(arr,0,sizeof(arr));
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        insert(arr,nums[i]);
    }
    HeapSize--;
    for (int i = 0; i < k; i++) {
        result = removeMaxElement(arr);
    }
    return result;
}



int main() {
    int arr[] = {15,20,2,3,5,7,8,85,35,78,65,11,79,85,85,85,13,45};
    int deneme = findKthLargest(arr,18,7);

    return deneme;
}
