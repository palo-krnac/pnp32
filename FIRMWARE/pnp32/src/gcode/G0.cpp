#include "G0.h"
#include <Arduino.h>
#include "config.h"

void handleG0(float x, float y, float z, float a, float b, float c)
{
  if (!isnan(x)) Serial.print("  X: "), Serial.println(x);
  if (!isnan(y)) Serial.print("  Y: "), Serial.println(y);
  if (!isnan(z)) Serial.print("  Z: "), Serial.println(z);
  if (!isnan(a)) Serial.print("  A: "), Serial.println(a);
  if (!isnan(b)) Serial.print("  B: "), Serial.println(b);
  if (!isnan(c)) Serial.print("  C: "), Serial.println(c);


  // Zaistíme, že ak niektorá súradnica je NaN, nahradíme ju nulou (alebo ignoruj podľa potreby)
  float fx = isnan(x) ? 0.0 : x;
  float fy = isnan(y) ? 0.0 : y;
  float fz = isnan(z) ? 0.0 : z;
  float fa = isnan(a) ? 0.0 : a;
  float fb = isnan(b) ? 0.0 : b;
  float fc = isnan(c) ? 0.0 : c;

  // Formátovaný výstup s dvoma desatinnými miestami
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "ok X:%.2f Y:%.2f Z:%.2f A:%.2f B:%.2f", fx, fy, fz, fa, fb);
  Serial.println(buffer);
  //Serial.println("ok"); // Dôležité: odpoveď pre OpenPnP
}