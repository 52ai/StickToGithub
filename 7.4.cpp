#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int v[2][10]={{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
	int (*a)[10]=v;//数组指针

	cout << **a<<endl;
	//cout << **(a+1) <<end;
	//cout << *(*a+1) <<endl;
	cout << **(a+1) <<endl;
	cout << *(*a+1) <<endl;
	cout << *(a[0]+1)<<endl;
	cout << *(a[1]+1)<<endl;


	return 0;
}