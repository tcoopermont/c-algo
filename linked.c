#include <stdio.h>
#include <stdlib.h>
struct ld{
	int data;
	struct ld * prev;
	struct ld * next;
};
struct ll{
	struct ld * first;
	struct ld * mid;
	struct ld * last;
};
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

        printf("%d\n",cur->data);
	cur = cur->next;
    } 
}
void revL(struct ll * aList){
    struct ld * cur;
    cur = aList->last;
    //for(i=0;i<4;i++){
    while(cur != NULL){

        printf("%d\n",cur->data);
	cur = cur->prev;
    } 
}
void insertL(struct ld * node,struct ld * anchor,struct ll * aList){
    //insert after node - not handle last or first
    //todo: check if anchor is last
    node->prev = anchor;
    node->next = anchor->next;
    node->next->prev = node;
    anchor->next = node;
    
}
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
void reInit(struct ll * aList,struct ld * a,struct ld * b,struct ld * c,struct ld * d){

    aList->first = NULL;
    aList->last = NULL;
    pushL(a,aList);
    pushL(b,aList);
    pushL(c,aList);
    pushL(d,aList);

    /*
    a->prev = NULL;
    a->next = b;

    b->prev = a;
    b->next = c;

    c->prev = b;
    c->next = d;

    d->prev = c;
    d->next = NULL;

    aList->first = a;
    aList->last = d;
    aList->mid = b;
    */
}
int main(void){
    int i,num,t;

    struct ld a;
    struct ld b;
    struct ld c;
    struct ld d;
    struct ll aList;
    struct ld * cur;

    aList.first = NULL;
    aList.last = NULL;

    a.data =1;
    //a.prev = NULL;
    //a.next = &b;

    b.data =2;
    //b.prev = &a;
    //b.next = &c;

    c.data =3;
    //c.prev = &b;
    //c.next = &d;

    d.data =4;
    //d.prev = &c;
    //d.next = NULL;
/*
    aList.first = &a;
    aList.last = &d;
    aList.mid = &b;
*/
    pushL(&a,&aList);
    pushL(&b,&aList);
    pushL(&c,&aList);
    pushL(&d,&aList);
    //printf("%d\n",b.data);
    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    puts("delete a");
    delL(&a,&aList);

    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    puts("delete b");
    delL(&d,&aList);

    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    pushL(&d,&aList);

    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);
    puts("reInit");
    reInit(&aList,&a,&b,&c,&d);
    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    delL(&b,&aList);

    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    insertL(&b,&a,&aList);

    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    delL(aList.last,&aList);
    delL(aList.last,&aList);
    delL(aList.last,&aList);
    delL(aList.last,&aList);
    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    reInit(&aList,&a,&b,&c,&d);
    delL(aList.first,&aList);
    delL(aList.first,&aList);
    delL(aList.first,&aList);
    delL(aList.first,&aList);
    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);

    puts("\n***dynamic tests******");
    aList.first = NULL;
    aList.last= NULL;
    int numSegs = 4;
    struct ld *srcD;
    struct ld *dstD;
    srcD = (struct ld *) malloc (sizeof (struct ld) * numSegs);
    //dstD = (struct ld *) malloc (sizeof (struct ld) * numSegs);

    for(i=0;i<4;i++){
        (srcD + i)->data = i;
        pushL(srcD + i,&aList);	
    }
    puts("forward");
    forwL(&aList);
    puts("reverse");
    revL(&aList);
    free(srcD);
    return 0;
}
