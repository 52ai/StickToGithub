#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//用数组实现队列
typedef struct ArrayQueue{//它的大小应该是400048 毕竟大家都是整型数据
	int h,t;
	int data[100010];
	inline void clear(){h=1,t=0;}//初始化队列
	inline void push(int n){data[++t]=n;}//入队
	inline int front(){return data[h];}//获取队首元素
	inline void pop(){h++;}//出队
	inline bool empty(){return h>t;}//当h>t时则为空
}aqueue;


//用链表实现队列，先进先出
typedef struct LNode
{
	int data;
	struct LNode *next;
}node;

typedef struct LinkQueue
{
	node *first,*rear;//定义队首和队尾节点
}queue;

//队列入队

queue *insert(queue *HQ, int x){//如果队列为空，或者队列不为空，需要分开考虑
	node *temp;
	temp = (node*)malloc(sizeof(node));//为插入的节点申请内存
	temp->data = x;
	temp->next = NULL;//初始化temp节点

	if(HQ->rear == NULL){//如果队列为空，则将队首和队尾元素都设为temp
		HQ->first = temp;
		HQ->rear = temp;
	}
	else{//如果队列不为空，在将temp插入到队尾元素后面，并移动队尾指针
		HQ->rear->next = temp;
		HQ->rear = temp;
	}
	return HQ;
}

//队列出队

queue *del(queue *HQ){//如果队列为空，或者不为空需要分开考虑
	node *temp;int x;
	if(HQ->first == NULL){//如果队列为空
		printf("队列为空！\n");
	}
	else{//否则，将队首元素出队，并移动队首指针，释放初始的头结点
		x=HQ->first->data;
		printf("%d->",x);
		temp = HQ->first;//保存队首节点的地址给temp，便于后面释放该节点

		if(HQ->first == HQ->rear){//到队尾了，如果出队的是最后一个节点，则将队列置空
			HQ->first = NULL;
			HQ->rear = NULL;
		}
		else{//否则移动队首指针
			HQ->first = HQ->first->next;
		}
		free(temp);//释放开始的队首节点
	}

	return HQ;
}
int main(int argc, char const *argv[])
{	
	//初始化队列为空
	queue *HQ;
	int num=10;
	printf("Size Of queue:%lu\n",sizeof(queue));
	HQ = (queue*)malloc(sizeof(queue));
	HQ->first = NULL;
	HQ->rear = NULL;
	while(num--){
		HQ = insert(HQ,num);
	}

	while(HQ->first != NULL){
		HQ = del(HQ);
	}
	printf("NULL\n");

	/***
	箭头（->）：左边必须为指针；
	点号（.）：左边必须为实体。
	***/
	aqueue AQ;//定义一个aqueue类型的队列,AQ为实体
	AQ.clear();//初始化队列

	num = 10;
	while(num--){
		AQ.push(num);//入队
	}
	while(!AQ.empty()){//当队列不为空，则出队
		printf("%d->",AQ.front());//输出队首元素
		AQ.pop();//队首元素出队
	}
	printf("NULL\n");

	//注意定义完指针要初始化，让它具体的指向一个实体，否则不能乱用他

	aqueue *AQ1;//这里的AQ1是个指针,但是这个指针只是一个指针，并没有初始化让它指向具体的内容
	AQ1 = (aqueue*)malloc(sizeof(aqueue));//在堆那申请一个aqueue大小的内存，并让一个aqueue类型的指针AQ1指向它
	AQ1->clear();
	num = 20;
	while(num--){
		AQ1->push(num);//入队
	}
	while(!AQ1->empty()){//当队列不为空，则出队
		printf("%d->",AQ1->front());//输出队首元素
		AQ1->pop();//队首元素出队
	}
	printf("NULL\n");
	printf("Size Of aqueue:%lu\n",sizeof(aqueue));


	return 0;
}



