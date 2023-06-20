#include <SoftwareSerial.h>
#include <Adafruit_AHTX0.h>
#include  <ArduinoJson.h>
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
        Serial.println(res);
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
void TCP_SENDData(void)//发布数据到服务器
{
  char sendjson[]="{\"params\":{\"CurrentTemperature\":{\"value\":%d.%d},\"RelativeHumidity\":{\"value\":%d.%d}}}";
  char sendtcp[]="AT+QISEND=0,%d,%s";
  char T_json[100];
  char T_send[100];
  char tempdata,humidata;
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  //Serial.print(humidity.relative_humidity);
  tempdata=(temp.temperature-(char)temp.temperature)*10;
  humidata=(humidity.relative_humidity-(char)humidity.relative_humidity)*10;
  sprintf(T_json,sendjson,(char)temp.temperature,tempdata,(char)humidity.relative_humidity,humidata);
  sprintf(T_send,sendtcp,strlen(T_json),T_json);
   mySerial.println(T_send);
  delay(300);              // wait for a second
  while (mySerial.available() > 0)
  {
    //  char inByte = mySerial.read();
    //  Serial.print(inByte);
    if (mySerial.find("SEND OK"))
    {
      Serial.println("SEND OK");
      break;
    }
  }
}
void TCP_RECData(void)//收取服务器下发数据
{
  String recstr="";
  String Jsontempdata="";//暂时的
  String Jsondata="";//实际的
  char index,endof;
  while (mySerial.available() > 0)
  {
    if (mySerial.find("+QIURC:"))
    {
      recstr=mySerial.readString();
     index=recstr.indexOf("{");//找到JOSN的地方
     Jsontempdata=recstr.substring(index);
     endof=Jsontempdata.length()-3;
     //Serial.println(endof);
     Jsondata=Jsontempdata.substring(0,endof);//去掉最后一个双引号.
      Serial.println(Jsondata);
      //Serial.println(recstr);
      break;
    }
  }
}
void BC260YTCP_init(void)//初始化TCP连接
{

  // prints title with ending line break
  connectNBIOT("AT", "OK");
  mySerial.println("ATE0&W");//关闭回显
  delay(300);
   mySerial.println("AT+QICLOSE=0");//关闭上一次socekt连接
  delay(300);
  connectNBIOT("AT+CPIN?", "+CPIN: READY"); //返+CPIN:READY，表明识别到卡了
  connectNBIOT("AT+CGATT?", "+CGATT: 1"); //返+CGACT: 1,就能正常工作了
  connectNBIOT("AT+QIOPEN=0,0,\"UDP\",\"47.92.146.210\",9999,1234,1","+QIOPEN: 0,0"); //建立服务器的IP和端口连接
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
  BC260YTCP_init();

}

// the loop function runs over and over again forever
void loop() {
    TCP_SENDData();
    TCP_RECData();
      delay(300);
}



