#include <stdio.h>

void setOnes(char * head,int val){
  int y;
  for(y=0;y<9; y++){
    *(head + 9*y + val) = (char)1;
  }
}

void genNext(char vals[],int maxPow,int skipPow){
  //const
  int powRoll[10] = {9,9*9,9*9*9,9^4,9^5,9^6,9^7,9^8,9^9,9^10};
  static int runVals[10] = {0,0,0,0,0,0,0,0,0,0}; //incremented each call, rolled when equal to powRoll
  static char hasRolled[10] = {0,0,0,0,0,0,0,0,0,0}; 
  //static int timesCalled = 0;
  int i;
  for(i=0;i<maxPow;i++){
    //printf("pow: %d\n",powRoll[i]);
    if(hasRolled[i]){
      if(vals[i] < 9){
        vals[i]++;
      }else{
        vals[i] = 1;
      }
      hasRolled[i] = 0;
    }
    if(runVals[i] < powRoll[i] - 1){
      runVals[i]++;
    }else{
      runVals[i] = 0;
      hasRolled[i] = 1;
    }
  }
    /*
    if(hasRolled[0]){
      vals[0]++;
      hasRolled[0] = 0;
    }
    if(runVals[0] < 9 - 1){
      runVals[0]++;
    }else{
      runVals[0] = 0;
      hasRolled[0] = 1;
    }
    */

  
}

int zero2eight(){
  static int count = 0;
  int retVal = 0;
  retVal = count;
  if (count < 8) {
    count++;
  }else{
    count = 0;
  }
  return retVal;
}
    
int pow2(){
  static int count = 0;
  static int dig2 = 1;
  int retVal = 0;
  retVal = dig2;
  if (count < 8) {
    count++;
  }else{
    dig2++;
    count = 0;
  }
  return retVal;
}
   //could start dig2 at 0 alternativly? 
int pow2i(){
  static int count = 0;
  static int dig2 = 1;
  static char beenInit = 0;
  if (beenInit && count == 0){
    dig2++;
  }
  if (count < 8) {
    count++;
  }else{
    beenInit = 1;
    count = 0;
  }
  return dig2;
}

int main(void){
  int a,j,i,k;
  int x,y;
  char flat[81];
  char xy[9][9];
  char xyz[9][9][9];

  char * pflat = &flat[0];
  char * y1 = pflat + 9;
  char * y2 = pflat + 18;
  char * yblock[9];
  char * pxy = ( char *) &xy[0][0];
 
  char runDigs[3] = {1,1,1};


  for(k=0; k<9; k++){
    for(j=0; j<9; j++){
      for(i=0; i<9; i++){
        xyz[k][j][i] = (char)0;
      }
    }
  }
  i=1;
  for(j=0; j<9; j++){
    for(i=1; i<=9; i++){
      //printf("\nloop: %d\n",i);
      genNext(runDigs,3,0);
      //printf("vals: %d - %d %d %d\n",i,runDigs[0],runDigs[1],runDigs[2]);
      //printf("%d - %d\n",i,zero2eight());
      //printf("%d - %d\n",i,pow2i());

      //gen all 9*81
      //xyz[runDigs[1] -1][runDigs[0]-1][i-1] = 1;
      
      //gen z==3
      xyz[runDigs[0] -1][i-1][3-1] = 1;

      //gen y==2 
      xyz[runDigs[0] -1][2-1][i-1] = 1;

      //gen x==1
      xyz[1-1][runDigs[0] -1][i-1] = 1;
    }
    //printf("vals: %d - %d %d %d\n",i,runDigs[0],runDigs[1],runDigs[2]);
  }
  puts("X1,X2,X3");
  for(k=0; k<9; k++){
    for(j=0; j<9; j++){
      for(i=0; i<9; i++){
        if(xyz[k][j][i] == 1){
          printf("%d,%d,%d\n",k+1,j+1,i+1);
	}
      }
    }
  }
/*
  for(i=0; i<9; i++){
    //printf("\nloop: %d\n",i);
    genNext(runDigs,3,0);
    //printf("vals: %d - %d %d %d\n",i,runDigs[0],runDigs[1],runDigs[2]);
  }
*/
  return 0;
  for(i=0; i<9; i++){
    yblock[i] = pflat + 9*i; 
  }
  for(i=0; i<81; i++){
   flat[i] = (char)0;  

  }
  for(j=0; j<9; j++){
    for(i=0; i<9; i++){
      xy[j][i] = (char) 9*j + i;
    }
  }

printf("flat y1: %d\n",*y1);
printf("xy y1: %d\n",xy[1][0]);
printf("yblock: %d\n",*yblock[1]);
printf("yblock: %d\n",*(yblock[1] + 1));
setOnes(flat,2);
y=1;
x=0;
//*(flat + 9*y + x) = (char)1;
printf("flat y+x: %d\n",*(flat + 9*y + x));
y=1;
x=1;
printf("flat y+x: %d\n",*(flat + 9*y + x));
//*
  for(i=0; i<81; i++){
    printf("%d %d -  %d %d\n",flat[i],pxy[i],i/9,i%9);

  }
//*/
    return 0;
}

