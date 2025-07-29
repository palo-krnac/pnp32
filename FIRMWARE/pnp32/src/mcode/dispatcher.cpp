#include "dispatcher.h"
#include "M114.h"
#include "M115.h"
#include "M150.h"
#include "M400.h"
#include "M600.h"
#include "M601.h"
#include "M602.h"
#include "M603.h"
#include "M604.h"
#include "M605.h"
#include "M606.h"

#include <Arduino.h>
#include "config.h"

void dispatchMCode(int code, GCodeParser& GCode)
{
  Serial.print("Handling M");
  Serial.println(code);

  switch (code)
  {
    case 114: handleM114(GCode); break;
    case 115: handleM115(GCode); break;
    case 150: handleM150(GCode); break;
    case 400: handleM400(GCode); break;
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
