#include "M114.h"
#include <Arduino.h>
#include "config.h"

void handleM114(GCodeParser &GCode)
{
  Serial.println ("X:0.0000 Y:0.0000 Z:0.0000 A:0.0000 B:0.0000 Count X:0 Y:0 Z:0 A:0 B:0");
  Serial.println(COMMAND_CONFIRM_REGEX);
}