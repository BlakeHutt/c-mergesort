#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int mergeSortR(int *array, int *work ,int left, int right);
int mergeSortI(int *array, int *work, int left, int right);
int merge(int *a, int *b, int left, int right, int size);
int correctness(int *array, int length, int *duplicates);
void output(int *a, double time, int size, int dupe);

int main(){

    double timeE = 0.0;
    srand(time(NULL));
    int N, R, C = 10000000;

    for(R = 1, N = C; N>= 10; R *=10, N /=10){
        
        clock_t start, end;
        double totalTimeR = 0.0, totalTimeI = 0.0;
        int dupesR = 0, dupesI = 0;

        printf("-------------------------\n");
        printf("Amount of runs: %d\nNumber of elements: %d\n", R, N);
        printf("-------------------------\n");
        int hedgehogsRec[N];
        int hedgehogsIt[N];
        int workhog[N];
          
        for(int i = 0; i < R; i++){
            for(int s = 0; s<N; s++){
              hedgehogsRec[s] = rand();
              hedgehogsIt[s] = rand();
            }
            start = clock();
            mergeSortR(hedgehogsRec, workhog, 0, N-1);
            end = clock();
            timeE = ((double)end-start)/CLOCKS_PER_SEC;
            totalTimeR += timeE;

            start = clock();
            mergeSortI(hedgehogsIt, workhog, 0, N-1);
            end = clock();
            timeE = ((double)end - start)/CLOCKS_PER_SEC;
            totalTimeI += timeE;

            if(correctness(hedgehogsRec, N, &dupesR) == -1){
                printf("Is not correctly sorted during recursive");
                return 1;
            } else if(correctness(hedgehogsIt, N, &dupesI) == -1){
                printf("Is not correctly sorted during iterative");
                return 1;
            }
        }      
        printf("\ntotal time taken recursive: %f\nNumber of Dupes: %d\n", totalTimeR, dupesR);
        printf("\ntotal time taken iterative: %f\nNumber of Dupes: %d\n", totalTimeI, dupesI);
    }   
    return 0;
}

int mergeSortR(int *array, int *work, int left, int right){

    if((left < right)){  
        
        int mid =ceil(left + right)/2;
    
        mergeSortR(array, work, left, mid);
        mergeSortR(array,  work, mid+1, right);
        
        merge(array, work, left, mid+1, right+1); 
    }
    return *array;
}

int mergeSortI(int *array, int *work, int left, int right){

     if((left < right)){
         for(int aSizePairs = 1; aSizePairs <= right; aSizePairs = 2*aSizePairs){

             for(int i = 0; i <= right; i +=  (2*aSizePairs)){
                 int mid, high;
                 if((i+aSizePairs) < right){
                     mid = i+aSizePairs;
                 } else
                     mid = right;
                 if((i+(2*aSizePairs)) < right){
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
    while(left < leftBound && right < rightBound){
    
        if(a[left] <= a[right]){
            b[target++] = a[left++];
        } else { 
            b[target++] = a[right++];
        }
    }
    
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

int correctness(int *array, int size, int *duplicates){

     for(int i = 0; i < size-1; i++){
         if(array[i] > array[i+1]){
             return -1;
         }
         if(array[i] == array[i+1]){
             *duplicates = *duplicates + 1;
         }
     }
 return 0;
 }
 
void output(int *a, double time, int size, int dupe){
     printf("-------------------------\n");
     for(int i = 0; i < size; i++){
         printf("A[%d]: %d\n", i, a[i]);
     }
     printf("Sort Elapsed Time: %f\n", time);
     printf("Amount of duplicates: %d\n", dupe);
     printf("-------------------------\n");
 }
