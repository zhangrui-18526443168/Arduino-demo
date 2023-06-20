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
#define ADpin A5
#define LED 13

int ADBuffer = 0;

void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);				//波特率9600
}

void loop()
{
  ADBuffer = analogRead(ADpin);		//读取AD值
  Serial.print("AD = ");
  Serial.println(ADBuffer);
  if(ADBuffer > 800)					//ADBuffer值大于设定值，相当于光照强度小于设定值
  {
    digitalWrite(LED,HIGH);		//点亮LED
  }
  else
  {
    digitalWrite(LED,LOW);		//关闭LED
  }
  delay(500);					//延时500ms
}
