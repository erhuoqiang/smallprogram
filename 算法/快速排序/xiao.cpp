#include<iostream>
#include<queue>
using namespace std;

#define Element int
//递归实现快排
int Quick_Sort(Element *num, int low, int high)
{
	Element temp = 0;
	int i = low, j = high;
	if(num == NULL || low < 0 || high < 0)
		return -1;
	
	if(i < j)
	{
		temp = num[i];
		while(i < j)	
		{
			while(i < j && temp <= num[j])
				j--;
			if( i < j )
				num[i++] = num[j];

			while(i < j && temp >= num[i])
				i++;
			if( i < j )
				num[j--] = num[i];
		}
		num[i] = temp;
		Quick_Sort(num, low, j - 1);
		Quick_Sort(num, j + 1, high);
	}
	return 1;
}

typedef struct
{
	int begin;
	int end;
}Range;
	
//快排非递归实现 这里使用栈或者列队都可有实现
int Non_Recusion_Quick_Sort(Element * num, int low, int high)
{
	Range temprange;
	queue<Range> q;
	Element temp = 0;
	int i = low, j = high;
	if(num == NULL || low <0 || high < 0|| low > high)
		return -1;
	temprange.begin = low;
	temprange.end = high;
	q.push(temprange);

	while(!q.empty())
	{	
		temprange = q.front();
		q.pop();
		low = i = temprange.begin;
		high = j = temprange.end;	

		temp = num[i];
		while(i < j)	
		{
			while(i < j && temp <= num[j])
				j--;
			if( i < j )
				num[i++] = num[j];

			while(i < j && temp >= num[i])
				i++;
			if( i < j )
				num[j--] = num[i];
		}
		num[i] = temp;
		if( i - 1 > low)
		{
			temprange.begin = low;
			temprange.end = i - 1;
			q.push(temprange);
		}
		
		if( i + 1 < high)
		{
			temprange.begin = i + 1;
			temprange.end = high;
			q.push(temprange);
		}		
	}
	return 1;
}
	
void print_num(Element * num, int count)
{
	if(num != NULL)
	{
		for(; count>0; count--)
			cout<<num[count - 1]<<" ";
		cout<<endl;
	}
}	

int main(int argc, char ** argv)
{
	Element num[10] = {34,1,3,41,4,12312,321,13,123,21};
	//Quick_Sort(num, 0, 4);
	Non_Recusion_Quick_Sort(num, 0, 10 -1 );
	print_num(num, 10);
}
