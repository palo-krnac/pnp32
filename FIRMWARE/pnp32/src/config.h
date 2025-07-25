#pragma once

// ==================== TYP FIRMVÉRU ===================
//#define OpenPNP_FirmwareInfo:
  //          stream.write("FIRMWARE_NAME:grblHAL ");
   //         stream.write("FIRMWARE_URL:https%3A//github.com/grblHAL ");
   //         stream.write("FIRMWARE_VERSION:" GRBL_VERSION " ");
   //         stream.write("FIRMWARE_BUILD:");
   //         stream.write(uitoa(GRBL_BUILD));
   //         stream.write(ASCII_EOL);

// ==================== VŠEOBECNÉ NASTAVENIA ====================
#define SERIAL_SPEED     115200


#include "pins/esp32/pins_pnp32_A.h"


// ==================== LED (M150 - NeoPixel) ====================
// Počet LEDiek na každý pás
#define LED_NUM_CH0         60
#define LED_NUM_CH1         60

// Typ LED pásov (napr. NEO_GRB, NEO_GRBW, atď.)
#define LED_TYPE_CH0            NEO_GRBW + NEO_KHZ800
#define LED_TYPE_CH1            NEO_GRBW + NEO_KHZ800


// ==================== OSTATNÉ VSTUPY/VÝSTUPY ====================
// Príklad – môžeš si rozšíriť podľa vlastného hardvéru
#define RELAY1_PIN            25
#define BUTTON1_PIN           32
#define ENDSTOP_X_PIN         33
#define ENDSTOP_Y_PIN         34
#define ENDSTOP_Z_PIN         35

// Invertovanie vstupov/výstupov (napr. pre tlačidlá alebo relé)
#define RELAY_ACTIVE_HIGH     true
#define BUTTON_ACTIVE_LOW     true

