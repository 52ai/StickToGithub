#include <stdio.h>
#include <stdlib.h>
#include <string>

#define N (10)

int main(){
	const char *p1="abcde";
	char *p2=(char*)malloc(sizeof(char)* N);
	char *p3=(char*)memcpy(p2,p1,N);
	printf("p2=%s\np3=%s\n",p2,p3);
	free(p2);
	p2=NULL;
	p3=NULL;
	int n='c';
	printf("%d,%d\n",n,++n);
	int i=0;
	printf("%d,%d\n",i++,i++);
	
	return 0;
}