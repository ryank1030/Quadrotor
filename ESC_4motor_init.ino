#include <Servo.h>

#define MAX_SIGNAL 1860
#define MIN_SIGNAL 1064
#define FIRST_MOTOR_PIN 9
#define SECOUND_MOTOR_PIN 10
#define THIRD_MOTOR_PIN 11
#define FOURTH_MOTOR_PIN 6
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup() {
  Serial.begin(115200);
  Serial.println("Program begin...");
  Serial.println("This program will calibrate the ESC.");

  motor1.attach(FIRST_MOTOR_PIN);
  motor2.attach(SECOUND_MOTOR_PIN);
  motor3.attach(THIRD_MOTOR_PIN);
  motor4.attach(FOURTH_MOTOR_PIN);

  Serial.println("Now writing maximum output.");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  motor1.writeMicroseconds(MAX_SIGNAL);
  motor2.writeMicroseconds(MAX_SIGNAL);
  motor3.writeMicroseconds(MAX_SIGNAL);
  motor4.writeMicroseconds(MAX_SIGNAL);
  
  // Wait for input
  while (!Serial.available());
  Serial.read();

  // Send min output
  Serial.println("Sending minimum output");
  motor1.writeMicroseconds(MIN_SIGNAL);
  motor2.writeMicroseconds(MIN_SIGNAL);
  motor3.writeMicroseconds(MIN_SIGNAL);
  motor4.writeMicroseconds(MIN_SIGNAL);
}

void loop() {  

}
