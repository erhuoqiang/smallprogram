#include<stdlib.h>
#define malloc ��Ҫֱ�ӵ���
#define MALLOC(num, type) (type *)alloc( (num) * sizeof(type) )

extern void * alloc( unsigned int size );



