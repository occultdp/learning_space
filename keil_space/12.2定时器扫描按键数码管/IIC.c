#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

/**
  * @brief  	I2C开始
  * @param  	无
  * @retval  	无
*/
void I2C_Start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}
/**
  * @brief  	I2C停止
  * @param  	无
  * @retval  	无
*/
void I2C_Stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}
/**
  * @brief  	I2C发送一个字节
  * @param  	byte：要发送的字节
  * @retval  	无
*/
void I2C_SendByte(unsigned char byte)
{
	unsigned int i=0;
	for(i = 0;i < 8;i++)
	{
		I2C_SDA = byte&(0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

/**
  * @brief  	I2C接收一个字节
  * @param  	无
  * @retval  	接收到的字节
*/
unsigned char I2C_ReceiveByte(void)
{
	unsigned int i=0;
	unsigned char byte = 0x00;
	I2C_SDA = 1;
	for(i = 0;i < 8;i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA)
		{
			byte |= (0x80 >> i);//接收
		}
		I2C_SCL = 0;
	}
	return byte;
}
/**
  * @brief  	I2C发送应答
  * @param  	Ackbit:发送的应答值(0或1)
  * @retval  	无
*/
void I2C_SendACK(unsigned char Ackbit)
{
	I2C_SDA = Ackbit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}
/**
  * @brief  	I2C接收应答
  * @param  	无
  * @retval  	接收到的应答值 
*/
unsigned char I2C_ReceiveACK()
{
	unsigned char AckBit = 0x00;
	I2C_SDA = 1;
	I2C_SCL = 1;
	AckBit = I2C_SDA;
	I2C_SCL = 0;
	return AckBit;
}
