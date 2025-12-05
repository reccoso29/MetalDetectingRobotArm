#include <Servo.h>

Servo base;
Servo joint1;
Servo joint2;
Servo joint3;

int sensor_pin = 8;
int val;

int enA = 4;
int in1 = 2;
int in2 = 3;

int angle4;
int angle3;
int angle2;
int angle1;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(5000); 

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  base.attach(13);
  joint1.attach(10);
  joint2.attach(11);
  joint3.attach(12);

  pinMode(sensor_pin,INPUT);

  // Reset to 90 degree position on startup
  joint1.write(90);
  delay(500);
  joint2.write(90);
  delay(500);
  joint3.write(90);
  delay(500);
  base.write(90);
  delay(500);
}

void loop() {
  // Your code here 
  delay(10);  
  val = digitalRead(sensor_pin);
  Serial.print(val);
  delay(200);

  while(val == 1){

      //Turn off motor A & B
      digitalWrite(enA, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      Serial.print(val);
      val = digitalRead(sensor_pin);
      delay(400);
  }

  if(val == 0){
      collect();
      val = digitalRead(sensor_pin);
      delay(2000);
      val = digitalRead(sensor_pin);
  }
}

void collect() {
  // base
  delay(10);
  for(angle4 = 90; angle4 > 8; angle4--)  
  {                                  
    base.write(angle4);               
    delay(20);                   
  } 
  // joint2
  for(angle2 = 90; angle2 > 70; angle2--)  
  {                                  
    joint2.write(angle2);               
    delay(20);                   
  } 
  // joint1
  for(angle1 = 90; angle1 < 140; angle1++)  
  {                                  
    joint1.write(angle1);               
    delay(20);                   
  } 
    // joint3
  for(angle3 = 90; angle3 > 37; angle3--)  
  {                                  
    joint3.write(angle3);               
    delay(20);                   
  } 

  //wait and pickup
  digitalWrite(enA, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(1000);

  //rotate to dropoff
  for(angle3 = 37; angle3 < 70; angle3++)  
  {                                  
    joint3.write(angle3);               
    delay(20);                   
  } 

  for(angle4 = 8; angle4 < 120; angle4++)  
  {                                  
    base.write(angle4);               
    delay(20);                   
  } 

  // joint1
  for(angle1 = 160; angle1 < 160; angle1++)  
  {                                  
    joint1.write(angle1);               
    delay(20);                   
  } 

  //wait and dropoff
  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);

    for(angle4 = 120; angle4 > 90; angle4--)  
  {                                  
    base.write(angle4);               
    delay(20);                   
  } 
  // joint3
  for(angle3 = 70; angle3 < 90; angle3++)  
  {                                  
    joint3.write(angle3);               
    delay(20);                   
  } 
  // joint2
  for(angle2 = 70; angle2 > 90; angle2--)  
  {                                  
    joint2.write(angle2);               
    delay(20);                   
  } 
  // joint1
  for(angle1 = 160; angle1 > 90; angle1--)  
  {                                  
    joint1.write(angle1);               
    delay(20);                   
  } 

}