#include <stdio.h>

// bits 8,16,32
#define NUM_SEGS 16 

//b1111-1111-1111-1111
void genBin(int aNum, char bNum[],int len){

    int digCheck,i,pos;
    int shift = len/4;
    bNum[0] = 'b';
    for(i=len-1;i>=0;i--){
	digCheck = 1 << (len - i - 1) ;
	pos =  i + shift;
	if(digCheck & aNum){
	    bNum[pos] = '1';
	}else{
            bNum[pos] = '0';
	}
	if(i != (len-1) && i != 0 && (i%4) == 0){
	    bNum[pos - 1] = '-';
	    shift--;
	}
    }

}

void testIt(int st, int end){
    int i ;
    char bNum[NUM_SEGS + NUM_SEGS/4];
    bNum[NUM_SEGS + NUM_SEGS/4 - 1 ] = '\0';
    for(i=st;i<=end;i++){
        genBin(i, bNum,NUM_SEGS);
        printf("%s\n",bNum); 
    }
}

int main(void){
    //testIt();
    int i,aNum ;
    char bNum[NUM_SEGS + NUM_SEGS/4];
    bNum[NUM_SEGS + NUM_SEGS/4 - 1 ] = '\0';
    puts("test: 0 - 8");
    testIt(0,8);
    puts("test: 32 - 40");
    testIt(32,40);
    puts("test: 65520 - 65535");
    testIt(65520,65535);
    aNum = 0xff;
    genBin(aNum, bNum,NUM_SEGS);
    printf("aNum: %s\n",bNum);
    aNum = ~7;
    genBin(aNum, bNum,NUM_SEGS);
    printf("aNum: %s\n",bNum);
    return 0;
}

