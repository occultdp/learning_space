#ifndef __IIC_H__
#define __IIC_H__

void I2C_Start();
void I2C_Stop();
void I2C_SendByte(unsigned char byte);
unsigned char I2C_ReceiveByte(void);
void I2C_SendACK(unsigned char Ackbit);
unsigned char I2C_ReceiveACK();


#endif