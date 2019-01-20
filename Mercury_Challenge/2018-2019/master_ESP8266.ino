#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//Wifi Vars
char ssid[] = "DE-Wireless";
char psw[] = "";

//UDP vars
WiFiUDP server;
unsigned int localUdpPort = 3702;
char Packet[255];

void getWiFi() {
  //get wifi and displya waitng perdiod in serial monitor
  Wifi.begin(ssid, psw);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  //dISPLAY LOCAL ip Address
  Serial.print(WiFi.status());
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
}

void setup() {
 
  Serial.begin(115200);
  
}
 
void loop() {
  getWiFi();
  wifiServer.begin(localUdpPort);
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        Serial.println(c);
        client.write(c);
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
}