#include "dispatcher.h"
#include "M150.h"
#include "m600.h"
#include "m601.h"
#include "m602.h"
#include "m603.h"
#include "m604.h"
#include "m605.h"
#include "m606.h"
#include <Arduino.h>
#include "config.h"

void dispatchMCode(int code, GCodeParser& GCode)
{
  Serial.print("Handling M");
  Serial.println(code);

  switch (code)
  {
    case 150: handleM150(GCode); break;
    case 600: handleM600(GCode); break;
    case 601: handleM601(GCode); break;
    case 602: handleM602(GCode); break;
    case 603: handleM603(GCode); break;
    case 604: handleM604(GCode); break;
    case 605: handleM605(GCode); break;
    case 606: handleM606(GCode); break;
    default: Serial.println(" → Unknown or unimplemented M-code"); break;
  }
}
