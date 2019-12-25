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
  static int i = 0;
  unsigned int inicio = millis();
  
  // Turn the LED on
  leds[i] = CRGB::Red;
  FastLED.show();
  // Now turn the LED off
  leds[i] = CRGB::Black;
  FastLED.show();

  i++;
  if (i == 300)
    i = 0;

  Serial.println("Tiempo: " + String(millis()-inicio));
}
