#include "flow_control.h"
#include "rules.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

void initialize(char * arr1, char * arr2){

  for (int i=0; i<SIZE; i++){
    (arr1)[i]=DEAD;
    (arr2)[i]=DEAD;
  }
  (arr1)[SIZE/2]=ALIVE;
  (arr1)[SIZE+1]='\0';
  (arr2)[SIZE+1]='\0';
}

void wait(int d) {
  unsigned int ttime = time(0);
  while (time(0) < ttime + d);
}

void lets_go(char * arr1, char * arr2,char (* rule)(const char*, int)){
  initialize(arr1, arr2);

  while (1) {
    for (int i=1; i<SIZE-1;i++) arr2[i] = rule(arr1, i);

    wait(DELAY);
  //  system("clear");
  //  printf("%s\n%s\n", arr1, arr2);
    printf("%s\n", arr1);

    if (memcmp (arr1, arr2, SIZE)==0) break;
    memmove(arr1, arr2, SIZE);
  }
}

void printMenu(){
  system("clear");
  printf("Choose your rule:\n1 - rule90\n2 - rule150\n3 - rule30\n\nPress 'e' to escape\n");
}

char getSingleChar() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}
