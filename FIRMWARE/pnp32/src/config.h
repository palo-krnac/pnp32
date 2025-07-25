#pragma once

#define SERIAL_SPEED     115200
#define DEFAULT_MACHINE_NAME "ESP Pick and Place"
#define DEFAULT_CONTROLLER_NAME "ESP Pick and Place"

// ==================== VÝBER DOSKY ====================
// Definuj iba jednu z nasledujúcich možností:
   #define PnP_Controller
// #define pnp32_MC
 //#define pnp32_MCH
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
#define RELAY1_PIN             25
#define BUTTON1_PIN            32
#define ENDSTOP_X_PIN          33
#define ENDSTOP_Y_PIN          34
#define ENDSTOP_Z_PIN          35

#define RELAY_ACTIVE_HI
