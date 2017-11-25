#include "rules.h"
#include "flow_control.h"


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
