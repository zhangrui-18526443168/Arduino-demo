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

//uno code
// String inputString = "";         // a string to hold incoming data
// boolean stringComplete = false;  // whether the string is complete
#include "SoftwareSerial.h"
SoftwareSerial BT(8, 9); 
char val;

void setup()
{
  Serial.begin(38400);
  Serial.println("连接正常");
  BT.begin(38400);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    BT.print(val);
  }


  if (BT.available())
  {
    val = BT.read();
    Serial.print(val);
  }
}

// void setup() 
// {
//   Serial.begin(9600);
//   pinMode(13,OUTPUT);
// }

// void loop() 
// { 
//   while(Serial.available())
//   {
//     char c=Serial.read();
//       if(c=='1')
//       {
//         Serial.println("BT is ready!");
//         // 返回到手机调试程序上
//         Serial.write("Serial--13--high");
//         digitalWrite(13, HIGH);
//       }
//      if(c=='2')
//      {
//        Serial.write("Serial--13--low");
//        digitalWrite(13, LOW);
//      }
//   }
// }

// void serialEvent() {
  // while (Serial.available()) {
  //   // 读取新字节
  //   char inChar = (char)Serial.read();
  //   // 将它添加到inputString中
  //   inputString += inChar;
  //   // 如果输入的字符是换行符，请设置一个标志
  //   // so the main loop can do something about it:
  //   if (inChar == '\n') 
  //   {
  //     stringComplete = true;
  //   }
    
  //   if (stringComplete) 
  //   {
  //     Serial.println(inputString);
  //     // 清除字符串
  //     inputString = "";
  //     stringComplete = false;
  //   }
  // }
// }

//leonardo code

// String inputString = "";         // a string to hold incoming data
// boolean stringComplete = false;  // whether the string is complete

// void setup() 
// {
//   Serial1.begin(9600);
//   pinMode(13,OUTPUT);
// }

// void loop() 
// { 
//   digitalWrite(13,HIGH);
//   delay(1000);
//   digitalWrite(13,LOW);
//   delay(1000);
// }

// void serialEvent1() {
//   while (Serial1.available()) {
//     // get the new byte:
//     char inChar = (char)Serial1.read();
//     // add it to the inputString:
//     inputString += inChar;
//     // if the incoming character is a newline, set a flag
//     // so the main loop can do something about it:
//     if (inChar == '\n') 
//     {
//       stringComplete = true;
//     }
    
//     if (stringComplete) 
//     {
//       Serial1.println(inputString);
//       // clear the string:
//       inputString = "";
//       stringComplete = false;
//     }
//   }
// }

