/******************************************************************************
----------------本例程仅供学习使用，未经作者允许，不得用于其他用途。-----------
------------------------版权所有，仿冒必究！-----------------------------------
----------------1.开发环境:Arduino IDE-----------------------------------------
----------------2.测试使用开发板型号：Arduino Leonardo or Arduino UNO R3-------
----------------3.单片机使用晶振：16M------------------------------------------
----------------4.淘宝网址：Ilovemcu.taobao.com--------------------------------
----------------------------epic-mcu.taobao.com--------------------------------
----------------5.作者：神秘藏宝室---------------------------------------------
******************************************************************************/
#include "InfraredRemote.h"  // 红外遥控库

void setup() 
{ 
	Serial.begin(9600); 
	pinMode(IR_IN,INPUT_PULLUP);  //设置红外接收引脚为输入
	Serial.flush();	              //清除串口缓冲器内容函数。 
	timer1_init();                //定时器初始化
} 
void loop() 
{ 	
	remote_decode(); //译码
	Deal_Print();	
} 

void Deal_Print()
{
	if( adrL_code == 0x45 )
	{
		Serial.println("ON/OFF");			
	}
	else if( adrL_code == 0x46)
	{
		Serial.println("CH");			
	}
	else if( adrL_code == 0x47 )
	{
		Serial.println("MENU");			
	}
	else if( adrL_code == 0x44 )
	{
		Serial.println("TEST");			
	}
	else if( adrL_code == 0x40 )
	{
		Serial.println("+");			
	}
	else if( adrL_code == 0x43 )
	{
		Serial.println("Return");			
	}
	else if( adrL_code == 0x07 )
	{
		Serial.println("Left");			
	}
	else if( adrL_code == 0x15)
	{
		Serial.println("Play");			
	}
	else if( adrL_code == 0x09 )
	{
		Serial.println("Right");			
	}
	else if( adrL_code == 0x16)
	{
		Serial.println("0");			
	}
	else if( adrL_code == 0x19)
	{
		Serial.println("-");			
	}
	else if( adrL_code == 0x0d)
	{
		Serial.println("C");			
	}
	else if( adrL_code == 0x0c)
	{
		Serial.println("1");			
	}
	else if( adrL_code == 0x18 )
	{
		Serial.println("2");			
	}
	else if( adrL_code == 0x5e )
	{
		Serial.println("3");			
	}
	else if(adrL_code == 0x08 )
	{
		Serial.println("4");			
	}
	else if( adrL_code == 0x1c )
	{
		Serial.println("5");			
	}
	else if( adrL_code == 0x5a )
	{
		Serial.println("6");			
	}
	else if( adrL_code == 0x42)
	{
		Serial.println("7");			
	}
	else if( adrL_code == 0x52)
	{
		Serial.println("8");			
	}
	else if( adrL_code == 0x4a)
	{
		Serial.println("9");			
	}

	adrL_code = 0x00;
        adrH_code = 0x00;
        ir_code = 0x00;
}

