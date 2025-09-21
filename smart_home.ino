#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "YourWiFiSSID";        // Your WiFi SSID
char pass[] = "YourWiFiPassword";    // Your WiFi Password

#define DHTPIN D4                    // Pin connected to DHT11
#define DHTTYPE DHT11

#define RELAY_PIN D2                 // Relay Module control pin

DHT dht(DHTPIN, DHTTYPE);

BLYNK_WRITE(V1) {                    // Virtual pin V1 controls relay
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN, relayState);
}

void sendSensorData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }
  
  Blynk.virtualWrite(V2, temperature);  // Send temperature to app
  Blynk.virtualWrite(V3, humidity);     // Send humidity to app
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  sendSensorData();
  delay(2000);  // Send data every 2 seconds
}
