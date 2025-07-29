#pragma once

#define SERIAL_SPEED     115200

#define FIRMWARE_NAME "pnp32-motion controller"
#define SOURCE_CODE_URL  "https://github.com/palo-krnac/pnp32/tree/main/FIRMWARE"
#define AUTHOR "Pavol Krnac"
#define MACHINE_TYPE "NEODEN"
#define CONTROLLER_TYPE "pnp32_MC"
#define FIRMWARE_VERSION "v0.1"
#define PROTOCOL_VERSION "v0.1"
#define EXTRUDER_COUNT 2
#define FIRMWARE_UUID "12345678-1234-5678-90ab-cdef12345678"


//===================== REGEX ==========================
#define COMMAND_CONFIRM_REGEX "ok"    // $0D" (^ok.*)
#define COMMAND_ERROR_REGEX   "error" // (^error.*)
#define POSITION_REPORT_REGEX         // (^.*X:(?<X>-?\d+\.\d+) Y:(?<Y>-?\d+\.\d+) Z:(?<Z>-?\d+\.\d+).*)

//FIRMWARE_NAME:Marlin 2.1.2.1 (Jun 25 2025 17:52:17) SOURCE_CODE_URL:github.com/MarlinFirmware/Marlin PROTOCOL_VERSION:1.0 MACHINE_TYPE:OpenPNP-cinska kokotina EXTRUDER_COUNT:2 UUID:cede2a2f-41a2-4748-9b12-c55c62f367ff

//X:0.00 Y:0.00 Z:200.00 E:0.00 Count X:0 Y:0 Z:16000

//G21 ; Set millimeters mode
//G90 ; Set absolute positioning mode

// ==================== VÝBER DOSKY ====================
// Definuj iba jednu z nasledujúcich možností:
  // #define PnP_Controller
 #define pnp32_MC
// #define pnp32_MCH
// #define pnp32_MCM

// ==================== AUTOMATICKÝ VÝBER BOARD KONFIGURÁCIE ====================
#if defined(pnp32_MC)
  #include "boards/pnp32_MC.h"
#elif defined(pnp32_MCH)
  #include "boards/pnp32_MCH.h"
#elif defined(pnp32_MCM)
  #include "boards/pnp32_MCM.h"
#elif defined(PnP_Controller)
  #include "boards/PnP_Controller.h"
#else
  #error "❌ Nezadaný alebo neznámy typ dosky – nastav správny #define vyššie v config.h"
#endif

// ==================== LED (M150 - NeoPixel) ====================
#define LED_NUM_CH0            60
#define LED_NUM_CH1            60
#define LED_TYPE_CH0           NEO_GRBW + NEO_KHZ800
#define LED_TYPE_CH1           NEO_GRBW + NEO_KHZ800

// ==================== OSTATNÉ VSTUPY/VÝSTUPY ====================
//#define RELAY1_PIN             25
//#define BUTTON1_PIN            32
//#define ENDSTOP_X_PIN          33
//#define ENDSTOP_Y_PIN          34
//#define ENDSTOP_Z_PIN          35

//#define RELAY_ACTIVE_HI


//platformio run -e pnp32_MC -t upload

