#include <stdio.h>
#include <iostream>

void bubble_sort(int *list);

int main(int argc, char const *argv[]){
	int list[10]={9,8,7,6,5,4,3,2,1,0};
	bubble_sort(list);
	for(int i=0;i<10;i++) printf("%2d",list[i]);
	printf("\n");
	return 1;
}

void bubble_sort(int *list){
	bool exchange;
	for(int i=0;i<9;i++){
		exchange=0;//重设本趟交换标记
		for(int j=0;j<9-i;j++){//每一次都把重的气泡选到最后面
			if(list[j] > list[j+1]){
				int tmp;tmp=list[j];list[j]=list[j+1];list[j+1]=tmp;
				exchange=1;//发生了交换
			}
		}
		if(!exchange) return;//本趟排序没有发生交换，提前终止算法
		//如果数组本来有序，因此只需要比较一趟就可以终止算法，所以时间复杂度最好的情况是O(n),而且冒泡排序是稳定的
	}
}

