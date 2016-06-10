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


//��׺���ʽת��׺                 src����������С���㣬(+ - *��)
int Infix_to_Postfix(const char *src, char * dest)
{
    int i = 0 ;
    char ch = 0;
	if( src == NULL || dest == NULL  )
		return -1;
		while(*src)
        {
            if(*src <= '9' && *src >= '0' || *src == '.')  //�����������С���� ֱ�Ӹ��������
                dest[i++] = *src;
            else if(*src == ' ')
                ;   //�����ո����
            else if(*src == '(')
                push(*src);  //����'(' ֱ��ѹ��ջ
            else if( *src == ')')
            {
                while( ((ch = gettop()) != '(') && !Is_Empty() )   //����')'�����destֱ������'('����ջΪ��
                {
                    dest[i++] = ch;
                    pop();
                }
                if(ch != '(')  //�������ջΪ���ˣ���û���ҵ�'��'
                {
                    printf("short of '(' ;\n");
                    return -1;
                }
                pop();  //��'('����
            }
            else if( *src == '+' || *src == '-' || *src == '*' || *src == '/' )
            {
                while( Priority(*src) <= Priority((ch = gettop())) )  //�����Ӽ��˳��򵯳����ڵ��ڵ�ǰ�ַ��Ĳ�������ֱ�������ȵ�ǰ�͵�
                {                                                       //�����ǰջΪ���򷵻�-1.���ȼ����
                    dest[i++] = ch;
                    pop();
                }
                dest[i++] = ' ';     //�ڲ�����ѹ��ջ֮ǰ ��dest��λ�ü��Ͽո� �����ֲ�ͬ������ 1 + 2 ��ɺ�׺�ͱ��12+�ֲ���������12��������1��2.
                                        //���Ͽո�����������
                push(*src);   //Ȼ�󽫵��ַ�ǰѹ���ջ��

            }
            else
                ;
            src++;
        }
        //src������� *src == '+' || *src == '-' || *src == '*' || *src == '/'��ջ����ʣ��Ĳ���������
        while(!Is_Empty())
        {
            dest[i++] = gettop();
            pop();
        }
        dest[i] = 0;
}


//�ַ���תdouble �����Ǹ���
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

            temp = gettop()/temp;   //ע������� �����ͱ�������˳������

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
