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

int y = 0;
int x = 0;

void setup()  //初始化部分
{
  pinMode(3, OUTPUT);  // 模拟读写时应该接标有PWM的引脚
}

void loop()  //主循环
{
  y = analogRead(0);  // 模拟读取，参数为模拟引脚
  x = map(y, 0, 1023, 1, 9);
  for (int val = 0; val < 255; val++) {
    analogWrite(3, val);
    delay(x);
  }
  for (int val = 255; val > 0; val--) {
    analogWrite(3, val);
    delay(x);
  }
}



    // digitalWrite(2,LOW);	//led引脚输出低电平，点亮led
    // delay(1000);						//延时1000ms
    // digitalWrite(2,HIGH);	//led引脚输出高电平，熄灭led
    // delay(1000);						//延时1s
