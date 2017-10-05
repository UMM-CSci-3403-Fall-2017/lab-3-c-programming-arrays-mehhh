#include <stdlib.h>
#include <stdbool.h>



//This function takes in the array called sizes and make one big array to hold
//the number of elements at the first index and the capacity for the element of the subarrays


int* array_copy(int num_arrays, int* sizes, int** values) {
  int i=0;
  int j=0;
  int arr_size=0;
  int count=0;
  int index=1;
  for(i=0; i<num_arrays; i++) {
    arr_size = sizes[i];
    for(j=0; j<arr_size; j++) {
      count++;
    }
  }

  int* arrCopy = (int*) calloc(count+1, sizeof(int));
  arrCopy[0]=count;

  for(i=0; i<num_arrays; i++) {
    arr_size= sizes[i];
    for(j=0; j<arr_size; j++) {
      arrCopy[index] = *(*(values+i)+j);
      index++;
    }
    
  }
  return arrCopy;
 }

void mergesortRange(int* values, int startIndex, int endIndex) {
  int rangeSize = endIndex-startIndex;
  int midPoint=0;
  if(rangeSize >=2) {
    midPoint = (startIndex+endIndex) /2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}

void mergesortRanges(int* values, int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex -startIndex;
  int* destination = (int*) calloc(rangeSize, sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex=0;
  int i = 0;
  while(firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }
  while (firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }

  while (secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }
  for ( i = 0; i < rangeSize; ++i) {
    values[i + startIndex] = destination[i];
  }
  free(destination);
}

