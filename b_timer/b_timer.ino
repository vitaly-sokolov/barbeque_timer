#include <Bounce2.h>

#define LED_PIN 13
#define BUTTON_PIN 2
#define pressed_long 2000
#define num_modes 5 
int speakerPin=9;
short int max_mode=num_modes+1;

Bounce bouncer=Bounce();

unsigned long pressed_moment;
int current_mode=0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  bouncer .attach(BUTTON_PIN);
  bouncer .interval(5);
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);

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
        }
    } 
}



