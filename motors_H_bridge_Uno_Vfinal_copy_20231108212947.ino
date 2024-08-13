#include <Arduino.h>

const int aMotorPin1 = 3;
const int aMotorPin2 = 5;
const int aenablePin = 2;  // Connect to arduino enable pin for motor A
const int bMotorPin1 = 6;  //
const int bMotorPin2 = 9;
const int bEnablePin = 7;  // Connect to the arduino enable pin for motor B



void setup() {
  // put your setup code here, to run once:

  pinMode(aMotorPin1, OUTPUT);
  pinMode(aMotorPin2, OUTPUT);
  pinMode(aenablePin, OUTPUT);
  pinMode(bMotorPin1, OUTPUT);
  pinMode(bMotorPin2, OUTPUT);
  pinMode(bEnablePin, OUTPUT);

  digitalWrite(bMotorPin1, LOW);
  digitalWrite(bMotorPin2, LOW);
  digitalWrite(aMotorPin1, LOW);
  digitalWrite(aMotorPin2, LOW);
  digitalWrite(aenablePin, LOW);  // Initialize with motor off
  digitalWrite(bEnablePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Both Motors will run at High speed in forward direction
  analogWrite(aMotorPin1, 255);
  analogWrite(aMotorPin2, 0);  // Full speed
  analogWrite(bMotorPin1, 255);
  analogWrite(bMotorPin2, 0);
  digitalWrite(aenablePin, HIGH);
  digitalWrite(bEnablePin, HIGH);

  delay(3000);

  //Both Motors will run at High speed in reverse
  analogWrite(aMotorPin1, 0);
  analogWrite(aMotorPin2, 255);  // Full speed
  analogWrite(bMotorPin1, 0);
  analogWrite(bMotorPin2, 255);
  digitalWrite(aenablePin, HIGH);
  digitalWrite(bEnablePin, HIGH);

  delay(3000);

  digitalWrite(aenablePin, LOW);
  digitalWrite(bEnablePin, LOW);

  delay(1000);
  //motor A will ramp up in forward motion
  for (int speed = 100; speed <= 255; speed++) {
    digitalWrite(aenablePin, HIGH);
    digitalWrite(bEnablePin, LOW);
    analogWrite(aMotorPin1, speed);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);


  //motor A will ramp down in forward motion
  for (int speed = 255; speed >= 100; speed--) {
    digitalWrite(aenablePin, HIGH);
    digitalWrite(bEnablePin, LOW);
    analogWrite(aMotorPin1, speed);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);

  digitalWrite(aenablePin, LOW);
  digitalWrite(bEnablePin, LOW);
  delay(1000);

  // motor A will ramp up in reverse
  for (int speed = 100; speed <= 255; speed++) {
    digitalWrite(aenablePin, HIGH);
    digitalWrite(bEnablePin, LOW);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, speed);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);
  // motor A will ramp down in reverse
  for (int speed = 255; speed >= 100; speed--) {
    digitalWrite(aenablePin, HIGH);
    digitalWrite(bEnablePin, LOW);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, speed);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);


  digitalWrite(aenablePin, LOW);
  digitalWrite(bEnablePin, LOW);

  //Motor B will do the same thing as motor A just did while motor A is not running

  //motor B will ramp up in forward motion
  for (int speed = 100; speed <= 255; speed++) {
    digitalWrite(aenablePin, LOW);
    digitalWrite(bEnablePin, HIGH);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, speed);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);


  //motor B will ramp down in forward motion
  for (int speed = 255; speed >= 100; speed--) {
    digitalWrite(aenablePin, LOW);
    digitalWrite(bEnablePin, HIGH);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, speed);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, 0);
    delay(50);
  }
  delay(4000);

  digitalWrite(aenablePin, LOW);
  digitalWrite(bEnablePin, LOW);
  delay(1000);

  // motor B will ramp up in reverse
  for (int speed = 100; speed <= 255; speed++) {
    digitalWrite(aenablePin, LOW);
    digitalWrite(bEnablePin, HIGH);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, speed);
    delay(50);
  }
  delay(4000);
  // motor B will ramp down in reverse
  for (int speed = 255; speed >= 100; speed--) {
    digitalWrite(aenablePin, LOW);
    digitalWrite(bEnablePin, HIGH);
    analogWrite(aMotorPin1, 0);
    analogWrite(bMotorPin1, 0);
    analogWrite(aMotorPin2, 0);
    analogWrite(bMotorPin2, speed);
    delay(50);
  }
  delay(4000);

  //Stops the both motors
  digitalWrite(aenablePin, LOW);
  digitalWrite(bEnablePin, LOW);


  while (true) {
    // You can add code here to handle other tasks if needed
  }
}
