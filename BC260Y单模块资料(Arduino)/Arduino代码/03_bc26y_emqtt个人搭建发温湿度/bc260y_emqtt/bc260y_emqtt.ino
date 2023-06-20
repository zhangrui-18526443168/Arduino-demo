#include <SoftwareSerial.h>
#include <Adafruit_AHTX0.h>
//实例化软串口
SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_AHTX0 aht;
//判断返回值是否正确
void connectNBIOT (String cmd, char *res)
{
  while (1)
  {
    mySerial.println(cmd);
    delay(300);
    while (mySerial.available() > 0)
    {
      if (mySerial.find(res))
      {
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);              // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        Serial.print(res);
        return;
      }
      else
      {
        Serial.print(cmd);
        Serial.println("  Return ERROR!");
      }
    }
    delay(200);
  }
}
void MQTT_PubData(void)//发布数据到平台
{
  char sendjson[]="{\"params\":{\"CurrentTemperature\":{\"value\":%d.%d},\"RelativeHumidity\":{\"value\":%d.%d}}}";
  char T_json[200];
  char tempdata,humidata;
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  //Serial.print(humidity.relative_humidity);
  tempdata=(temp.temperature-(char)temp.temperature)*10;
  humidata=(humidity.relative_humidity-(char)humidity.relative_humidity)*10;
  sprintf(T_json,sendjson,(char)temp.temperature,tempdata,(char)humidity.relative_humidity,humidata);
  connectNBIOT("AT+QMTPUB=0,0,0,0,\"mzh_pub\"", ">"); //send message
  mySerial.println(T_json);
  mySerial.write(0x1A);
  delay(300);              // wait for a second
  while (mySerial.available() > 0)
  {
    //  char inByte = mySerial.read();
    //  Serial.print(inByte);
    if (mySerial.find("+QMTPUB: 0,0,0"))
    {
    
      Serial.print("+QMTPUB: 0,0,0");
      break;
    }
  }
}
void MQTT_SubData(void)//订阅数据
{
  String subtring = "";
   if (mySerial.available() > 0)//有数据了
  {
    //  char inByte = mySerial.read();
    //  Serial.print(inByte);
    if (mySerial.find("+QMTRECV:"))//订阅到数据了
    {
      subtring = mySerial.readString();//读串口缓存数据
      Serial.print(subtring);
    }
  }
  }
void BC260YMQTT_init(void)//初始化MQTT连接
{
  // prints title with ending line break
  connectNBIOT("AT", "OK");
  mySerial.println("ATE0&W");//关闭回显
  delay(300);
  connectNBIOT("AT+CPIN?", "+CPIN: READY"); //返+CPIN:READY，表明识别到卡了
  connectNBIOT("AT+CGATT?", "+CGATT: 1"); //返+CGACT: 1,就能正常工作了
  mySerial.println("AT+QMTCLOSE=0");//关闭上一次socekt连接
  delay(300);
  connectNBIOT("AT+QMTOPEN=0,\"47.92.146.210\",1883", "+QMTOPEN: 0,0"); //建立服务器的IP和端口连接
  delay(300);
  connectNBIOT("AT+QMTCONN=0,\"clientExample\"", "+QMTCONN: 0,0,0"); //建立服务器的IP和端口连接
  delay(300);
  //AT+QMTSUB=0,1,"oyjtmPl5a5j/S2fXbFBKh4NSwwyIjSC4/user/update",0
  connectNBIOT("AT+QMTSUB=0,1,\"mzh_sub\",0", "+QMTSUB: 0,1,0,0"); //订阅主题进行数据发送
  delay(300);
}
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600); //
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
    if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 or AHT20 found");
 BC260YMQTT_init();

}

// the loop function runs over and over again forever
void loop() {
 MQTT_PubData();//发布数据
 MQTT_SubData();//订阅数据
}



