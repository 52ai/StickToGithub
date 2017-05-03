#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool used[10];
vector<long long> v;//long long 类型为int类型长度的两倍

void dfs(int k, long long a){//转化为深度搜索的问题
	
	if(k&&a%k !=0) return;//递归终止条件1

	if(k == 9){//递归终止条件2
		v.push_back(a);
		return;
	}

	for(int i=1;i<=9;i++){
		if(!used[i]){//如果i没有被访问过
			used[i]=1;//将i访问标记置为1
			dfs(k+1,a*10+i);//深度搜索剩余数
			used[i]=0;//递归返回，将i访问标记置为0
		}
	}


}

int main(int argc, char const *argv[])

{	cout << sizeof(long long)<<endl;//8B
	cout << sizeof(int)<<endl;//4B

	dfs(0,0);
	cout << v.size()<<endl;
	for(int i=0; i< v.size();i++) printf("%lld",v[i]);
	cout<<endl;
	return 0;
}

