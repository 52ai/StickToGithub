#include <stdio.h>
#include <string.h>

/*
#define swap(a,b) {
	char tempBuf[10];
	memcpy(tempBuf,&a,sizeof(a));
	memcpy(&a,&b,sizeof(b));
	memcpy(&b,tempBuf,sizeof(b));

}*/

void swap(int *a,int *b){//慎用指针
	//*a += 1;
	//*b += 1;
	int tempBuf = *a;
	*a = *b;
	*b = tempBuf; 

}

int main(){
	int  a=2,b=3;
	swap(&a,&b);
	printf("%d,%d\n",a,b);
	return 0;
}