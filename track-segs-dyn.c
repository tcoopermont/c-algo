#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_RANGE 80 
struct seg {
    int st;
    int end;
    int l;
    int pt;
};
struct ld{
	struct seg * data;
	struct ld * prev;
	struct ld * next;
};
struct ll{
	struct ld * first;
	struct ld * mid;
	struct ld * last;
};
//struct seg segs[NUM_SEGS];
//int unMatched = NUM_SEGS;

/* ************************
 * Linked List Functions
 */ 
void pushL(struct ld * node,struct ll * aList){
    //first element - should we make sure next,prev are null?
    if(aList->last == NULL){
	aList->first = node;
	aList->last = node;
	node->prev = NULL;
	node->next = NULL;
        return;
    }
    node->prev = aList->last;
    node->next = NULL;
    aList->last->next = node;
    aList->last = node;
}

void forwL(struct ll * aList){
    struct ld * cur;
    cur = aList->first;
    //for(i=0;i<4;i++){
    while(cur != NULL){

        printf("%d\n",cur->data->st);
	cur = cur->next;
    } 
}
/*
int compareSegs(const void *a, const void *b){
    struct seg *sa = (struct seg *) a;
    struct seg *sb = (struct seg *) b;
    return sa->l - sb->l;
}

void checkSeg(struct seg *a){
    int i,k;
    int ct = 0; //count point matches
    int maxCt =0; //the running max matches
    int maxInx = 0; //the 0 - 101 with most matches
    //printf("a: %d %d\n",a->st,a->end); 
    for(i=a->st;i<=a->end;i++){
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
*/
int main(void){
    int a,b,i,k;
    int numSegs = 0;
    //struct ld *srcD;
    struct ld *segBoxes;
    //struct ld *dstD;
    struct ll segList;
    scanf("%d",&numSegs);
    segBoxes = (struct ld *) malloc (sizeof (struct ld) * numSegs);
    //dstD = (struct ld *) malloc (sizeof (struct ld) * numSegs);
    for(i=0;i<numSegs;i++){
	scanf("%d %d",&a,&b);
    	//printf("%d-%d %d\n",a,b,b-a);
        struct seg * node = (struct seg *) malloc (sizeof (struct seg));
	node->st = a;
	node->end = b;
	node->l = b - a;
	node->pt = -1;
	(segBoxes + i)->data = node;
	pushL(segBoxes + i,&segList);
    }
    forwL(&segList);
    //qsort(segs,NUM_SEGS,sizeof(struct seg),compareSegs);
    //for(i=0;i<NUM_SEGS;i++){
    //    printf("%d-%d %d\n",segs[i].st,segs[i].end,segs[i].l);
    //}
    //printf("min: %d\n",segs[0].l);
    //printf("max: %d\n",segs[19].l);

    /*
    printf("<!--\n") ;
    checkSeg(&segs[0]);
    while(unMatched > 0){
        for(i=0;i<NUM_SEGS;i++){
	    if(segs[i].pt == -1){
                break;
            }
        }
    	checkSeg(&segs[i]);
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
    */
    return 0;
}

