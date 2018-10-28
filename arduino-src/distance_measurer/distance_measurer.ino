/*
 * Code to pull the distance from an ultrasonic sensor
 * and show it on a 4 digit display.
 */

 #include <TM1637Display.h>

 const int DISP_CLK = 9;
 const int DISP_DIO = 8;

 TM1637Display display(DISP_CLK, DISP_DIO);

void setup() {
  display.setBrightness(0x0a); // Max brightness

}

void loop() {
  display.showNumberDec(999);
  delay(1000);
}
