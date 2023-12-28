#include <stdio.h>

int HeapSize = 1;

void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int left = currNode*2;
    int right = currNode*2+1;
    while(arr[currNode] < arr[left] || arr[currNode] < arr[right]){

    }


}

void insert(int arr[],int value){
    arr[HeapSize++] = value;
    heapifyUp(arr,HeapSize-1);
}

int removeMaxElement(int * arr){
    int result = arr[1];
    arr[1] = arr[HeapSize];
    HeapSize--;
    heapifyDown(arr);

    return 0;
}

void printArray(int * arr,int numsSize){
    for (int i = 0; i < numsSize+1; i++) {
        printf("[%d]\n",arr[i]);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int arr[numsSize+1] = {};
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        insert(arr,nums[i]);
    }
    /*for (int i = 0; i < k; i++) {
        result = removeMaxElement(arr);
    }*/
    printArray(arr,6);
    return result;
}







int main() {
    int arr[] = {3,2,1,5,6,4};
    findKthLargest(arr,6,3);
    removeMaxElement(arr);

    return 0;
}
