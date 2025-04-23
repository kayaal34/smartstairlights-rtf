#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WIFI_ADI";        // <-- Buraya kendi Wi-Fi ağ adını yaz
const char* password = "WIFI_SIFRESI"; // <-- Buraya şifreni yaz

WebServer server(80);

const int ledPin = 2; // LED pin

void handleRoot() {
  String html = "<h1>Merdiven Işıkları</h1>";
  html += "<p><a href=\"/on\">Aç</a></p>";
  html += "<p><a href=\"/off\">Kapat</a></p>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", "<p>LED Açıldı</p><a href='/'>Geri</a>");
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", "<p>LED Kapatıldı</p><a href='/'>Geri</a>");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi bağlandı!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
  Serial.println("HTTP sunucu başlatıldı");
}

void loop() {
  server.handleClient();
}
