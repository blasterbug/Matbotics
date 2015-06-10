/**
 * @file
 *
 * @section desc File description
 *
 * Control Matrix Robotics System Motor & Servo controller with an Arduino board
 *
 * @section copyright Copyright
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * @date 2015/04/20
 * @author Benjamin Sientzoff
 * @version 0.1
 *
 *
 * \page info Servos Control
 *
 * The Servo 1/2/3/4 speed bytes allow the rate, at which changes to the
 * servo positions are made, to be controlled. If the value is set to zero,
 * changes to the servo position is immediate. If the value is non-zero,
 * changes will occur at a rate equal 10*value milliseconds per step.
 * The angle range is from 0 to 250 corresponding of the pulse ariation (to set
 * the angle) between 0.75ms and 2.25ms.
 *
 */


#ifndef _MATBOTICS_H_
#define _MATBOTICS_H_

// matbotics address
#define CONTROLLER_ADDRESS  0x08
// register address to write in to control motors/servos
// for more details see MatriX Controller specification
// controller vars
/// controller firmware version
#define MTBS_VRS            0x00
/// controller manufacturer name
#define MTBS_MANU           0x08
/// controller type 
#define MTBS_TYPE           0x10
/// controller status 
#define MTBS_STATUS         0x41
/// set timeout
#define MTBS_TIME_OUT       0x42
/// get battery level
#define MTBS_BATT_LEVEL     0x43
/// set motors start flag ? (see doc)
#define MTBS_STRT_FLAG      0x44
// servos commands
#define MTBS_SERVOS_STATE   0x45
/**
 * actived all servos
 * Matrix Controller uses for bits to enable each one.
 *   SERVOS  1   2   3   4
 *   0xF     1   1   1   1
 */
#define MTBS_USE_ALL_SERVOS 0xF
// desactived all servos
#define MTBS_USE_NO_SERVO   0x0
//  SERVO 1
#define MTBS_SRV1_SPEED     0x46
#define MTBS_SRV1_TRGT      0x47
//  SERVO 2
#define MTBS_SRV2_SPEED     0x48
#define MTBS_SRV2_TRGT      0x49
//  SERVO 3
#define MTBS_SRV3_SPEED     0x4A
#define MTBS_SRV3_TRGT      0x4B
//  SERVO 4
#define MTBS_SRV4_SPEED     0x4C
#define MTBS_SRV4_TRGT      0x4D
// motors commands
//  MOTOR 1
#define MTBS_MTR1_POS       0x4E
#define MTBS_MTR1_TRGT      0x52
#define MTBS_MTR1_SPEED     0x56
#define MTBS_MTR1_MODE      0x57
//  MOTOR 2
#define MTBS_MTR2_POS       0x58
#define MTBS_MTR2_TRGT      0x5C
#define MTBS_MTR2_SPEED     0x60
#define MTBS_MTR2_MODE      0x61
//  MOTOR 3
#define MTBS_MTR3_POS       0x62
#define MTBS_MTR3_TRGT      0x66
#define MTBS_MTR3_SPEED     0x6A
#define MTBS_MTR3_MODE      0x6B
//  MOTOR 4
#define MTBS_MTR4_POS       0x6C
#define MTBS_MTR4_TRGT      0x70
#define MTBS_MTR4_SPEED     0x74
#define MTBS_MTR4_MODE      0x75

/**
 * motor modes
 * \todo read/set motor modes
 */
enum MTBS_MOTOR_MODES {
    /// Float mode
    MTBS_MTR_MODE_FLOAT = 0x0,
    /// Brake mode
    MTBS_MTR_MODE_BRAKE,
    /// Speed mode
    MTBS_MTR_MODE_SPEED,
    /// Slew mode
    MTBS_MTR_MODE_SLEW          
};

/**
 * Controller status
 */
enum MTBS_STATUS_VALUE {
    MTBS_STATUS_OK = 0,
    MTBS_STATUS_FAULT, // fault status
    MTBS_STATUS_LOWBATT  // low battery
};

/**
 * MTController
 * object to encapsulate Matrix Robotic System controller control
 */
class MTController
{
    public:
    
    /**
    * Create MTController object
    */
    MTController();
    
    /**
     * Get the controller version manufacturer
     * @return Controller version manufacturer
     */
    String manufacturer();
    /**
     * Get the controller version type
     * @return Controller version type
     */
    String type();
    /**
     * Get the controller version number
     * @return Controller version number
     */
    String version();
    
    /**
     * Get battery level
     * @return The Battery level returns the current battery voltage in volts.
     */
    float batteryLevel();
    
    /**
     * Return the status of the box
     * @return the status of the controller
     */
    MTBS_STATUS_VALUE status();
    
    /**
     * Shut down motors and servos automaticcally within if no I2C transactions
     * are received within the specified time, in the seconds
     * @param time Amount of time to shut down automatically motors and 
     * servos in seconds. Zero (0) means no timeout.
     */
    void timeout( int time );
    
    /**
     * enable servo motors
     */
    void enableServos();
    
    /**
     * disable servos
     */
    void disableServos();
    
    /**
     * Set speed of the servo one
     * @param servo_speed the speed to set
     */
    void servoOneSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo one
     * @param angle angle to reach
     */
    void servoOneAngle( int angle );
    
    /**
     * Set speed of the servo two
     * @param servo_speed the speed to set
     */
    void servoTwoSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo two
     * @param angle angle to reach
     */
    void servoTwoAngle( int angle );
    
    /**
     * Set speed of the servo three
     * @param servo_speed the speed to set
     */
    void servoThreeSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo three
     * @param angle angle to reach
     */
    void servoThreeAngle( int angle );
    
    /**
     * Set speed of the servo four
     * @param servo_speed the speed to set
     */
    void servoFourSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo four
     * @param angle angle to reach
     */
    void servoFourAngle( int angle );
    
    /**
     * Set the speed of the motor one, zero (0) causes the motor to stop.
     * @param motor_speed The speed of the motor ( from -100 to 100 )
     */
    void motorOneSpeed( int motor_speed );
    
    /**
     * get the position of the motor one
     * @return Value of the current motor encoder value from 0 to 250
     */
    int motorOnePosition();
    
    /**
     * Set the position of the motor one encoder, if the motor is in *slew* mode.
     * @param target Position to reach
     */
    void motorOneReach( int target );
    
    /**
     * Set the motor one mode 
     * @param mode the mode for the motor one
     */
    void motorOneMode( MTBS_MOTOR_MODES mode );
    
    /**
     * Set the speed of the motor two, zero (0) causes the motor to stop.
     * @param motor_speed The speed of the motor ( from -100 to 100 )
     */
    void motorTwoSpeed( int motor_speed );
    
    /**
     * get the position of the motor two
     * @return Value of the current motor encoder value from 0 to 250
     */
    int motorTwoPosition();
    
    /**
     * Set the position of the motor two encoder, if the motor is in *slew* mode.
     * @param target Position to reach, value ranging from 0 to 250.
     */
    void motorTwoReach( int target );
    
    /**
     * Set the motor two mode 
     * @param mode the mode for the motor two
     */
    void motorTwoMode( MTBS_MOTOR_MODES mode );
    
    /**
     * Set the speed of the motor three, zero (0) causes the motor to stop.
     * @param motor_speed The speed of the motor ( from -100 to 100 )
     */
    void motorThreeSpeed( int motor_speed );
    
    /**
     * get the position of the motor three
     * @return Value of the current motor encoder value from 0 to 250
     */
    int motorThreePosition();
    
    /**
     * Set the position of the motor three encoder, if the motor is in *slew* 
     * mode.
     * @param target Position to reach, value ranging from 0 to 250.
     */
    void motorThreeReach( int target );
    
    /**
     * Set the motor three mode 
     * @param mode the mode for the motor three
     */
    void motorThreeMode( MTBS_MOTOR_MODES mode );
    
    /**
     * Set the speed of the motor four, zero (0) causes the motor to stop.
     * @param motor_speed The speed of the motor ( from -100 to 100 )
     */
    void motorFourSpeed( int motor_speed );
    
    /**
     * get the position of the motor four
     * @return Value of the current motor encoder value from 0 to 250
     */
    int motorFourPosition();
    
    /**
     * Set the position of the motor four encoder, if the motor is in *slew* mode.
     * @param target Position to reach, value ranging from 0 to 250.
     */
    void motorFourReach( int target );
    
    /**
     * Set the motor four mode 
     * @param mode the mode for the motor four
     */
    void motorFourMode( MTBS_MOTOR_MODES mode );

    private:
    
    // controller manufacturer
    char __manufacturer[9];
    // controller type
    char __type[9];
    // Controller version number
    char __vers_number[5];
    uint8_t __battery_level;
    MTBS_STATUS_VALUE __status;
    // int __servos_state;
    // MOTOR_MODES[4] __mtrs_mode; // TODO
    
    
    //void I2C_reader( int dataSize );
};


#endif // _MATBOTICS_H_