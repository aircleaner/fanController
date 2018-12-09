#include <Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// For temperature
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS_PIN 2
// Setup a oneWire instance to communicate with any OneWire devices (not just
// Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS_PIN);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// For FAN
#define FAN_CONTROL_PIN 3

void setupFan()
{
  TCCR2A = 0x23;
  // Select clock
  TCCR2B = 0x09;
  // Aiming for 25kHz
  OCR2A = 79;
  // Enable the PWM output on FAN_CONTROL_PIN
  pinMode(FAN_CONTROL_PIN, OUTPUT);
  // Set PWM duty cycle (31 = 25%)
  OCR2B = 1;
}

void setupTemp()
{
  Serial.println("Arduino Digital Temperature // Serial Monitor Version");
  sensors.begin();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupFan();
  setupTemp();
}

void loop() {
  // put your main code here, to run repeatedly:

  float temp = 0.0f;
  // Send the command to get temperatures
  sensors.requestTemperatures();
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers
  // to the first IC on the wire
  temp = sensors.getTempCByIndex(0);
  Serial.print("Temperature is: ");
  Serial.println(temp);
  if (temp > 30)
  {
    OCR2B = 120;
  }
  else
  {
    OCR2B = 31;
  }

  // Update every 5 sec.
  delay(5000);

  //  OCR2B = 120;
  //  Serial.print("Setting OCR2B to: ");
  //  Serial.print(OCR2B);
  //  Serial.print("\n");
  //  delay(5000);
  //  OCR2B = 31;
  //  Serial.print("Setting OCR2B to: ");
  //  Serial.print(OCR2B);
  //  Serial.print("\n");
  //  delay(5000);
}
