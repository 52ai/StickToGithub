#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//typedef 为数据类型定义一个新的名字
typedef struct LNode
{	
	int data;
	struct LNode *next;

}node;

void josephus(int n,int m,int k){//总共有n个人，从第k个人开始数，数到第m个人出列，然后从m+1个人开始继续

	//根据n的信息，创建循环链表
	node *head,*p,*pre,*temp;
	int num=1,cycle=1;
	head = (node*)malloc(sizeof(node));//为头结点申请空间
	p=head;

	while(cycle){
		temp = (node*)malloc(sizeof(node));
		temp->data = num;num++;
		p->next=temp;
		p=temp;//移动pd的位置
		if(num > n) cycle=0;//当已创建n个节点，则修改循环标记
	}

	head = head->next;//移动头结点到第一个节点位置
	p->next = head;//将尾节点的next指向head,构建循环链表

	//寻找开始节点

	p=head;//从头结点开始
	while(k--) {pre=p;p=p->next;}//执行n次，移动到开始数数的位置

	/*
	q=p;len=1;
	while(q->next->data != p->data) {len++;q=q->next;printf("%d->",q->data);}
	printf("当前长度%d\n",len);

	while(len){//当链表不为空时，执行循环体
		cnt = 0;
		while(cnt < m){//找下一个输出位置
			pre=p;//保存前一个节点
			p=p->next;
			cnt++;
		}

		printf("%d->",p->data);//输出找到的位置
		//删除当前节点

		pre->next = p->next;
		q=p;//保存当前节点的指针
		p=p->next;//从下一个节点开始数
		free(q);//释放当前节点

		//计算当前环的长度

		q=p;len=1;
		while(q->next->data != p->data) {len++;q=q->next;}
		if(len == 1){
			printf("%d->\n",p->data);
			free(p);p=NULL;//释放最后一个节点
			len=0;
		}	

	}*/

	while(n--){
		//寻找下一个输出位置
		int s=m-1;
		while(s--){
			pre=p;
			p=p->next;
		}
		printf("%d->",p->data);//输出找到的位置
		pre->next = p->next;
		free(p);//释放当前节点
		p=pre->next;//从下一个节点开始数
	}
	printf("NULL\n");


}

int main(int argc, char const *argv[])
{
	josephus(13,1,1);
	return 0;
}