#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int data;
	struct student *next;//后置链
	struct student *pre;//前置链
}dnode;

dnode *create(){//创建一个双链表
	dnode *head,*p,*temp;

	int x,cycle=1;
	head = (dnode*)malloc(sizeof(dnode));
	head->next = NULL;//初始化头结点，还需要为头结点申请空间
	p=head;//初始化p的开始位置
	while(cycle){//循环创建节点，插入末尾
		printf("请输入要创建的节点:\n");
		scanf("%d",&x);
		if(x){
			temp = (dnode *)malloc(sizeof(dnode));//为节点申请空间
			temp->data = x;
			p->next = temp;//将p的后置链设为temp
			temp->pre = p;//将temp的前置链设为p,毕竟这是双链表，总得有双链表的特性
			p=temp;//移动p的位置
		}
		else cycle=0;//否则改变循环标记，终止循环
	}
	head = head->next;//将头结点移到创建的第一个节点的位置
	p->next = NULL;
	return head;

}

void print_linklist(dnode *head){//打印列表
	dnode *p;
	p=head;
	while(p){
		printf("%d",p->data);
		p=p->next;
		printf("->");
	}
	printf("NULL\n");
}

dnode *del_node(dnode *head, int num){//删除节点,节点的位置有考究，头结点，中间节点，尾节点以及不存在四类
	dnode *p1;
	p1=head;
	while(p1->data != num && p1->next!=NULL){//找节点
		p1=p1->next;
	}

	if(p1->data == num){//将p1的前一个节点的后置链表设为p1的后置链，将p1后一个节点的前置链设为p1的前置链

		if(p1==head){//待删除节点位于头结点
			head = head->next;//直接将头结点右移一个节点
			free(p1);p1=NULL;
		}
		else if(p1->next == NULL){//待删除节点位于尾节点
			p1->pre->next = NULL;//将p1的前一个节点的后置链设为空
			free(p1);p1=NULL;//将悬浮指针置为空指针，降低风险
		}
		else{
			p1->pre->next = p1->next;
			p1->next->pre = p1->pre; 
			free(p1);p1=NULL;
		}
	}
	else printf("待删除节点不存在:%d\n",num);
	return head;
}

dnode *insert_node(dnode *head, int num){//插入节点，插入的位置要考究，头结点之前，中间节点，尾节点之后
	dnode *p1,*temp,*p2;
	//给待插入节点申请空间并初始化
	temp = (dnode*)malloc(sizeof(dnode));
	temp->data = num;

	p1=head;

	while(p1 && p1->data < num){//利用逻辑短路，如果p1为空，其p1->data域就不存在，必须把p1放在前面否则会出错

		p2=p1;//保存最后一个节点，当num比所有数都大时(一个小技巧)
		p1=p1->next;//移动指针p1的位置
	}


	if(p1 == head){//如果插入节点位置头节点之前，直接让temp的后置链为p1,p1的前置链为temp,前置链为NULL,然后head移到temp上
		temp->next = p1;
		p1->pre = temp;
		temp->pre = NULL;
		head = temp;
	}
	else if(p1 == NULL){//当num比所有数都大的时候
		temp->pre = p2;
		p2->next = temp;
		temp->pre = NULL;
		free(p1);p1=NULL;
	}

	else{//插入位置在中间,temp的前置链为p1的前置链，p1的前一个节点的后置链为temp,p1的前置链为temp
		temp->pre = p1->pre;
		p1->pre->next = temp;
		p1->pre = temp;
		temp->next = p1;
	}

	return head;

}

int main(int argc, char const *argv[])
{
	/* code */
	printf("节点的大小(我计算是24):%lu\n",sizeof(dnode));//64位机器指针大小应为8B
	printf("long整型的长度:%lu\n",sizeof(long));//这个long因机器而异，我的mac就是8个字节
	dnode *dl;
	dl = create();
	print_linklist(dl);
	dl = del_node(dl,2);//删除节点
	print_linklist(dl);
	dl= insert_node(dl,4);//插入节点
	print_linklist(dl);

	return 0;
}