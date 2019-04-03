#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(int *array, int left, int right);
void merge(int *a, int *b, int left, int right, int size);

int main(){

     int size = 0;
 
     srand(time(NULL));
     printf("How many elemets: ");
     scanf("%d", &size);
     int unSort[size];
     
     for(int s = 0; s < size; s++){
         unSort[s] = rand();
     }
     int length = sizeof(unSort)/sizeof(unSort[0]);

     mergeSort(unSort, 0, length-1);

     printf("now sorted\n");
     for(int i = 0; i<size;i++){
         printf("A[%d]: %d\n",i, unSort[i]);
     }


    return 0;
}

void mergeSort(int *array, int left, int right){
     //make a work array the size of the array to be sorted
    int oSize = sizeof(&array)/sizeof(array[0]);
    int mergeArray[oSize];
    int mid = (left + right)/2;
    if(right - left >= 2){
        //middle point to define the bounds between left and right.

        mergeSort(array, left, mid); // left subarray
        mergeSort(array,  mid+1, right); // right subarray

        merge(array, mergeArray, left, right, oSize);
    }
}

void merge(int *a, int *b, int left, int right, int size){
    
    int target = left, leftBound = right, rightBound = size;
    
    while(left<leftBound && right<rightBound){
    
        if(a[left]<=a[right]){
            b[target] = a[left];
            left++, target++;
        } else { // a[right] < a[left]
            b[target] = a[right];
            target++, right++;
        }
    }


}
