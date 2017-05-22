#include <stdio.h>

int main(int argc, char const *argv[]){
	int arr[] = {6,7,8,9,10};
	int i=0,j=0,k=0;
	printf("0x%08x\n",&i);
	printf("0x%08x\n",&j);
	printf("0x%08x\n",&k);//从左向右压栈，栈的生长方向，由高向低



	int *ptr = arr; 
	*(ptr++)+= 123;//ptr++先运算，再向右移动，因此改变的是0号位，并把ptr指向1号位
	printf("%d\n",*ptr);
	printf("%d,%d\n",*ptr,*(++ptr));
	printf("%d,%d\n",++i,i);
}