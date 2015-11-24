#include <Servo.h>

#define FIRST_MOTOR_PIN 9  //Back Right         //define the pins the motors are on 
#define SECOUND_MOTOR_PIN 10 //Front Right
#define THIRD_MOTOR_PIN 11  //Back Left
#define FOURTH_MOTOR_PIN 6  //Front Left

Servo motorFL;   //say there are 4 motors
Servo motorFR;
Servo motorBL;
Servo motorBR;
int input = 0;      //variables for speed and serial input
int spdFL = 1200;     //defualt speed to start the program
int spdFR = 1200;
int spdBL = 1200;
int spdBR = 1200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                   //start serial
  motorBR.attach(FIRST_MOTOR_PIN);       //attach the motors to the pins
  motorFR.attach(SECOUND_MOTOR_PIN);
  motorBL.attach(THIRD_MOTOR_PIN);
  motorFL.attach(FOURTH_MOTOR_PIN);
  Serial.println("Program Starting");
  Serial.println("1 = -10 | 2 = -5 | 3 = -1 | 4 = +1 | 5 = +5 | 6 = +10 | k = kill process");      //input usage prompt
  Serial.println("q = FL-1 | w = FL+1 || e = FR-1 | r = FR+1 || a = BL-1 | s = BL+1 || d = BR-1 | f = BR+1");
}

void loop() {
  if(input == 0)
  {
  motorFL.writeMicroseconds(spdFL);    //start the motors at spd
  motorFR.writeMicroseconds(spdFR);
  motorBL.writeMicroseconds(spdBL);
  motorBR.writeMicroseconds(spdBR);
  }
  
  if(Serial.available() > 0)      //read from serial
  {
    input = Serial.read();      //store the serial input into input
    Serial.print("input = ");   //display the value read
    Serial.print(input);
    Serial.println("");
  }
  if(input == 49)       //the value of 1
  {
    spdFL = spdFL - 10;
    spdFR = spdFR - 10;
    spdBL = spdBL - 10;
    spdBR = spdBR - 10;
  }
  else if(input == 50)        //the value of 2
  {
    spdFL = spdFL - 5;
    spdFR = spdFR - 5;
    spdBL = spdBL - 5;
    spdBR = spdBR - 5;
  }
  else if(input == 51)        //the value of 3
  {
    spdFL = spdFL - 1;
    spdFR = spdFR - 1;
    spdBL = spdBL - 1;
    spdBR = spdBR - 1;
  }
  else if(input == 52)      //the value of 4
  {
    spdFL = spdFL + 1;
    spdFR = spdFR + 1;
    spdBL = spdBL + 1;
    spdBR = spdBR + 1;
  }
  else if(input == 53)      //the value of 5
  {
    spdFL = spdFL + 5;
    spdFR = spdFR + 5;
    spdBL = spdBL + 5;
    spdBR = spdBR + 5;
  }
  else if (input == 54)     //the value of 6
  {
    spdFL = spdFL + 10;
    spdFR = spdFR + 10;
    spdBL = spdBL + 10;
    spdBR = spdBR + 10;
  }
  else if (input == 'q') // FL - 1
    spdFL--;
  else if (input == 'w') //FL + 1
    spdFL++;
  else if (input == 'e') //FR - 1
    spdFR--;
  else if (input == 'r') //FR + 1
    spdFR++;
  else if (input == 'a')  //BL - 1
    spdBL--;
  else if (input == 's')  //BL + 1
    spdBL++;
  else if (input == 'd')  //BR - 1
    spdBR--;
  else if (input == 'f') //BR + 1
    spdBR++;
  else if(input == 'k')     //if k is sent
  {
     Serial.println("");
     Serial.print("process killed");
     motorFL.writeMicroseconds(1000);      //slow the motors down
     motorFR.writeMicroseconds(1000);
     motorBL.writeMicroseconds(1000);
     motorBR.writeMicroseconds(1000);
     delay(1000);                           //wait for the motor to slow down
     motorFL.detach();                 //detach the motors to stop from turing on again
     motorFR.detach();
     motorBL.detach();
     motorBR.detach();
  }
  if(input != 0)      //if input was given
  {
    if(input != 'k')    //if the input was not kill
    {
      Serial.print("Speed FL = ");       //display the speed
      Serial.print(spdFL);
      Serial.print(" | FR = ");
      Serial.print(spdFR);
      Serial.print(" | BL = ");
      Serial.print(spdBL);
      Serial.print(" | BR = ");
      Serial.println(spdBR);
      Serial.println("");
    }
    input = 0;                          //re initalize the input
  }
  
}
