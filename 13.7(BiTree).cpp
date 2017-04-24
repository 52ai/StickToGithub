#include <stdio.h>
#include <stdlib.h>

//定义二叉树的节点数据结构

typedef struct BiTNode{
	char data;//数据域
	struct BiTNode *left_child;//左子树指针
	struct BiTNode *right_child;//右子树指针
}node;

//初始化

/*
node *initiate(node *root){//初始化,利用指针函数（返回值为指针）实现根节点初始化
	//当然也可以通过双指针来实现根节点的初始化

}*/

void initiate(node **root, char data){//利用双指针实现根节点的初始化
	*root = (node *)malloc(sizeof(node));//此时*root还是指针，指向传入的根节点
	(*root)->left_child = NULL;
	(*root)->right_child = NULL;
	(*root)->data = data;
}

//左插入节点
//若当前节点curr非空，则在curr的左子树插入元素值为data的新节点

node *create_left_node(node *curr, char data){
	node *c,*c_pre;//f表示父节点指针，c表示孩子节点的指针,c_pre表示原孩子节点指针
	if(NULL == curr) return NULL;//如果当前节点为空，则返回空
	c_pre = curr->left_child;//保留原curr所指向左子树
	c = (node *)malloc(sizeof(node));//给节点申请内存空间（在堆上）
	c->data = data;
	c->left_child=c_pre;//新插入的节点的左子树为原curr的左子树
	c->right_child=NULL;//右子树为空

	curr->left_child = c;//更新当前节点的左子树
	return c;//返回新插入节点的指针
}

//右插入节点
//若当前节点curr非空，则在curr的左子树插入元素为data的新节点
node *create_right_node(node *curr, char data){
	node *c,*c_pre;
	if(NULL == curr) return NULL;
	c_pre = curr->right_child;
	c = (node *)malloc(sizeof(node));
	c->data=data;
	c->left_child=NULL;
	c->right_child=c_pre;

	curr->right_child=c;
	return c;
}

//前序遍历
/*
1.访问根节点
2.递归前序遍历根节点的左子树
3.递归前序遍历根节点的右子树
*/

void pre_order(node *root){
	if(root!=NULL){
		printf("%c->",root->data);
		pre_order(root->left_child);
		pre_order(root->right_child);
	}
}


//递归创建二叉树


int main(int argc, char const *argv[]){
	node *root,*p;
	initiate(&root, 'A');//初始化根节点
	printf("root:%c\n",root->data);

	p = create_left_node(root,'B');
	p = create_right_node(root,'C');

	printf("root left child:%c\n",root->left_child->data);
	printf("root right child:%c\n",root->right_child->data);
	pre_order(root);
	printf("\n");



}

