
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9GkzECAe3xK5Zz7U_IVkOwtDZrjhQtdm";
char ssid[] = "Tenda_C193C0";
char pass[] = "88594002";
int LED = D8;
int pin1,pin2,pin3,pin4,tpin1;
int a,b,c,d,ta;
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
  
}

BLYNK_WRITE(V1) 
{
 pin1 = param.asInt(); // Assigning incoming value from pin V1 to a variable, will be used to turn on APPLIANCE 1 
 if(pin1==0)
 a=0;
 else if(pin1==1)
 a=1;
 Serial.write(a);
 Serial.println(a);
}
BLYNK_WRITE(V2) 
{
 pin2 = param.asInt(); // Assigning incoming value from pin V2 to a variable, will be used to turn on APPLIANCE 2
 if(pin2==0)
 b=0;
 else if(pin2==1)
 b=1;
 Serial.write(b);
 Serial.println(b);
}
BLYNK_WRITE(V3) 
{
 pin3 = param.asInt(); // Assigning incoming value from pin V3 to a variable, will be used to turn on APPLIANCE 3
 if(pin3==0)
 c=0;
 else if(pin3==1)
 c=1;
 Serial.write(c);
 Serial.println(c);
}
BLYNK_WRITE(V4) 
{
 pin4 = param.asInt(); // Assigning incoming value from pin V4 to a variable, will be used to turn on APPLIANCE 4
 if(pin4==0)
 d=0;
 else if(pin4==1)
 d=1;
 Serial.write(d);
 Serial.println(d);
}
BLYNK_WRITE(V5)
{
  tpin1=param.asInt();
  if(tpin1==0)
  ta=0;
  else if(tpin1==1)
  ta=1;
  Serial.write(ta);
  Serial.println(ta);
}
