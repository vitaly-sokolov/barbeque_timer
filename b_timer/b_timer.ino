#include <Bounce2.h>

#define LED_15S 3  //led pin for 15 seconds mode
#define LED_20S 5  //led pin for 20 seconds mode
#define LED_30S 6  //led pin for 30 seconds mode
#define LED_45S 9   //led pin for 45 seconds mode
#define LED_60S 10   //led pin for 60 seconds mode
#define LED_T 13   //led for timer LED
#define LED_T_DELAY 120
#define BUTTON_PIN 2
#define pressed_long 800
#define num_modes 5
#define LED_BRIGHTNESS 5

int speakerPin=11;
int speakerVolume=40;
short int max_mode=num_modes+1;

Bounce bouncer = Bounce();

unsigned long pressed_moment;
unsigned long timer;
int current_mode=0;

void setup() {
  pinMode(LED_15S,OUTPUT);
  pinMode(LED_20S,OUTPUT);
  pinMode(LED_30S,OUTPUT);
  pinMode(LED_45S,OUTPUT);
  pinMode(LED_60S,OUTPUT);
  pinMode(LED_T,OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
  bouncer .attach(BUTTON_PIN);
  bouncer .interval(5);
  Serial.begin(9600);
  pinMode(speakerPin,OUTPUT);

}

// Led and buzzer signalization when chosen time has passed
void actuation() {
  digitalWrite(LED_T,HIGH);
  analogWrite(speakerPin,speakerVolume);
  delay(LED_T_DELAY);
  digitalWrite(LED_T,LOW);
  analogWrite(speakerPin,0);
}

void led_on(int led_n) {
  if (led_n==1)
    {
      analogWrite(LED_15S,LED_BRIGHTNESS);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
    }
  if (led_n==2)
   {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,LED_BRIGHTNESS);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
   }
  if (led_n==3)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,LED_BRIGHTNESS);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
  }
  if (led_n==4)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,LED_BRIGHTNESS);
      analogWrite(LED_60S,0);
  }
  if (led_n==5)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,LED_BRIGHTNESS);
  }
  if (led_n==0)
  //else
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
  }
    
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
      if ((millis()-pressed_moment)<pressed_long)
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
    }
  }
  led_on(current_mode);
  //Serial.println(current_mode);
  if (current_mode==1)
  {
    //Serial.println(current_mode);
    // The following 'while' was used for debugging
    /*while((millis()-pressed_moment)<=15000UL)
    {
      Serial.println("millis:");
      Serial.println(millis());
      Serial.println("pressed_moment:");
      Serial.println(pressed_moment);
      Serial.println("time passed:");
      Serial.println(millis()-pressed_moment);      
      break;
    }
    Serial.println("====stop====");
    */
    
    if (millis()-pressed_moment>=15000UL)
    {
      Serial.println("15 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==2)
  {
    if (millis()-pressed_moment>=20000UL)
    {
      Serial.println("20 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==3)
  {
    if (millis()-pressed_moment>=30000UL)
    {
      Serial.println("30 seconds have passed");
      actuation();
      pressed_moment=millis();
    }      
  }

  if (current_mode==4)
  {
    if (millis()-pressed_moment>=45000UL)
    {
      Serial.println("45 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==5)
  {
    if (millis()-pressed_moment>=60000UL)
    {
      Serial.println("60 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

}#include <Bounce2.h>

#define LED_15S 3  //led pin for 15 seconds mode
#define LED_20S 5  //led pin for 20 seconds mode
#define LED_30S 6  //led pin for 30 seconds mode
#define LED_45S 9   //led pin for 45 seconds mode
#define LED_60S 10   //led pin for 60 seconds mode
#define LED_T 13   //led for timer LED
#define LED_T_DELAY 120
#define BUTTON_PIN 2
#define pressed_long 800
#define num_modes 5
#define LED_BRIGHTNESS 5

int speakerPin=4;
int speakerVolume=40;
short int max_mode=num_modes+1;

Bounce bouncer = Bounce();

unsigned long pressed_moment;
unsigned long timer;
int current_mode=0;

void setup() {
  pinMode(LED_15S,OUTPUT);
  pinMode(LED_20S,OUTPUT);
  pinMode(LED_30S,OUTPUT);
  pinMode(LED_45S,OUTPUT);
  pinMode(LED_60S,OUTPUT);
  pinMode(LED_T,OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
  bouncer .attach(BUTTON_PIN);
  bouncer .interval(5);
  Serial.begin(9600);
  pinMode(speakerPin,OUTPUT);

}

// Led and buzzer signalization when chosen time has passed
void actuation() {
  digitalWrite(LED_T,HIGH);
  analogWrite(speakerPin,speakerVolume);
  delay(LED_T_DELAY);
  digitalWrite(LED_T,LOW);
  analogWrite(speakerPin,0);
}

void led_on(int led_n) {
  if (led_n==1)
    {
      analogWrite(LED_15S,LED_BRIGHTNESS);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
    }
  if (led_n==2)
   {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,LED_BRIGHTNESS);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
   }
  if (led_n==3)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,LED_BRIGHTNESS);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
  }
  if (led_n==4)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,LED_BRIGHTNESS);
      analogWrite(LED_60S,0);
  }
  if (led_n==5)
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,LED_BRIGHTNESS);
  }
  if (led_n==0)
  //else
  {
      analogWrite(LED_15S,0);
      analogWrite(LED_20S,0);
      analogWrite(LED_30S,0);
      analogWrite(LED_45S,0);
      analogWrite(LED_60S,0);
  }
    
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
      if ((millis()-pressed_moment)<pressed_long)
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
    }
  }
  led_on(current_mode);
  //Serial.println(current_mode);
  if (current_mode==1)
  {
    //Serial.println(current_mode);
    // The following 'while' was used for debugging
    /*while((millis()-pressed_moment)<=15000UL)
    {
      Serial.println("millis:");
      Serial.println(millis());
      Serial.println("pressed_moment:");
      Serial.println(pressed_moment);
      Serial.println("time passed:");
      Serial.println(millis()-pressed_moment);      
      break;
    }
    Serial.println("====stop====");
    */
    
    if (millis()-pressed_moment>=15000UL)
    {
      Serial.println("15 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==2)
  {
    if (millis()-pressed_moment>=20000UL)
    {
      Serial.println("20 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==3)
  {
    if (millis()-pressed_moment>=30000UL)
    {
      Serial.println("30 seconds have passed");
      actuation();
      pressed_moment=millis();
    }      
  }

  if (current_mode==4)
  {
    if (millis()-pressed_moment>=45000UL)
    {
      Serial.println("45 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

  if (current_mode==5)
  {
    if (millis()-pressed_moment>=60000UL)
    {
      Serial.println("60 seconds have passed");
      actuation();
      pressed_moment=millis();
    }
  }

}
