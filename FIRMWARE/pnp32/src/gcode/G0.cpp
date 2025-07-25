#include "G0.h"
#include <Arduino.h>
#include "config.h"

void handleG0(float x, float y, float z, float a, float b, float c)
{
  Serial.println(" → G0: Rýchly pohyb");
  if (!isnan(x)) Serial.print("  X: "), Serial.println(x);
  if (!isnan(y)) Serial.print("  Y: "), Serial.println(y);
  if (!isnan(z)) Serial.print("  Z: "), Serial.println(z);
  if (!isnan(a)) Serial.print("  A: "), Serial.println(a);
  if (!isnan(b)) Serial.print("  B: "), Serial.println(b);
  if (!isnan(c)) Serial.print("  C: "), Serial.println(c);
}