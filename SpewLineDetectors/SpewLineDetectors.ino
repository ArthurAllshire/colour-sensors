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

QTRSensors qtr;

const uint8_t SensorCount = 14;
uint16_t sensorValues[SensorCount];

void setup()
{
  // configure the sensors
  qtr.setTypeRC();
    qtr.setSensorPins((const uint8_t[]){22, 25, 26, 29, 30, 33, 34, 38, 40, 44, 43, 41, 47, 48}, SensorCount);

  //qtr.setSensorPins((const uint8_t[]){22, 25, 26, 29, 30, 33, 34, 38, 40, 41, 43, 44, 47, 48}, SensorCount);
  qtr.setTimeout(32767);

  Serial.begin(115200);
}


void loop()
{
  // read raw sensor values
  qtr.read(sensorValues);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print(',');
  }
  Serial.print("\n");
  Serial.flush();
}
