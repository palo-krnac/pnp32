#include "G1.h"
#include <Arduino.h>
#include "config.h"

void handleG1(float x, float y, float z, float a, float b, float c)
{
  Serial.println(" → G1: Lineárny pohyb");

  if (!isnan(x)) Serial.print("  X: "), Serial.println(x);
  if (!isnan(y)) Serial.print("  Y: "), Serial.println(y);
  if (!isnan(z)) Serial.print("  Z: "), Serial.println(z);
  if (!isnan(a)) Serial.print("  A: "), Serial.println(a);
  if (!isnan(b)) Serial.print("  B: "), Serial.println(b);
  if (!isnan(c)) Serial.print("  C: "), Serial.println(c);

  // Vypíš pozíciu v OpenPnP formáte
  // ^.*X:(?<X>-?\d+\.\d+) Y:(?<Y>-?\d+\.\d+) Z:(?<Z>-?\d+\.\d+).*
  // Výstup musí byť v tvare: ok X:12.34 Y:-56.78 Z:90.00

  // Zaistíme, že ak niektorá súradnica je NaN, nahradíme ju nulou (alebo ignoruj podľa potreby)
  float fx = isnan(x) ? 0.0 : x;
  float fy = isnan(y) ? 0.0 : y;
  float fz = isnan(z) ? 0.0 : z;

  // Formátovaný výstup s dvoma desatinnými miestami
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "ok X:%.2f Y:%.2f Z:%.2f", fx, fy, fz);
  Serial.println(buffer);
  Serial.println("ok"); // Dôležité: odpoveď pre OpenPnP
}
