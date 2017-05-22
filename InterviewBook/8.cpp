#include <iostream>
#include <stdio.h>

//分别用递归和循环实现n的阶乘
int func(int i){
	int n,val=1;
	for(n=i;n>0;n--){
		val *= n;
	}
	return val;
}

int recursion_func(int n){
	if(n>0) return n*recursion_func(n-1);
	else return 1;
}	

int main(int argc, char const *argv[])
{
	printf("%d\n",func(3));
	printf("%d\n",recursion_func(3));
	return 0;
}


