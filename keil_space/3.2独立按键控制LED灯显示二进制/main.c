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
	P2 = 0x07; //1111 1111全部灯关闭
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay1ms(20);
			while(P3_1 == 0);
			Delay1ms(20);
			P2--;
			if(P2 == -1) //当P2=0全部LED灯亮，然后重置
			{
					P2 = 0xFF;			
			}
		}
	}

}