#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char key=0;
unsigned int Password=0,count=0;
void main()
{
	LCD_init();
	LCD_ShowNum(2,1,Password,4);
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		key = MatrixKey();
		if(key)
		{
			LCD_ShowString(1,14,"   "); //当重新输入密码的时候清除OK和ERR
			if(key<=10)
			{
				//四位密码，count用来计数
				if(count < 4)
				{
					key%=10;//将10转换为0
					Password*=10;
					Password+=key;
					count++;
				}
			}
			//确认按钮
			if(key == 11)
			{
				if(Password == 5555 && count == 4)
				{
					LCD_ShowString(1,14,"OK ");
					Password=0,count=0;
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0,count=0;
				}
			}
			if(key == 12) //back
			{
				if(count >0)
				{
					Password /= 10;
					count --;
				}
			}
			LCD_ShowNum(2,1,Password,4);
			key=0;
		}
	}
}