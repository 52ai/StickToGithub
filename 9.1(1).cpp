#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>);

int main(int argc, char const *argv[])
{
	vector<int> vec;
	vec.push_back(34);
	vec.push_back(23);
	print(vec);
	vector<int>::iterator p;//神奇的游标，用来指向STL容器中的元素
	p=vec.begin();//让游标指向vec向量容器的首元素位置

	*p = 68;//通过游标访问并改变向量容器元素
	*(p+1) = 69;
	//*(p+2) = 70;//这么做是有问题的，因为vec向量容器只有两个元素
	print(vec);
	//cout << *(p+2)<<endl;

	vec.pop_back();//让向量容器队尾元素出队
	print(vec);

	vec[0]=100;//通过下表访问并改变向量容器元素
	print(vec);
	vec.push_back(101);
	vec.push_back(102);
	vec.push_back(103);
	print(vec);

	cout << "队首："<<vec.front()<<endl;
	cout << "队尾："<<vec.back()<<endl; 

	//vector<int>::iterator p2 = vec;
	//cout << *p2<<endl;


	return 0;
}

void print(vector<int> v){
	cout << "vector size is:"<<v.size()<<endl;
	//vector<int>::iterator p=v.begin();
	int i=0;
	while(i<v.size()){cout <<v[i++]<<endl;}

}