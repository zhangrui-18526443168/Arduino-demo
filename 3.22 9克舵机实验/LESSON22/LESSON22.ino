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

// #include <Arduino.h>

// #define PWM_pin 9

// int pulsewidth = 0;		//高电平时间

// void setup()
// {
//   pinMode(PWM_pin,OUTPUT);
// }

// void loop()
// {
//     pulse(0);			//设置舵机指向90度
//     delay(1000);
//     pulse(90);
//     delay(1000);
//     pulse(180);
//     delay(1000);
// }

// void pulse(int angle)			//设置舵机角度为angle
// {
// 	pulsewidth=int ((angle*11)+500);	//计算高电平时间
// 	digitalWrite(PWM_pin,HIGH);				//设置高电平
// 	delayMicroseconds(pulsewidth);		//延时pulsewidth （us）
// 	digitalWrite(PWM_pin,LOW);				//设置低电平
// 	delay(20-pulsewidth/1000);				//延时20-pulsewidth/1000 （ms）
// }



// #include <Servo.h>  //引入文件
// Servo myservo;      // 创建对象
// #define potpin  A5  // 设定连接可变电阻的模拟引脚
// int val;            // 创建变量，储存从模拟端口读取的值（0到1023）
// void setup()
// {
//   myservo.attach(9);  // 9号引脚输出电机控制信号（仅能使用PWM引脚），控制舵机的引脚
// }
// void loop()
// {
//   val = analogRead(potpin);  // 读取来自可变电阻的模拟值（0到1023之间） 
//   val = map(val, 0, 1023, 0, 179);  // 利用“map”函数缩放该值，得到舵机需要的角度（0到180之间） 
//   myservo.write(val);     // 设定舵机的位置，旋转到val
//   delay(15);              // 等待电机旋转到目标角度
// }


// 舵机的来回转动
// #include <Servo.h>
// int pos = 0;
// Servo myservo;
 
// void setup()
// {
//   myservo.attach(9, 500, 2500); //修正脉冲宽度
// }
 
// void loop()
// {
//   for (pos = 0; pos <= 180; pos += 1) {
//     myservo.write(pos);
//     delay(15);					
//   }
//   for (pos = 180; pos >= 0; pos -= 1) {
//     myservo.write(pos);
//     delay(15); 					
//   }
// }

#include <Servo.h>
int led4=4;       
int led=13;         
Servo myservo;//创建舵机对象
 
void setup(){
  myservo.attach(9, 500, 2500);
  pinMode(led,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  if(Serial.available()>0){
    char c=Serial.read();
    if(c=='2'){
      digitalWrite(led,HIGH);
      digitalWrite(led4,HIGH);
      myservo.write(90);
      Serial.println("ON");
    }
   	else if(c=='4'){
      digitalWrite(led,LOW);
      digitalWrite(led4,LOW);
      myservo.write(180);
      Serial.println("OFF");
    }
  }
}
