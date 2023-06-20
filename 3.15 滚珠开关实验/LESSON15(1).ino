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
#define KEY 2
#define Buzzer 3

int count = 0;			//计数变量
int flag = 0;				//中断执行标志位

void setup()
{
  pinMode(KEY,INPUT_PULLUP);		//按键设置为输入带上拉
  pinMode(Buzzer,OUTPUT);
  attachInterrupt(0,BuzzerDi,FALLING);		//设置ARDUINO UNO中断0（数字IO 2），下降沿触发中断函数BuzzerDi， 
  //attachInterrupt(1,BuzzerDi,FALLING);		//设置ARDUINO Leonardo中断1（数字IO 2），这点和UNO有所不同，请知悉！
  Serial.begin(9600);
}

void loop()
{
  if(flag == 1)						//如果flag被置一，说明有中断产生，执行该段程序
  {
    flag = 0;							//flag清零
    digitalWrite(Buzzer,HIGH);		//蜂鸣器响
    delay(1000);    			//延时1000ms
  }
  else
  {
    digitalWrite(Buzzer,LOW);//没有中断时候，蜂鸣器不响
  }
  Serial.println(count);		//串口显示中断次数
}

void BuzzerDi()			//中断函数BuzzerDi
{
  flag = 1;					//置位标志位
  count++;					//进中断次数加一
}

