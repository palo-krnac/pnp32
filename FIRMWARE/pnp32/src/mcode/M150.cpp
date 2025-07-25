#include "m150.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"




Adafruit_NeoPixel strip0(LED_NUM_CH0 , LED_PIN_CH0, LED_TYPE_CH0 );
Adafruit_NeoPixel strip1(LED_NUM_CH1 , LED_PIN_CH1, LED_TYPE_CH1 );

int ledIndex = 0;  // pozícia v páse

void setupM150()
{
  strip0.begin();
  strip0.show();
  strip1.begin();
  strip1.show();
}

void handleM150(GCodeParser& GCode)
{
  // Získaj parametre
  uint8_t red   = GCode.HasWord('R') ? GCode.GetWordValue('R') : 0;
  uint8_t green = GCode.HasWord('U') ? GCode.GetWordValue('U') : 0;
  uint8_t blue  = GCode.HasWord('B') ? GCode.GetWordValue('B') : 0;
  uint8_t white = GCode.HasWord('W') ? GCode.GetWordValue('W') : 0;
  uint8_t bright = GCode.HasWord('P') ? GCode.GetWordValue('P') : 255;
  int ledCount = GCode.HasWord('S') ? GCode.GetWordValue('S') : 1;
  int follow = GCode.HasWord('F') ? GCode.GetWordValue('F') : 0;

  // Aplikuj jas
  uint8_t r = (red   * bright) / 255;
  uint8_t g = (green * bright) / 255;
  uint8_t b = (blue  * bright) / 255;
  uint8_t w = (white * bright) / 255;

  Serial.printf(" → M150: R=%d U=%d B=%d W=%d P=%d S=%d F=%d\n",
                red, green, blue, white, bright, ledCount, follow);

  // Nastav farbu na oboch kanáloch
  for (int i = 0; i < ledCount && (ledIndex + i) < LED_NUM_CH0; i++) {
    strip0.setPixelColor(ledIndex + i, strip0.Color(r, g, b, w));
  }

  for (int i = 0; i < ledCount && (ledIndex + i) < LED_NUM_CH1; i++) {
    strip1.setPixelColor(ledIndex + i, strip0.Color(r, g, b, w));
  }
  // Aktualizuj LED pásy
  strip0.show();
  strip1.show();

  // Posuň index ak F1 (follow)
  if (follow) {
    ledIndex += ledCount;
  } else {
    ledIndex = 0;
  }
}
