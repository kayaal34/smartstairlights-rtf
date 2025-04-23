#define PIR_UP 12
#define PIR_DOWN 14
#define LED_START 2  // Başlangıç pini
#define LED_COUNT 10 // 10 LED kullanıyoruz

int leds[LED_COUNT] = {2, 4, 5, 18, 19, 21, 22, 23, 25, 26}; // LED pinleri

void setup() {
  pinMode(PIR_UP, INPUT);
  pinMode(PIR_DOWN, INPUT);

  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  Serial.begin(115200);
}

void loop() {
  if (digitalRead(PIR_UP) == HIGH) {
    Serial.println("Hareket yukarıdan!");
    lightFromTop();
  } else if (digitalRead(PIR_DOWN) == HIGH) {
    Serial.println("Hareket aşağıdan!");
    lightFromBottom();
  }
}

void lightFromTop() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
  }
  delay(3000);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(leds[i], LOW);
    delay(100);
  }
}

void lightFromBottom() {
  for (int i = LED_COUNT - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(200);
  }
  delay(3000);
  for (int i = LED_COUNT - 1; i >= 0; i--) {
    digitalWrite(leds[i], LOW);
    delay(100);
  }
}


