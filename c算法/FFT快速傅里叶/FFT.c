#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<assert.h>


#define PI 3.1415926
#define INTERVAL 3

typedef struct complexx
{
    float real;
    float imag;
}  Complex;

/***********************屏幕坐标跳转*********************/
void Gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}
/******************画表格**********************************
	NUM是当前画的图形是第几个  如如果前面以及画了一
	个图像 那么这里就是第二个
	HIGH 图像的高度  A数组放大的刻度因为
	坐标定位只能是整数所以需要将浮点数 扩大1/A倍后转化为整数
	才有明显的曲线效果
**********************************************************/
void Draw_Graphisc(int N, float * src, int NUM,int HIGH, double A)
{
	int i = 0;
	for( i = 0; i < N; i++ )
	{
		Gotoxy(i*INTERVAL, (int)(HIGH*NUM - src[i]/A));
		putchar('*');	
	}
}

/******************复数加法********************************/
void  Complex_Add(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real + b.real;
    c->imag = a.imag + b.imag;
}

/******************复数减法********************************/
void Complex_Sub(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real - b.real;
    c->imag = a.imag - b.imag;
}

/******************复数乘法********************************/
void Complex_Mul(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real * b.real - a.imag * b.imag;
    c->imag = a.real * b.imag + a.imag * b.real;
}

/******************复数除法********************************/
void Complex_Div(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = (a.real * b.real + a.imag * b.imag)/(b.real * b.real +b.imag * b.imag);
    c->imag = (a.imag * b.real - a.real * b.imag)/(b.real * b.real +b.imag * b.imag);
}

/******************求共轭复数********************************/
void Conjugate_Complex(int NUM, Complex * const In, Complex * const Out)
{
  int i = 0;
  assert( In != NULL && Out != NULL && NUM >= 0 );
  for( i=0; i< NUM; i++ )
  {
    Out[i].imag = -In[i].imag;
    Out[i].real = In[i].real;
  }
}

/******************求复数的模*******************************/
void Complex_Abs(int N, Complex * src, float * Ampl_Fre )
{
    int i = 0;
    assert( N >=0 && src != NULL && Ampl_Fre != NULL);
    for( i = 0; i < N; i++ )
    {
        Ampl_Fre[i] = (float)sqrt(src[i].real * src[i].real + src[i].imag * src[i].imag);
    }
}

/******************求复数的相位*******************************/
void Complex_Phase(int N, Complex * src, float * Phase_Fre )
{
    int i = 0;
    assert( N >=0 && src != NULL && Phase_Fre != NULL);
    for( i = 0; i < N; i++ )
    {
        Phase_Fre[i] = (float)atan(src[i].imag / src[i].real);
    }
}

/******************求WN_kn*******************************/
void WN_kn( int N, int kn, Complex * wn)
{
    assert(wn != NULL);
    wn->real = (float)cos(2*PI*kn/N);
    wn->imag = (float)-sin(2*PI*kn/N);
}

/******************FFT算法 根据流程图编写*******************************/
void FFT( int N, Complex * Dest )
{
    int M = 1, i = N, back = 0;// M是级数， i for循环的临时变量，back倒序用的临时变量
    int k = 0;//k 为倒序算法中的权位值
    int m = 0, n = 0, dish = 0, wn_kn, Group_Member_Num = 0, Group_Dish_Num = 0; //m,n,dish是FFT步骤中的FOR循环临时变量
     //wn_kn是每个级数对应的旋转因子的系数   Group_Member_Num 同级数中每个组成员数 Group_Dish_Num每个组的碟形数
    Complex temp, wn;
    int lc;  //LC是碟形运算中 A-WN*B A+WN*B中 B的位置
    assert(Dest != NULL);

    //计算级数 M = log 2^N;
    while( (i /= 2) != 1) M++;


    //源信号的序号倒序 如 第3个 二进制011 = 3 变成  110 = 6
    //从1开始是因为 0的二进制倒叙还是0没必要在做一次倒叙
    //到N/2是因为前一半倒叙实质是前一半的某个值和后一班的某个值交换 所以 执行N/2次也就倒序完成了
    //i 从1 开始 ，back从N/2开始(N/2实质是二进制的最高位)，两两交换。课本117
    //个人理解是  就是倒序的加法运算  如  100 + 110 = 001      从左往右 进行进位加法计算
    for( i = 1,back = N/2; i <= N/2; i++ )
    {
        if(i < back)
        {
            temp = Dest[i];
            Dest[i] = Dest[back];
            Dest[back] = temp;
        }
        k = N / 2;

        while(k <= back)
        {
            back = back - k;
            k = k / 2;
        }
        back += k;
    }

    //FFT算法计算部分 根据路程图思路
    for( i = 1; i <= M; i++ ) //M代表级数
    {
        Group_Member_Num = (int)pow(2, i);  //在不同级数中每个分组的成员数
        Group_Dish_Num = Group_Member_Num/2; // 每组的碟形数是每组成员数的一半

        //这里是吧遍历分组放在最外层循环，其实放里面的话效率会高一点
        //因为放最外层wn_kn每个相同节点需要n/Group_Member_Num计算次，而放里层每个相同节点要计算1次 方法如下面注释部分
        for( n = 0; n < N - 1; n += Group_Member_Num ) //遍历每个分组，分组总数为N/Group_Member_Num
        {
			 for(dish = 1; dish <= Group_Dish_Num; dish++ ) //
			 {
                wn_kn = (dish - 1)*(int)pow(2, M - i); //不同级数M中 和第dish个碟形对应的旋转系数的计算
                lc=n + Group_Dish_Num + dish - 1;  //n,lc分别代表一个碟形单元的上、下节点编号
                WN_kn(N,wn_kn,&wn);  //wn=Wn^kn
                Complex_Mul(Dest[lc],wn,&temp);//temp = Dest[lc] * wn 复数运算
                Complex_Sub(Dest[n + dish - 1],temp,&(Dest[lc]));//Dest[lc] = Dest[n + dish - 1] - Dest[lc] * Wn^kn
                Complex_Add(Dest[n + dish - 1],temp,&(Dest[n + dish - 1]));//Dest[lc] = Dest[n + dish - 1] + Dest[n] * Wn^kn
             }
        }

        /* //分组遍历放里层
        for(dish = 1; dish <= Group_Dish_Num; dish++ )
        {
            wn_kn = (dish - 1)*pow(2, M - i); //不同级数M中 和第dish个碟形对应的旋转系数的计算
            for( n = 0; n < N - 1; n += Group_Member_Num ) //遍历每个分组，分组总数为N/Group_Member_Num
            {
                lc=n + Group_Dish_Num + dish - 1;  //n,lc分别代表一个碟形单元的上、下节点编号
                WN_kn(N,wn_kn,&wn);//wn=Wnr
                Complex_Mul(Dest[lc],wn,&temp);//t = f[lc] * wn复数运算
                Complex_Sub(Dest[n + dish - 1],temp,&(Dest[lc]));//f[lc] = f[n] - f[lc] * Wnr
                Complex_Add(Dest[n + dish - 1],temp,&(Dest[n + dish - 1]));//f[n] = f[n] + f[lc] * Wnr
            }
        }*/
    }
}


/********IFFT : 书本121页 利用FFT求的IFFT***************/
void IFFT(int N, Complex src[])
{
  int i=0;

  Conjugate_Complex(N,src,src);  //取src的共轭复数
  FFT(N,src);						
  Conjugate_Complex(N,src,src);  //取src的共轭复数

  for(i=0;i<N;i++)
  {
    src[i].imag = (src[i].imag)/N;
    src[i].real = (src[i].real)/N;
  }
}



int main()
{
	Complex SRC[100] = {{1,0},{1,0},{1,0},{1,0}};
	float out[100] = {0.0};
	int num = 0;
	printf("请输入x(n)(CTRL + Z结束):\n");
	while(scanf("%f", &SRC[num++].real) == 1);

	printf("输入e^-j2PI/N中N的值(值为2的m次幂):\n");
	scanf("%d",&num);
	
	printf("\n输入信号x(n)图形:\n");
	Complex_Abs(num, SRC, out);   //复数的绝对值等于入sqrt(real^2 + imag^2);
	Draw_Graphisc(num, out, 1, 15,0.2);

	FFT(num,SRC);
	
	printf("\n\n输入信号%d点FFT 幅频特性图形:\n",num);
	Complex_Abs(num, SRC, out);
	Draw_Graphisc(num,out,2, 20, 0.2);
	
	Gotoxy(0,60);
	printf("\n\n输入信号%d点FFT 相频特性图形:\n",num);
	Complex_Phase(num, SRC, out);
	Draw_Graphisc(num,out,4, 20, 0.5);
	printf("\n\n\n");

	Gotoxy(0,90);
	printf("\n\n %d点IFFT 还原图形:\n",num);
	IFFT(num, SRC);
	Complex_Abs(num, SRC, out);
	Draw_Graphisc(num,out,5, 20, 0.2);
	while(1);
	
}
