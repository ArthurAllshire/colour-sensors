#include <QTRSensors.h>

// This example is designed for use with eight RC QTR sensors. These
// reflectance sensors should be connected to digital pins 3 to 10. The
// sensors' emitter control pin (CTRL or LEDON) can optionally be connected to
// digital pin 2, or you can leave it disconnected and remove the call to
// setEmitterPin().
//
// The main loop of the example reads the raw sensor values (uncalibrated). You
// can test this by taping a piece of 3/4" black electrical tape to a piece of
// white paper and sliding the sensor across it. It prints the sensor values to
// the serial monitor as numbers from 0 (maximum reflectance) to 2500 (minimum
// reflectance; this is the default RC timeout, which can be changed with
// setTimeout()).

QTRSensors qtr_front;
QTRSensors qtr_back;

const uint8_t SensorCount = 7;
uint16_t sensorValuesFront[SensorCount];
uint16_t sensorValuesBack[SensorCount];

void setup()
{
  // configure the sensors
  qtr_front.setTypeRC();
  qtr_front.setSensorPins((const uint8_t[]){22, 25, 26, 29, 30, 33, 34}, SensorCount);
  qtr_back.setTypeRC();
  qtr_back.setSensorPins((const uint8_t[]){40, 43, 44, 47, 48, 51, 52}, SensorCount);

  Serial.begin(9600);
}

void printSensorValues(uint16_t sensorValues[], char leadChar)
{
  Serial.print(leadChar);
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print(','); 
  }
  Serial.println();
}



void loop()
{
  // read raw sensor values
  qtr_front.read(sensorValuesFront);
  qtr_back.read(sensorValuesBack);
  printSensorValues(sensorValuesFront, 'f');
  printSensorValues(sensorValuesBack, 'b');
  Serial.flush();
  delay(1000);
}
