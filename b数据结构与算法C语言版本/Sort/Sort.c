#include<stdio.h>
#define Element int

int Bollue_Sort(Element a[], int len)
{
    int flag = 1, i = 0, j = 0;
    Element  temp;

    if( a == NULL || len == 0)
    {
        return 0;
    }

    for(i = 0; i < len - 1 && flag; ++i)
    {
        flag = 0;
        for(j = 0; j < len - 1 - i; ++j)
        {
            if( a[j] > a[j + 1] )
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return 1;
}

int Insert_Sort(Element a[], int len)
{
    int i = 0, j = 0;
    Element temp;
    if( a == NULL || len == 0)
    {
        return 0;
    }

    for( i = 1; i < len; ++i )
    {
        temp = a[i];
        for( j = i - 1; j >=0 && temp < a[j]; --j)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] =  temp;
    }

    return 1;
}

int Quick_Sort(Element a[], int low, int high)
{
    int i = low, j = high;
    Element temp;

    if(a == NULL || low < 0 || high < 0 )
    {
        return 0;
    }
    if( i < j )
    {

        temp = a[i];
        while(i < j)
        {
            while(i < j && temp <= a[j])
                j--;
            if(i < j)
                a[i++] = a[j];

            while(i < j && temp >= a[i])
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = temp;
        Quick_Sort(a, low, i - 1);
        Quick_Sort(a, i + 1, high);

    }
    return 1;
}

int Select_Sort(Element a[], int len)
{
    int i = 0, j = 0, l;
    Element temp;
    if(a == NULL || len < 0)
    {
        return 0;
    }
    for( i = 0; i < len; i++)
    {
        temp = a[i];
        for( j = i + 1; j < len; j++)
        {
            if(temp > a[j])
            {
                temp = a[j];
                l = j;
            }
        }
        a[l] = a[i];
        a[i] = temp;
    }
    return 1;

}

int swap(int *a, int *b)
{
   /* int temp = *a;
    *a = *b;
    *b = temp;*/
    if(a == NULL || b == NULL)
        return 0;

    if(*a != *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
    return 1;
}

/*************全排列组合**************/
int count;
int perm(int a[], int begin, int end)
{
    int i = 0;
    if(a == NULL || end < 0 || begin < 0)
        return 0;
    if(begin >= end)
    {
        for(i = 0; i <= end; i++)
        {
            printf("%d ",a[i]);
        }
        count++;
        putchar('\n');
    }
    else
    {
        for( i = begin; i <= end; i++ )
        {
            swap(a+begin, a + i);
            perm(a, begin + 1, end);
            swap(a+begin, a + i);
        }
    }
    return 1;
}

int main()
{
    int i = 0;
    Element a[10] = {1,4,5,8,9,10,-1,2,11,2};
    //Bollue_Sort(a, 10);
    //Insert_Sort(a,10);
    //Quick_Sort(a, 0, 9);
    Select_Sort(a, 10);

    for( i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    perm(a,0,5);

}
