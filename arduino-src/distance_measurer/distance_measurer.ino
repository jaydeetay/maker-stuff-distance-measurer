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
const int SLEEP_TIME_MILLIS = 10;

TM1637Display display(DISP_CLK, DISP_DIO);
SR04 sr04 = SR04(SENS_ECHO, SENS_TRIG);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0a); // Max brightness
}

class Smoother {
  public:
    Smoother(double lambda) : last_value_(-1), lambda_(lambda) {}
    long smooth_me(long value) {
      if (last_value_ == -1) {
        last_value_ = value;
        return value;
      } else {
        long new_value = lambda_ * value + (1-lambda_) * last_value_;
        last_value_ = new_value;
        return new_value;
      }
    }
    private:
    long last_value_;
    double lambda_;
};

Smoother smoother(0.5);

void loop() {
  long dist_cm = smoother.smooth_me(sr04.Distance());
  Serial.print(dist_cm);
  Serial.println("cm");
  display.showNumberDec(dist_cm);
  delay(SLEEP_TIME_MILLIS);
}
