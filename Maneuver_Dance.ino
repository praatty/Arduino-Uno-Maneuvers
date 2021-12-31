/* Robotics with the shield - ManeuverSequence 
 *  Move forward, left, right, then backward with an array and the
 *  maneuver function.
 */

#include <Servo.h>;     // Include servo library 
Servo servoLeft;
Servo servoRight;
            //        forward     left       backward    stop
            //  index  0            1          3          4   
int speedsLeft[] =    {200,      -200,        200,       0};
int speedsRight[]=    {200,       200,        200,       0};
int times[]      =    {2000,      900,        2000,      -1}; 


void setup()                   // Built-in initialization block
{
tone(4, 3000, 1000);          // Play tone for 1 second 
delay(1000);                 // Delay to finish tone

 servoLeft.attach(11);      // Attach left signal to pin 11
 servoRight.attach(12);    // Attach right signal to pin 12
int elementCount = sizeof(times) / sizeof(int);

for(int index = 0; index < elementCount; index++)
{
  maneuver(speedsLeft[index], speedsRight[index], times[index]);
}
}
void loop()
{
}
void maneuver(int speedLeft, int speedRight, int Time)
{ 
        //speedLeft, speedRight ranges: Backward Linear   Stop   Linear  Forward
        //                                -200    -100.....0......100      200
servoLeft.writeMicroseconds(1500 + speedLeft);
servoRight.writeMicroseconds(1500 - speedRight);
if(Time==-1)
{
  servoLeft.detach();
  servoRight.detach();
}
delay(Time);
}
