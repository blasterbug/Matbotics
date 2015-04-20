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
 * MTController
 * object to encapsulate Matrix Robotic System controller control
 */
class MTController
{
  private:
  
  public:
    
}


#endif // _MATBOTICS_H_