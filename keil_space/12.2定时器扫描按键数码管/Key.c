#include <REGX52.H>
#include "Delay.H"
unsigned char Key_KeyNumber;

unsigned char Key(void)
{
	unsigned char temp = 0;
	temp = Key_KeyNumber;
	Key_KeyNumber = 0;
	return temp;
}

unsigned char Key_GetState()
{
	unsigned char KeyNumber = 0;
	if(P3_1 == 0)
	{
		KeyNumber=1;
	}
	if(P3_0 == 0)
	{
		KeyNumber=2;
	}
	if(P3_2 == 0)
	{
		KeyNumber=3;
	}
	if(P3_3 == 0)
	{
		KeyNumber=4;
	}
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char nowState,lastState;
	lastState = nowState;
	nowState = Key_GetState();
	if(lastState == 1 && nowState == 0)
	{
		Key_KeyNumber = 1;
	}
	if(lastState == 2 && nowState == 0)
	{
		Key_KeyNumber = 2;
	}
	if(lastState == 3 && nowState == 0)
	{
		Key_KeyNumber = 3;
	}
	if(lastState == 4 && nowState == 0)
	{
		Key_KeyNumber = 4;
	}
}