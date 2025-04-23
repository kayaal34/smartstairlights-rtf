#include "time.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600 * 3; // Türkiye için GMT+3
const int   daylightOffset_sec = 0;

void setup(){
  Serial.begin(115200);
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Saat alınamadı");
    return;
  }

  int hour = timeinfo.tm_hour;

  if(hour >= 22 || hour < 6){
    Serial.println("Gece modu aktif");
    // LED parlaklık düşür
  } else {
    Serial.println("Gündüz modu aktif");
    // Normal aydınlatma
  }

  delay(60000); // her dakika kontrol
}

