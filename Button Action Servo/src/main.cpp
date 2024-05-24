#include <Arduino.h>
#include <Servo.h>

Servo myServo;
const byte servoPin = 5;
const byte leftPin = 8;
const byte rightPin = 9;

int currentAngle = 5;
unsigned int lastTimePressed = millis();
unsigned int lastTimeLetOff = millis();
unsigned int debounceDelay = 200;
int currentState = 0;

// 0 - 100
int speed = 90;

// put function declarations here:
void moveLeft(int degrees);
void moveRight(int degrees);

void setup() {
  Serial.begin(9600);

  myServo.attach(5);
  // set initial position
  myServo.write(5);

  pinMode(servoPin, OUTPUT);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if the button has been pressed down
  if (millis() - lastTimePressed > debounceDelay) {
    currentState = 1;
    // if the button has not been released
    if (millis() - lastTimeLetOff > debounceDelay) {
      while (digitalRead(leftPin) == LOW) {
        moveLeft(1);
        delay(100 - speed);
      }
      while (digitalRead(rightPin) == LOW) {
        moveRight(1);
        delay(100 - speed);
      }
      lastTimeLetOff = millis();
    }
    lastTimePressed = millis();
  }
}

void moveLeft(int degrees) {
  currentAngle += degrees;
  if (currentAngle > 180) {
    currentAngle = 180;
  }
  myServo.write(currentAngle);
}

void moveRight(int degrees) {
  currentAngle -= degrees;
  if (currentAngle < 5) {
    currentAngle = 5;
  }
  myServo.write(currentAngle);
}
