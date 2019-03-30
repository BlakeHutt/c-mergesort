#include <stdio.h>
#include <stdlib.h>


int mergeSort(int *array, int left, int right);
int merge(int *a, int *b, int left, int right, int size);

int main(){


    return 0;
}

void mergeSort(int *array, int left, int right){
 
    if(left>=right){
    
        return;
    }
    int oSize = sizeof(array)/sizeof(array[0]);
    int mergeArray[oSize];

    merge(array, mergeArray, left, right, oSize);

}

int merge(int *a, int *b, int left, int right, int size){
    
    int target = left, lBound = right, rBound = size;
    
    while(left<lBound && right<rBound){
    
        if(a[left]<=a[right]){
            b[target] = a[left];
            left++;
        } else if (a[right] < a[left]){
            b[target] = a[right];
            target++, right++;
        }
    }


}
