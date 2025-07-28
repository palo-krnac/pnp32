#include "m604.h"
#include <Arduino.h>
#include "config.h"

void handleM604(GCodeParser &GCode) {
  // load parameter S, trim to range 0–255
  int duty = -1;
  if (GCode.HasWord('S')) {
    float sVal = GCode.GetWordValue('S');
    if (sVal < 0) sVal = 0;
    if (sVal > 255) sVal = 255;
    duty = static_cast<int>(sVal + 0.5f);
  }

  pinMode(M604_PIN, OUTPUT); // pin initialization

  if (duty < 0) {
    Serial.println(" → M604: S parameter missing. Expected S0–255.");
    return;
  }

  Serial.print(" → M604: digital output S switching on ");
  Serial.println(duty);

  if (duty == 0) {
    digitalWrite(M604_PIN, LOW);
    Serial.print(" → M604: DigitalOutput_OFF");
  } else if (duty >= 255) {
    digitalWrite(M604_PIN, HIGH);
    Serial.print(" → M604: DigitalOutput_ON");
  } else {
    analogWrite(M604_PIN, duty);
    Serial.print(" → M604: DigitalOutput_PWM");
  }
}