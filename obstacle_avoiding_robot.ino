#include <Servo.h>         
#include <NewPing.h>       

//sensor pins
#define trig_pin 9 
#define echo_pin 11 

#define maximum_distance 200
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  servo_motor.attach(10); //our servo pin

  servo_motor.write(90);
  delay(2000);
}
void loop() {

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(500);
    moveBackward();
    delay(300);
    moveStop();
    delay(500);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(200);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
void moveForward(){
    analogWrite(5,255);
    analogWrite(6,255);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH); 
  }


void moveBackward(){

 
  analogWrite(5,255);
    analogWrite(6,255);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH); 
}
void turnLeft(){
analogWrite(5,255);
    analogWrite(6,255);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  
  delay(1000);
  
  analogWrite(5,255);
    analogWrite(6,255);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH); 
}
void turnRight(){
analogWrite(5,255);
    analogWrite(6,255);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  
  delay(1000);
  
  analogWrite(5,255);
    analogWrite(6,255);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH); 
}


