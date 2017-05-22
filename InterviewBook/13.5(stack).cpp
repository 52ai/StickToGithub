#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//用数组实现栈（先进后出）
typedef struct AStack
{
	int h,t;
	int data[100010];
	inline void clear(){h=0,t=1;}
	inline void push(int x){data[++h]=x;}
	inline int front(){return data[h];}
	inline void pop(){h--;}
	inline bool empty(){return h < t;}
}astack;


//用链表实现栈（先进后出）

typedef struct LNode
{
	int data;
	struct LNode *next;
}node;

typedef struct LStack
{
	node *top, *tail;//定义，栈顶和栈底指针

}lstack;


lstack *push(lstack *LS, int x){//压栈，压栈的时候要考虑，当前栈是空还是已经有元素
	//初始化待压栈节点
	node *temp;
	temp = (node*)malloc(sizeof(node));//为待压栈节点申请空间
	temp->data = x;
	temp->next = NULL;

	if(LS->top == NULL){//如果栈顶元素为空，则让栈顶和栈底指针都指向temp;
		LS->top=temp;
		LS->tail=temp;
	}
	else{//否则，将待压栈元素，插入到栈顶节点的头部，并移动栈顶指针
		temp->next = LS->top;
		LS->top = temp;
	}
	return LS;
}

lstack *pop(lstack *LS){//弹栈，弹栈的时候要考虑当前栈是空，还是有一个元素，或有多于一个元素
	int x;
	node *temp;

	if(LS->top == NULL){//如果当前栈为空
		printf("当前栈为空！\n");
	}
	else{//否则栈不为空
		temp = LS->top;//取出栈顶元素
		x = temp->data;//去除栈顶元素的值
		printf("%d->",x);//输出栈顶元素的值

		if(LS->top == LS->tail){//如果栈内只有一个元素
			LS->top=NULL;
			LS->tail=NULL;
		}
		else{//如果不止一个元素，则移动栈顶指针
			LS->top = LS->top->next;
		}
		free(temp);//释放初始的栈顶节点
	}

	return LS;
}

int main(int argc, char const *argv[])
{
	//初始化栈
	lstack *LS;//定义而指针，需要初始化指向一个具体的实体
	int num=10;
	LS = (lstack*)malloc(sizeof(lstack));
	LS->top= NULL;
	LS->tail=NULL;

	while(num--){//入栈
		LS = push(LS,num);
	}

	while(LS->top != NULL){//当栈不为空，出栈
		LS = pop(LS);
	}
	printf("NULL\n");

	printf("Size Of lstack:%lu\n",sizeof(lstack));
	//结果还是16，因为它就两个指针，我的mac是64位，指针大小为8B.
	//不要以为它的node类型，就大点，没这个特权.指针的大小统统的是一样的大。

	astack *AS;
	AS = (astack*)malloc(sizeof(astack));
	AS->clear();
	num =10;
	while(num--){//入栈
		AS->push(num);
	}

	while(!AS->empty()){//如果栈不为空，则出栈
		printf("%d->",AS->front());
		AS->pop();//队首元素出栈
	}
	printf("NULL\n");
	printf("Size Of astack:%lu\n",sizeof(astack));

	return 0;
}

