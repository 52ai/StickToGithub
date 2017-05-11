#include <stdio.h>
#include <iostream>
using namespace std;
int main(int args, const char* argv[]){
	int n,m;
	int a[3][4];
	cin>>n>>m;
	cout<<"n:"<<n<<endl;
	cout<<"m:"<<m<<endl;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout << a[i][j];
		}
		cout<<endl;
	}
	return 0;
}