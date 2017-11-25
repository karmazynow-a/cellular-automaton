#include "flow_control.h"
#include "rules.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
  char *arr1, *arr2;
  arr1 = malloc (SIZE + 1);
  arr2 = malloc (SIZE + 1);
  if (arr1==NULL || arr2==NULL) exit(-1);

  char (* rule)(const char*, int);
  char mode;


  while (1){
    printMenu();
    mode = getSingleChar();

    switch (mode){
      case 'e':
        exit(-1);
      case '1':
        lets_go(arr1, arr2, rule90);
        break;
      case '2':
        lets_go(arr1, arr2, rule150);
        break;
      case '3':
        lets_go(arr1, arr2, rule30);
        break;
      default:
        break;
    }

    wait(5);
  }

  free(arr1);
  free(arr2);

  return 0;
}
