#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 300

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.
#define DATA_PIN 2

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(250000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  static int i = 4;
  static uint8_t gHue = 0; // rotating "base color" used by many of the patterns

  unsigned int inicio = millis();
  // Turn the LED on
  leds[i - 4] = CHSV(gHue, 255, 72);
  leds[i - 3] = CHSV(gHue, 255, 102);
  leds[i - 2] = CHSV(gHue, 255, 132);
  leds[i - 1] = CHSV(gHue, 255, 162);
  leds[i] = CHSV(gHue, 255, 192);
  leds[i + 1] = CHSV(gHue, 255, 162);
  leds[i + 2] = CHSV(gHue, 255, 132);
  leds[i + 3] = CHSV(gHue, 255, 102);
  leds[i + 4] = CHSV(gHue, 255, 72);
  FastLED.show();
  leds[i - 4] = CRGB::Black;
  FastLED.show();

  gHue++;
  i++;
  if (i == 296)
    i = 4;

  Serial.println("Tiempo: " + String(millis() - inicio));
  Serial.println(i);
}
