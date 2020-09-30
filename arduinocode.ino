 
#include <RTClib.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

RTC_DS3231 rtc;
int Contrast=10;
char t[13];
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int t1=0,t2=0,t3=0,t4=0;
int a,h1,m1,offh1,offm1,h2,m2,offh2,offm2,h3,m3,offh3,offm3,h4,m4,offh4,offm4;
int pin1=8,pin2=9,pin3=10,pin4=13,s1=0,s2=0,s3=0,s4=0;
char l1[16],l2[16];
int app;
int ac[4]={0,0,0,0},tn[4]={0,0,0,0},ovr[4]={0,0,0,0};

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  rtc.begin();
  irrecv.enableIRIn();
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
}

void loop()
{
  
 
  lcd.clear();
  while(Serial.available())
  {
    app=Serial.read();
    if(app==0)
    {
      s1=0;
      if(tn[0]==1)
          {ovr[0]=1;}
    }
    else if(app==1)
    {
      s1=1;
      if(tn[0]==1)
          {ovr[0]=1;}
    }
  }





  
  lcd.clear();
  lcd.setCursor(0, 0);
  DateTime now = rtc.now();
  sprintf(t, "%02d:%02d %02d/%02d/%d",  now.hour(), now.minute(), now.day(), now.month(), (now.year()));  
  lcd.print(t);
  if(s1==1)
  {
    lcd.setCursor(1,1);
    lcd.print("1");
  }
  if(s2==1)
  {
    lcd.setCursor(5,1);
    lcd.print("2");
  }
  if(s3==1)
  {
    lcd.setCursor(9,1);
    lcd.print("3");
  }
  if(s4==1)
  {
    lcd.setCursor(13,1);
    lcd.print("4");
  }
  if(ac[0]==1)
  {
    lcd.setCursor(0,1);
    lcd.print("#");
  }
  if(ac[1]==1)
  {
    lcd.setCursor(4,1);
    lcd.print("#");
  }
  if(ac[2]==1)
  {
    lcd.setCursor(8,1);
    lcd.print("#");
  }
  if(ac[3]==1)
  {
    lcd.setCursor(12,1);
    lcd.print("#");
  }
  delay(2000);
  if (irrecv.decode(&results))
  {
        switch(results.value)
        {
          // device 1
          case 0xFFA25D:
          s1=!s1;
          if(tn[0]==1)
          ovr[0]=1;
          Serial.println("hi i m working");
          break;

          // device 2
          case 0xFF629D:
          s2=!s2;
          if(tn[1]==1)
          ovr[1]=1;
          break;

          // device 3
          case 0xFFE21D:
          s3=!s3;
          if(tn[2]==1)
          ovr[2]=1;
          break;

          // device 4
          case 0xFF22DD:
          s4=!s4;
          if(tn[3]==1)
          ovr[3]=1;
          break;
          
          // Tdevice 1
          case 0xFF02FD:
          ac[0]=!ac[0];
          break;

          // Tdevice 2
          case 0xFFC23D:
          ac[1]=!ac[1];
          break;

          // Tdevice 3
          case 0xFFE01F:
          ac[2]=!ac[2];
          break;

          // Tdevice 4
          case 0xFFA857:
          ac[3]=!ac[3];
          break;

          //view time * 
          case 0xFF6897:
          //Serial.println("view tim1e");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Press 1-4");
          while(1){
           irrecv.resume();
            delay(1000);
            if (irrecv.decode(&results)){
              //Serial.println(irrecv.decode(&results));
                // device 1
                if(results.value == 0xFFA25D){
                  lcd.clear();
                //Serial.println("aagya");
                sprintf(l1, "ON1  %02d:%02d", h1, m1);        //press 1
                lcd.setCursor(0,0);
                lcd.print(l1);
                sprintf(l2, "OFF1 %02d:%02d", offh1, offm1);
                lcd.setCursor(0,1);
                lcd.print(l2);
                if(ac[0]==0)
                {
                  lcd.setCursor(13,0);
                  lcd.print("OFF");
                }
                else if(ac[0]==1)
                {
                  lcd.setCursor(13,0);
                  lcd.print("ON");
                }
                }
      
                // device 2
                else if(results.value == 0xFF629D){
                  lcd.clear();
                sprintf(l1,"ON2  %02d:%02d",h2,m2);        //press 2
                lcd.setCursor(0,0);
                lcd.print(l1);
                sprintf(l2,"OFF2 %02d:%02d",offh2,offm2);
                lcd.setCursor(0,1);
                lcd.print(l2);
                if(ac[1]==0)
                {
                  lcd.setCursor(13,0);
                  lcd.print("OFF");
                }
                else if(ac[1]==1)
                {
                  lcd.setCursor(13,0);
                  lcd.print("ON");
                }
                }
      
                // device 3
                else if(results.value == 0xFFE21D){
                  lcd.clear();
                sprintf(l1,"ON3  %02d:%02d",h3,m3);        //press 3
                lcd.setCursor(0,0);
                lcd.print(l1);
                sprintf(l2,"OFF3 %02d:%02d",offh3,offm3);
                lcd.setCursor(0,1);
                lcd.print(l2);
                if(ac[2]==0)
                {
                  lcd.setCursor(13,0);
                  lcd.print("OFF");
                }
                else if(ac[2]==1)
                {
                  lcd.setCursor(13,0);
                  lcd.print("ON");
                }
                }
      
                // device 4
                else if(results.value == 0xFF22DD){
                  lcd.clear();
                sprintf(l1,"ON4  %02d:%02d",h4,m4);        //press 4
                lcd.setCursor(0,0);
                lcd.print(l1);
                sprintf(l2,"OFF4 %02d:%02d",offh4,offm4);
                lcd.setCursor(0,1);
                lcd.print(l2);
                if(ac[3]==0)
                {
                  lcd.setCursor(13,0);
                  lcd.print("OFF");
                }
                else if(ac[3]==1)
                {
                  lcd.setCursor(13,0);
                  lcd.print("ON");
                }
                }
                
                // okay to exit view
                else if(results.value == 0xFF38C7){
                  //Serial.println("aaya last me");
                  lcd.clear();
                irrecv.resume();                               //press ok to exit "view" 
                break ; }
              }
        }
        break;


          //Set time #

          case 0xFFB04F:          
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("Press 1-4");
                        while(1)
                        {
                          // Serial.println(irrecv.decode(&results));
                          // OPTION
                          irrecv.resume();
                          delay(1000);
                          Serial.println("aagya");
                          if (irrecv.decode(&results))
                          {
                            if(results.value == 0xFFA25D)
                            {
                              a=1;
                              Serial.println("aagya andar");
                              break;
                            }
                            if(results.value == 0xFF629D)
                            {
                              a=2;
                              Serial.println("aagya andar");
                              break;
                            }
                            if(results.value == 0xFFE21D)
                            {
                              a=3;
                              Serial.println("aagya andar");
                              break;
                            }
                            if(results.value == 0xFF22DD)
                            {
                              a=4;
                              Serial.println("aagya andar");
                              break;
                            }
                          } 
                        }
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print(a);
                        lcd.print(" ON  00:00");
                        lcd.setCursor(0,1);
                        lcd.print(a);
                        lcd.print(" OFF 00:00");
                        while(1)
                        {
                          // Serial.println(irrecv.decode(&results));
                          // ON TIMER (HOURS)
                          irrecv.resume();
                          delay(1000);
                          Serial.println("aagya time lene");
                          if (irrecv.decode(&results))
                          {
                            if(results.value == 0xFF18E7)
                            {
                              t1++;
                              t1=t1%24;
                              lcd.setCursor(6,0);
                              if(t1<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t1);                           
                              Serial.print("current hour is: ");
                              Serial.println(t1);
                            }
                            if(results.value == 0xFF4AB5)
                            {
                              t1--;
                              t1=t1%24;
                              lcd.setCursor(6,0);
                              if(t1<0)
                              {
                                t1=23;
                              }
                              if(t1<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t1);                           
                              Serial.print("current hour is: ");
                              Serial.println(t1);
                            }
                            if(results.value == 0xFF38C7)
                            {
                              irrecv.resume();
                              break;
                            }
                          } 
                        }
                   
                       while(1)
                       {
                        // Serial.println(irrecv.decode(&results));
                        //ON TIMER (MINS)
                        irrecv.resume();
                        delay(1000);
                        if(irrecv.decode(&results))
                        {
                          if(results.value == 0xFF18E7)
                          {
                            t2++;
                            t2=t2%60;
                            lcd.setCursor(9,0);
                              if(t2<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t2); 
                            Serial.print("current minute is: ");
                            Serial.println(t2);
                            
                          }
                          if(results.value == 0xFF4AB5)
                          {
                            t2--;
                            t2=t2%60;
                            lcd.setCursor(9,0);
                            if(t2<0)
                              {
                                t2=59;
                              }
                              if(t2<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t2); 
                            Serial.print("current minute is: ");
                            Serial.println(t2);
                            
                          }
                          if(results.value == 0xFF38C7)
                          {
                            irrecv.resume();
                            break ; 
                          }
                         } 
                        }
                        while(1)
                        {
                          // Serial.println(irrecv.decode(&results));
                          // OFF TIMER(HOURS)
                          irrecv.resume();
                          delay(1000);
                          if (irrecv.decode(&results))
                          {
                            if(results.value == 0xFF18E7)
                            {
                              t3++;
                              t3=t3%24;  
                              lcd.setCursor(6,1);
                              if(t3<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t3);                          
                              Serial.print("current hour is: ");
                              Serial.println(t3);
                            }
                            if(results.value == 0xFF4AB5)
                            {
                              t3--;
                              t3=t3%24;  
                              lcd.setCursor(6,1);
                              if(t3<0)
                              {
                                t3=23;
                              }
                              if(t3<10)
                              {
                                lcd.print("0");
                              }
                              lcd.print(t3);                          
                              Serial.print("current hour is: ");
                              Serial.println(t3);
                            }
                            if(results.value == 0xFF38C7)
                            {
                              irrecv.resume();
                              break;
                            }
                          } 
                        }
                   
                       while(1)
                       {
                        // Serial.println(irrecv.decode(&results));
                        //OFF TIMER(MINS)
                        irrecv.resume();
                        delay(1000);
                        if(irrecv.decode(&results))
                        {
                          if(results.value == 0xFF18E7)
                          {
                            t4++;
                            t4=t4%60;
                            lcd.setCursor(9,1);
                            if(t4<10)
                             {
                               lcd.print("0");
                             }
                            lcd.print(t4);  
                            Serial.print("current minute is: ");
                            Serial.println(t4);
                          }
                          if(results.value == 0xFF4AB5)
                          {
                            t4--;
                            t4=t4%60;
                            if(t4<0)
                              {
                                t4=59;
                              }
                            lcd.setCursor(9,1);
                            if(t4<10)
                             {
                               lcd.print("0");
                             }
                            lcd.print(t4);  
                            Serial.print("current minute is: ");
                            Serial.println(t4);
                          }
                          if(results.value == 0xFF38C7)
                          {
                            irrecv.resume();
                            break ; 
                          }
                         } 
                        }
                        switch(a)
                        {
                              // device 1
                              case 1:
                              h1=t1;
                              m1=t2;
                              offh1=t3;
                              offm1=t4;
                              ovr[0]=0;
                              break;
                              // device 2
                              case 2:
                              h2=t1;
                              m2=t2;
                              offh2=t3;
                              offm2=t4;
                              ovr[1]=0;
                              break;
                              // device 3
                              case 3:
                              h3=t1;
                              m3=t2;
                              offh3=t3;
                              offm3=t4;
                              ovr[2]=0;
                              break;       
                              // device 4
                              case 4:  
                              h4=t1;
                              m4=t2;
                              offh4=t3;
                              offm4=t4;
                              ovr[3]=0;
                              break;                                            
                        }
          
          break;                             //case # ka break h ye
  }
  }irrecv.resume();

  //block to start according to the timer
  if(h1==now.hour() && m1==now.minute() && ac[0]==1 && ovr[0]!=1)
  {
    s1=1;
    tn[0]=1;
  }
  if(h2==now.hour() && m2==now.minute() && ac[1]==1 && ovr[1]!=1)
  {
    s2=1;
    tn[1]=1;
  }
  if(h3==now.hour() && m3==now.minute() && ac[2]==1 && ovr[2]!=1)
  {
    s3=1;
    tn[2]=1;
  }
  if(h4==now.hour() && m4==now.minute() && ac[3]==1 && ovr[3]!=1)
  {
    s4=1;
    tn[3]=1;
  }

  //block to stop according to the timer
  if(offh1==now.hour() && offm1==now.minute() && now.second()==0 && ac[0]==1)
  {
    if(ovr[0]!=1)
    s1=0;
    tn[0]=0;
  }
  if(offh2==now.hour() && offm2==now.minute() && now.second()==0 && ac[1]==1)
  {
    if(ovr[1]!=1)
    s2=0;
    tn[1]=0;
  }
  if(offh3==now.hour() && offm3==now.minute() && now.second()==0 && ac[2]==1)
  {
    if(ovr[2]!=1)
    s3=0;
    tn[2]=0;
  }
  if(offh4==now.hour() && offm4==now.minute() && now.second()==0 && ac[3]==1)
  {
    if(ovr[3]!=1)
    s4=0;
    tn[3]=0;
  }

  //final working
  digitalWrite(pin1,s1);
  digitalWrite(pin2,s2);
  digitalWrite(pin3,s3);
  digitalWrite(pin4,s4);

  //reset the override buttons
  if(0==now.hour() && 0==now.minute())
  {
    ovr[0]=0;
    ovr[1]=0;
    ovr[2]=0;
    ovr[3]=0;
  }
}
