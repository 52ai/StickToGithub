#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//单链表的建立，遍历，删除节点，插入节点，对结点排序，对链表进行逆置，查找中间节点，合并链表

typedef struct student{
	int data;
	struct student *next;
}node;


node *create(){
	node *head, *p, *s;
	int x,cycle=1;
	head = (node*)malloc(sizeof(node));
	p=head;
	while(cycle){
		printf("\nPlease input the data:");
		scanf("%d", &x);
		if(x!=0){
			s=(node*)malloc(sizeof(node));
			s->data=x;
			printf("\n%d",s->data);
			p->next = s;
			p=s;
		}
		else cycle =0;
	}
	head = head->next;
	p->next=NULL;
	//printf("\n头结点的值：%d", head->data);
	return(head);
}

int get_len(node *head){
	int n=0;
	node *p;
	p=head;
	while(p!=NULL){
		p=p->next;
		n++;
	}

	return n;
}

void print_linklist(node *head){
	node *p;
	p=head;
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL\n");
}

node *del_node(node *head, int num){//删除节点，待删除节点的位置需要考究
	node *p,*q;
	p=head;
	while(p->data!=num && p->next!=NULL){
		q=p;//保留上一个节点指针
		p=p->next;//指向下一个节点
	}

	if(num == p->data){
		if(p==head){//如果是删除头结点，则让head指向p的下一个节点，free掉p
			head = p->next;
			free(p);p=NULL;
		}
		else{//否则，让q指向p的下一个节点
			q->next=p->next;
		}

	}
	else{
		printf("该链表中没有要删除的数：%d\n",num);
	}
	return head;
}

node *insert_node(node *head, int num){//插入节点，插入的位置需要考究
	node *p0,*p1,*p2;
	p1=head;
	p0=(node *)malloc(sizeof(node));//给新的节点申请内存
	p0->data = num;
	while(p0->data > p1->data && p1->next!=NULL){
		p2=p1;//保存上一个节点
		p1=p1->next;
	}
	if(p0->data <= p1->data){
		if(head == p1){//如果插入在头结点以前，直接让p0下一个节点指向p1,head指向p0
			p0->next = p1;
			head = p0;
		}
		else{//否则，让p2的next存储p0,p0的next指向p1
			p2->next=p0;
			p0->next=p1;
		}
	}
	else{//插入在尾节点，让p1指向p0,p0指向NULL
		p1->next=p0;
		p0->next=NULL;
	}

	return head;

}

node *sort_linklist(node *head){//对链表进行排序
	node *p1,*p2;
	int temp;
	if(head == NULL || head->next == NULL) return head;
	p1=head;
	while(p1){//保证最后一个能比较的上
		p2=p1->next;
		while(p2){//此处必须保证，最后一个能够比较的上
			if(p2->data < p1->data){//如果p2节点中的值小于p1节点,则交换二者的值
				temp = p2->data;
				p2->data = p1->data;
				p1->data = temp;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	return head;
}


node *reverse_linklist(node *head){//对链表进行逆置
	node *p1,*p2,*p3;
	if(head == NULL || head->next == NULL) return head;
	p1=head;
	p2=p1->next;
	while(p2){//使用三个指针，遍历单链表，逐个连接点反转
		//其中p1用来保存翻转后的那部分头指针，p2用来保存未反转部分的头指针，p3的作用是辅助
		p3=p2->next;//将未反转的部分保存为p3
		p2->next=p1;//让p2的next指向p1,反转p1与p2
		p1=p2;//移动p1到p2位置
		p2=p3;//移动p2到p3位置
	}
	head->next = NULL;
	head = p1;
	return head;
}

void get_mid_node(node *head){//求中间节点，要考虑节点的个数是奇数还是偶数
	int len = get_len(head);
	node *p,*q,*mid=NULL;
	p=head;
	q=head;
	/*
	if(p->next == NULL){
		printf("中间元素为:%d\n",p->data);
		return;
	}
	if(p->next->next == NULL){
		printf("中间蒜素为:%d,%d\n",p->data,p->next->data);
		return;
	}*/

	while(p->next !=NULL && p->next->next !=NULL){
		p=p->next->next;
		q=q->next;
		mid = q;
	}

	if(len % 2 == 0){
		if(mid) printf("中间元素为：%d,%d\n",mid->data,mid->next->data);
		else printf("中间元素为：%d,%d\n",p->data,p->next->data);
	}
	else{
		if(mid) printf("中间元素为：%d\n",mid->data);
		else printf("中间元素为：%d\n",p->data);
	}

}
node *merge_linklist(node *head1, node *head2){//合并两个增序链表
	node *p1,*p2,*temp,*p3,*p4;
	//比较两个链表头结点的大小，以小的作为母链保存为head1
	if(head1->data > head2->data){//交换head1和head2
		temp=head1;
		head1=head2;
		head2=temp;
	}

	//print_linklist(head1);
	//print_linklist(head2);

	p2=head2;

	while(p2){//从head2中取结点，插入到head1中

		p3=p2;//将节点取出来，用于操作
		p2=p2->next;//保存当前节点的下一个节点的位置

		p1=head1;//重置p1的位置
		while(p1 && p3->data >= p1->data){//找位置，由于规定好了head1小于head2所以没有插入头结点之前的情况
			p4 = p1;//保存上一个节点
			p1=p1->next;
		}


		if(p1 == NULL){//如果到了最后一个结点，则直接把p1的前一个节点temp的后置链设为p2,p2的next域为空
			p4->next = p3;
			p3->next = NULL;
		}
		else{//插入在中间位置
			p4->next = p3;
			p3->next = p1;

		}
		printf("要添加的节点：%d\n", p3->data);
		print_linklist(head1);

	}
	return head1;

}


int main(int argc, char const *argv[])
{
	/* code */
	printf("链表节点的大小(我的计算是16):%lu\n",sizeof(node));
	//注意，这里我的mac是64位机器，所以指针固定大小为8个字节，加上内存对齐，这里应该是16B

	/*
	int lenth;
	node *l;
	l=create();
	lenth = get_len(l);
	printf("\n链表的长度为:%d\n",lenth);
	print_linklist(l);//输出链表
	//l=del_node(l,3);//删除节点
	//print_linklist(l);
	//l=insert_node(l,2);//插入节点
	//print_linklist(l);
	//l=sort_linklist(l);//对链表进行排序
	//print_linklist(l);
	l=reverse_linklist(l);
	print_linklist(l);
	get_mid_node(l);*/

	node *l1, *l2,*l;
	l1=create();
	l2=create();
	print_linklist(l1);
	print_linklist(l2);
	l = merge_linklist(l1,l2);
	print_linklist(l);
	return 0;
}