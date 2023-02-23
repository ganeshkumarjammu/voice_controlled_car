/**
 * Ganesh Kumar Jammu
 * github: https://github.com/ganeshkumarjammu
 * Voice Controlled App download link : https://play.google.com/store/apps/details?id=com.himanshu.ArduinoAutomation
 * 
 **/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); //RX = 10, TX=11 of Arduino and Tx and Rx of Bluetooth
//No need to connect RX of bluetooth to Arduino UNO
String readvoice;
int k = 0;
const int IN1 = 7 ;
const int IN2 = 8 ;
const int IN3 = 9 ;
const int IN4 = 10 ;
const int ENA = 6 ;
const int ENB = 11 ;
int motorSpeed = 150;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.println("Voice Controlled Car");
}

void loop() {
  while (mySerial.available())
  {
    delay(3);
    char c = mySerial.read();
    readvoice += c;
  }

  if (readvoice.length() > 0)
  {
    Serial.println(readvoice);
    analogWrite(ENA, motorSpeed);
    analogWrite(ENB, motorSpeed);
    if (readvoice == "forward")
    {
      Serial.println(readvoice);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);
      k = 1;
    }
    if (readvoice == "backward")
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      k = 2;
      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);
    }

    if (readvoice == "right")
    {
      if (k == 2)
      {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(1000);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
      }
      else
      {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(1000);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
      }
    }

    if (readvoice == "left")
    {
      if (k == 2)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        delay(1000);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
      }
      else
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        delay(1000);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
      }
    }

    if (readvoice == "stop")
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }

    if (readvoice == "increase")
    {
      if (motorSpeed > 0) {
        motorSpeed -= 30;
      }
      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);
    }

    if (readvoice == "decrease")
    {
      if (motorSpeed > 0) {
        motorSpeed -= 30;
      }
      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);
    }

  }
  readvoice = "";
}
