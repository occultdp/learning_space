#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"

unsigned char LEDNumber = 0;
unsigned char KeyNum, LEDMode = 1; // 初始化模式为1

void main() {
    Timer0Init();
    while (1)
	{
        KeyNum = Key();
        if (KeyNum == 1 || KeyNum == 2) 
		{
            LEDMode = KeyNum;
        }
    }
}

void Timer0_routine() interrupt 1 {
    static unsigned int T0Count;
    TL0 = 0x18;     // 定时初值（1ms中断一次）
    TH0 = 0xFC;
    T0Count++;
    if (T0Count >= 200) 
	{  // 每200ms更新一次LED
        T0Count = 0;
        if (LEDMode == 2) 
		{
            LEDNumber = (LEDNumber + 1) % 8; // 正向流水
        } else if (LEDMode == 1) 
		{
            LEDNumber = (LEDNumber - 1 + 8) % 8; // 反向流水
        }
        P2 = ~(0x01 << LEDNumber); // 单灯流水效果
    }
}