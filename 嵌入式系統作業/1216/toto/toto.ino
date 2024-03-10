#include <LWiFi.h>                                     
                                             
char ssid[] = "iPhone";                              
char pass[] = "88888888";                                                                 
                              
                                     
int status = WL_IDLE_STATUS;                           
char server[] = "172.20.10.2";                         
WiFiClient client;                                     
void setup() {                      
    Serial.begin(115200);                                 
    pinMode(14, INPUT);                                    
    while (!Serial) {                                     
        ;
    }

}

void loop() {                                                      
    while (status != WL_CONNECTED) {                      
        Serial.print("Attempting to connect to SSID: ");  
        Serial.println(ssid);                             
        status = WiFi.begin(ssid, pass);                  
    } 
    Serial.println("Connected to wifi");                  
    if (client.connect(server, 80)) {                     
        Serial.println("connected to server (GET)");      
    }
    delay(1000);                                          
    String sensorValue;                             
    sensorValue = analogRead(14);                                                    
    String str="聲音數據:"+sensorValue;   
    Serial.println(str);                                  
    String GET="GET /insert.php";                         
    String getStr = GET + "?c=" + String(sensorValue)+
                  "&f=" + String(sensorValue) +
                  "&h=" + String(sensorValue) +
                  " HTTP/1.1";
                           
    client.println(getStr);                               
    client.println("Host: 172.20.10.2");                  
    client.println("Accept: */*");                        
    client.println("Connection: close");                  
    client.println();                                     
    delay(1000);                                          
        
    while (client.available()) {                          
        char c = client.read();                           
        Serial.write(c);                                  
        }
    }
