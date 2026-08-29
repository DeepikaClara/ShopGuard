/*#ShopGuard
Step 1: Motion Detection Problem Statement → Detect human movement in front of shop.

Components → PIR sensor + ESP8266.

Outputs → Buzzer + Blynk notification.

Skills Acquired → GPIO handling, sensor interfacing, IoT notifications.
24-08-2026 | Comments: LDR is so sensitive, even small lightness is detected as HIGH/LOW, need to work on this and because of this 
you unknowingly thnkking it has wrong.
->Also need to check whether giving 3 V to LDR is working fine since previously i didn't took this sensitive factor 
->if stable in both high or low, pir is sensing, but logic has to be pir should sense only when ldr is high and darkness and time should be 11:00 to 5 am. 
Removed LDR, since already restricted with night timings
------------------------------------------------------------
29-08-2026
PIR HIGH + vibration HIGH → Intrusion confirmed.

PIR LOW + vibration HIGH → Tamper alert (possible break‑in attempt).

PIR HIGH + vibration LOW → Motion alert (someone moving near shop).

Both LOW → Normal state.
*/
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const uint8_t pir_pin = D6;
const uint8_t buzzer = D4;
const uint8_t vib_pin = D5;
bool previous_pir_state = LOW;
//bool previous_vib_state = LOW;
//bool led_reset = 0;
//bool current_pir_state = LOW;
unsigned long debouncing_delay = 500;
unsigned long current_time = 0;
unsigned long last_trigger =0;
bool current_vib_state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir_pin,INPUT);
  pinMode(vib_pin,INPUT);
  pinMode(buzzer,OUTPUT);
  uint8_t calibration_time = 30;
  Serial.begin(9600);
  Wire.begin(D2,D1);
  Serial.println("PIR Sensor under calibration...");
delay(calibration_time * 1000);
Serial.println("PIR Sensor is ACTIVE!..");
delay(1000);

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

bool vib_state()
  {
    //current_vib_state = LOW;
    bool initial_vib = digitalRead(vib_pin);
     Serial.println("Checking Intrusion...");
     delay(1000);
     current_time =millis();
     Serial.println(current_time);
     delay(1000);
            Serial.print("Direct output of vib:");
    Serial.println(initial_vib);
      if(current_time - last_trigger > debouncing_delay)
      {
          //Serial.println("Stable Intrusion Detected!");
          //Serial.println("BUZZER IS ON!!!")
          //digitalWrite(buzzer,HIGH);
   
        current_vib_state = initial_vib;
        last_trigger = current_time;
      
        
      }
     
    return current_vib_state ;
  }
void loop() 
{
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());
  delay(1000);

  if(now.hour()>=19 || (now.hour()<=5))
  {
    Serial.println("ShopGuard is ACTIVE!!!");
    bool current_pir_state = digitalRead(pir_pin);
    bool stable_vib_state = vib_state();

    Serial.print("PIR:");
    Serial.println(current_pir_state);
    Serial.print("Vibration:");
    Serial.println(stable_vib_state);
    
    delay(1000);
    if( (current_pir_state == HIGH) && (stable_vib_state == HIGH) )
    {
      Serial.println("Motion & Intrusion Detected!");
      delay(1000);
      digitalWrite(buzzer,HIGH);
      previous_pir_state = HIGH;
    }
    else if((current_pir_state == HIGH) && (stable_vib_state == LOW))
    {
      Serial.println("Motion Detected!");
      delay(1000);
      //digitalWrite(buzzer,HIGH);
      previous_pir_state = HIGH;
    }
    else if((current_pir_state == LOW) && (stable_vib_state == HIGH) )
    {
      Serial.println("Vibration without any motion, Be Careful!!!");
      delay(1000);
      digitalWrite(buzzer,HIGH);
      previous_pir_state = LOW;
    }
    else if( (current_pir_state == LOW) && (stable_vib_state == LOW))
    {
      Serial.println("Things are normal, Dont worry!");
      delay(1000);
      digitalWrite(buzzer,LOW);
      previous_pir_state = LOW;
    }

    

  }
  else
  {
    Serial.println("ShopGuard is INACTIVE :(");
    delay(1000);
  }
}


