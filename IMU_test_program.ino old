#include <Wire.h>
const int MPU = 0x68; //MPU-6050 address
int16_t AccX, AccY, AccZ, Temp, GyroX, GyroY, GyroZ;     //unsigned 16 bit int
int16_t AccXoff, AccYoff, AccZoff, GyroXoff, GyroYoff, GyroZoff;
int GyroXAngle, GyroYAngle, GyroZAngle, AccXAngle, AccYAngle, AccZAngle;
int GyroXRate, GyroYRate, GyroZRate, AccXRate, AccYRate, AccZRate;
int Yaw, Pitch, Roll;
int FYaw, FPitch, FRoll;
int timer;


void setup() {
  // initialize the chip
  Serial.begin(9600);   //start serial
  Wire.begin();         //start i2c
  Wire.beginTransmission(MPU);    //start transmission with chip
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);      //wake up the chip
  Wire.endTransmission(true); //stop communication to chip
  
}

void loop() {

  Wire.beginTransmission(MPU);    //start the transmission
  Wire.write(0x3B);   //register of ACCEL_XOUT_H
  Wire.endTransmission(false); //stop talking but hold the connection with the chip
  Wire.requestFrom(MPU, 14, true);    //request next 14 registers from chip with a stop message after each
  AccX=Wire.read()<<8|Wire.read();   //starts at register 0x3B, ACCEL_XOUT_H
  AccY=Wire.read()<<8|Wire.read();    //read the registers and shift the bits 8 positions
  AccZ=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();   //stops at register 0x048, GYRO_ZOUT_L
  Serial.print("Accx = ");
  Serial.print(AccX);
  Serial.print(", AccY = ");
  Serial.print(AccY);
  Serial.print(", AccZ = ");
  Serial.print(AccZ);
  Serial.print(", Temp = ");
  Serial.print(Temp/340.00+36.53);
  Serial.print(", GyroX = ");
  Serial.print(GyroX);    // the divition of 131 is from the sensitivity in data sheet
  Serial.print(", GyroY = ");
  Serial.print(GyroY);
  Serial.print(", GyroZ = ");
  Serial.print(GyroZ);
  Serial.println("");
 //at this point i should have the raw values off the chip
   // default at power-up:
  //    Gyro at 250 degrees second
  //    Acceleration at 2g
  //    Clock source at internal 8MHz
  //    The device is in sleep mode.
  //
  //AX 103  AY -340 AZ 1147 GX 47 GY 39 GZ 2  offsets of my sensor


  GyroX = (GyroX - 47);  //gets the Corrected Gyro Rates
  GyroY = (GyroY - 39);
  GyroZ = (GyroZ - 2);
  
  Roll = atan2(AccY,AccZ) * 180/PI;   //calculate the Roll
  Serial.print("Roll = ");
  Serial.print(Roll);
  
  Pitch = atan2(AccX,AccZ) * 180/PI;      //calculate the Pitch
  Serial.print(", Pitch = ");
  Serial.println(Pitch);
  Serial.println("");

  GyroXRate = GyroX - 47;
  GyroXAngle += GyroXRate /131;   //gets the angle from the gyro
  FRoll = 0.98 * (FRoll + GyroXRate*(double)(millis() - timer)/1000) + 0.02 * Roll;
  timer = millis();
  Serial.println("");
  Serial.println(FRoll);
  
  delay(100);
 // }

 
  /*Serial.print("AccXoff = ");   //used to get the average
  Serial.print(AccXoff/20);
  Serial.print(", AccYoff = ");
  Serial.print(AccYoff/20);
  Serial.print(", AccZoff = ");
  Serial.print(AccZoff/20);
  Serial.print(", GyroXoff = ");
  Serial.print(GyroXoff/20);
  Serial.print(", GyroYoff = ");
  Serial.print(GyroYoff/20);
  Serial.print(", GyroZoff = ");
  Serial.println(GyroZoff/20);
  Serial.println("");*/
  
}

