#include <Arduino.h>
#include "config.h"
#include "dispatcher.h"
#include "G0.h"
#include "G1.h"
#include "G21.h"
#include "G28.h"
#include "G90.h"


void dispatchGCode(int code, float x, float y, float z, float a, float b, float c)
{
  // Serial.print("Handling M"");
  // Serial.println(code);
  switch (code)
  {
    case 0: handleG0(x, y, z, a, b, c); break;
    case 1: handleG1(x, y, z, a, b, c); break;
    case 21: handleG21(); break;
    case 28: handleG28(); break;
    case 90: handleG90(); break;
    default: Serial.println(" → Neznámy G-kód"); break;
  }
}
