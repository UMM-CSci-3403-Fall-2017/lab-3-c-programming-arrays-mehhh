


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
  int index=0;
  
  //Counts the total number of elements in values
  for(i=0; i<num_arrays; i++) {
    count = count + sizes[i];
  }
 

  //making an array pointer to contain all elements
int* arrCopy = (int*)calloc(count, sizeof(int));
//doing the same thing as above.
 int* b = (int*)calloc(count, sizeof(int));
 //copying things over to arrCopy
  for(i=0; i<num_arrays; i++) {
    arr_size= sizes[i];
    for(j=0; j<arr_size; j++) {
      arrCopy[index] = values[i][j];
      index++;
    }
  }

  //sorting
mergesort(count, arrCopy);


int newSize=0;

//this loop will copy over all elements from arrCopy without repeats
   for(i=0;i<count;i++)
   {
      for(j=0;j<newSize;j++)
      {
         if(arrCopy[i]==b[j])
            break;
      }
      if(j==newSize)
      {
         b[newSize] = arrCopy[i];
         newSize++;
      }
   }

   //making a new array that will hold the correct number of elements
  int* arrCopy2 = (int*) calloc(newSize+1, sizeof(int));
     for(i=1; i<=newSize; i++) {
       arrCopy2[i]= b[i-1];
     }
     //replacing the first index of the array with the nubmer of elements in it
       arrCopy2[0] = newSize;
        free(arrCopy);
	free(b);
   
return arrCopy2;
}
