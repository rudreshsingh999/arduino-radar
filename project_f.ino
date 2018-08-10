#include <Servo.h>
int servopin=6;
Servo mp;
int trig=13;
int echo=11;
float targetDistance;
float pingTime;
float speedOfSound=776.5;
int rotate=0;
float ar[180];
void setup() {
  Serial.begin(9600);
  mp.attach(6);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(servopin,OUTPUT);
  mp.write(0);
}
void loop() {
  if(rotate!=0)
  {
  }
  else
  {
  for(int x=0;x<180;x++)
  {
    mp.write(x);
    float x1=0.0;
    for(int y=0;y<2;y++)
    {
      digitalWrite(trig,LOW);
      delayMicroseconds(2000);
      digitalWrite(trig,HIGH);
      delayMicroseconds(15);
      digitalWrite(trig,LOW);
      delayMicroseconds(10);
      pingTime=pulseIn(echo,HIGH);
      pingTime=pingTime/1000000; 
      pingTime=pingTime/3600;
      targetDistance= speedOfSound * pingTime; 
      targetDistance=targetDistance/2;
      targetDistance= targetDistance*63360;
      x1=x1+targetDistance;
    }
    ar[x]=x1/2.0;
  }
  for(int x=179;x>=0;x--)
  {
    mp.write(x);
    float x1=0.0;
    for(int y=0;y<2;y++)
    {
      digitalWrite(trig,LOW);
      delayMicroseconds(2000);
      digitalWrite(trig,HIGH);
      delayMicroseconds(15);
      digitalWrite(trig,LOW);
      delayMicroseconds(10);
      pingTime=pulseIn(echo,HIGH);
      pingTime=pingTime/1000000; 
      pingTime=pingTime/3600;
      targetDistance= speedOfSound * pingTime;
      targetDistance=targetDistance/2;
      targetDistance= targetDistance*63360;
      x1=x1+targetDistance;
    }
    ar[x]=(ar[x]+(x1/2.0))/2.0;
  }
  for(int x=0;x<180;x++)
  {
    Serial.print(ar[x]);
    Serial.print(",");
  }
  Serial.print("\n");
  rotate=1;
  }
}
