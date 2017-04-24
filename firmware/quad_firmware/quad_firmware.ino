

int PWM1 = 1;
int PWM2 = 2;
int PWM3 = 3;
int PWM4 = 4;

int throtVal = 0;



void setup()

{


}



void loop()

{


  analogWrite(PWM1, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(PWM2, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(PWM3, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(PWM4, throtVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255


   if (Serial.available())  
  {
    rfWrite(Serial.read()); // ...send it out the radio.
  }
  if (rfAvailable())  // If data received on radio...
  {
    Serial.print(rfRead());  // ... send it out serial.
    throtVal = rfRead());
  }


}

