#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_WriteByte(unsigned char wordAddress , Data);
unsigned char AT24C02_ReadByte(unsigned char wordAddress);

#endif