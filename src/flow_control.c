#include "flow_control.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void initialize(char * arr1, char * arr2){

  for (int i=0; i<SIZE; i++){
    (arr1)[i]=DEAD;
    (arr2)[i]=DEAD;
  }
  (arr1)[SIZE/2]=ALIVE;
  (arr1)[SIZE+1]='\0';
  (arr2)[SIZE+1]='\0';
}

void wait() {
  unsigned int ttime = time(0);
  while (time(0) < ttime + DELAY);
}

char rule90 (const char *arr, int index){
  if ((arr[index-1]==ALIVE && arr[index]==arr[index+1] && arr[index+1]==DEAD)
    ||(arr[index-1]==DEAD && arr[index]==arr[index+1] && arr[index+1]==ALIVE)
    ||(arr[index]==ALIVE && arr[index-1]==arr[index+1] && arr[index+1]==DEAD)
    ||(arr[index+1]==ALIVE && arr[index-1]==arr[index] && arr[index]==DEAD))
  return ALIVE;
  else return DEAD;
}

char rule150 (const char *arr, int index){
  if ((arr[index-1]==arr[index] && arr[index]==arr[index+1] && arr[index+1]==ALIVE)
    ||(arr[index-1]==ALIVE && arr[index]==arr[index+1] && arr[index+1]==DEAD)
    ||(arr[index-1]==arr[index] && arr[index]==ALIVE && arr[index+1]==DEAD)
    ||(arr[index]==ALIVE && arr[index-1]==arr[index+1] && arr[index+1]==DEAD)
    ||(arr[index+1]==ALIVE && arr[index-1]==arr[index] && arr[index]==DEAD))
    return ALIVE;
  else return DEAD;
}

void lets_go(char * arr1, char * arr2){
  initialize(arr1, arr2);

  while (1) {
    for (int i=1; i<SIZE-1;i++) arr2[i] = rule150(arr1, i);

    wait();
  //  system("clear");
  //  printf("%s\n%s\n", arr1, arr2);
    printf("%s\n", arr1);

    if (memcmp (arr1, arr2, SIZE)==0) break;
    memmove(arr1, arr2, SIZE);
  }
}
