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
#define LED 13
#define KEY 2

int KEY_NUM = 0;			//按键键值存放变量，非1说明有按键按下

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);					//定义LED为输出引脚
  pinMode(KEY,INPUT_PULLUP);		//定义KEY为带上拉输入引脚
  // Serial.flush();
}

void loop()
{
  ScanKey();						        //按键扫描程序，当按键按下时候，该子程序会修改KEY_NUM的值

  Serial.println("1.LOOP");
  Serial.print("KEY_NUM:  ");
  Serial.println(KEY_NUM);
  Serial.println("____________");

  if(KEY_NUM == 1)							//是否按键按下
  { 
    Serial.println("************");
    Serial.print("digitalRead(LED):"); 
    Serial.println(digitalRead(LED));  

    digitalWrite(LED,!digitalRead(LED));		//LED的状态翻转
    
    Serial.println("************");
    // Serial.print("digitalWrite(LED):    ");
    // Serial.println(digitalWrite(LED,!digitalRead(LED)));
    Serial.println(".               ");
  }
  //delay(1000) ;
}

//按键扫描程序
void ScanKey()						
{
  KEY_NUM = 0;							      //清空变量

  Serial.println("2.ScanKey:    ");
  Serial.print("KEY_NUM:  ");
  Serial.println(KEY_NUM);
  Serial.print("digitalRead(KEY):  ");
  Serial.println(digitalRead(KEY));
  Serial.println("____________");

  if(digitalRead(KEY) == LOW)			//有按键按下
  {
    Serial.println("2.1ScanKey_if:    ");
    Serial.print("digitalRead(KEY):  ");
    Serial.println(digitalRead(KEY));
    Serial.println("____________");

    delay(20);						        //延时去抖动
    if(digitalRead(KEY) == LOW)		//有按键按下
    {

      Serial.println("2.2ScanKey_if_if:    ");
      Serial.print("KEY_NUM:  ");
      Serial.println(KEY_NUM);

      KEY_NUM = 1;				            //变量设置为1

      Serial.print("Change KEY_NUM:  ");
      Serial.println(KEY_NUM);
      Serial.println("____________");

      while(digitalRead(KEY) == LOW){
        Serial.println("END");
      };	//等待按键松手
    }
     Serial.println("____________");
  }
}


// int a=0;
// void setup() {
//   pinMode(7,INPUT);//设置数字引脚7为输出模式
//   pinMode(3,OUTPUT);
// }

// void loop() {
//   int i=digitalRead(7);  //读取端口7的状态，并赋值给i
//   if (a==0){  //当a的值为0时，意味着开关被按下了双数次
//     if (i==HIGH){  //如果开关被按下
//       delay(500);  //为了消除抖动
//       digitalWrite(3,HIGH);
//       a++;
//     }
//   }
//   else
//   if(a==1){  //当a的值为1时，意味着开关被按下了单数次
//     if(i==HIGH){
//       delay(500);
//       digitalWrite(3,LOW);
//       a--;
//     }
//   }
// }
