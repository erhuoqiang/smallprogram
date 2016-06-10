#include<stdio.h>

/*
	用位运算实现加法
*/
int add(int a, int b)
{
	int temp = 0;
	while(b) 
	{	
		temp = a;
		a = a^b; //取两个数的不同的地方，把位都为1的地方置0
		b = (temp&b)<<1;  //b是进位，与上异或前的a，求出相同的位,也就是需要进位的位，其位在a异或的时已经置0，然后左移动一位
	}
	return a;
}

int sub(int a,int b)
{
	int temp = 0;

	while(b)
	{	
		temp = a&b;
		a ^= temp;
		b ^= temp;
		a ^= b;
		b = b<<1;
	}
	return a;
}
/*
	不使用减法实现比较两个数的大小
*/
int Judge_DealWithNoSub(int a,int b)
{
	if( !(a^b) )
		printf("Judge result is a=b\n");
	else
	{

		b = ~b + 1; //取B的补码相当于-B
		if( (a + b)&(1<<31) )//相加以后判断最高符号位即可 
		{
			printf("Judge result is a<b\n");
		}
		else
		{	
			printf("Judge result is a>b\n");
		}
	}
}

/*                  位运算实现乘法          */
int Mul(int a,int b)
{
	int sum = 0;
	int flag = 0;
        if( a < 0 )
        {
		flag++;
                a = ~a + 1;
        }
        if( b < 0 )
        {
		flag++;
                b = ~b + 1;
        }
	
	while(b)
	{
		if(b & 0x01)
		{
			sum = add(sum,a);
		}
		b >>= 1;
		a <<= 1;
	}
	return flag == 1? ~sum + 1 : sum;
}
/*
	减法实现除法  被除数小于除数的时候用 Q15定点数表示	
	或者基于add（a,-b）减一个加一个	
*/
int main(int argc,char **argv)
{
	int fir = 0, sec = 0;
	while(1)
	{
		printf("Please input your num:");
		scanf("%d%d",&fir,&sec);
		Judge_DealWithNoSub(fir,sec);
		printf("add result = %d\n",add(fir,sec));
		printf("sub result = %d\n",sub(fir,sec));		
		printf("Mul result = %d\n",Mul(fir,sec));	
		
	}
}
