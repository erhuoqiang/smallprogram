#include<stdio.h>

int n = 0;
int Search( int a[], int key , int low, int high )
{
	int mid = 0;
	while(low <= high )
	{
		n++;
		//mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
		mid = (low + high) /2;
		if( a[mid] > key )
		{
			high = mid - 1;
		}
		else if( a[mid] < key )
		{
			low = mid + 1;
		}
		else 
		{
			return mid;
		}
	}
	return 0;
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int num = 0;
	scanf("%d",&num);
	num = Search(a, num, 0, 9);
	printf("%d,%d", num, n);
	return 0;
}
