#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H


#define SIZE 7
#define DELAY 1
#define DEAD '-'
#define ALIVE 'x'

void initialize(char * arr1, char * arr2);
//initializing array, fill with signs
void lets_go();
//make simulation
void wait();
//is waiting delay time
//void clean(char * arr);
//free alocated memory on arrays
void printMenu();

#endif
