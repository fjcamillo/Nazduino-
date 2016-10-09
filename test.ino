#include <Servo.h>


Servo aileron; 
Servo throttle;
Servo rudder;
Servo elevator;
//int pos = 0;
int i=0;

void setup() {
  aileron.attach(9);
  throttle.attach(11);
  rudder.attach(12);
  elevator.attach(10);
  Serial.begin(9600);
}

void loop() {
//
//  throttle.write(95);
//  aileron.write(90);
//  rudder.write(92);
//  elevator.write(90);
//  int o;
//  o = throttle.read();
//  Serial.println(o);
//  delay(5000);
testFlight();

}

void testFlight(){
  Serial.println("Testflight");
  aileron.write(90);
  elevator.write(90);
  throttle.write(95);
  rudder.write(92);
  delay(1000);
  Serial.println("reduce to engage");
  aileron.write(173);
  elevator.write(173);
  throttle.write(173);
  rudder.write(30);
  delay(1000);
  Serial.println("engaging");
  delay(2000);
  aileron.write(90);
  elevator.write(90);
  throttle.write(140);
  rudder.write(92);
  delay(1000);
  Serial.println("increasing thrust");
  for(int i=140;i>=30;i--){
    throttle.write(i);
    Serial.println(i);
    delay(250);}
}

/*#############################################################
*Functions for the Drone movement
*#############################################################
*/

// 1. Throttle Up
// 2. Throttle Down
// 3. Aileron Left
// 4. Aileron Right

// 5. Rudder Up
// 6. Rudder Down
// 7. Elevator Left
// 8. Elevator Right

// Main Parameters ~ Frequency, port number, 

//Engage
void Engage(){
  throttle.write(0);
  aileron.write(180);
  rudder.write(180);
  elevator.write(180);
  delay(1000);
  throttle.write(0);
  aileron.write(0);
  rudder.write(0);
  elevator.write(360);
}

void return_to_normal(){
  aileron.write(180);
  rudder.write(180);
  elevator.write(180);
}

void lift(){
  for(i = 0; i <= 360; i++){
    throttle.write(i);
    delay(100);
    if(i==180){
      delay(2500);  
    }
  }
  delay(5000);
  
}
