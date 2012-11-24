#include "kandrcchapter3answers.h"

void ex3_1(){
  int array[] = {1,2,3,4,5,6,7,8,9,10};

  int toFind = 1;
  int where = -1;

  where = newbinsearch(toFind, array, 10);
  if(where < 0)
    printf("Sorry number not found\n");
  else
    printf("Number %d found at location array[%d]\n", toFind, where);
}


int newbinsearch(int tofind, int values[], int max){
  /*
   *  Attempt to provide bin search below but with only one test made inside the loop
   */
  int low, mid, high;

  low = 0;
  high = max-1;

  /*
   *  inside loop will divide an conquer, 
   */
  mid = (low+high)/2;

  while(low+1 < high){
    printf("Low:%d Mid:%d High:%d\n", low, mid, high);
    if(tofind <= mid)
      high = mid;
    else
      low = mid;

    mid = (low+high)/2;
  }

  if(tofind == values[mid])
    return mid;
  else if(tofind == values[high])
    return high;
  else
    return -1;
}

int binsearch(int tofind, int values[], int max){
  int low, mid, high;

  low = 0;
  high = max-1;

  while(low <= high){
    mid = (low+high) / 2; // get mid point

    if(tofind < values[mid])
      high = mid - 1;
    else if(tofind > values[mid])
      low = mid + 1;
    else
      return mid;      
  }

  return -1;
}
