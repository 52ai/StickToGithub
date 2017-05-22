#include <iostream>
#include <stdio.h>

//快速排序， 不稳定排序，平均O(nlogn) 最差为O(n2)
/*
void quick_sort(int *list, int m, int n){
	int k,t,i,j;
	if(m<n){//当区间长度大于1时才开始排序

		i=m,j=n+1;k=list[m];//选取无序区的第一个记录作为基准，记为k
		while(i<j){//一次循环，就是一轮寻找
			for(i=i+1;i<n;i++){//从左向右扫描，找到第一个比基准k大的数,记录位置i
				if(list[i] > k) break;
			}

			for(j=j-1;j>m;j--){//从右向左扫描，找到第一个比基准k小的数，记录位置j
				if(list[j] < k) break;
			}

			if(i<j){//如果i<j 则交换二者
				t=list[i];
				list[i] = list[j];
				list[j] = t;
			}

			t=list[m];list[m]=list[j];list[j]=t;//本轮扫描结束，基准位置确认为j,交换list[j]和list[m]的内容
		}
		printf("i=%d,j=%d\n",i,j);

		quick_sort(list,m,j-1);//递归对[m~j-1]区间排序
		quick_sort(list,i,n);//递归对[i~n]进行排序

	}
}*/

inline void swap(int &a,int &b){
	int temp;temp=a;a=b;b=temp;
};

int Partition(int *a, int low, int high);
void quick_sort(int *a, int low,int high);

int main(int argc, char const *argv[])
{
	int list[10]={9,8,1,6,5,4,3,2,7,0};
	int m=0,n=9,i;
	//printf("请输入十个数：\n");
	//for(i=0;i<10;i++) scanf("%d",&list[i]);
	//printf("\n");
	quick_sort(list, m, n);

	for(i=0;i<10;i++) printf("%5d",list[i]);
	printf("\n");
	return 0;
}

int Partition(int *a, int low, int high){
	int x = a[high];//对输入数组最后一个数作为主元，用它来对数组划分
	int i = low -1;//i是最后一个小于主元的下标

	for(int j=low;j < high;j++){//遍历下边由low到high-1的数
		if(a[j] < x){//如果小于主元的话，就将i向前挪动一个位置，并且交换j和i所指向的数
			i++;//挪动i,保证i是最后一个小于主元的下标
			//int temp;
			//temp = a[i];a[i]=a[j];a[j]=temp;
			swap(a[i],a[j]);
		}
	}
	//经过上面的循环之后，下标为从low到i(包括i)的数均小于x，现将主元和i+1位置上的数交换
	//a[high] = a[i+1];a[i+1]=x;//交换主元和第一个比主元大的数也就是i+1所指的
	swap(a[high],a[i+1]);

	return i+1;//i+1为交换后主元的位置
}


void quick_sort(int *a, int low, int high){
	if(low < high){
		int q = Partition(a, low, high);
		quick_sort(a, low, q-1);
		quick_sort(a, q+1,high);
	}
}
