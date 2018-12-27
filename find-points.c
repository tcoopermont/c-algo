#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_SEGS 20
#define MAX_RANGE 80 
struct seg {
    int st;
    int end;
    int l;
    int pt;
};
struct seg segs[NUM_SEGS];
int unMatched = NUM_SEGS;

void getMax(void){
    int i,k;
    int ct = 0; //count point matches
    int maxCt =0; //the running max matches
    int maxInx = 0; //the 0 - 101 with most matches
    for(i=0;i<=(MAX_RANGE + NUM_SEGS - 2) ;i++){ //ex: max 100 length 20 =  modulus  99 + 19

	ct = 0;
    	for(k=0;k<NUM_SEGS;k++){
	    if(segs[k].pt == -1 && segs[k].st <= i && segs[k].end >= i){
		ct++;		
	    }
        }
	if(ct > maxCt){
	    maxCt = ct;
	    maxInx = i;
	}
    }
    printf("inx:%d max:%d\n",maxInx,maxCt);
    for(i=0;i<NUM_SEGS;i++){
	if(segs[i].st <= maxInx && segs[i].end >= maxInx){
	    segs[i].pt = maxInx;
	}
	
    }
    unMatched -= maxCt;
}

int main(void){
    int a,b,i,k;
    srand(time(NULL));
    for(i=0;i<NUM_SEGS;i++){
	//a = rand()%MAX_RANGE;
	//b = rand()%20;
	scanf("%d %d",&a,&b);
    	printf("%d %d\n",a,a +b);
	segs[i].st = a;
	segs[i].end = b;
	segs[i].l = b - a;
	segs[i].pt = -1;
    }
    printf("<!--\n") ;
    while(unMatched > 0){
        getMax();
        printf("unMatched:%d\n",unMatched);
    }
    for(i=0;i<NUM_SEGS;i++){
	printf("%d-%d %d %d\n",segs[i].st,segs[i].end,segs[i].l,segs[i].pt);
    }
    printf("-->\n") ;
    for(i=0;i<NUM_SEGS;i++){
	printf("<line  style='stroke:black;fill:none;stroke-width:2'");
        printf("x1='%d' y1='%d' x2='%d' y2='%d'></line>\n",
			segs[i].st*10,i*10 + 10 ,segs[i].end*10,i*10 + 10);
    }
    for(i=0;i<NUM_SEGS;i++){
	printf("<line  style='stroke:green;fill:none;stroke-width:2'");
        printf("x1='%d' y1='%d' x2='%d' y2='%d'></line>\n",
			segs[i].pt*10,0,segs[i].pt*10,500);
    }
    return 0;
}

