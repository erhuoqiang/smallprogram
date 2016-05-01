#include<stdio.h>
#include<assert.h>
/*网站上的******/
#define POLY        0x1021  
int crc16(unsigned char *addr, int num,int crc)  
{  
    int i;  
    for (; num > 0; num--)              /* Step through bytes in memory */  
    {  
        crc = crc ^ (*addr++ << 8);     /* Fetch byte from memory, XOR into CRC top byte*/  
        for (i = 0; i < 8; i++)             /* Prepare to rotate 8 bits */  
        {  
            if (crc & 0x8000)            /* b15 is set... */  
                crc = (crc << 1) ^ POLY;    /* rotate and XOR with polynomic */  
            else                          /* b15 is clear... */  
                crc <<= 1;                  /* just rotate */  
        }                             /* Loop for 8 bits */  
        crc &= 0xFFFF;                  /* Ensure CRC remains 16-bit value */  
    }                               /* Loop until num=0 */  
    return(crc);                    /* Return updated CRC */  
}

/*自己书本思路写的*/
  
#define POLY_8 0x31   //相当于多项式是0x131

int CRC_8(unsigned char * data,  int num)
{
	int i = 0;
	int crc = 0;
	assert(data != NULL);
	
	crc = *data++;
	for(; num > 1; num--)
	{
			for( i = 0; i < 8; i++)
			{
					if( crc & 0x80 )
					{
						crc = ((crc<<1)|( ( *data &  (0x80 >> i) )>>(7 - i)) ) ^ POLY_8;//这里因为CRC的最高位为1 多项式的最高为也为1 所以异或肯定为0所以只比较后8位
						//	printf("%x\n",crc);
					}
					else
						crc = ((crc<<1)|(( *data &  (0x80 >> i) )>>(7 - i)));
					crc &= 0xFF;
					
			}	
			data++;
	}
	for( i = 0; i < 8; i++)
	{
		if( crc & 0x80 )
		{
			crc = (crc<<1) ^ POLY_8;
		//	printf("%x\n",crc);
		}
		else
			crc = (crc<<1);
		crc &= 0xFF;

	}
	return  crc;
}
int CRC_16(unsigned char * data,  int num)
{
	int i = 0;
	int crc = 0;
	assert(data != NULL);
	
	crc = *data++;
	for(; num > 1; num--)
	{
			for( i = 0; i < 8; i++)
			{
					if( crc & 0x8000 )
					{
						crc = ((crc<<1)|( ( *data &  (0x80 >> i) )>>(7 - i)) ) ^ POLY;
						//	printf("%x\n",crc);
					}
					else
						crc = ((crc<<1)|(( *data &  (0x80 >> i) )>>(7 - i)));
					crc &= 0xFFFF;
					
			}	
			data++;
	}
	for( i = 0; i < 16; i++)
	{
		if( crc & 0x8000 )
		{
			crc = (crc<<1) ^ POLY;
		//	printf("%x\n",crc);
		}
		else
			crc = (crc<<1);
		crc &= 0xFFFF;

	}
	return  crc;
}

/*****该算法基于这样一个事实：计算本字节后的CRC码，等于上一字节余式CRC码的低8位左移8位，
加上   上一字节CRC右移 8位和本字节之和后所求得的CRC码。如果我们把8位二进制序列数的CRC(共256个)全部
计算出来，放在一个表里，编码时只要从表中查找对应的值进行处理即可。  注意INITIAL_REMAINDER不同的CRC_X初值不同 记得修改否则会出错
http://blog.csdn.net/liyuanbhu/article/details/7882789				************/
  
#ifndef CRC_H_INCLUDED  
#define CRC_H_INCLUDED  
  
/* 
* The CRC parameters. Currently configured for CCITT. 
* Simply modify these to switch to another CRC Standard. 
*/  
/* 
#define POLYNOMIAL          0x8005 
#define INITIAL_REMAINDER   0x0000 
#define FINAL_XOR_VALUE     0x0000 
*/  
#define POLYNOMIAL          0x1021  
#define INITIAL_REMAINDER   0x0000    //记得改这个初值CCITT是FFFF  按书本计算思路也就是CRC_16是0000   
#define FINAL_XOR_VALUE     0x0000  
  
/* 
#define POLYNOMIAL          0x1021 
#define POLYNOMIAL          0xA001 
#define INITIAL_REMAINDER   0xFFFF 
#define FINAL_XOR_VALUE     0x0000 
*/  
  
/* 
* The width of the CRC calculation and result. 
* Modify the typedef for an 8 or 32-bit CRC standard. 
*/  
typedef unsigned short width_t;  
#define WIDTH (8 * sizeof(width_t))  
#define TOPBIT (1 << (WIDTH - 1))  
  
/** 
 * Initialize the CRC lookup table. 
 * This table is used by crcCompute() to make CRC computation faster. 
 */  
void crcInit(void);  
  
/** 
 * Compute the CRC checksum of a binary message block. 
 * @para message, 用来计算的数据 
 * @para nBytes, 数据的长度 
 * @note This function expects that crcInit() has been called 
 *       first to initialize the CRC lookup table. 
 */  
width_t crcCompute(unsigned char * message, unsigned int nBytes);  
  
#endif // CRC_H_INCLUDED  

//#include "crc.h"  
/* 
* An array containing the pre-computed intermediate result for each 
* possible byte of input. This is used to speed up the computation. 
*/  
static width_t crcTable[256];  
  
/** 
 * Initialize the CRC lookup table. 
 * This table is used by crcCompute() to make CRC computation faster. 
 */  
void crcInit(void)  
{  
    width_t remainder;  
    width_t dividend;  
    int bit;  
    /* Perform binary long division, a bit at a time. */  
    for(dividend = 0; dividend < 256; dividend++)  
    {  
        /* Initialize the remainder.  */  
        remainder = dividend << (WIDTH - 8);  
        /* Shift and XOR with the polynomial.   */  
        for(bit = 0; bit < 8; bit++)  
        {  
            /* Try to divide the current data bit.  */  
            if(remainder & TOPBIT)  
            {  
                remainder = (remainder << 1) ^ POLYNOMIAL;  
            }  
            else  
            {  
                remainder = remainder << 1;  
            }  
        }  
        /* Save the result in the table. */  
        crcTable[dividend] = remainder;  
    }  
} /* crcInit() */  
  
/** 
 * Compute the CRC checksum of a binary message block. 
 * @para message, 用来计算的数据 
 * @para nBytes, 数据的长度 
 * @note This function expects that crcInit() has been called 
 *       first to initialize the CRC lookup table. 
 */  
width_t crcCompute(unsigned char * message, unsigned int nBytes)  
{  
    unsigned int offset;  
    unsigned char byte;  
    width_t remainder = INITIAL_REMAINDER;  
    /* Divide the message by the polynomial, a byte at a time. */  
    for( offset = 0; offset < nBytes; offset++)  
    {  
		//本字节CRC = 上一字节余式CRC码的低8位左移8位  ^   上一字节CRC右移 8位和本字节之和后所求得的CRC码
        byte = (remainder >> (WIDTH - 8)) ^ message[offset];   //上一字节的CRC 的高8位异或上 当前的数据 得到运算后的数据
        remainder = crcTable[byte] ^ (remainder << 8);   //    运算后的数据对应的CRC异或 上一个CRC<<8
    }  
    /* The final remainder is the CRC result. */  
    return (remainder ^ FINAL_XOR_VALUE);  
} /* crcCompute() */  
int main()
{
	int c;

	unsigned char data[] = {3, 4, '3', 0, '5', '6', '7', '8', '9'};  
	crcInit();
	c = CRC_8(data,1);
	printf("%x\n",c);
	c = crc16(data, 2,0);
	printf("%x\n",c);
	c = CRC_16(data, 2);
	printf("%x\n",c);
	c =  crcCompute(data,2);
		printf("%x\n",c);
}
