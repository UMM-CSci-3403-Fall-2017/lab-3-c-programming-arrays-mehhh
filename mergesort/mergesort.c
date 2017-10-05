#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "mergesort.h"

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
