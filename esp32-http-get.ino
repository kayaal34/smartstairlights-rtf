#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WIFI_ADI";
const char* password = "WIFI_SIFRESI";

WebServer server(80);

const int ledPin = 2;

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/plain", "LED Açıldı");
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/plain", "LED Kapatıldı");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
