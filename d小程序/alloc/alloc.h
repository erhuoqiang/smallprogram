#include<stdlib.h>
#define malloc 不要直接调用
#define MALLOC(num, type) (type *)alloc( (num) * sizeof(type) )

extern void * alloc( unsigned int size );



