#include <iostream>
#include <stdio.h>
using namespace std;

const int *find(const int* array, int n, int x){
	const int* p=array;
	for(int i=0;i<n;i++){
		if(*p == x){
			return p;
		}
		p++;
	}
	return 0;
}

//将普通函数改成泛型函数,使用模板
template <typename T> //后面应该紧接着模板函数的定义

const T* my_find(T *array, T n, T x){
	const T* p=array;
	for(int i=0;i<n;i++){
		if(*p == x){return p;}
		p++;
	}
	return 0;
}





int main(int argc, char const *argv[])
{
	int a[10]={1,2,3,4,5,6,9,8,7};
	int len = 9;
	int x=5;
	cout <<*find(a,len,x)<<endl;

	cout <<*my_find(a,len,x)<<endl;

	return 0;
}