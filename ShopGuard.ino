/*#ShopGuard
Step 1: Motion Detection Problem Statement → Detect human movement in front of shop.

Components → PIR sensor + ESP8266.

Outputs → Buzzer + Blynk notification.

Skills Acquired → GPIO handling, sensor interfacing, IoT notifications.
24-08-2026 | Comments: LDR is so sensitive, even small lightness is detected as HIGH/LOW, need to work on this and because of this 
you unknowingly thnkking it has wrong.
->Also need to check whether giving 3 V to LDR is working fine since previously i didn't took this sensitive factor 
->if stable in both high or low, pir is sensing, but logic has to be pir should sense only when ldr is high and darkness and time should be 11:00 to 5 am. 
*/
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const uint8_t pir_pin = D6;
const uint8_t buzzer = D4;
const uint8_t ldr_pin = D5;
bool previous_pir_state = LOW;
bool led_reset = 0;
//bool current_pir_state = LOW;
unsigned long wait_time_off = 5000;
unsigned long timer =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pir_pin,INPUT);
  pinMode(ldr_pin,INPUT);
  pinMode(buzzer,OUTPUT);
  uint8_t calibration_time = 30;
  Serial.begin(9600);
  Wire.begin(D2,D1);
  Serial.println("PIR Sensor under calibration...");
delay(calibration_time * 1000);
Serial.println("PIR Sensor is ACTIVE!..");

  if(!rtc.begin())
  {
    Serial.println("Couldn't find RTC :( ");
    while(1);
  }

  if(rtc.lostPower())
  {
    Serial.println("RTC lost power, setting time...");
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  }
}
/*
bool pir_detection()
{
  bool pir_output = digitalRead(D3);
  return pir_output;
}
*/

bool ldr_state()
  {
    bool initial_ldr = digitalRead(ldr_pin);
    return initial_ldr;
  }
void loop() 
{
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());

  if(now.hour()>=19 || (now.hour()<=5))
  {
    Serial.println("ShopGuard is ACTIVE!!!");
    uint8_t counters;
    bool stable = true;
    bool temp_ldr = LOW;
    bool current_ldr= ldr_state();
  
  //for(start_time=millis();(millis()-start_time)<=5000;counters++)
    for(counters =1;counters<=5;counters++)
    {
  
      delay(1000);
      temp_ldr = ldr_state();
      if(temp_ldr == current_ldr)
      {
        Serial.print("current_ldr:");
        Serial.println(current_ldr);
        Serial.println(("Stability Check, please wait..."));
        Serial.print("counters:");
        Serial.println(counters);
    
      }
      else
      {
        Serial.print("current_ldr:");
        Serial.println(current_ldr);
        Serial.println("Signal is non stable!");
        Serial.print("counters:");
        Serial.println(counters);
        stable = false;
        break;
      
      }
    }
  
    if(stable)
    {
      Serial.println("System stable...");
      bool current_pir_state = digitalRead(pir_pin);
      Serial.println("current PIR:");
      Serial.println(current_pir_state);
      if((previous_pir_state ==LOW ) && (current_pir_state == HIGH))
      {
        Serial.println("Motion Detection");
        Serial.println("Current_ldr:");
        Serial.println(current_ldr);
        
        Serial.println("Stable Darkness.. LED is ON!");
        digitalWrite(buzzer,HIGH);
      
        //digitalWrite(led_pin, HIGH);
        //Serial.println("LED is ON...");
        //led_reset = 1;
      
        previous_pir_state = HIGH;
      }
     
      else if((previous_pir_state == HIGH ) && (current_pir_state == LOW ) )
      {
        Serial.println("Motion Ended");
        timer = millis();
        Serial.print("Timer Started at:");
        Serial.println(timer);
        previous_pir_state = LOW;
        led_reset=0;
      }
    
      if((current_pir_state == LOW ) && ((millis() - timer)> wait_time_off) && (led_reset ==0))
      {
        Serial.println("No Motion Confirmed..");
        Serial.println("Stable Brightness.. LED is OFF!");
        digitalWrite(buzzer,LOW);
        //digitalWrite(led_pin, LOW);
        //Serial.println("LED is OFF...");
        led_reset = 1;
      
      }
    }
  }
  else
  {
    Serial.println("ShopGuard is INACTIVE :(");
  }
}


