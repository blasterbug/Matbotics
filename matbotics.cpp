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

#ifndef _MATBOTICS_CPP_
#define _MATBOTICS_CPP_

// use TWI/I2C to communicate with Controller
#include <Wire.h>

#include "matbotics.h"

MTController::MTController() :
__servos_state(false),
__battery_level(-1)
{}

int MTController::BatteryLevel()
{
    Wire.begin( CONTROLLER_ADDRESS );
    Wire._I2C_WRITE( CTRL_BATT_LEVEL);
    Wire.endTransmission();
    return __battery_level;
}

void MTController::EnableServos()
{
    __servos_state = true;
    Wire.begin( CONTROLLER_ADDRESS );
    Wire._I2C_WRITE( CTRL_SERVO_ON );
    Wire.endTransmission();
}

void MTController::ServoOneSpeed( int servo_speed )
{
    Wire.begin( CONTROLLER_ADDRESS );
    Wire._I2C_WRITE( CTRL_SRV1_SPEED );
    Wire._I2C_WRITE( servo_speed );
    Wire.endTransmission();
}

void MTController::ServoOneAngle( int angle )
{
    Wire.begin( CONTROLLER_ADDRESS );
    Wire._I2C_WRITE( CTRL_SRV1_TRGT );
    Wire._I2C_WRITE( angle );
    Wire.endTransmission();
}

void MTController::MotorOneSpeed( int motor_speed )
{
    Wire.begin( CONTROLLER_ADDRESS );
    Wire._I2C_WRITE( CTRL_MTR1_SPEED );
    Wire._I2C_WRITE( motor_speed );
    Wire.endTransmission();
}

#endif // _MATBOTICS_CPP_
