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
