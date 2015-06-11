# Matbotics
Matbotics is a Arduino library to control [Matrix Robotics System controller].  
Matbotics uses [Arduino I2C master library] to support _repeat start_, 
because Wire library (issued with the Arduino IDE) does not.

[Online documentation]

### Features

- Get battery level, controller status, version, etc.
- Control all servos
- set speed of all motors
- set motor target
- read motors encoders value
- timeout function

### Installation (Unix like systems)

Open a terminal and run :
```bash
$ cd <UserDirectory>/Arduino/libraries
$ git clone https://github.com/blasterbug/Matbotics.git
```

Now after (re)starting the Arduino IDE you shloud see Matbotics in Arduino 
libraries menu.

### Exemple

This exemple shows how to control a servo plugged to the port one

```arduino
// import libraries
#include <I2C.h>
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
```

### TODO

 - More exemples
 - Optimization?


[Arduino I2C master library]: http://dsscircuits.com/articles/arduino-i2c-master-library
[Matrix Robotics System controller]: http://matrixrobotics.com/2014/10/09/controller-specification/
[Online documentation]: http://blasterbug.github.io/Matbotics/
