<H1>Arduino Quadcopter</H1>

=======
Arduino Based Flight Controller Running a Quadcopter
The Arduino is a flexbile system that enables quick and easy manipulation of many different electronic components such as sensors, motors, LEDs, etc. Because of this Arduinos are commonly used in DIY projects. In this case, the Arduino will be combined with an accelerometer and gyrometer to create an accuruate measurement of postition. With theses measurements, the Arduino will send signals to four motors attached to an x-frame which will in turn produce stable flight. This forms the basis for a functional quadcopter flight controller.

<H2>Parts</H2>
<ul>
<li>1 of : KYPOM 3300mah 3S 35~70C Lipo Pack [Lipo Battery]</li>
<li>4 of : Motor AC2836-358, 880Kv (jDrones improved)[Brushless Motor]</li>
<li>4 of : New jDrones 20A ESC (updated Firmware)[Electronic Speed Controller]</li>
<li>2 of : Propeller set 12X45 EPP Style (Black)[Propellers]</li>
<li>1 of : SparkFun Triple Axis Accelerometer & Gyro Breakout (MPU-6050)[Accelerometer & Gyrometer]</li>
<li>1 of : Arduino Uno</li>
</ul>


<H2>Copyright</H2>

This is an open source project with rights to the public to download, change, and modify without further consent. For further information on copyright please refer to the license document.

<H2>User Manual</H2>
1. Connect the MPU-6050 sensor to the Arduino Uno following the circuit diagram.
2. Run the MPU6050_Calibration.ino file with the MPU-6050 connected on a flat, level surface.
3. Input the offset values of your chip (every chip is different) into IMU_Flight_Test.ino.
4. Run the ESC_4motor_init.ino program on the Arduino Uno with everything connected (do not run this program twice because the Motors will start at full power).
5. Run the IMU_Flight_Test.ino program. This program will promt if there are errors with sensor.
6. Give serial input to start the IMU_Flight_Test.ino program and values should be comming on screen.
7. To control use keyboard serial input: <ul><li>1,2,3 are decrement speed for all</li> <li>4,5,6 are increment speed for all</li> <li>q,w control the speed of front right motor</li> <li>e,r control the speed of front left motor</li> <li>a,s control the speed of back left motor</li> <li>d,f control the speed of back right motor</li> <li>k will kill the program and detach the motors.</li></ul>

<H2>Software Used</H2>
<ul>
  <li>Arduino IDE</li>
  <li>https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050</li>
</ul>

<H2>Contact Info</H2>

<H5>Ryan Kopp</H5>
<ul>
  <li>email: ryank1030@gmail.com</li>
</ul>

<H5>Duane Classen</H5>
<ul>
  <li>email: d.classen95@gmail.com</li>
</ul>

