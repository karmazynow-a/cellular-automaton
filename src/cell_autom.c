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
    mode = getchar();

    switch (mode){
      case 'e':
        exit(-1);
      case '1':
        rule = rule90;
        break;
      case '2':
        rule = rule150;
        break;
      default:
        break;
    }

    lets_go(arr1, arr2, rule90);
  }

  free(arr1);
  free(arr2);

  return 0;
}
