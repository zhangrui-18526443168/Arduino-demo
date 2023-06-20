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
// #define KEY 2
// #define Buzzer 3

// int KEY_NUM = 0;			//按键键值变量

// void setup()
// {
//   pinMode(KEY,INPUT_PULLUP);//按键为IO带上拉输入
//   pinMode(Buzzer,OUTPUT);		//蜂鸣器为IO输出
//   digitalWrite(Buzzer,LOW);	//蜂鸣器初始为不鸣叫
// }

// void loop()
// {
//   ScanKey();							//按键扫描
// }

// void ScanKey()
// {
//   if(digitalRead(KEY) == LOW)
//   {
//     delay(20);							//延时去抖动
//     if(digitalRead(KEY) == LOW)
//     {
//       BuzzerDi();					//滴一声
//       while(digitalRead(KEY) == LOW);	//松手检测
//     }
//   }
// }

// void BuzzerDi()
// {
//   digitalWrite(Buzzer,HIGH);			//蜂鸣器响
//   delay(20);											//延时20ms
//   digitalWrite(Buzzer,LOW);				//蜂鸣器关闭
// }

#define NOTE_C4 262 //C4 1
#define NOTE_D4 294 //D4 2
#define NOTE_E4 330 //E4 3
#define NOTE_F4 349 //F4 4
#define NOTE_G4 392 //G4 5
#define NOTE_A4 440 //A4 6
#define NOTE_G3 196 //G3 ·5


//音符
int tune[]={
  // 1 2 3 1
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_C4,
  // 1 2 3 1
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_C4,
  // 3 4 5
  NOTE_E4,NOTE_F4,NOTE_G4,
  // 3 4 5
  NOTE_E4,NOTE_F4,NOTE_G4,
  // 5 6 5 4 3 1
  NOTE_G4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,
  // 5 6 5 4 3 1
  NOTE_G4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,
  // 2 .5 1 0
  NOTE_D4,NOTE_G3,NOTE_C4,0,
  // 2 .5 1 0
  NOTE_D4,NOTE_G3,NOTE_C4,0,
};

//节拍
int durt[]={
  125,125,125,125,
  125,125,125,125,
  125,125,250,
  125,125,250,
  125,125,125,125,250,250,
  125,125,125,125,250,250,
  250,250,250,250,
  250,250,250,250,
};

int length;
int tonepin=6;  
int ledp=2;

void setup(){
  pinMode(tonepin,OUTPUT);
  pinMode(ledp,OUTPUT);
  Serial.begin(9600);
  length = sizeof(tune) / sizeof(tune[0]);
}

void loop(){

  Serial.println(sizeof(tune));
  Serial.println(sizeof(tune[0]));
  Serial.println(length);

  for(int x = 0; x < length; x++)
  {
    tone(tonepin,tune[x]);
    digitalWrite(ledp, HIGH);
    delay(durt[x]);
    digitalWrite(ledp, LOW);
    delay(durt[x]);   
    noTone(tonepin);
  }
  delay(2000);
}



// void loop(){

// play();//播放音乐的命令

// delay(300);

// }


// //播放命令

// void play()

// {

// for(int thisNote = 0;thisNote<29;thisNote++){

// //计算旋律持续时间

// //1秒（1000ms）除以音符类型

// //比如：四分音符：1000/noteDurations[thisNote],

// //八分音符：1000/noteDurations[thisNote].

// int noteDuration = 1000/noteDurations[thisNote];

// tone(8,melody[thisNote], noteDuration);//播放音乐

// //为了区别不同旋律，设置一个最小的间隔时间

// //一般设置为旋律持续时间的130%比较合适

// int pauseBetweenNotes = noteDuration * 1.30;

// delay(pauseBetweenNotes);

// //停止当前旋律播放

// noTone(8);

// }
// }
