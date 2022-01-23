#include "config.h"

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");

  timer = timerBegin(0 , 80 , true);
 
  /*將onTimer函數附加到計時器*/ 
  timerAttachInterrupt(timer, &onTimer, true);
 
  /* *設置鬧鐘每秒調用onTimer函數1 tick為1us * / 
  / *重複鬧鐘（第三個參數）*/
  timerAlarmWrite(timer, 1000000 , true);
  timerAlarmEnable(timer);
}
 
void loop() 
{
  get_status();
  check_status();
  change_status();

  delay(10000);
}

void check_status()
{
  if(device1_status == 1 && device1_counter == -1)
  {
    device1_counter = 300;
    digitalWrite(Relay1,HIGH);
  }

  if(device2_status == 1 && device2_counter == -1)
  {
    device2_counter = 300;
    digitalWrite(Relay2,HIGH);
  }

  if(device3_status == 1 && device3_counter == -1)
  {
    device3_counter = 300;
    digitalWrite(Relay3,HIGH);
  }

  if(device4_status == 1 && device4_counter == -1)
  {
    device4_counter = 300;
    digitalWrite(Relay4,HIGH);
  }
}

void change_status()
{
  if(device1_counter == 0)
  {
    post_status("1","0");
    device1_counter = -1;
    device1_status = 0;
    digitalWrite(Relay1,LOW);
  }

  if(device2_counter == 0)
  {
    post_status("2","0");
    device2_counter = -1;
    device2_status = 0;
    digitalWrite(Relay2,LOW);
  }

  if(device3_counter == 0)
  {
    post_status("3","0");
    device3_counter = -1;
    device3_status = 0;
    digitalWrite(Relay3,LOW);
  }

  if(device4_counter == 0)
  {
    post_status("4","0");
    device4_counter = -1;
    device4_status = 0;
    digitalWrite(Relay4,LOW);
  }
}
