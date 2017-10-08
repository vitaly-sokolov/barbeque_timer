#include <Bounce2.h>

#define LED_15S 13
#define LED_20S 12
#define LED_30S 11
#define LED_45S 10
#define LED_60S 9
#define BUTTON_PIN 2
#define pressed_long 1000
#define num_modes 5 
int speakerPin=9;
short int max_mode=num_modes+1;

Bounce bouncer=Bounce();

unsigned long pressed_moment;
unsigned long timer;
int current_mode=0;

void setup() {
  pinMode(LED_15S,OUTPUT);
  pinMode(LED_20S,OUTPUT);
  pinMode(LED_30S,OUTPUT);
  pinMode(LED_45S,OUTPUT);
  pinMode(LED_60S,OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
  bouncer .attach(BUTTON_PIN);
  bouncer .interval(5);
  Serial.begin(9600);
  pinMode(speakerPin,OUTPUT);

}

void loop() {
  if (bouncer.update())
    {
      if (bouncer.read()==0)
        {
          pressed_moment=millis();
        }
      else 
        {
          if((millis()-pressed_moment)<pressed_long)
          {
            current_mode++;
            current_mode%=max_mode;
            if (current_mode==0) current_mode=1;
          }
          else 
          {
            current_mode=0;
            pressed_moment=0;
          }
          Serial.println("Current mode:");
          Serial.println(current_mode);
          
          switch(current_mode) 
            {
              case 1: 
                digitalWrite(LED_15S,HIGH);
                digitalWrite(LED_20S,LOW);
                digitalWrite(LED_30S,LOW);
                digitalWrite(LED_45S,LOW);
                digitalWrite(LED_60S,LOW);

                Serial.println("led 15 is on");
                timer=millis();
                while ((millis()-timer)<=5000UL)
                  {
                    Serial.println("==");
                  }
                Serial.println("stop");
                break;
              case 2: 
                digitalWrite(LED_15S,LOW);
                digitalWrite(LED_20S,HIGH);
                digitalWrite(LED_30S,LOW);
                digitalWrite(LED_45S,LOW);
                digitalWrite(LED_60S,LOW);
                break;
              case 3:
                digitalWrite(LED_15S,LOW);
                digitalWrite(LED_20S,LOW);
                digitalWrite(LED_30S,HIGH);
                digitalWrite(LED_45S,LOW);
                digitalWrite(LED_60S,LOW);
                break;
              case 4:
                digitalWrite(LED_15S,LOW);
                digitalWrite(LED_20S,LOW);
                digitalWrite(LED_30S,LOW);
                digitalWrite(LED_45S,HIGH);
                digitalWrite(LED_60S,LOW);
                break;
              case 5:
                digitalWrite(LED_15S,LOW);
                digitalWrite(LED_20S,LOW);
                digitalWrite(LED_30S,LOW);
                digitalWrite(LED_45S,LOW);
                digitalWrite(LED_60S,HIGH);
                break;
              default:
                digitalWrite(LED_15S,LOW);
                digitalWrite(LED_20S,LOW);
                digitalWrite(LED_30S,LOW);
                digitalWrite(LED_45S,LOW);
                digitalWrite(LED_60S,LOW);
                break;
            }
            
           /* if (current_mode==1)
            {
              //Serial.println("led 15 is on");
              timer=millis();
              Serial.println(millis());
              while ((millis()-timer)<=5000UL)
                {
                  Serial.println("hey");
                }
              
              Serial.println("stop");
            }*/
        }
    }
    
     
}



