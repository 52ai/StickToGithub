#include <iostream>
#include <stdio.h>

/**
第三便宜的帽子

输入n代表帽子的个数

输入n个数字，代表每个帽子的价格

输出：第三便宜的帽子

思路：

把输入的每个帽子的价格存入数组，然后对其，从小到大排序

取第三个帽子的价格，如果存在输出，如果不存在则输出-1

**/

int main(int argc, char const *argv[])
{
	int n;
	int price[100];//最大为50个，就姑且申请数组为100个吧
	//输入

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);price[i]=x;
	}

	if(n <=2){//如果帽子的个数小于3，则不存在第三便宜的帽子，直接输出-1
		printf("-1\n");
	}
	else{//否则对价格数组按照价格从小到大的顺序进行排序，取第三个便宜帽子的价格，如果存在价格相同的帽子则后移

		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(price[i] > price[j]){//如果price[i]大于price[j]则交换
					int temp;temp=price[i];price[i]=price[j];price[j]=temp;
				}
			}
		}
		int cnt=1;

		for(int i=1;i<n;i++){
			if(price[i]!=price[i-1]){//如果价格不同，则cnt加1
				cnt++;
				if(cnt == 3){
					printf("%d\n",price[i]);
					return 0;
				}
			}
		}

		printf("-1\n");

	}

	return 0;
}