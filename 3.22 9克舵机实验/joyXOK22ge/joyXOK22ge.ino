
//arduino捣鼓 欢迎大家评论区一起交流！如有不足请大家指正 共同进步！谢谢！

#include <Servo.h>
  
Servo servo1;
Servo servo2;
int joyX = A0;
int joyY = A1;
int seconds=50;
int servoVal;
  
void setup() 
{
  // servo1.attach(3);
  servo2.attach(5);
}
  
void loop()
{
  
  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 1023, 0, 180);
  servo1.write(servoVal);
  delay(seconds);  

  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 0, 360);
  servo2.write(servoVal);
  delay(seconds);  
}
