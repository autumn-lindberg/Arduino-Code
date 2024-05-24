#include <Arduino.h>
#include <HCSR04.h>

#include "color.h"

// put function declarations here:
void setColor(const Color & color);

const byte triggerPin = 13;
const byte echoPin = 12;
const byte redPin = 8;
const byte greenPin = 9;
const byte bluePin = 10;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
const Color RED = Color(255, 0, 0);
const Color ORANGE = Color(200, 85, 0);
const Color YELLOW = Color(255, 255, 0);
const Color GREEN = Color(0, 255, 0);
const Color NONE = Color(0, 0, 0);

const float redDist = 4;
const float orangeDist = 8; 
const float yellowDist = 14;
const float greenDist = 17;
const float limitDist = 40;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance = distanceSensor.measureDistanceCm();
  if (distance <= redDist) {
    setColor(RED);
  }
  else if (distance <= orangeDist) {
    setColor(ORANGE);
  }
  else if (distance <= yellowDist) {
    setColor(YELLOW);
  }
  else if (distance <= greenDist) {
    setColor(GREEN);
  }
  else if (distance <= limitDist || distance < 0) {
    setColor(NONE);
  }
  Serial.println(distance);
  delay(500);
}

// put function definitions here:
void setColor(const Color & c) {
  analogWrite(redPin, c.red);
  analogWrite(greenPin, c.green);
  analogWrite(bluePin, c.blue);
}