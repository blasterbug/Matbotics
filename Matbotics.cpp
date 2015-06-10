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
 * @date 2015/06/10
 * @author Benjamin Sientzoff
 * @version 0.2
 *
 *
 * \todo documentation for this file
 *
 */

#ifndef _MATBOTICS_CPP_
#define _MATBOTICS_CPP_

// use Arduino I2C Master library
#include "I2C.h"
// header file
#include "Matbotics.h"

MTController::MTController() :
//__servos_state( 0 ),
__battery_level( -1 )
{
    I2c.begin();
    // get Controller verion number
    I2c.read( CONTROLLER_ADDRESS, MTBS_VRS , 4, (uint8_t*)__vers_number );
    // adding terminate zero, because not present due to casting char*/uint8_t*
    __vers_number[4] = '\0'; 
    // get Controller manufacturer
    I2c.read( CONTROLLER_ADDRESS, MTBS_MANU , 8, (uint8_t*)__manufacturer );
    __manufacturer[8] = '\0'; 
    // get Controller type
    I2c.read( CONTROLLER_ADDRESS, MTBS_TYPE , 8, (uint8_t*)__type );
    __type[8] = '\0'; 
}

String MTController::manufacturer()
{
    return String( __manufacturer );
}

String MTController::type()
{
    return String( __type );
}

String MTController::version()
{
    return String( __vers_number );
}

float MTController::batteryLevel()
{
    I2c.read( CONTROLLER_ADDRESS, MTBS_BATT_LEVEL , 1, &__battery_level );
    // battery voltage is in units of 40mV
    return __battery_level*.04;
}

MTBS_STATUS_VALUE MTController::status()
{
    I2c.read( CONTROLLER_ADDRESS, MTBS_STATUS , 1, (uint8_t*)&__status );
    return __status;
}

void MTController::timeout( int time )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_TIME_OUT, time );
}

void MTController::enableServos()
{
    //__servos_state = MTBS_USE_ALL_SERVOS;
    // enable all Servos
    I2c.write( CONTROLLER_ADDRESS, MTBS_SERVOS_STATE, MTBS_USE_ALL_SERVOS );
}

void MTController::disableServos()
{
    //__servos_state = MTBS_USE_NO_SERVO;
    // disable all Servos
    I2c.write( CONTROLLER_ADDRESS, MTBS_SERVOS_STATE, MTBS_USE_NO_SERVO );
}

void MTController::servoOneSpeed( int servo_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV1_SPEED, servo_speed );
}

void MTController::servoOneAngle( int angle )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV1_TRGT, angle );
}

void MTController::servoTwoSpeed( int servo_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV2_SPEED, servo_speed );
}

void MTController::servoTwoAngle( int angle )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV2_TRGT, angle );
}

void MTController::servoThreeSpeed( int servo_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV3_SPEED, servo_speed );
}

void MTController::servoThreeAngle( int angle )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV3_TRGT, angle );
}

void MTController::servoFourSpeed( int servo_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV4_SPEED, servo_speed );
}

void MTController::servoFourAngle( int angle )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_SRV4_TRGT, angle );
}


void MTController::motorOneSpeed( int motor_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR1_SPEED, motor_speed );
}

long MTController::motorOnePosition()
{
    return 0;
}

void MTController::motorOneReach( long target )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR1_TRGT, (uint8_t*)&target, 8 );
}

void MTController::motorOneMode( MTBS_MOTOR_MODES mode )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR1_MODE, mode );
}

void MTController::motorTwoSpeed( int motor_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR2_SPEED, motor_speed );
}

long MTController::motorTwoPosition()
{
    long pos = 0;
    I2c.read( CONTROLLER_ADDRESS, MTBS_MTR2_POS, 4, (uint8_t*)&pos );
    return pos;
}

void MTController::motorTwoReach( long target )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR2_TRGT, (uint8_t*)&target, 8 );
}

void MTController::motorTwoMode( MTBS_MOTOR_MODES mode )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR2_MODE, mode );
}

void MTController::motorThreeSpeed( int motor_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR3_SPEED, motor_speed );
}

long MTController::motorThreePosition()
{
    return 0;
}

void MTController::motorThreeReach( long target )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR3_TRGT, (uint8_t*)&target, 8 );
}

void MTController::motorThreeMode( MTBS_MOTOR_MODES mode )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR3_MODE, mode ) ;
}

void MTController::motorFourSpeed( int motor_speed )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR4_SPEED, motor_speed );
}

long MTController::motorFourPosition()
{
    return 0;
}

void MTController::motorFourReach( long target )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR4_TRGT, (uint8_t*)&target, 8 );
}

void MTController::motorFourMode( MTBS_MOTOR_MODES mode )
{
    I2c.write( CONTROLLER_ADDRESS, MTBS_MTR4_MODE, mode ) ;
}

#endif // _MATBOTICS_CPP_
