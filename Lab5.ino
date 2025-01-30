#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);

long duration, distance;

void setup() {
  AFMS.begin();
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600); 
}

long distanceTest(){
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  duration = pulseIn(8, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  return distance;
}

void forwards(){
    rightMotor->setSpeed(126);
  leftMotor->setSpeed(120);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}
void turnLeft(){
      rightMotor->setSpeed(0);
  leftMotor->setSpeed(120);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

void turnRight(){
      rightMotor->setSpeed(126);
  leftMotor->setSpeed(0);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

void backwards(){
    rightMotor->setSpeed(123);
  leftMotor->setSpeed(120);

  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

void loop() {
  if(distance < 10){
    forwards();
    delay(500);
  }
  else{
    backwards();
    delay(500);
    turnLeft();
    delay(500);
  }
}
