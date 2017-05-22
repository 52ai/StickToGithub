#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;

/**

总的来说就是求空间中三个点组成的最大三角形面积

满足如下约束：

1.三个点的颜色要么完全相同，要么完全不同

输入N表示空间中点的个数

接下来N行表示每个点的信息，颜色+(x,y,z)坐标

输出保留5位小数的浮点数


基本思路：

先用暴力破解吧

在满足约束条件下，求出所有的三个点的组合

然后用空间中三个点的坐标三角形面积公式求出面积，选出最小的

**/

struct Point{//定义点类
	char color;
	int x,y,z;
	Point(char mycolor,int a,int b,int c):color(mycolor),x(a),y(b),z(c){}

};


double count_triangle_area(Point a,Point b,Point c){  
    double area = -1;  
       
    double side[3];//存储三条边的长度;  
  
    side[0] = sqrt(pow(a.x - b.x,2)+pow(a.y - b.y,2) + pow(a.z - b.z,2));   
    side[1] = sqrt(pow(a.x - c.x,2)+pow(a.y - c.y,2) + pow(a.z - c.z,2));  
    side[2] = sqrt(pow(c.x - b.x,2)+pow(c.y - b.y,2) + pow(c.z - b.z,2));   
  
    //不能构成三角形;  
    if(side[0]+side[1]<=side[2] || side[0]+side[2]<=side[1] || side[1]+side[2]<=side[0]) return area;   
  
    //利用海伦公式。s=sqr(p*(p-a)(p-b)(p-c));   
    double p = (side[0]+side[1]+side[2])/2; //半周长;  
    area = sqrt(p*(p-side[0])*(p-side[1])*(p-side[2]));   
      
    return area;  
}

int main(int argc, char const *argv[])
{	
	vector<Point> vector_of_point;
	int n;//表示点的个数
	char line[5];

	//输入

	cin >> n;

	for(int i=0;i<n+1;i++){//循环输入n行点的信息

		for(int j=0;j<5;j++){
			char x;scanf("%c",&x);line[j]=x;
		}

		/*
		char color_in;

		int x,y,z;
		
		scanf("%c",&color_in);

		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&z);
		getchar();

		Point temp_point(color_in,x,y,z);//生成点的结构体
		vector_of_point.push_back(temp_point);//将点压入vector数组*/

	}


	for(int j=0;j<5;j++){
		printf("%d\n",line[j]);
	}
	/*

	for(int i=0;i<vector_of_point.size();i++){
		printf("%c\n",vector_of_point[i].color);
	}*/


	return 0;
}
