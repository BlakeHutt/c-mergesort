#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int mergeSort(int *array, int *work ,int left, int right);
int merge(int *a, int *b, int left, int right, int size);

int main(){

     int size = 0;
 
     srand(time(NULL));
     printf("How many elemets: ");
     scanf("%d", &size);
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

int mergeSort(int *array, int *work, int left, int right){

    if(left < right){  
        
        int mid =ceil(left + right)/2;
    
        mergeSort(array, work, left, mid); // left path
        mergeSort(array,  work, mid+1, right); // right path
        
        merge(array, work, left, mid+1, right+1); 
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
        } else { // a[right] < a[left]
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
