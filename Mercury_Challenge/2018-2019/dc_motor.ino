const int pwm = ##### ;	//initializing pin # as pwm
const int MR = ##### ;  //set Right Motor to pin #
const int ML = ##### ;  //set Left Motor to pin #



void setup()
{
pinMode(pwm,OUTPUT) ;  	//we have to set PWM pin as output
pinMode(MR,OUTPUT) ; 	//Logic pins are also set as output
pinMode(ML,OUTPUT) ;
}

void loop()
{
//For Clock wise motion , MR = High , ML = Low

digitalWrite(MR,HIGH) ;
digitalWrite(ML,LOW) ;
analogWrite(pwm,255) ;

/*setting pwm of the motor to 255
we can change the speed of rotaion
by chaning pwm input but we are only
using arduino so we are using higest
value to driver the motor  */
 }