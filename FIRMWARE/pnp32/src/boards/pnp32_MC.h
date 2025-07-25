/**
 * pnp32 - openPNP motion controller firmware
 * Copyright (c) 2025 Pavol Krnac [https://github.com/palo-krnac/pnp32]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/****************************************************************************************
* Teensy 4.1 (IMXRT1062) Breadboard pin assignments
* Requires the Teensyduino software with Teensy 4.1 selected in Arduino IDE!
* https://www.pjrc.com/teensy/teensyduino.html
****************************************************************************************/

//#if NOT_TARGET(IS_TEENSY41)
//  #error "Oops! Select 'Teensy 4.1' in 'Tools > Board.'"
//#endif

#define BOARD_INFO_NAME "pnp32-MC"

//
// SPI
//
#define MISO_PIN                              19
#define MOSI_PIN                              23
#define SCK_PIN                               18

//
// Limit Switches
//
#define X_STOP_PIN                            36
#define Y_STOP_PIN                            39
#define Z_STOP_PIN                            34
#define A_STOP_PIN                            35
#define B_STOP_PIN                            05
#define C_STOP_PIN                            16

//
// Steppers
//
#define X_CS_PIN                             136
#define Y_CS_PIN                             137
#define Z_CS_PIN                             138
#define A_CS_PIN                             139
#define B_CS_PIN                             139
#define C_CS_PIN                             139

//
//LED
//
#define LED_PIN_CH0   4
#define LED_PIN_CH1   5