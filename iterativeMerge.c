#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int mergeSort(int *array, int *work ,int left, int right);
int merge(int *a, int *b, int left, int right, int size);
int main(){

     int size = 11;
 
     srand(time(NULL));
    // printf("How many elemets: ");
    // scanf("%d", &size);
     int unSort[size];
     int worker[size];
     for(int s = 0; s < size; s++){
         unSort[s] = rand();
     }
     int length = sizeof(unSort)/sizeof(unSort[0]);

     mergeSort(unSort, worker, 0, length-1);

     printf("now sorted\n");
     for(int i = 0; i<length;i++){
         printf("A[%d]: %d\n",i, unSort[i]);
     }


    return 0;
}

/*
 *  Begin by starting at a subarray of 1 - designated as aSizePairs (Array Pair Size)
 *  Go into another for loop, with with the begining index element always being 0 of the array.
 *      Incrementing that value by twice the array pair size
 *  Find the lowest value between the current index element + the current pair size or the size of the original array
 *      Becomes the middle value of the subarray to be sorted, which is the leftBound/right pointer for subarray
 *  Repeats process but for maximum value of subarray
 *      Becomes the rightBound/size of the subarray
 *  
 *  Whole process repeats until the size pairs is larger than the original array size. 
 */

int mergeSort(int *array, int *work, int left, int right){

    if((left < right)){  
        for(int aSizePairs = 1; aSizePairs < right; aSizePairs *= 2){

            for(int i = 0; i < right; i +=  (2*aSizePairs)){
                int mid, high;
                if((i+aSizePairs) <= right){
                    mid = i+aSizePairs;
                } else 
                    mid = right+1;
                if((i+(2*aSizePairs)) <= right){
                    high = i+(2*aSizePairs);
                } else 
                    high = right+1;
                merge(array, work, i, mid, high);
            }
        }        
    }
    return *array;
}


int merge(int *a, int *b, int left, int right, int size){
    int target = left, leftBound = right, rightBound = size, oLeft = left;
    //Go through partitions, while one of them is not empty.    
    while(left < leftBound && right < rightBound){
    
        if(a[left] <= a[right]){
            b[target++] = a[left++];
            //left++;
        } else { // a[right] <= a[left]
            b[target++] = a[right++];
           // right++; 
        }
       // target++;
    }
   
    /*
     *  Copy rest of unsorted elements into array
     *  Copy the temp array back into the main array
     *
     *  Depending on which broke the while, it does the other half of the array. 
     *      ie left broke, so it does the right and vice versa.
     *
     */


    while(left < leftBound){
        b[target++] = a[left++];
    }
    while(right < rightBound){
        b[target++] = a[right++];
    }

    for(int i = oLeft; i < size; i++){
        a[i] = b[i];
    }
    return *a;
}
