#include<stdio.h>
#include<malloc.h>
#include<assert.h>


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