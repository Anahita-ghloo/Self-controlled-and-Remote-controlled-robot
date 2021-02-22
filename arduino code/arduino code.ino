#include "LedControl.h"
#include <NewPing.h>
#include <Servo.h>

String msg,cmd;

// Ultrasonic Sensor pins and variables initialization
int trigPin = 11; 
int echoPin = 12; 
int MAX_DISTANCE_POSSIBLE = 1000;

float pingTime; //time for ping to travel to target and return
float targetDistance; //Distance from servo to target
float speedOfSound = 776.5; //Speed of sound in Miles per Hour
float maxDistance = 8; // maximum distance in inches
NewPing sonar(trigPin, echoPin, MAX_DISTANCE_POSSIBLE); //Sets up sensor library

// Motor Pins
const int pwm = 2; // For speed control
const int in_A1 = 8; 
const int in_A2 = 9;
const int in_B3 = 6;
const int in_B4 = 7;

// Dot Matrix Pin
int DIN = 5;
int CLK = 4;
int CS = 3;
LedControl lc = LedControl(DIN,CLK,CS,3);

// Servo Pin
int servoControlPin = 10; //Servo control pin
Servo myPointer; //Create a Servo Object called mypointer 
float servoAngle; //Variable for the Angle of the servo

// To check If we are in automatic or remote mode
boolean automatic = false;

byte smile_eyes[8] = {B00000000,
                       B00000000,
                       B00010000,
                       B00001000,
                       B00001000,
                       B00010000,
                       B00000000,
                       B00000000};

byte frightened_eyes[8] = {B00000000,
                       B00000000,
                       B00111100,
                       B00100100,
                       B00100100,
                       B00111100,
                       B00000000,
                       B00000000};

byte sad_eyes[8] = {B00000000,
                       B00000000,
                       B00001000,
                       B00010000,
                       B00010000,
                       B00001000,
                       B00000000,
                       B00000000};

byte poker_eyes[8] = {B00000000,
                       B00000000,
                       B00011000,
                       B00011000,
                       B00011000,
                       B00011000,
                       B00000000,
                       B00000000};

byte cross_eyes[8] = {B00000000,
                       B00000000,
                       B00100000,
                       B00110000,
                       B00101000,
                       B00100000,
                       B00000000,
                       B00000000};
                       
byte surprised_eyes[8] = {B00000000,
                       B00000000,
                       B00111100,
                       B00111100,
                       B00111100,
                       B00111100,
                       B00000000,
                       B00000000};

byte smile[8] = {
                       B00000000,
                       B00111000,
                       B00100000,
                       B00100000,
                       B00100000,
                       B00100000,
                       B00111000,
                       B00000000,
                        };

byte sad[8] = {
                         B00000000,
                         B00100000,
                         B00010000,
                         B00001000,
                         B00001000,
                         B00010000,
                         B00100000,
                         B00000000,
                        };

byte surprised[8] = {
                         B00000000,
                         B01111100,
                         B01000100,
                         B01000100,
                         B01000100,
                         B01000100,
                         B01111100,
                         B00000000,
                        };

byte poker[8] = {
                         B00000000,
                         B00010000,
                         B00010000,
                         B00010000,
                         B00010000,
                         B00010000,
                         B00010000,
                         B00000000,
                        };

byte cross[8] = {
                         B00000000,
                         B00000000,
                         B00100100,
                         B00011000,
                         B00011000,
                         B00100100,
                         B00000000,
                         B00000000,
                        };

byte frightened[8] = {
                         B11111111,
                         B10000001,
                         B10000001,
                         B10000001,
                         B10000001,
                         B10000001,
                         B10000001,
                         B11111111,
                        };
                       
void setup() {
  // put your setup code here, to run once:

  setting();  

  Serial.begin(9600);
  msg = "";
  Serial.setTimeout(100);
  brake();
  smile_face();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // To read message received from other Bluetooth Device
  if (Serial.available() > 0){ // Check if there is data coming
    msg = Serial.readString(); // Read the message as String
    //Serial.println("Android Command: " + msg);

    // If we are in automatic mode, only check for "<remote>" bluetooth message.
    if (automatic) {
          if (msg == "<remote>"){
            automatic = false; 
            delay(50);
            brake();
            smile_face ();
         }
     }

    else {
        if(msg == "<smile>"){
          smile_face();
       }
        else if ( msg == "<sad>") {
          sad_face();
       }
        else if (msg == "<cross>"){
          cross_face();
       }
        else if (msg == "<poker>"){
          poker_face();
       }
        else if (msg == "<surprised>"){
          surprised_face();
       }
        else if (msg == "<forward>"){
          move_forward();
       }
        else if (msg == "<backward>"){
          move_backward();
       }
        else if (msg == "<right>"){
          turn_right();
       }
       else if (msg == "<left>"){
         turn_left();
       }
      else if (msg == "<stop>"){
         brake();
       }
      else if (msg == "<auto>"){
         automatic = true;
         delay(50); 
       }
      else if (msg == "<remote>"){
         automatic = false; 
         delay(50);
         brake();
         smile_face ();
      }
    }
  }

 if (automatic) {
  check_forward();
 }
}

//////////////////////////////////////////////////////
void setting () {

   //Initialize the Dot matrix
   lc.shutdown(0,false);
   lc.setIntensity(0,1);
   lc.clearDisplay(0);
   lc.shutdown(1,false);
   lc.setIntensity(1,1);
   lc.clearDisplay(1);
   lc.shutdown(2,false);
   lc.setIntensity(2,1);
   lc.clearDisplay(2);

   // Initialize the L298N IC pins
   pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
   pinMode(in_A1,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_A2,OUTPUT) ;
   pinMode(in_B3,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_B4,OUTPUT) ;  

  // Setting speed of motors
   analogWrite(pwm,130) ;

 // Initialize Servo
  pinMode(servoControlPin,INPUT); 
  myPointer.attach(servoControlPin); //Tell Arduino where the Servo is connected
  
}

////////////////////////////////////////
void smile_face() {
  display_eyes(smile_eyes);
  display_mouth(smile);
}

void sad_face() {
   display_eyes(sad_eyes);
   display_mouth(sad); 
}

void cross_face() {
  display_eyes(cross_eyes);
  display_mouth(cross); 
}

void poker_face() {
  display_eyes(poker_eyes);
  display_mouth(poker);
}

void surprised_face() {
  display_eyes(surprised_eyes);
  display_mouth(surprised);
}

void frightened_face() {
  display_eyes(frightened_eyes);
  display_mouth(frightened); 
}

//////////////////////////////////////////////////////
void display_eyes(byte eyes[]) {
  for(int i=0;i<8;i++) {
   lc.setColumn(0,i,eyes[i]);
   lc.setColumn(1,i,eyes[7-i]);
  } 
}

void display_mouth(byte mouth[]) {
  for(int i=0;i<8;i++) {
    lc.setColumn(2,i,mouth[i]);
  }
}

//////////////////////////////////////////////////
void move_forward (){

   digitalWrite(in_A1,HIGH) ;
   digitalWrite(in_B3,HIGH) ;
   digitalWrite(in_A2,LOW) ;
   digitalWrite(in_B4,LOW) ;
}

///////////////////////////////////////////////
void move_backward (){

   digitalWrite(in_A1,LOW) ;
   digitalWrite(in_B3,LOW) ;
   digitalWrite(in_A2,HIGH) ;
   digitalWrite(in_B4,HIGH) ;
}

/////////////////////////////////////////
void turn_right (){

   digitalWrite(in_A1,HIGH) ;
   digitalWrite(in_B3,LOW) ;
   digitalWrite(in_A2,LOW) ;
   digitalWrite(in_B4,HIGH) ;
   
}

////////////////////////////////////////////
void turn_left (){
  
   digitalWrite(in_A1,LOW) ;
   digitalWrite(in_B3,HIGH) ;
   digitalWrite(in_A2,HIGH) ;
   digitalWrite(in_B4,LOW) ;

}

/////////////////////////////////////////////
void brake () {
  
   digitalWrite(in_A1,HIGH) ;
   digitalWrite(in_A2,HIGH) ;
   digitalWrite(in_B3,HIGH) ;
   digitalWrite(in_B4,HIGH) ;

}

/////////////////////////////////////////////
void check_forward(){
  //this function decides if the forward path is clear or not

  myPointer.write(90); // Servo should look forward at first
  delay(50);

  brake();
  delay(40);
  move_forward();
  
  if(!compare_distance()){
      change_direction();
  }
  else {
       check_right();
       myPointer.write(90);
       delay(50); 
   
       brake();
       if(!compare_distance()){
         change_direction();
       }   
       move_forward(); 
       
       check_left(); 
   
       brake(); 
       delay(40); 
       move_forward();
  }
}

///////////////////////////////////////////////////
bool compare_distance(){
  //Decides if the distance is less than max_distance or more than that returns True
  
  float targetDistance = measure_distance();
  
  if (targetDistance>maxDistance || targetDistance==0){
     smile_face();
     return true; 
  }
  else{    
    //obstacle
    // Change face to frightened
    frightened_face();
    return false;
  }
}
///////////////////////////////////////////////////

float measure_distance(){
  // measures the distance in inche
  
  delay(50);                     
  targetDistance = sonar.ping_in();
  return targetDistance;
}

/////////////////////////////////////////////////     
void change_direction(){
    //change the direction if theres an abstacle infront
    
    brake ();
    // Change face to piker
    poker_face();
    delay(1000); 

    move_backward();
    delay(400);
        
    brake ();
    delay(1000);

    int pos = 40;
     myPointer.write(pos);
     delay(100);
     if(compare_distance()){
       turn_right();
       delay(250);
       brake ();
      }

    else {
    pos = 140;
    myPointer.write(pos);
    delay(300);
    if(compare_distance()){
     turn_left();
     delay(300);
     brake ();
      }
     }
}

//////////////////////////////////////////////////
void check_right() {
  //checks right direction to avoid abstacle
  int pos = 40;
  myPointer.write(pos);
  delay(50);
  if(!compare_distance()){
     turn_left();
     delay(200);
     }
}

//////////////////////////////////////////////////
void check_left() {
   //checks left direction to avoid abstacle
  
   int pos = 140;
    myPointer.write(pos);
    delay(50);
    if(!compare_distance()){
     turn_right();
     delay(200);
      }
}
