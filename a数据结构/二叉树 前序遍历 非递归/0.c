#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//二叉树类型
typedef struct TREENODE
{
	int data;
	struct TREENODE * leftchild;
	struct TREENODE * rightchild;
}TreeNode;
//定义根节点 注意 野指针 赋值NULL
TreeNode * root = NULL;
//初始化根节点
void Init_root(int data)
{
	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->data = data;
	root->rightchild = NULL;
	root->leftchild = NULL;
}
//链栈的类型
typedef struct List_stack
{
	TreeNode * data;
	struct List_stack * next;
}list;
//定义栈顶
list * stack_top = NULL;
//栈是否为空
int if_empty()
{
	if(stack_top == NULL)
		return 1;
	else
		return 0;
}
//推入栈
void push(TreeNode * data)
{
	list * temp = (list *)(malloc(sizeof(TreeNode)));
	temp->data = data;
	temp->next = stack_top;
	stack_top = temp;
}
//推出栈
TreeNode * pop(void)
{	
	list * top = stack_top;
	TreeNode * temp = NULL;
	if(if_empty())
	{
		printf("空栈");
	}
	else 
	{	
		stack_top = top->next;
		temp = top->data;
		free(top);
		return temp;
	}
	return NULL;
}
int num ;
/******************************

  前序遍历的非递归

******************************/
/* 
void pre_order(TreeNode * temp)
{
	while( temp != NULL ||  !(if_empty()) )
	{
		while(temp != NULL)
		{
			printf(" %d",temp->data);
			push(temp);
			temp = temp->leftchild;
		}
		if(stack_top != NULL)
		{
			temp = pop();
			temp = temp->rightchild;
		}
	}
}*/
/******************************

  前序遍历的递归

******************************/
void pre_order(TreeNode * temp)
{
	if(temp != NULL)
	{
		num++;
		printf(" %d",temp->data);
		pre_order(temp->leftchild);
		pre_order(temp->rightchild);
	//	free(temp);
	}
}
void insert(int data)
{
	TreeNode ** current;
	current = &root;
	while(*current != NULL)
	{
		if((*current)->data > data)
		{
			current = &(*current)->leftchild;
		}
		else
		{
			assert((*current)->data != data);
			current = &(*current)->rightchild;
		}
	}
	*current = (TreeNode *)malloc(sizeof(TreeNode));
	(*current)->data = data;
	(*current)->leftchild = NULL;
	(*current)->rightchild = NULL;
}

TreeNode * find(int data)
{
	TreeNode * current = root;
	while(current != NULL && current->data != data)
	{
		if(current->data > data)
		{
			current = current->leftchild;
		}
		else
		{
			current = current->rightchild;
		}
	}
	if(current != NULL)
	{
		return current;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int temp[20] = {12, 5, 9, 16,15,11};
	int i = 0;
	TreeNode * treetemp = NULL;
	Init_root(20);
	for(i = 0;i < 6; i++)
	{
		insert(temp[i]);
	}	
	pre_order(root);	
}




	



