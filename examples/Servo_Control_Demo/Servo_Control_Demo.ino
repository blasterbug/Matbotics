/**
 * # Controlling a servo with Matrix Robotics controller
 *
 * Matrix controller is a Lego Mindstorm NXT device which use I2C
 * to be controlled, so it easy to use it with Arduino boards
 *
 * # Usage
 * - Plug a servo to the controller (port one)
 * - Connect the controller with an Arduino board
 * - Switch on controller, connect the board to your computer
 * - Upload this code to the Arduino
 * - See the magic
*/

// import libraries
//  for I2C/TWI
#include <Wire.h>
//  for Matrics controller
#include <Matbotics.h>

// use the controller
MTController ctlr;

void setup()
{
    // enable servos
    ctlr.enableServos();
    // switchoff timeout
    ctlr.timeout( 0 );
    // set a custom speed for the servo one
    ctlr.servoOneSpeed( 5 );
}

// some variables
int angle = 0;

void loop()
{
    // increase angle and stay in boundaries
    angle = (angle + 10)%250;
    // set the angle to the first servo
    ctlr.servoOneAngle( angle );
    delay( 600 ); 
}