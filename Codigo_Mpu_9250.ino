#include "MPU9250.h"
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();


// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire, 0x68);
int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while (!Serial) {}

  // start communication with IMU
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while (1) {}
  }
   
 tft.init();
  tft.setRotation(3); // ajustar según la orientación de la pantalla
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  // read the sensor
  IMU.readSensor();
  // display the data
 /* Serial.print(IMU.getAccelX_mss(), 6);
  Serial.print("\t");
  Serial.print(IMU.getAccelY_mss(), 6);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(), 6);
  Serial.print("\t");
  Serial.print(IMU.getGyroX_rads(), 6);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(), 6);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(), 6);
  Serial.print("\t");
  Serial.print(IMU.getMagX_uT(), 6);
  Serial.print("\t");
  Serial.print(IMU.getMagY_uT(), 6);
  Serial.print("\t");
  Serial.print(IMU.getMagZ_uT(), 6);
  Serial.print("\t");
  Serial.println(IMU.getTemperature_C(), 6);
  delay(100);
*/

  // actualizar la pantalla con los datos
  tft.setCursor(0, 0);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  tft.print("Aceleración (mg):");
  tft.setCursor(0, 16);
  tft.print(IMU.getAccelX_mss(), 6);
  tft.print(" ");
  tft.print(IMU.getAccelY_mss(), 6);
  tft.print(" ");
  tft.println(IMU.getAccelZ_mss(), 6);

  tft.setCursor(0, 32);
  tft.print("Giroscopio (rad/s):");
  tft.setCursor(0, 48);
  tft.print(IMU.getGyroX_rads(), 6);
  tft.print(" ");
  tft.print(IMU.getGyroY_rads(), 6);
  tft.print(" ");
  tft.println(IMU.getGyroZ_rads(), 6);

  tft.setCursor(0, 64);
  tft.print("Magnetómetro (uT):");
  tft.setCursor(0, 80);
  tft.print(IMU.getMagX_uT(), 6);
  tft.print(" ");
  tft.print(IMU.getMagY_uT(), 6);
  tft.print(" ");
  tft.println(IMU.getMagZ_uT(), 6);

  tft.setCursor(0, 96);
  tft.print("Temperatura (°C):");
  tft.setCursor(0, 112);
  tft.print(IMU.getTemperature_C(), 6);

  // ...

  delay(100);
}
