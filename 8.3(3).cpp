#include <stdio.h>
#include <iostream>

using namespace std;

void matching(int a[],int b[],int k){
	int i=0;
	while(i <= k-1){
		int j=0;
		while(j<k-1){
			if(a[i] == b[j]){
				printf("a[%d] 与 b[%d]匹配\n",i,j);
				break;
			}
			j++;
		}
		i++;
	}

}

int main(int argc, char const *argv[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {10,6,4,5,1,8,7,9,3,2};

	int k = sizeof(a)/sizeof(int);//取得数组的长度
	printf("数组的长度：%d\n",k);
	matching(a,b,k);
	int *p;
	p=a;
	while(*p!='\0'){
		printf("%d  ",*p++);

	}
	printf("\n");

	return 0;
}