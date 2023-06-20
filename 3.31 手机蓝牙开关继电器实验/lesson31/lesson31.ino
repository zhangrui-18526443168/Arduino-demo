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
/*
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int Relay = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(Relay,OUTPUT);
}

void loop() 
{ 
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if(inChar == 'A' || inChar == 'a' )
    {
      digitalWrite(Relay,HIGH);
    }
    else  if(inChar == 'B' || inChar == 'b')
    {
      digitalWrite(Relay,LOW);
    }
  }
}
*/

//leonardo code

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int Relay = 2;

void setup() 
{
  Serial1.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(Relay,OUTPUT);
}

void loop() 
{ 
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

void serialEvent1() {
  while (Serial1.available()) {
    // get the new byte:
    char inChar = (char)Serial1.read();
    // add it to the inputString:
    if(inChar == 'A' || inChar == 'a' )
    {
      digitalWrite(Relay,HIGH);
    }
    else  if(inChar == 'B' || inChar == 'b')
    {
      digitalWrite(Relay,LOW);
    }
  }
}

