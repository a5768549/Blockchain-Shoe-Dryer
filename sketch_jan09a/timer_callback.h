int device1_counter = -1;
int device2_counter = -1;
int device3_counter = -1;
int device4_counter = -1;

hw_timer_t * timer = NULL ;

void IRAM_ATTR onTimer ()
{
  if(device1_counter > 0 && device1_counter < 301)device1_counter = device1_counter - 1;
  if(device2_counter > 0 && device2_counter < 301)device2_counter = device2_counter - 1;
  if(device3_counter > 0 && device3_counter < 301)device3_counter = device3_counter - 1;
  if(device4_counter > 0 && device4_counter < 301)device4_counter = device4_counter - 1;

  Serial.println("設備狀態：");
  Serial.println(device1_counter);
  Serial.println(device2_counter);
  Serial.println(device3_counter);
  Serial.println(device4_counter);
  Serial.println();
}
