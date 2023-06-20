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
#include "RC522.h"
#include <SPI.h>

#define Relay 2

unsigned char serNum[5];

void setup() 
{ 
    Serial.begin(9600); 
    Serial.print("Ilovemcu.taobao.com");
    pinMode(Relay,OUTPUT);
    SPI.begin();   
    pinMode(chipSelectPin, OUTPUT);    // 将10引脚设置为输出，连接到RFID的ENABLE
    digitalWrite(chipSelectPin, LOW);  // 激活RFID
    pinMode(NRSTPD, OUTPUT);           // 设置复位
    
    MFRC522_Init();						//初始化RFID
}


void loop()
{
    unsigned char status;
    unsigned char str[MAX_LEN];
    
    //搜索卡片，读取卡片类型，返回MI_OK
    status = MFRC522_Request(PICC_REQIDL, str); 
  if (status == MI_OK)			//读取到ID卡时候
  {   
		// 防止冲突，读取卡号，返回MI_OK
		status = MFRC522_Anticoll(str);
    
	  if (status == MI_OK)
		{
			memcpy(serNum, str, 5);
			Serial.print("ID:");
		  ShowCardID(serNum);
    
			// 检查相关ID
			unsigned char* id = serNum;
			// if( id[0]==0xed && id[1]==0x34 && id[2]==0xfa && id[3]==0x95 ) 
      if( id[0]==0x81 && id[1]==0x18 && id[2]==0xE9 && id[3]==0x1C ) 
			{
		    digitalWrite(Relay,HIGH);		//打开继电器
        Serial.println("The Host 1!");
      } 
			// else if(id[0]==0x4C && id[1]==0xB3 && id[2]==0x74 && id[3]==0x19) 
      else if(id[0]==0x60 && id[1]==0x86 && id[2]==0x70 && id[3]==0x53) 
		  {
				digitalWrite(Relay,LOW);		//继电器
        Serial.println("The Host 2!");
			}
      else
      {
        Serial.println("Stranger!");
      }
		}	
  }

    //命令卡进入睡眠模式
    MFRC522_Halt(); 
    delay(100);
}
