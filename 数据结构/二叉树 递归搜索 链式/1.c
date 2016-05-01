#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*******************¶þ²æÊ÷*****************/

typedef struct TREENODE
{
	int data;
	struct TREENODE * leftchild;
	struct TREENODE * rightchild;
}TreeNode;

TreeNode * tree;

void insert(int data)
{
	TreeNode ** current;
	current = &tree;
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
	TreeNode * current = tree;
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
int num;
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

void init_tree()
{
	tree = (TreeNode *)malloc(sizeof(TreeNode));
	tree->data = 20;
	tree->leftchild = NULL;
	tree->rightchild = NULL;
}

/******************Á´Õ»**********************/
struct stack_node
{
	TreeNode * data;
	struct stack_node * next;
};

typedef struct stack_node   list ;

list * stack = NULL;

int if_empty()
{
	if(stack == NULL)
		return 0;
	else 
		return 1;
}

void push( TreeNode * value )
{
	list * temp;
	temp = (list *)malloc(sizeof(list));
	temp->data = value;
	temp->next = stack;
	stack = temp;
}

TreeNode * pop( void )
{
	list * top = stack;
	TreeNode * temp = NULL;
	if(top == NULL)
		printf(" ¿ÕÕ» ");
	else
	{
		stack = top->next;
		temp = top->data;
		free(top);
		return temp;
		
	}
	return NULL;
}

int main()
{
	int temp[20] = {12, 5, 9, 16,15,11};
	int i = 0;
	TreeNode * treetemp = NULL;
	init_tree();
	for(i = 0;i < 6; i++)
	{
		insert(temp[i]);
	}	
	treetemp= find(20);
	pre_order(treetemp);
	printf(" \nnumber: %d \n",num);

}

