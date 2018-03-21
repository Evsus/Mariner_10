#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

//setup what the wifi is looking for
int status = WL_IDLE_STATUS;
char ssid[] = "DE-Wireless";
unsigned int localPort = ?;

char packetBuffer[255];
WiFiUDP network;

void setup() {
  while(status != WL_CONNECTED);
    status = Wifi.begin(ssid); //if wifi doesn't work, see how to poke out for unbroadcasted ssid's
    delay(10000);
    network.begin(localPort);
}

void loop() {
  // put your main code here, to run repeatedly: note:remember to run WiFiStatus() a lot for loss of signal

}
