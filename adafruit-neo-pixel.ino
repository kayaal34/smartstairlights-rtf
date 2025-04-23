#include <Adafruit_NeoPixel.h>

#define PIN 5           // Data pini
#define NUMPIXELS 10    // LED sayısı

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Tüm LED'leri kapat
}

void loop() {
  // Merdiven yukarıdan aşağı akış efekti (mavi)
  for(int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255)); // Mavi
    strip.show();
    delay(150);
  }

  delay(2000);

  // Merdiveni söndür
  for(int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, 0); // LED'i kapat
    strip.show();
    delay(100);
  }

  delay(2000);
}

