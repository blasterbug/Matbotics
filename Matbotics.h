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
 */

/**
 * @section About Servos
 *
 * @n The Servo 1/2/3/4 speed bytes allow the rate, at which changes to the
 * servo positions are made, to be controlled. If the value is set to zero,
 * changes to the servo position is immediate. If the value is non-zero,
 * changes will occur at a rate equal 10*value milliseconds per step.
 */


#ifndef _MATBOTICS_H_
#define _MATBOTICS_H_

// matbotics address
#define CONTROLLER_ADDRESS 0x08

// register address to write in to control motors/servos
// controller vars
#define CTRL_VRS 0x07
#define CTRL_MANU 0x0F
#define CTRL_TYPE 0x17
#define CTRL_STATUS 0x41
#define CTRL_TIME_OUT 0x42
#define CTRL_BATT_LEVEL 0x43
#define CTRL_STRT_FALG 0x44
// servos commands
#define CTRL_SERVO_ON 0x45
// Arctived all servos
// Matrix Controller uses for bits to enable each one.
//  SERVOS  1   2   3   4
//  0xF     1   1   1   1
#define USE_SERVOS 0xF
//  SERVO 1
#define CTRL_SRV1_SPEED 0x46
#define CTRL_SRV1_TRGT 0x47
//  SERVO 2
#define CTRL_SRV2_SPEED 0x48
#define CTRL_SRV2_TRGT 0x49
//  SERVO 3
#define CTRL_SRV3_SPEED 0x4A
#define CTRL_SRV3_TRGT 0x4B
//  SERVO 4
#define CTRL_SRV4_SPEED 0x4C
#define CTRL_SRV4_TRGT 0x4D
// motors commands
//  MOTOR 1
#define CTRL_MTR1_POS 0x4E
#define CTRL_MTR1_TRGT 0x52
#define CTRL_MTR1_SPEED 0x56
#define CTRL_MTR1_MODE 0x57
//  MOTOR 2
#define CTRL_MTR2_POS 0x58
#define CTRL_MTR2_TRGT 0x5C
#define CTRL_MTR2_SPEED 0x60
#define CTRL_MTR2_MODE 0x61
//  MOTOR 3
#define CTRL_MTR3_POS 0x62
#define CTRL_MTR3_TRGT 0x66
#define CTRL_MTR3_SPEED 0x6A
#define CTRL_MTR3_MODE 0x6B
//  MOTOR 4
#define CTRL_MTR4_POS 0x6C
#define CTRL_MTR4_TRGT 0x70
#define CTRL_MTR4_SPEED 0x74
#define CTRL_MTR4_MODE 0x75

/**
 * motor modes
 */
enum MOTOR_MODES {
    MTR_MODE_FLOAT = 0,
    MTR_MODE_BRAKE,
    MTR_MODE_SPEED,
    MTR_MODE_SLEW
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
     * Get battery level
     * @n The Battery level returns the current battery voltage in units 
     * of 40mV.
     * param[out] battery level (TODO)
     */
    int batteryLevel();
    
    /**
     * enable servomotors
     */
    void enableServos();
    
    /**
     * Set speed of the servo one
     * @param[in] speed the speed to set
     */
    void servoOneSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo one
     * @param[in] angle angle to reach
     */
    void servoOneAngle( int angle );
    
    /**
     * Set speed of the servo two
     * @param[in] speed the speed to set
     */
    void servoTwoSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo two
     * @param[in] angle angle to reach
     */
    void servoTwoAngle( int angle );
    
    /**
     * Set speed of the servo three
     * @param[in] speed the speed to set
     */
    void servoThreeSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo three
     * @param[in] angle angle to reach
     */
    void servoThreeAngle( int angle );
    
    /**
     * Set speed of the servo four
     * @param[in] speed the speed to set
     */
    void servoFourSpeed( int servo_speed );
    
    /**
     * Set the angle of the servo four
     * @param[in] angle angle to reach
     */
    void servoFourAngle( int angle );
    
    /**
     * Set the speed of the motor one, zero (0) causes the motor to stop.
     * @param[in] motor_speed The speed of the motor ( from -100 to 100 )
     */
    void motorOneSpeed( int motor_speed );
    
    /**
     * get the position of the motor one
     * @param[out] int Value of the current motor encoder value from 0 to 250
     */
    int motorOnePosition();
    
    /**
     * Set the position of the motor one encoder , fi it is in *slew* mode.
     * param[in] target Position to reach
     */
    void motorOneReach( int target );
    
    /**
     * Set the motor one mode 
     * @param[in] mode the mode for the motor one
     */
    void motorOneMode( MOTOR_MODES mode );
    

    private:
        uint8_t __servos_state;
        int __battery_level;
};


#endif // _MATBOTICS_H_