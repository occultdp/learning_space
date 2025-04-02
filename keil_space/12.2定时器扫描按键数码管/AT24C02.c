#include "IIC.h"
#include <REGX52.H>
//#include "LCD1602.h"
#define AT24C02_ADDRESS 0xA0

/**
  * @brief  	AT24C02写入一个字节
  * @param  	wordAddress:存放数据的地址	Data:数据的值
  * @retval  	无	
*/
void AT24C02_WriteByte(unsigned char wordAddress , Data)
{
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveACK();
	I2C_SendByte(wordAddress);
	I2C_ReceiveACK();
	I2C_SendByte(Data);
	I2C_ReceiveACK();
	I2C_Stop();
}
/**
  * @brief  	AT24C02读取一个字节
  * @param  	wordAddress:要读取的地址
  * @retval  	对应地址的值
*/
unsigned char AT24C02_ReadByte(unsigned char wordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveACK();
	I2C_SendByte(wordAddress);
	I2C_ReceiveACK();
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS|0x01);
	I2C_ReceiveACK();
	Data = I2C_ReceiveByte();
	I2C_SendACK(1);
	I2C_Stop();
	return Data;
}