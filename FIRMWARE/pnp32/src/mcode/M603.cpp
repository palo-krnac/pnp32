#include "m603.h"
#include <Arduino.h>
#include "config.h"

void handleM603(GCodeParser &GCode) {
  // load parameter S, trim to range 0–255
  int duty = -1;
  if (GCode.HasWord('S')) {
    float sVal = GCode.GetWordValue('S');
    if (sVal < 0) sVal = 0;
    if (sVal > 255) sVal = 255;
    duty = static_cast<int>(sVal + 0.5f);
  }

  pinMode(M603_PIN, OUTPUT); // pin initialization

  if (duty < 0) {
    Serial.println(" → M603: S parameter missing. Expected S0–255.");
    return;
  }

  Serial.print(" → M603: digital output S switching on ");
  Serial.println(duty);

  if (duty == 0) {
    digitalWrite(M603_PIN, LOW);
    Serial.print(" → M603: DigitalOutput_OFF");
  } else if (duty >= 255) {
    digitalWrite(M603_PIN, HIGH);
    Serial.print(" → M603: DigitalOutput_ON");
  } else {
    analogWrite(M603_PIN, duty);
    Serial.print(" → M603: DigitalOutput_PWM");
  }
}