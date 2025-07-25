#include "dispatcher.h"
#include "M150.h"
#include "m600.h"
#include "m601.h"
#include "m602.h"
#include "m603.h"
#include "m604.h"
#include "m605.h"
#include <Arduino.h>
#include "config.h"

void dispatchMCode(int code, GCodeParser& GCode)
{
  Serial.print("Handling M");
  Serial.println(code);

  switch (code)
  {
    case 150: handleM150(GCode); break;
    case 600: handleM600(); break;
    case 601: handleM601(); break;
    case 602: handleM602(); break;
    case 603: handleM603(); break;
    case 604: handleM604(); break;
    case 605: handleM605(); break;
    default: Serial.println(" → Unknown or unimplemented M-code"); break;
  }
}
