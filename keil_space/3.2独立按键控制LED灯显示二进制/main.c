#include <REGX52.H>
void Delay1ms(unsigned int nms)		//@12.000MHz
{
	unsigned char i, j;
	while(nms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		nms--;
	}
}

void main()
{
	unsigned char LEDNumber=0xee;
	P2 = 0xFF; //1111 1111È«²¿µÆ¹Ø±Õ
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay1ms(20);
			while(P3_1 == 0);
			Delay1ms(20);
			LEDNumber++;
			P2 = ~LEDNumber;
		}
	}
}