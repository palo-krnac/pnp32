#include <Arduino.h>
#include "config.h"
#include <GCodeParser.h>
#include "gcode/dispatcher.h"
#include "mcode/dispatcher.h"
#include "mcode/m150.h"



GCodeParser GCode = GCodeParser();

float xPos = NAN, yPos = NAN, zPos = NAN, aPos = NAN, bPos = NAN, cPos = NAN;
int gCode = -1, mCode = -1;

void setup()
{
  Serial.begin(SERIAL_SPEED); //set in config.h
  Serial.println("Ready GCodeParser");
  setupM150();  // inicializácia LED pásov
}

void loop()
{
  if (Serial.available() > 0)
  {
    if (GCode.AddCharToLine(Serial.read()))
    {
      GCode.ParseLine();
      GCode.RemoveCommentSeparators();

      Serial.print("\nPrijatý riadok: ");
      Serial.println(GCode.line);

      xPos = yPos = zPos = aPos = bPos = cPos = NAN;
      gCode = mCode = -1;

      bool hasG = GCode.HasWord('G');
      bool hasM = GCode.HasWord('M');

      if (GCode.HasWord('X')) xPos = GCode.GetWordValue('X');
      if (GCode.HasWord('Y')) yPos = GCode.GetWordValue('Y');
      if (GCode.HasWord('Z')) zPos = GCode.GetWordValue('Z');
      if (GCode.HasWord('A')) aPos = GCode.GetWordValue('A');
      if (GCode.HasWord('B')) bPos = GCode.GetWordValue('B');
      if (GCode.HasWord('C')) cPos = GCode.GetWordValue('C');

      if (hasG) {
        gCode = GCode.GetWordValue('G');
        dispatchGCode(gCode, xPos, yPos, zPos, aPos, bPos, cPos);
      }

      if (hasM) {
        mCode = GCode.GetWordValue('M');
        dispatchMCode(mCode, GCode);
      }

      if (!hasG && !hasM) {
        Serial.println(" → Žiadny G ani M kód.");
      }
    }
  }
}
