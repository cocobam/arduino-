#include "DHT.h"
#include <Ultrasonic.h>
#include <Servo.h>


Ultrasonic ultrasonic_2_3(2, 3);

DHT dht2(4, DHT11);
int speaker_pin=6;//p5插蜂鳴器sig
String Str01 = "";

Servo myservo; 


void setup()
{
  Serial.begin(115200);
  dht2.begin();
  myservo.attach(5);
}
void loop()
{
  if(Serial.available())
 {
  Str01="";
  delay(1);
  while(Serial.available())
  {
    Str01+=(char)Serial.read();
    
    }
  Serial.println(Str01);
  }

  if(Str01[0] == 'c')
{
  float Ms=ultrasonic_2_3.timing();
  long cmMs=ultrasonic_2_3.convert(Ms, Ultrasonic::CM);  
  String hum, temp, temf ,cmm;
  hum = dht2.readHumidity();
  temp = dht2.readTemperature();
  temf = dht2.readTemperature(true);
  cmm = String(cmMs);
  String str="相對濕度 : "+hum+","+"攝氏溫度 : "+temp+","+"華氏溫度 : " +temf+","+"感測距離 : "+cmm;
  Serial.println(str);
  delay(3000);
}

if(Str01[0] == 'a')
{
  Serial.print("相對溼度 : ");
  Serial.println(dht2.readHumidity());
  Serial.print("攝氏溫度 : ");
  Serial.println(dht2.readTemperature());
  delay(50);

  int H = dht2.readTemperature();
  
  if(H  <  27){
    for (int pos=0; pos<=180;pos++){
    myservo.write(180);
    delay(1);
    }
    for (int pos=180; pos>=0;pos--){
    myservo.write(0);
    delay(1);
    }
  }else if(H >= 27 && H <= 28){
    for (int pos=0; pos<=180;pos++){
    myservo.write(180);
    delay(5);
    }
    for (int pos=180; pos>=0;pos--){
    myservo.write(0);
    delay(5);
    }
  }else if(H > 28){
    for (int pos=0; pos<=180;pos++){
    myservo.write(180);
    delay(10);
    }
    for (int pos=180; pos>=0;pos--){
    myservo.write(0);
    delay(10);
    }
  }
  }
  if(Str01[0] == 'b')
{
  float Ms=ultrasonic_2_3.timing();
  long cmMs=ultrasonic_2_3.convert(Ms, Ultrasonic::CM);  
  Serial.print("感測距離(單位cm):");
  Serial.println(String(cmMs));
  if(cmMs>50)
    speaker(0);
  else if(cmMs>10)
  speaker(3);
  else if(cmMs>5)
  speaker(1);
  else
  speaker(0); 
  }
  
  

}

int speaker(int state){
  if(state >= 1 && state<4){
  tone(speaker_pin,1000);
  delay(50);
  noTone(speaker_pin);
  delay(200*state);
  }else{
   noTone(speaker_pin);
   delay(500); 
  }
}
