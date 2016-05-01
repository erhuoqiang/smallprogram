#include<stdio.h>
#include<assert.h>


#define MAXSIZE 100

int tree[MAXSIZE];

static int left_child(int current)
{
	return current * 2;
}

static int right_child(int current)
{
	return current * 2 + 1;
}

static int right_parent(int current)
{
	return current / 2;
}


void insert(int value)
{
	int current = 1;// 从1开始 避免 0*2等于0
	assert(value != 0);
	while(current < MAXSIZE && tree[current] != 0)
	{
		if(value < tree[current])
		{
			current = left_child(current);
		}
		else
		{
			assert(value != tree[current]);
			current = right_child(current);
		}
	}
	if(current < MAXSIZE)
	tree[current] = value;
	else
		printf("error");
}

int find(int value)
{
	int current = 1;
	assert(tree[current] != 0);
	while(current < MAXSIZE && tree[current] != value)
	{
		if(value < tree[current])
		{
			current = left_child(current);
		}
		else
		{
			current = right_child(current);
		}
	}
	if(current < MAXSIZE)
		return  current;
	else
		return 0;
}
int num = 0;
void pre_order(int current)
{
	if(current < MAXSIZE && tree[current] != 0)
	{	
		num++;
		printf("%d	",tree[current]);
		pre_order(left_child(current));
		pre_order(right_child(current));
	}
}

int main()
{
	int temp[20] = {12, 5, 9, 16,15,11};
	int i = 0;
	tree[1] = 20;
	for(i = 0;i < 6; i++)
	{
		insert(temp[i]);
	}	
	i = find(12);
	pre_order(i);
	printf("\n个数: %d个 \n", num);


}



