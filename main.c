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
    int maxValueIndex = currNode;
    while(1){
        int left = currNode * 2;
        int right = currNode * 2 + 1;
        if(left <= HeapSize && arr[left] > arr[maxValueIndex]){
            maxValueIndex = left;
        }
        if(right <= HeapSize && arr[right] > arr[maxValueIndex]){
            maxValueIndex = right;
        }
        if(maxValueIndex == currNode){
            break;
        }
        swap(&arr[currNode],&arr[maxValueIndex]);
        currNode = maxValueIndex;
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
    int arr[] = {4,5,1,3,2,8,9,10};
    int deneme = findKthLargest(arr,8,5);

    return deneme;
}
