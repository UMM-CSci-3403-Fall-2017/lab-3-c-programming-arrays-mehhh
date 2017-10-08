#include <stdlib.h>
#include <stdbool.h>
#include "array_merge.h"
#include "mergesort.h"
#include <stdio.h>
//This function takes in the array called sizes and make one big array to hold
//the number of elements at the first index and the capacity for the element of the subarrays


int* array_merge(int num_arrays, int* sizes, int** values) {
  int i=0;
  int j=0;
  int arr_size=0;
  int count=0;
  int index=1;
  int z =0;
  //the outter loop goes over the array containing the sizes of the arrays and sets the inner loop constraint as the size of the 1st arrray
  //until the last array. A count is being added to get the number of elements.
  for(i=0; i<num_arrays; i++) {
    arr_size = sizes[i];
    for(j=0; j<arr_size; j++) {
      count++;
    }
  }
  //adding 1 extra spot to contain the number of elements in the array.
  int* arrCopy = (int*) calloc(count, sizeof(int));
  //The first index contains the total number of elements


  for(i=0; i<num_arrays; i++) {
    arr_size= sizes[i];
    for(j=0; j<arr_size; j++) {
      arrCopy[index] = *(*(values+i)+j);
      index++;
    }
  }

  mergesort(count, arrCopy);
 int* arrCopy2 = (int*) calloc(count+1, sizeof(int));
 arrCopy2[0] = count;
 for(i=1; i <= count; i++) {
   arrCopy2[i] = arrCopy[z];
   z++;
 }
 free(arrCopy);
 free(values);
  return arrCopy2;
 }


