/* 
 * References: https://forum.arduino.cc/index.php?topic=100421.0
 * This code changes the color of the RGB LED based on the amount of force applied.
 * 
 */

int fsrAnalogPin = A0; // FSR is connected to analog 0

int redpin = 11;      // connect ___ LED to pin 11 (PWM pin)
int greenpin = 10;      // connect ___ LED to pin 10 (PWM pin)
int bluepin = 9;      // connect ___ LED to pin 9 (PWM pin)

int fsrValue;      // the analog reading from the FSR resistor divider

int red, green, blue;
int rgbValue;

void setup(void) {
 Serial.begin(9600); 
 pinMode(redpin, OUTPUT);
 pinMode(greenpin, OUTPUT);
 pinMode(bluepin, OUTPUT);
 pinMode(fsrAnalogPin, INPUT);
}

void loop()
{
  //Get the analog reading from the FSR
  fsrValue = analogRead(fsrAnalogPin);
  rgbValue = map(raw, 0, 1000, 0, 765);

  //Assign the readings to each pin depending on the range they fall within.
  //Also allows for overlapping of colors to have a smooth transition.
  if (rgbValue <= 255) {
    red = rgbValue;
    green = 0;
    blue = 0;
  }
  // Readings from 
  if (rgbValue > 255 && rgbValue <= 510) {
    red = 510 - rgbValue;
    green = rgbValue - 255;
    blue = 0;
  }
  if (rgbValue > 510 && rgbValue <= 765) {
    red = 0;
    green = 765 - rgbValue;
    blue = rgbValue - 510;
  }

  //Write the values to each pin
  analogWrite(redpin, red);
  analogWrite(greenpin, green);
  analogWrite(bluepin, blue);
}
