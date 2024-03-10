String Str01 = "";

void setup()
{
  Serial.begin(115200);
  pinMode(14, INPUT);
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

if(Str01[0] == 'a')
{
  String sensorValue;
  sensorValue = analogRead(14);
  String str="聲音數據 : "+sensorValue;
  Serial.println(str);
  delay(1000);
}
}
