#include <iostream>
#include <stack>
using namespace std;

template<class T>

struct Queue
{	
	stack<T> s1;//s1栈负责入栈
	stack<T> s2;//s2负责出栈，如果s2中有元素则直接出栈，否则s1出栈到s2中，再由s2出栈

	void push(T &t){//压栈
		s1.push(t);
	}


	T front(){//取队首元素
		if(s2.empty()){//如果栈s2为空，s1不为空，则将s1依次弹栈到s2
			//if(s1.size() == 0) throw;//如果栈s1也为空，则抛异常(加了个empty()出站前，先判断队列是否为空)
			while(!s1.empty()){//否则s1依次弹栈，压栈到s2
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();//如果s2不为空，则取s2栈顶元素
	}

	void pop(){//队首元素出队
		if(s2.empty()){//如果s2为空，s1不为空，则将s1依次弹栈到s2
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}

		}
		s2.pop();//如果s2不为空，则s2直接弹出栈顶元素
	}

	bool empty(){//当前队列是否为空
		return s1.empty() && s2.empty();
	}	

};

int main(int argc, char const *argv[])
{
	Queue<int> queue;
	int num =10;
	while(num --){//入队
		queue.push(num);
		printf("%d->",num);
	}
	printf("NULL\n");
	num = 10;
	while(!queue.empty()){
		cout << queue.front()<<"->";
		queue.pop();
	}
	cout<<"NULL"<<endl;
	//cout<<"Size Of T:"<<sizeof(queue)<<end;//测不出大小，你是不是傻，泛型根据传入参数的类型有关

	return 0;
}