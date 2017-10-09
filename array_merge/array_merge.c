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
  int k=0;
  
  //the outter loop goes over the array containing the sizes of the arrays and sets the inner loop constraint as the size of the 1st arrray
  //until the last array. A count is being added to get the number of elements.
  for(i=0; i<num_arrays; i++) {
    count = count + sizes[i];
  }
 

  
  //adding 1 extra spot to contain the number of elements in the array.
  int* arrCopy = (int*) calloc(count, sizeof(int));
  //The first index contains the total number of elements
       printf("%s\n", "this should be the size of the array");
       printf("%d\n", count);

  for(i=0; i<num_arrays; i++) {
    arr_size= sizes[i];
    for(j=0; j<arr_size; j++) {
      arrCopy[index] = values[i][j];
      index++;
    }
  }


mergesort(count, arrCopy);
for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            /* If any duplicate found */
            if(arrCopy[i] == arrCopy[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<count; k++)
                {
                    arrCopy[k] = arrCopy[k + 1];
                }

                /* Decrement size after removing duplicate element */
                count--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
  int* arrCopy2 = (int*) calloc(count+1, sizeof(int));
     for(i=1; i<=count; i++) {
       arrCopy2[i]= arrCopy[i-1];
     }

       arrCopy2[0] = count;
       
return arrCopy2;
}


