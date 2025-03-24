#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "UART.h"


unsigned char p = 0;
void UART_Routine(void) interrupt 4 
{
	if(RI == 1)		
	{
		p = ~SBUF;
		UART_Send(SBUF);
		RI = 0;
		P2 = p;
	}		
}

void main()
{
	UART_Init();
	while(1)
	{
		Delay1ms(1000);
	}
}