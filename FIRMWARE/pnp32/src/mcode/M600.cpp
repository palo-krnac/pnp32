#include "m600.h"
#include <Arduino.h>
#include "config.h"

void handleM600(GCodeParser &GCode) {
  // načítaj parameter S, orez na rozsah 0–255
  int duty = -1;
  if (GCode.HasWord('S')) {
    float sVal = GCode.GetWordValue('S');
    if (sVal < 0) sVal = 0;
    if (sVal > 255) sVal = 255;
    duty = static_cast<int>(sVal + 0.5f);
  }

  pinMode(M600_PIN, OUTPUT); // inicializácia pinu

  if (duty < 0) {
    Serial.println(" → M600: chýba parameter S. Očakávané S0–255.");
    return;
  }

  Serial.print(" → M600: spúšťame vreteno s hodnotou S");
  Serial.println(duty);

  if (duty == 0) {
    digitalWrite(M600_PIN, LOW);
  } else if (duty >= 255) {
    digitalWrite(M600_PIN, HIGH);
  } else {
    analogWrite(M600_PIN, duty);
  }
}