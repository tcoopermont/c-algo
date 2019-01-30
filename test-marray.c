#include <stdio.h>

void setOnes(char * head,int val){
  int y;
  for(y=0;y<9; y++){
    *(head + 9*y + val) = (char)1;
  }
}

int main(void){
  int a,j,i;
  int x,y;
  char flat[81];
  char xy[9][9];
  char * pflat = &flat[0];
  char * y1 = pflat + 9;
  char * y2 = pflat + 18;
  char * yblock[9];
  char * pxy = ( char *) &xy[0][0];

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

