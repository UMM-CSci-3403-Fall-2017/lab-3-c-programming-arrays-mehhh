
#include <stdlib.h>
#include <string.h>

#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values);


//This function takes in the array called sizes and make one big array to hold
//the number of elements at the first index and the capacity for the element of the subarrays
int* array_copy(int num_arrays, int* sizes, int** values) {
  int count=0;
  int i=0;
  int j=0;
  int z=0;
  int numElements=0;
  int* arr1;
  for(i=0; i<sizeof(sizes)/sizeof(int); i++) {
    count= count + sizes[i];
  }
  arr1= (int*) calloc(count+1, sizeof(int));
  arr1[0]=count;
  for(i=1; i<count; i++) {
    for(j=0; j<sizes[z]; j++) {
      arr1[i] = values[j];

    }
    z++;

 }

  return arr1;
    
}
