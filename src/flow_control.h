#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H


#define SIZE 7
#define DELAY 1
#define DEAD ' '
#define ALIVE '0'

void initialize(char * arr1, char * arr2);
//initializing array, fill with signs
void lets_go();
//make simulation
void wait(int d);
//is waiting delay time
//void clean(char * arr);
//free alocated memory on arrays
void printMenu();
//is printing printMenu
char getSingleChar();
//is getting single char from terminator

#endif
