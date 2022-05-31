#include <stdio.h>

// Define heap array-related variables
const int heapArraySize = 100;
int heap[heapArraySize];
int currentHeapSize = 0;

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int index){

    // Base case
    if(index == 1){
        return;
    }

    // Check if the element of child is smaller than that of parent index
    // If true, swap
    // Divide by 2 to check parent index
    int parentIndex = index / 2;
    if(heap[index] < heap[parentIndex]){
        swap(&heap[index], &heap[parentIndex]);
        upHeap(parentIndex);
    }

}

void insertHeap(int valueToBeInserted){

    // If heap is full, then return
    if(currentHeapSize + 1 == heapArraySize){
        return;
    }

    // If heap is full, increase the current size and insert value at the end
    currentHeapSize++;
    heap[currentHeapSize] = valueToBeInserted;
    upHeap(currentHeapSize);

}

void printHeap(){

    for(int index = 1; index <= currentHeapSize; index++){

        printf("%d ", heap[index]);
    }

    puts("");
}

void downHeap(int index){

    int leftChild = index * 2;
    int rightChild = (index * 2) + 1;
    
    // If there are two children
    if(rightChild <= currentHeapSize){

        if(heap[leftChild] < heap[index] || heap[rightChild] < heap[index]){
            
            // If left child is smaller than right child, swap with parent
            if(heap[leftChild] < heap[rightChild]){
                swap(&heap[index], &heap[leftChild]);
                downHeap(leftChild);
            }
            
            // Else, swap right child
            swap(&heap[index], &heap[rightChild]);
            downHeap(rightChild);
        }
    }
}

void extractMin(){

    // If no data
    if(currentHeapSize == 0){
        return;
    }

    // If there is only one data, reduce heap size by 1
    if(currentHeapSize == 1){
        currentHeapSize--;
    }

    else{
        printf("Min = %d\n", heap[1]);
        heap[1] = heap[currentHeapSize];
        currentHeapSize--;
        downHeap(1);
    }
}

int main(){

    insertHeap(30);
    insertHeap(20);
    insertHeap(10);
    insertHeap(8);
    insertHeap(6);
    insertHeap(5);

    printHeap();

    extractMin();
    printHeap();

    return 0;
}