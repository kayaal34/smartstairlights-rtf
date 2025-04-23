#include <Adafruit_NeoPixel.h>
#define MQ2_PIN 13
#define LED_PIN 5
#define NUMPIXELS 10

Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pinMode(MQ2_PIN, INPUT);
  strip.begin();
  strip.show(); // LED'leri kapat
}

void loop() {
  int gazDurumu = digitalRead(MQ2_PIN);

  if (gazDurumu == LOW) { // Gaz var!
    Serial.println("Gaz algılandı!");
    alarmModu();
  } else {
    normalMod();
  }

  delay(2000);
}

void alarmModu() {
  for (int i = 0; i < 3; i++) {
    setAllLEDsColor(255, 0, 0); // Kırmızı
    delay(300);
    strip.clear();
    strip.show();
    delay(300);
  }
}

void normalMod() {
  strip.clear();
  strip.show();
}

void setAllLEDsColor(int r, int g, int b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}
