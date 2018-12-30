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

void insertL(struct ld * node,struct ld * anchor,struct ll * aList){
    //insert after node - not handle last or first
    //todo: check if anchor is last
    node->prev = anchor;
    node->next = anchor->next;
    node->next->prev = node;
    anchor->next = node;
    
}

void shiftL(struct ld * node,struct ll * aList){
    //assume there is an element already
    node->prev = NULL; 
    node->next = aList->first;
    aList->first->prev = node;
    aList->first = node;
}

void delL(struct ld * node,struct ll * aList){
    //todo: adjust the mid
    //need to check if last element
    if(aList->first == aList->last){
        aList->first = NULL;
        aList->last = NULL;
	node->prev= NULL;
	node->next = NULL;
	return;
    }
    if(node == aList->first){
        printf("first\n");
	node->next->prev = NULL;
	aList->first = node->next;
	//node->data = -1;
	node->prev= NULL;
	node->next = NULL;
	return;
    }
    if(node == aList->last){
        printf("last\n");
	node->prev->next = NULL;
	aList->last = node->prev;
	//node->data = -1;
	node->prev= NULL;
	node->next = NULL;
	return;
    }
	node->next->prev = node->prev;
	node->prev->next = node->next;
	node->prev= NULL;
	node->next = NULL;

}

void forwL(struct ll * aList){
    struct ld * cur;
    cur = aList->first;
    //for(i=0;i<4;i++){
    while(cur != NULL){

        printf("%d - %d\n",cur->data->st,cur->data->l);
	cur = cur->next;
    } 
}
/*
int compareSegs(const void *a, const void *b){
    struct seg *sa = (struct seg *) a;
    struct seg *sb = (struct seg *) b;
    return sa->l - sb->l;
}

*/
void checkSeg(struct ld * node,struct ll * aList){
    int i,k;
    int ct = 0; //count point matches
    int maxCt =0; //the running max matches
    int maxInx = 0; //the 0 - 101 with most matches
    struct ld * cur;
    for(i=node->data->st; i<=node->data->end ;i++){
	ct = 0;
        cur = aList->first;
        while(cur != NULL){
	    if(cur->data->st <= i && cur->data->end >= i){
		ct++;		
	    }
	    cur = cur->next;
        }
	if(ct > maxCt){
	    maxCt = ct;
	    maxInx = i;
	}
    }
    printf("inx:%d max:%d\n",maxInx,maxCt);
    //return here with a point
    //do this in main
    cur = aList->first;
    while(cur != NULL){
	if(cur->data->st <= maxInx && cur->data->end >= maxInx){
            struct ld * tagged = cur;
	    delL(cur,aList); 
	    //segs[i].pt = maxInx;
	    cur = tagged->next;
	}else{
	    cur = cur->next;
	}
    }
    //unMatched -= maxCt;
}
void insertSorted(struct ld * node,struct ll * aList) {
    //printf("insert f:%d l:%d len:%d\n",aList->first->data->l,aList->last->data->l,node->data->l);
    if(node->data->l < aList->first->data->l){
        shiftL(node,aList);
	return;
    }
    if(node->data->l > aList->last->data->l){
        pushL(node,aList);
	return;
    }
    struct ld * cur;
    cur = aList->first;
    while(cur != NULL){
	if(cur->data->l > node->data->l){
            printf("insert c:%d len:%d\n",cur->data->l,node->data->l);
	    insertL(node,cur->prev,aList);
	    break;
	}
	cur = cur->next;
    } 
}
int main(void){
    int a,b,i,k;
    int numSegs = 0;
    //struct ld *srcD;
    struct ld *segBoxes;
    struct seg *nodeBoxes;
    //struct ld *dstD;
    struct ll segList;
    segList.first = NULL;
    segList.last= NULL;
    scanf("%d",&numSegs);
    segBoxes = (struct ld *) malloc (sizeof (struct ld) * numSegs);
    nodeBoxes = (struct seg *) malloc (sizeof (struct ld) * numSegs);
    for(i=0;i<numSegs;i++){
        scanf("%d %d",&a,&b);
        //printf("%d-%d %d\n",a,b,b-a);
        //struct seg * node = (struct seg *) malloc (sizeof (struct seg));
        struct seg * node = nodeBoxes + i;
        node->st = a;
        node->end = b;
        node->l = b - a;
        node->pt = -1;
        (segBoxes + i)->data = node;
        (segBoxes + i)->next = NULL;
        (segBoxes + i)->prev = NULL;
	if(i == 0){
	    puts("first elem");
            pushL(segBoxes + i,&segList);
	}else{
            insertSorted(segBoxes + i,&segList);
	}
    }
    forwL(&segList);
    //qsort(segs,NUM_SEGS,sizeof(struct seg),compareSegs);
    //for(i=0;i<NUM_SEGS;i++){
    //    printf("%d-%d %d\n",segs[i].st,segs[i].end,segs[i].l);
    //}
    //printf("min: %d\n",segs[0].l);
    //printf("max: %d\n",segs[19].l);

    printf("<!--\n") ;
    //checkSeg(&segs[0]);
    struct ld * cur;
    cur = segList.first;
    //while first is not null
    while(cur != NULL){
    	point = checkSeg(cur,&segList);
        //printf("unMatched:%d\n",unMatched);
	//cur = cur->next;
	//do the deletes here
    }
    /*
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
    //for valgrind
    free(segBoxes);
    free(nodeBoxes);
    return 0;
}

