# Matbotics
Matbotics is a Arduino library to control [Matrix Robotics System controller](http://matrixrobotics.com/2014/10/09/controller-specification/)

The library is under **heavy** development!

Matbotics uses [Arduino I2C master library](http://dsscircuits.com/articles/arduino-i2c-master-library) to support "repeat start".

Online documentation [here](http://blasterbug.github.io/Matbotics/)

### Installation (Unix systems)

Open a terminal and run :

    $ cd <UserDirectory>/Arduino/libraries
    $ git clone https://github.com/blasterbug/Matbotics.git
 
Now after (re)starting the Arduino IDE you shloud see Matbotics in Arduino 
libraries menu.

### Exemple

This exemple shows how to control a servo plugged to the port one

        // import libraries
        #include <Wire.h>
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

### Working

 - Control all servos
 - set speed of all motors
 - timeout function


### TODO

 - Read I2C messages from controller (i.e. battery level, motors encoders 
postions, etc.)
 - Exemples
 - Optimization
