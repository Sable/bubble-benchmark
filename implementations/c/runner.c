#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "bubble.h"
#include "common.h"
#include "ostrich_twister_rand.c"

int checksum(int* A, int size) {
  // Fletcher sum
  int sum1 = 0;
  int sum2 = 0;
  int i;
  for (i=0; i < size; i++) {
    sum1 = (sum1 + A[i]) % 255;
    sum2 = (sum2 + sum1) % 255;
  }
  return (sum2 << 8) | sum1;
}

int main(int argc, char *argv[])
{
  int size;
  if(argc == 2){    
    size = atoi(argv[1]); 
  }
  else{
    printf("Please provide appropriate arguments\n");
    exit(1);
  } 
 
  int *A = (int*)malloc(size*sizeof(int));
  int i;
  for(i=0; i <size; i++){
    A[i] = abs((int)(ostrich_rand_double()*100));
  } 
  stopwatch sw;   
  stopwatch_start(&sw);
  bubble(A,size);
  stopwatch_stop(&sw);
  double elapsed_time = get_interval_by_sec(&sw);


  printf("{\"options\":%d, \"time\":%f, \"output\": %d}\n",size, elapsed_time, checksum(A, size));

  free(A);
  return 0;
}
