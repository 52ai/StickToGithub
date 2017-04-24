#include <iostream>
#include <stdio.h>

void shell_sort(int *a, int n){
	int gap;
	for(gap =3;gap > 0;gap--){
		for(int i=0; i<gap; i++){//通过增量gap分组，假设gap=3,则每隔三个距离为一组，也就是分成三组
			for(int j=i+gap;j<n;j=j+gap){//组内进行直接插入排序
				if(a[j] < a[j-gap]){
					int temp = a[j];
					int k=j-gap;
					while(k>=0 && a[k] > temp){
						a[k+gap] = a[k];//移动位置
						k=k-gap;
					}
					a[k+gap] = temp;
				}
			}

		}
	}

}

int main(int argc, char const *argv[])
{
	int a[10]={9,8,7,6,5,4,3,2,1,0};

	shell_sort(a,10);
	for(int i=0;i<10;i++){
		printf("%5d",a[i]);
	}
	printf("\n");

	return 0;
}