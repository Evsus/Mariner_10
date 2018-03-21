/*****
  If we have continuous rotation servos, 
  [servo object].write(0) = spin at counter clockwise at full speed
  [servo object].write(90) = stop
  [servo object].write(180) = spin clockwise at full speed
*****/

--------------------------------------------------------------------------------
Actual code below
--------------------------------------------------------------------------------

#include <Servo.h>

Servo SR; //Create servo object Right
Servo SL; //Create servo object Left

int sPin1 = ##; //Set '##' = what pin is being used for the Servo
int sPin2 = ##;

void setup(){
Serial.begin(9600); //Open serial port and set BPS to 9600

SR.attach(sPin1); //
SL.attach(sPin2);

SR.write(90); //Stop the servos initially
SL.write(90);

}

void loop(){
   if (Serial.available()){
      mov = Serial.read();
         while (mov == <particular button is pressed>){
            SR.write(95); //Move right servo counter clockwise
            SL.write(95);
            }
         while (mov == <particular button is pressed>){
            SR.write(85); //Move right servo clockwise
            SL.write(85);
         }
         while (mov != <forward> || != <backward>){
            SR.write(90);
            SL.write(90);
         }
   }
}
/* the <> tags are not used at all in final code, they are just used to bring a visual flag to where there is still some psuedo code*/
