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
//定义了那三个引脚
int latchPin = 8;
int clockPin = 12;
int dataPin = 11; 

unsigned char table[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};	//LED状态显示的变量

void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //让三个引脚都是输出状态
}
void loop()
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(latchPin,LOW); //将ST_CP口上面加低电平让芯片准备好接收数据
    //数据输入引脚为dataPin，时钟引脚为clockPin，执行MSB优先发送，发送数据table[i]
    shiftOut(dataPin,clockPin,MSBFIRST,table[i]);
    digitalWrite(latchPin,HIGH); //将ST_CP这个针脚恢复到高电平
    delay(100);				//延时500ms 
  }
}
