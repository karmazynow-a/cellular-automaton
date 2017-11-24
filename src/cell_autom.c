#include "flow_control.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  char *arr1, *arr2;
  arr1 = malloc (SIZE + 1);
  arr2 = malloc (SIZE + 1);
  if (arr1==NULL || arr2==NULL) exit(-1);

  lets_go(arr1, arr2);

  free(arr1);
  free(arr2);

  return 0;
}
