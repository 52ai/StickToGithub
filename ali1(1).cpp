#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	int n,m,i=0,j=0;
	float p,cash=1.0,num_of_share=0.0;
	float price[1000][1000];
	char str[1000][1000];

	scanf("%d%d%f",&n,&m,&p);
	scanf("%d%d%f",&n,&m,&p);

	//printf("%d %d %f\n",n,m,p);
	i=0;
	while(i < m){
			j=0;
			while(j<n){
				scanf("%s",str[i]);
				j++;

			}
			i++;
	}
	
	i=0;
	while(i< m){
		j=0;
		while(j< n){
			printf("%c\n",str[i][j]);
			j++;
		}
		i++;
	}

	//到此数据输入完毕 n表示股票个数，m表示交易期个数，p表示税
	/*
	printf("i:%d\n",i);

	while(--i){
			printf("%f\n",price[i]);
	}*/
	/*
	i=0;
	num_of_share = cash / price[1];//第一期全部买入股票
	//printf("num_of_share:%f\n",num_of_share );
	cash = 0.0;
	while(i++ < m ){//对m个交易期进行计算，第一期，第二期。。。直到第m期
		//printf("%f\n",price[i]);//每期的股票价格
		//购入和卖出策略，第一次全部买入，等到最后一期全部卖出
	}
	cash = num_of_share * price[m]*(1-p);
	printf("%.1f\n",cash);*/



	return 0;
}