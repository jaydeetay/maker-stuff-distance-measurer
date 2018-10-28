/*
   Code to pull the distance from an ultrasonic sensor
   and show it on a 4 digit display.
*/

#include <SR04.h>
#include <TM1637Display.h>

const int DISP_CLK = 9;
const int DISP_DIO = 8;
const int SENS_TRIG = 10;
const int SENS_ECHO = 11;

TM1637Display display(DISP_CLK, DISP_DIO);
SR04 sr04 = SR04(SENS_ECHO, SENS_TRIG);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0a); // Max brightness
}

void loop() {
  long dist_cm = sr04.Distance();
  Serial.print(dist_cm);
  Serial.println("cm");
  display.showNumberDec(dist_cm);
  delay(100);
}
