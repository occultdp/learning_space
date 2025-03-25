#include <REGX52.H>
#include "Delay.h"
sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

/**
  * @brief  	点阵屏初始化
  * @param  	无
  * @retval  	无
*/
void MATRIX_Init()
{
	RCK = 0;
	SCK = 0;
}

/**
  * @brief  	74HC595写入一个字节
  * @param		要写入的字节  
  * @retval  	无
*/
void _74HC595_WriteByte(unsigned char byte)
{
	unsigned int i = 0;
	//循环的作用是取出byte中的每一位，通过SCK升高发送出去
	for(i=0;i<8;i++)
	{
		SER = byte & (0x80>>i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief  	控制LED点阵屏发光
  * @param  	column:想控制的列，Data：对应行八位二进制的状态，1是打开，0是关闭
  * @retval  
*/
void MATRIXLED_ShowColumn(unsigned char column,Data)
{
	_74HC595_WriteByte(Data); //控制行
	P0 = ~(0x80>>column); //控制列	
	Delay1ms(1);
	P0 = 0xff;
}