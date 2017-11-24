#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H


#define SIZE 10
#define DELAY 1
#define DEAD '-'
#define ALIVE 'x'

void initialize(char * arr1, char * arr2);
//initializing array, fill with signs
void lets_go();
//make simulation
char rule90 (const char * arr, int index);
//return new sign based on rule90
char rule150 (const char *arr, int index);
//return new sign based on rule 150
void wait();
//is waiting delay time
//void clean(char * arr);
//free alocated memory on arrays

#endif
