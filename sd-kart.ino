#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(115200);
  SD.begin(5); // CS pini

  File dosya = SD.open("/log.txt", FILE_WRITE);
  if (dosya) {
    dosya.println("Sistem başlatıldı.");
    dosya.close();
  }
}

void loop() {
  float volt = analogRead(A0) * (3.3 / 4095.0); // varsayılan gerilim ölçüm
  File dosya = SD.open("/log.txt", FILE_WRITE);
  if (dosya) {
    dosya.print("Volt: ");
    dosya.println(volt);
    dosya.close();
  }

  delay(10000);
}
