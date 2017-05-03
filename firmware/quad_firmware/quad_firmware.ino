#include "radio.h"
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_Simple_AHRS.h>

typedef struct {
  int magic;
  int throttle;
  int yaw;
  int pitch;
  int roll;
  int pot1;
  int pot2;
} Controller;


Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

Adafruit_Simple_AHRS ahrs(&lsm.getAccel(), &lsm.getMag(), &lsm.getGyro() );
void initializeSensor()
{
  //Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);

  //Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);

}


void setup()
{
  Serial.begin(115200);
  rfBegin(11);
  initializeSensor();
}

void loop()

{

 // analogWrite(PWM1, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
 // analogWrite(PWM2, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
 // analogWrite(PWM3, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
 // analogWrite(PWM4, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255


  if (rfAvailable())  
  {
    rfRead((uint8_t*) (&control), sizeof(struct Controller));
    if(control.magic != 0xFFFF){
      return;
    }
    //rfWrite(Serial.read()); // ...send it out the radio.
  }
 
}

