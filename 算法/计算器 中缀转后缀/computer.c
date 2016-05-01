#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define Element double
#define Element_NULL -1

typedef struct stack_list
{
	Element Data;
	struct stack_list * Next;
}stack_list;

stack_list * SP = NULL;

int push(const Element Value)
{
	stack_list * temp = (stack_list *)malloc(sizeof(stack_list));

	if( temp == NULL)
		return -1;

	temp->Next = SP;
	temp->Data = Value;

	SP = temp;

	return 1;
}

Element gettop(void)
{
	if(SP != NULL)
	{
		return  SP->Data;
	}
	return Element_NULL;
}

Element pop(void)
{
	stack_list * temp = SP;
	if(SP != NULL)
	{
		SP = SP->Next;

		free(temp);
		temp = NULL;
	}
	return Element_NULL;
}

int Is_Empty(void)
{
	return SP == NULL? 1:0;
}

int my_strlen(const char * src)
{
	const char * temp = src;
	if(src == NULL)
		return -1;
	while(*src++);

	return src - temp - 1;
}

int Priority(const char value)
{
    switch(value)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}


//中缀表达式转后缀                 src仅包括数字小数点，(+ - *／)
int Infix_to_Postfix(const char *src, char * dest)
{
    int i = 0 ;
    char ch = 0;
	if( src == NULL || dest == NULL  )
		return -1;
		while(*src)
        {
            if(*src <= '9' && *src >= '0' || *src == '.')  //碰到数组或者小数点 直接给输出数组
                dest[i++] = *src;
            else if(*src == ' ')
                ;   //碰到空格忽略
            else if(*src == '(')
                push(*src);  //碰到'(' 直接压入栈
            else if( *src == ')')
            {
                while( ((ch = gettop()) != '(') && !Is_Empty() )   //碰到')'输出给dest直到碰到'('或者栈为空
                {
                    dest[i++] = ch;
                    pop();
                }
                if(ch != '(')  //如果碰到栈为空了，还没有找到'（'
                {
                    printf("short of '(' ;\n");
                    return -1;
                }
                pop();  //将'('弹出
            }
            else if( *src == '+' || *src == '-' || *src == '*' || *src == '/' )
            {
                while( Priority(*src) <= Priority((ch = gettop())) )  //碰到加减乘除则弹出大于等于当前字符的操作符，直到碰到比当前低的
                {                                                       //如果当前栈为空则返回-1.优先级最低
                    dest[i++] = ch;
                    pop();
                }
                dest[i++] = ' ';     //在操作符压入栈之前 将dest的位置加上空格 以区分不同的整数 1 + 2 变成后缀就变成12+分不清是数字12还是数子1和2.
                                        //加上空格后解决这个问题
                push(*src);   //然后将当字符前压入堆栈。

            }
            else
                ;
            src++;
        }
        //src处理完后 *src == '+' || *src == '-' || *src == '*' || *src == '/'将栈里面剩余的操作符弹出
        while(!Is_Empty())
        {
            dest[i++] = gettop();
            pop();
        }
        dest[i] = 0;
}


//字符串转double 不考虑负数
Element Str_to_Double(const char **src)
{
    Element value = 0;
    int counter = 0;
    assert(src != NULL);

    while(**src <= '9' &&  **src >= '0')
    {
        value = value * 10 + **src - 48;
        (*src)++;
    }
    if(**src == '.')
    {
        (*src)++;
        while(**src <= '9' &&  **src >= '0')
        {
            counter++;
            value = value * 10 + **src - 48;
            (*src)++;
        }
        while(counter--)
        {
            value /= 10;
        }

    }
    (*src)--;
    return value;
}


Element Computer_Postfix(const char * src)
{
    Element temp = 0;
    if(src == NULL)
        return Element_NULL;
    while(*src)
    {
        if(*src <= '9' &&  *src >= '0')
        {
            push(Str_to_Double(&src));
        }
        else if(*src == '+')
        {
            temp = gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            temp += gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            push(temp);
        }
        else if(*src == '-')
        {
            temp = gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            temp -= gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            push(temp);
        }
        else if(*src == '*')
        {
            temp = gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            temp *= gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            push(temp);
        }
        else if(*src == '/')
        {
            temp = gettop();

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            temp = gettop()/temp;   //注意除法中 除数和被除数的顺序问题

            if(!Is_Empty())
                pop();
            else
                return Element_NULL;

            push(temp);
        }
        else
            ;
        src++;
    }
    return temp;

}

char dest[100] = "";
int main(char argc, char **argv)
{
    char src[100] = "";
    fgets(src, 100, stdin);
    Infix_to_Postfix(src,dest);
    printf("Postfix : %s\n",dest);
    printf("result is %lf\n",Computer_Postfix(dest));


}
