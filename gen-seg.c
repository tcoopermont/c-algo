#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_SEGS 20
#define MAX_RANGE 80 
int main(void){
    int a,b,i;
    int shSeg = 21; 
    srand(time(NULL));
    for(i=0;i<NUM_SEGS;i++){
	a = rand()%MAX_RANGE;
	b = rand()%20;
    	printf("%d %d\n",a,a +b + 1); //min length
    }
    return 0;
}

