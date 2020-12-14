#include <Arduino.h>

#define SERIAL_DEBUG

int RightMotor = 0;
int LeftMotor = 0;
int SpeedValue = 0;

//int ch1;
//int ch2;
//int ch3;
//int ch4;

// Двигатель A 
int enA = 9;
int in1 = 8;
int in2 = 7;
// Двигатель B
int enB = 3;
int in3 = 5;
int in4 = 4;

int m1 = 0;
int m2 = 0;

void setup() {
  
  Serial.begin(57600);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  /*
  pinMode(9, INPUT);
  pinMode(6, INPUT);
  */
  /*
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  */
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}



void loop() {
    //SpeedValue = map(pulseIn(10, HIGH), 1100, 1900, 0, 255);
    SpeedValue = pulseIn(10, HIGH);
    if (SpeedValue > 1500) {
      m1 = map(pulseIn(10, HIGH), 1500, 1900, 0, 255);
      if (m1 >= 255) { 
        m1 = 255;
      } else if (m1 <= 30) {
        m1 = 0;
      }
      m2 = 0;
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);      
    } else {
      m1 = 0;
      m2 = map(pulseIn(10, HIGH), 1100, 1500, 255, 0);
      if (m2 >= 255) {
        m2 = 255;
      } else if (m2 <= 30) {
        m2 = 0;
      }
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);          
    }
    //SpeedValue = map(pulseIn(10, HIGH), 1025, 1900, 0, 255);
// Serial.print("forward: ");
 //Serial.println(m1);
 //Serial.print("back: ");
 //Serial.println(m2);
 
  RightMotor = (m1 + m2) - map(pulseIn(11, HIGH), 1100, 1900, -70, 70);
  LeftMotor = (m1 + m2) - map(pulseIn(11, HIGH), 1000, 1900, +70, -70);
  if (RightMotor >= 255) {
    RightMotor = 255;
  } else if (RightMotor <= 0) {
    RightMotor = 0;
  }
  if (LeftMotor >= 255) {
    LeftMotor = 255;
  } else if (LeftMotor < 0) {
    LeftMotor = 0;
  }

#ifdef SERIAL_DEBUG
  Serial.print("RIGHT MOTOR: ");
  Serial.println(RightMotor);
  Serial.print("LEFT MOTOR: ");
  Serial.println(LeftMotor);
#endif
//delay(500);
//if(RightMotor < 0){
 // RightMotor = 0;
//}
//if(LeftMotor < 0){
 // LeftMotor = 0;
//}
analogWrite(enA, LeftMotor);
analogWrite(enB, RightMotor);
//delay(500);

  // Установка двигателя A и B на максимальную скорость (0 ... 255)  
  //analogWrite(enA, 255);   
  //analogWrite(enB, 255);
// Вращение двигателем A и B вперед
 // digitalWrite(in1, HIGH);
 //digitalWrite(in2, LOW);
  //digitalWrite(in3, HIGH);
 //digitalWrite(in4, LOW);
 //delay(2000);
// Вращение двигателем A и B назад
 // digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);
 // digitalWrite(in4, HIGH);
//  delay(2000);
// Отключение мотора A и B
  //digitalWrite(in1, LOW);
 // digitalWrite(in2, LOW);
 // digitalWrite(in3, LOW);
 // digitalWrite(in4, LOW);
/*
 ch1 = map(pulseIn(11, HIGH), 1100, 1900, 0, 255);
  ch1 = pulseIn(11, HIGH);
  ch2 = pulseIn(10, HIGH, 2000); //, -70, 70);
  ch2 = pulseIn(10, HIGH);
  */
  /*
//  ch3 = pulseIn(9, HIGH, 2000); //, -70, 70);
  ch3 = pulseIn(9, HIGH);
//  ch4 = pulseIn(6, HIGH, 2000); //, -70, 70);
  ch4 = pulseIn(6, HIGH);

*/
/*
  Serial.print("ch1: ");
  Serial.print(ch1);
  Serial.println("");
  Serial.print("ch3: ");
  Serial.print(ch2); 
  Serial.println("");
  */
 /* Serial.print("ch3: ");
  Serial.print(ch3);
  Serial.println("");
  Serial.print("ch4: ");
  Serial.print(ch4);
  Serial.println("");
  delay(500);
  */
}
