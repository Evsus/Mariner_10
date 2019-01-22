/* https://techtutorialsx.com/2017/11/13/esp32-arduino-setting-a-socket-server/

https://techtutorialsx.com/2018/05/17/esp32-arduino-sending-data-with-socket-client/
*/
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
  WiFi.begin(ssid, psw);
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

//determine input from socket or get wifi if not connected
int check() {
  if(WiFi.status() != WL_CONNECTED){
    getWiFi();
  }
  int packetSize = server.parsePacket(); //is something on the socket
  if(packetSize){ //if there is
    int len = server.read(Packet, 255); //shift it into Packet var and get the length of byte(s)
    if (len > 0){ //seems redundant, but it allows the message to be chomped down
      Packet[len] = 0; //chomp message
      Serial.println(Packet);  //display message
      int input = atoi(Packet); //turn message input expected numeric value
      return input; //give the function the number back
    }
  }
}

void setup() {
 
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT); //Initialize the Led_builtin pin as an output
  digitalWrite(LED_BUILTIN, LOW); //Turn the LED on
  
}
 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); //Turn the LED off by making the voltage HIGH
  getWiFi();
  server.begin(localUdpPort);
 
  while(WiFi.status() == WL_CONNECTED) {
    int mov = check();
    Serial.println(mov);
  }
 
    /*
    client.stop();
    Serial.println("Client disconnected");*/
 
  }
