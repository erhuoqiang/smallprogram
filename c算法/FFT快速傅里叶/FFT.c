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

/***********************��Ļ������ת*********************/
void Gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}
/******************�����**********************************
	NUM�ǵ�ǰ����ͼ���ǵڼ���  �����ǰ���Լ�����һ
	��ͼ�� ��ô������ǵڶ���
	HIGH ͼ��ĸ߶�  A����Ŵ�Ŀ̶���Ϊ
	���궨λֻ��������������Ҫ�������� ����1/A����ת��Ϊ����
	�������Ե�����Ч��
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

/******************�����ӷ�********************************/
void  Complex_Add(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real + b.real;
    c->imag = a.imag + b.imag;
}

/******************��������********************************/
void Complex_Sub(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real - b.real;
    c->imag = a.imag - b.imag;
}

/******************�����˷�********************************/
void Complex_Mul(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = a.real * b.real - a.imag * b.imag;
    c->imag = a.real * b.imag + a.imag * b.real;
}

/******************��������********************************/
void Complex_Div(const Complex a, const Complex b, Complex * const c)
{
    assert( c != NULL );
    c->real = (a.real * b.real + a.imag * b.imag)/(b.real * b.real +b.imag * b.imag);
    c->imag = (a.imag * b.real - a.real * b.imag)/(b.real * b.real +b.imag * b.imag);
}

/******************�����********************************/
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

/******************������ģ*******************************/
void Complex_Abs(int N, Complex * src, float * Ampl_Fre )
{
    int i = 0;
    assert( N >=0 && src != NULL && Ampl_Fre != NULL);
    for( i = 0; i < N; i++ )
    {
        Ampl_Fre[i] = (float)sqrt(src[i].real * src[i].real + src[i].imag * src[i].imag);
    }
}

/******************��������λ*******************************/
void Complex_Phase(int N, Complex * src, float * Phase_Fre )
{
    int i = 0;
    assert( N >=0 && src != NULL && Phase_Fre != NULL);
    for( i = 0; i < N; i++ )
    {
        Phase_Fre[i] = (float)atan(src[i].imag / src[i].real);
    }
}

/******************��WN_kn*******************************/
void WN_kn( int N, int kn, Complex * wn)
{
    assert(wn != NULL);
    wn->real = (float)cos(2*PI*kn/N);
    wn->imag = (float)-sin(2*PI*kn/N);
}

/******************FFT�㷨 ��������ͼ��д*******************************/
void FFT( int N, Complex * Dest )
{
    int M = 1, i = N, back = 0;// M�Ǽ����� i forѭ������ʱ������back�����õ���ʱ����
    int k = 0;//k Ϊ�����㷨�е�Ȩλֵ
    int m = 0, n = 0, dish = 0, wn_kn, Group_Member_Num = 0, Group_Dish_Num = 0; //m,n,dish��FFT�����е�FORѭ����ʱ����
     //wn_kn��ÿ��������Ӧ����ת���ӵ�ϵ��   Group_Member_Num ͬ������ÿ�����Ա�� Group_Dish_Numÿ����ĵ�����
    Complex temp, wn;
    int lc;  //LC�ǵ��������� A-WN*B A+WN*B�� B��λ��
    assert(Dest != NULL);

    //���㼶�� M = log 2^N;
    while( (i /= 2) != 1) M++;


    //Դ�źŵ���ŵ��� �� ��3�� ������011 = 3 ���  110 = 6
    //��1��ʼ����Ϊ 0�Ķ����Ƶ�����0û��Ҫ����һ�ε���
    //��N/2����Ϊǰһ�뵹��ʵ����ǰһ���ĳ��ֵ�ͺ�һ���ĳ��ֵ���� ���� ִ��N/2��Ҳ�͵��������
    //i ��1 ��ʼ ��back��N/2��ʼ(N/2ʵ���Ƕ����Ƶ����λ)�������������α�117
    //���������  ���ǵ���ļӷ�����  ��  100 + 110 = 001      �������� ���н�λ�ӷ�����
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

    //FFT�㷨���㲿�� ����·��ͼ˼·
    for( i = 1; i <= M; i++ ) //M������
    {
        Group_Member_Num = (int)pow(2, i);  //�ڲ�ͬ������ÿ������ĳ�Ա��
        Group_Dish_Num = Group_Member_Num/2; // ÿ��ĵ�������ÿ���Ա����һ��

        //�����ǰɱ���������������ѭ������ʵ������Ļ�Ч�ʻ��һ��
        //��Ϊ�������wn_knÿ����ͬ�ڵ���Ҫn/Group_Member_Num����Σ��������ÿ����ͬ�ڵ�Ҫ����1�� ����������ע�Ͳ���
        for( n = 0; n < N - 1; n += Group_Member_Num ) //����ÿ�����飬��������ΪN/Group_Member_Num
        {
			 for(dish = 1; dish <= Group_Dish_Num; dish++ ) //
			 {
                wn_kn = (dish - 1)*(int)pow(2, M - i); //��ͬ����M�� �͵�dish�����ζ�Ӧ����תϵ���ļ���
                lc=n + Group_Dish_Num + dish - 1;  //n,lc�ֱ����һ�����ε�Ԫ���ϡ��½ڵ���
                WN_kn(N,wn_kn,&wn);  //wn=Wn^kn
                Complex_Mul(Dest[lc],wn,&temp);//temp = Dest[lc] * wn ��������
                Complex_Sub(Dest[n + dish - 1],temp,&(Dest[lc]));//Dest[lc] = Dest[n + dish - 1] - Dest[lc] * Wn^kn
                Complex_Add(Dest[n + dish - 1],temp,&(Dest[n + dish - 1]));//Dest[lc] = Dest[n + dish - 1] + Dest[n] * Wn^kn
             }
        }

        /* //������������
        for(dish = 1; dish <= Group_Dish_Num; dish++ )
        {
            wn_kn = (dish - 1)*pow(2, M - i); //��ͬ����M�� �͵�dish�����ζ�Ӧ����תϵ���ļ���
            for( n = 0; n < N - 1; n += Group_Member_Num ) //����ÿ�����飬��������ΪN/Group_Member_Num
            {
                lc=n + Group_Dish_Num + dish - 1;  //n,lc�ֱ����һ�����ε�Ԫ���ϡ��½ڵ���
                WN_kn(N,wn_kn,&wn);//wn=Wnr
                Complex_Mul(Dest[lc],wn,&temp);//t = f[lc] * wn��������
                Complex_Sub(Dest[n + dish - 1],temp,&(Dest[lc]));//f[lc] = f[n] - f[lc] * Wnr
                Complex_Add(Dest[n + dish - 1],temp,&(Dest[n + dish - 1]));//f[n] = f[n] + f[lc] * Wnr
            }
        }*/
    }
}


/********IFFT : �鱾121ҳ ����FFT���IFFT***************/
void IFFT(int N, Complex src[])
{
  int i=0;

  Conjugate_Complex(N,src,src);  //ȡsrc�Ĺ����
  FFT(N,src);						
  Conjugate_Complex(N,src,src);  //ȡsrc�Ĺ����

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
	printf("������x(n)(CTRL + Z����):\n");
	while(scanf("%f", &SRC[num++].real) == 1);

	printf("����e^-j2PI/N��N��ֵ(ֵΪ2��m����):\n");
	scanf("%d",&num);
	
	printf("\n�����ź�x(n)ͼ��:\n");
	Complex_Abs(num, SRC, out);   //�����ľ���ֵ������sqrt(real^2 + imag^2);
	Draw_Graphisc(num, out, 1, 15,0.2);

	FFT(num,SRC);
	
	printf("\n\n�����ź�%d��FFT ��Ƶ����ͼ��:\n",num);
	Complex_Abs(num, SRC, out);
	Draw_Graphisc(num,out,2, 20, 0.2);
	
	Gotoxy(0,60);
	printf("\n\n�����ź�%d��FFT ��Ƶ����ͼ��:\n",num);
	Complex_Phase(num, SRC, out);
	Draw_Graphisc(num,out,4, 20, 0.5);
	printf("\n\n\n");

	Gotoxy(0,90);
	printf("\n\n %d��IFFT ��ԭͼ��:\n",num);
	IFFT(num, SRC);
	Complex_Abs(num, SRC, out);
	Draw_Graphisc(num,out,5, 20, 0.2);
	while(1);
	
}
