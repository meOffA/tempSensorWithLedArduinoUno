#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();

const int ledPin =  7;// the number of the LED pin

int ledState = LOW;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }
  Serial.println("Adafruit AM2320 Basic Test");
  am2320.begin();
  pinMode(ledPin, OUTPUT);
}

float temp;

void loop() {
    temp = am2320.readTemperature();
    check_temp();
    Serial.println(temp);
    delay(1000);
}
void check_temp() {
    if (temp > 25) {
        digitalWrite(ledPin, HIGH);
      }
    else {
      digitalWrite(ledPin, LOW);
      }
  }