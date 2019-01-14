#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Servo.h>

//wifi Vars
char ssid[] = "MERCURY";
char psw[] = "";
int noWiFi = 4;
int yesWiFi = 14;

//UDP vars
WiFiUDP server;
unsigned int localUdpPort = 3702;
char Packet[255];

//Servo vars
Servo TL;
Servo TR;
Servo AX;
int AXdeg = 65;
Servo AY;
int AYdeg = 170;
Servo AZ;
int AZdeg = 20;
Servo claw;
int clawdeg = 100;

//get wifi
void getWiFi(){
  //turn servos off
  TL.write(90);
  TR.write(90);
  digitalWrite(noWiFi, HIGH);
  digitalWrite(yesWiFi, LOW);
  Serial.println();
  //get wifi and display waiting period in Serial monitor
  WiFi.begin(ssid, psw);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
  }
  Serial.println();
  //display local IP address
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(noWiFi, LOW);
  digitalWrite(yesWiFi, HIGH);
}

int check(){//determine input from socket or get wifi if not connected
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
void setup(){
  //attach servos and set start position;
  Serial.begin(115200);
  pinMode(noWiFi, OUTPUT);
  pinMode(yesWiFi, OUTPUT);
  TL.attach(16);
  TR.attach(12);
  AX.attach(0);
  AY.attach(13);
  AZ.attach(5);
  claw.attach(2);
  AX.write(AXdeg);
  AY.write(AYdeg);
  AZ.write(AZdeg);
  claw.write(clawdeg);
}

void loop() {
  getWiFi();
  server.begin(localUdpPort);
  while(WiFi.status() == WL_CONNECTED){
    int mov = check();
      while(mov == 10){ //stop
        TL.write(90);
        TR.write(90);
        mov = check(); 
      }
      while(mov == 119){ //forward
        TL.write(0);
        TR.write(180);
        mov = check(); 
      }
      while(mov == 116){ //backwards
        TL.write(180);
        TR.write(0);
        mov = check(); 
      }
      while(mov == 97){ //turn left
        TL.write(180);
        TR.write(180);
        mov = check(); 
      }
      while(mov == 100){ //turn right
        TL.write(0);
        TR.write(0);
        mov = check(); 
      }
      while(mov == 4){ //AXleft
        AXdeg = AXdeg - 2;
        AX.write(AXdeg);
        Serial.println(AX.read());
        mov = check(); 
      }
      while(mov == 2){ //AXright
        AXdeg = AXdeg + 2;
        AX.write(AXdeg);
        Serial.println(AX.read());
        mov = check(); 
      }
      while(mov == 3){ //AYdown
        AYdeg = AYdeg + 2;
        AY.write(AYdeg);
        Serial.println(AY.read());
        mov = check(); 
      }
      while(mov == 1){ //AYup
        AYdeg = AYdeg - 2;
        AY.write(AYdeg);
        Serial.println(AY.read());
        mov = check(); 
      }
      while(mov == 6){ //AZup
        AZdeg = AZdeg + 2;
        AZ.write(AZdeg);
        Serial.println(AZ.read());
        mov = check();
      }
      while(mov == 5){ //AZdown
        AZdeg = AZdeg - 2;
        AZ.write(AZdeg);
        Serial.println(AZ.read());
        mov = check(); 
      }
      while(mov == 7){ //claw close
        clawdeg = clawdeg + 2;
        claw.write(clawdeg);
        Serial.println(claw.read());
        mov = check(); 
      }
      while(mov == 8){ //claw open
        clawdeg = clawdeg - 2;
        claw.write(clawdeg);
        Serial.println(claw.read());
        mov = check(); 
      }
    }
  }
