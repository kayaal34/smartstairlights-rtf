#include <WiFi.h>
#include <DHT.h>
#include <Firebase_ESP_Client.h>

// WiFi ayarları
#define WIFI_SSID "WiFi_ADINIZ"
#define WIFI_PASSWORD "WiFi_SIFRENIZ"

// Firebase ayarları
#define DATABASE_URL "https://senin-projen.firebaseio.com/" 
#define DATABASE_SECRET "senin-secret-key"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

#define DHTPIN 4     
#define PIRPIN 12     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(PIRPIN, INPUT);
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("WiFi bağlı!");

  config.database_url = DATABASE_URL;
  config.signer.tokens.legacy_token = DATABASE_SECRET;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  float t = dht.readTemperature();
  int motion = digitalRead(PIRPIN);

  if (Firebase.ready()) {
    Firebase.RTDB.setFloat(&fbdo, "/sensor/sicaklik", t);
    Firebase.RTDB.setInt(&fbdo, "/sensor/hareket", motion);
  }

  delay(5000); // 5 saniyede bir güncelle
}

