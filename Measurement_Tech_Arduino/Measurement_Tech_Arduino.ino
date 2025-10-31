#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);

void setup()
{
 Serial.begin(9600);
}

float range_previous = 0;

void loop()
{

  int rn = range_noise();
  int r = range();
  float rb = (float)rn*0.2 + range_previous*0.8; // binomial filtering with 20%/80% weighing
  
  range_previous = rb; //update previous value for filtering

  
 Serial.print(rn); //signal with added noise
 Serial.print(" ");
 Serial.print(rb); //signal & noise and binomial filtering
 Serial.print(" ");
 Serial.println(r); //pure signal
 delay(200);

 

}

int range() {
  return ultrasonic.MeasureInCentimeters();
}

int range_noise(){
  return ultrasonic.MeasureInCentimeters() + random(10);
}