#include "flow_control.h"
#include "rules.h"
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

void lets_go(char * arr1, char * arr2,char (* rule)(const char*, int)){
  initialize(arr1, arr2);

  while (1) {
    for (int i=1; i<SIZE-1;i++) arr2[i] = rule(arr1, i);

    wait();
  //  system("clear");
  //  printf("%s\n%s\n", arr1, arr2);
    printf("%s\n", arr1);

    if (memcmp (arr1, arr2, SIZE)==0) break;
    memmove(arr1, arr2, SIZE);
  }
}

void printMenu(){
  system("clear");
  printf("Choose your rule:\n1 - rule90\n2 - rule150\n\nPress 'e' to escape\n");
}
