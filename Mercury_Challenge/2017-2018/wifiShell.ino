#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

//setup what the wifi is looking for
int status = WL_IDLE_STATUS;
char ssid[] = "DE-Wireless";
unsigned int localPort = ?; //?
unsigned int remotePort = ?; //?
char hostName = "?"; //?

char packetBuffer[255];
WiFiUDP network;

void getWifi(){ //Subroutine to connect to specified ssid(global var)
  while(status != WL_CONNECTED){
    status = Wifi.begin(ssid); //if wifi doesn't work, see how to poke out for unbroadcasted ssid's
    delay(10000);
  }
  network.begin(localPort);
}

void setup() {
  getWifi();
}

void loop() {
  //note:remember to run WiFiStatus() a lot for loss of signal test
  status = Wifi.status();
  if(status != WL_CONNECTED){
    //set LED to on state to display robot is searching for network.
    getWifi();
  }
  else{
    int packetSize = network.parsePacket();
    if(packetSize){
      int length = network.read(packetBuffer, 255);
      remotePort = network.remotePort();
      if(length > 0){
        packetBuffer[length] = 0;
      }
    }
    network.beginPacket(hostName, remotePort);
    network.write(heartBeat);
    network.endPacket();
  }


//://www.binarytides.com/programming-udp-sockets-in-python/
//https://gamedev.stackexchange.com/questions/26840/send-regular-keyboard-samples-or-keyboard-state-changes-over-network