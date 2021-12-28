 #include <Servo.h>
#include <Arduino.h>

int ServoYatayPin=3;
int ServoDikeyPin=4;

//Analog pinler,joystick
int YatayPotPin=A0;
int DikeyPotPin=A1;

//Servo dönme dereceleri
#define ServoY_Min 0
#define ServoY_Max 180
#define ServoX_Min 0
#define ServoX_Max 180

Servo YatayServo;
Servo DikeyServo; 
//Servo kütüphanesinden Servo1 nesnesini tanımladım
//Direk olarak servo kütüphanesini kullanamam

//Pozisyon kontrolu
int YatayPotValue;
int YatayServoPosition;

int DikeyPotValue;
int DikeyServoPosition;

void setup()
{
  YatayServo.attach(ServoYatayPin);
  DikeyServo.attach(ServoDikeyPin);
}

void loop()
{
  //Joystick değerleri
  YatayPotValue=analogRead(YatayPotPin);
  DikeyPotValue=analogRead(DikeyPotPin);

  //Map fonk. belli değer aralığına çevirir
  YatayServoPosition=map(YatayPotValue,0,1023,ServoY_Min,ServoY_Max);
  DikeyServoPosition=map(DikeyPotValue,0,1023,ServoX_Min,ServoX_Max);

  //Hareket ettirmek için
  YatayServo.write(YatayServoPosition);
  DikeyServo.write(DikeyServoPosition);
  delay(20);
}
