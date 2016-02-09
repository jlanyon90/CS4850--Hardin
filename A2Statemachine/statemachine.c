#include <stdio.h>
#include <string.h>
#define boolean int
#define true 1
#define false 0
/*Prototype for transFinder*/
int transFinder(char trans);
/*Prototype for foundW*/
char* foundW(int foundState);

int main (){
  char c[50];
  boolean found = false;
  int length;
  char* foundFirst;
  /*STATE MACHINE ARRAY DERIVED FROM PHYSICAL SATE MACHINE REPRESENTATION*/
  int stateArray[14][6] = {{1,11,0,6,0,0},{1,2,0,6,0,0},{1,3,0,6,0,0},{1,12,4,6,0,0}
                      ,{-1,-1,-1,5,-1,-1},{-2,-2,-2,-2,-2,-2},{1,11,0,6,7,0},{1,8,0,6,0,0}
                      ,{1,9,0,6,0,0},{1,12,10,6,0,0},{-3,-3,-3,-3,-3,-3},{1,12,0,6,0,0}
                      ,{1,12,13,6,0,0},{-4,-4,-4,-4,-4,-4}};
  int state,count;
  printf("Welcome to the string state machine word finder please enter a string or quit\n");
  printf("Enter a string: ");
  while(strcmp(fgets(c,strlen(c),stdin),"quit")){
    /*INITIALIZE ALL REUSED VARIABLES TO RESET ON EACH RUN*/
      count =0;
      state =0;
      found = false;
      length = strlen(c);
      while(found ==false && count<=length){
        state = stateArray[state][transFinder(c[count])];
        if (state<0){
          found = true;
          foundFirst = foundW(state);
          printf("%s was found first\n",foundFirst);
        }
        count++;
      }/*END STATE MACHINE LOOP*/
      if(state>=0){
        printf("No Matches Were Found\n");
      }

      printf("Enter a string: ");
  }/*END STRING LOOP*/
}

int transFinder(char trans){
  int transNumber;
  trans = tolower(trans);
  transNumber = 0;
  switch(trans){
    case 'l':
        transNumber =0;
        break;
    case 'o':
        transNumber =1;
        break;
    case 'p':
        transNumber =2;
        break;
    case 's':
        transNumber =3;
        break;
    case 'n':
        transNumber =4;
        break;
    default: transNumber =5;
  }

  return transNumber;
}

char* foundW(int foundState){
  char* foundFirst;
  switch (foundState) {
    case -1:
      foundFirst = "Loop";
      break;
    case -2:
      foundFirst = "Loops";
      break;
    case -3:
      foundFirst = "Snoop";
      break;
    case -4:
      foundFirst = "Oop";
      break;
  }
  return foundFirst;
}
