#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Servo.h>

//Wifi vars
int wifiLed = ?; //tbd
int noWifiLed = ?; //tbd
int status = WL_IDLE_STATUS;
char ssid[] = "DE-Wireless";
unsigned int localPort = ?; //tbd
unsigned int remotePort = ?; //tbd
char hostName = "?"; //tbd (computer acting as host)
char packetBuffer[255];
char heartBeat = "<3";
unsigned long int lastHeartBeat = 0;
int twoSeconds = 2000;
WiFiUDP network; //Udp network object

//Servo vars Use it for the arm latter.
Servo SR; //Create servo object Right
Servo SL; //Create servo object Left
int sPin1 = ##; //Set '##' = what pin is being used for the Servo
int sPin2 = ##;

//Motors vars
const int pwm = ##### ;	//initializing pin # as pwm
const int MR = ##### ;  //set Right Motor to pin #
const int ML = ##### ;  //set Left Motor to pin #



//Subroutine to connect to specified ssid(global var)
void getWifi(){
  digitalWrite(wifiLed, LOW);
  digitalWrite(noWifiLed, HIGH);
  while(status != WL_CONNECTED){
    status = Wifi.begin(ssid); //if wifi doesn't work, see how to poke out for unbroadcasted ssid's
    delay(2000);
  }
  network.begin(localPort);
  digitalWrite(noWifiLed, LOW);
  digitalWrite(wifiLed, HIGH);
}

void setup() {
  //setup pins
  pinMode(wifiLed, OUTPUT);
  pinMode(noWifiLed, OUTPUT);
  
  pins for servos?
  
  //Setup Motors
  pinMode(pwm,OUTPUT) ;  	//we have to set PWM pin as output
  pinMode(MR,OUTPUT) ; 	//Logic pins are also set as output
  pinMode(ML,OUTPUT) ;
  
  
  getWifi();
  
 // setup servos
  SR.attach(sPin1); // need to assign pins?
  SL.attach(sPin2);
  //begin servos in halt position
  SR.write(90);
  SL.write(90);
  
}

void loop() {
  //note:remember to run WiFiStatus() a lot for loss of signal test
  status = Wifi.status();
  if(status != WL_CONNECTED){
    getWifi();
  }
  else{
    // if there's data available, read a packet
    int packetSize = network.parsePacket();
    if(packetSize){
      //Send port recived info
      network.beginPacket(network.remoteIP(), network.remotePort();
      network.write("Port: ");
      network.write(network.remotePort());
      network.endPacket();
      //Send packetSize recived
      network.beginPacket(network.remoteIP(), network.remotePort();
      network.write("Packet Size ");
      network.write(packetSize);
      network.endPacket();
      
      // read the packet into packetBufffer
      int length = network.read(packetBuffer, 255);
      remotePort = network.remotePort();
      
      if(length > 0){
        mov = packetBuffer;
        if (mov == <particular button is pressed>){
          SR.write(95); //Move right servo counter clockwise
          SL.write(95);
        }
        if (mov == <particular button is pressed>){
          SR.write(85); //Move right servo clockwise
          SL.write(85);
        }
        if (mov != <forward> || != <backward>){
          SR.write(90);
          SL.write(90);
        }
        if (mov == 'w'){
          //Move Forward
          digitalWrite(MR,LOW) ;
          digitalWrite(ML,HIGH) ;
        }
        if (mov == 's'){
          digitalWrite(MR,HIGH) ;
          digitalWrite(ML,LOW) ;
        }
        if (mov == 'a'){
          digitalWrite(MR,HIGH) ;
          digitalWrite(ML,HIGH) ;
        }
        if (mov == 'd'){
          digitalWrite(MR,LOW) ;
          digitalWrite(ML,LOW) ;
        }
      }
      unsigned long int millis = millis();
      if(millis > lastHeartBeat + twoSeconds){
        lastHeartBeat = millis;
        network.beginPacket(hostName, remotePort);
        network.write(heartBeat);
        network.endPacket();
      }
    }


//://www.binarytides.com/programming-udp-sockets-in-python/
//https://gamedev.stackexchange.com/questions/26840/send-regular-keyboard-samples-or-keyboard-state-changes-over-network