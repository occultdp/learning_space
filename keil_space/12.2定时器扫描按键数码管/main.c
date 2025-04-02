#include <REGX52.H>
#include "Key.h"
#include "Timer0.h"
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"

unsigned char keyNumber = 0;
unsigned char min,sec,miniSec;
unsigned char flag = 0;

void Sec_Loop()
{
	if(flag)
	{
		miniSec++;
		if(miniSec == 100)
		{
			miniSec = 0;
			sec++;
			if(sec == 60)
			{
				sec = 0;
				min++;
				if(min == 60)
				{
					min = 0;
				}
			}
		}
	}
	
}

void main()
{
	Timer0_Init();
	while(1)
	{
		keyNumber = Key();
		if(keyNumber == 1)
		{
			flag = !flag;
		}
		if(keyNumber == 2)
		{
			min = 0;
			sec = 0;
			miniSec = 0;
		}
		if(keyNumber == 3)
		{
			AT24C02_WriteByte(1,min);
			Delay1ms(5);
			AT24C02_WriteByte(2,sec);
			Delay1ms(5);
			AT24C02_WriteByte(3,miniSec);
		}
		if(keyNumber == 4)
		{
			min = AT24C02_ReadByte(1);
			sec = AT24C02_ReadByte(2);
			miniSec = AT24C02_ReadByte(3);
		}
		
		Nixie_SetBuf(1,min / 10);
		Nixie_SetBuf(2,min % 10);
		      
		Nixie_SetBuf(3,11);
		      
		Nixie_SetBuf(4,sec / 10);
		Nixie_SetBuf(5,sec % 10);
		
		Nixie_SetBuf(6,11);
		
		Nixie_SetBuf(7,miniSec / 10);
		Nixie_SetBuf(8,miniSec % 10);
		
	}
}

void Timer0_routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	if(T0Count1 >= 20)
	{
		T0Count1 = 0;
		Key_Loop();
	}	
	T0Count2++;
	if(T0Count2 >= 2)
	{
		T0Count2 = 0;
		Nixie_Loop();
	}	
	T0Count3++;
	if(T0Count3 >= 10)
	{
		T0Count3 = 0;
		Sec_Loop();
	}
}