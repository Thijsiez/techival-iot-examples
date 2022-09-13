#include <Adafruit_NeoPixel.h>

#define LEDS_PIN 16
#define LED_NUM 7
#define SENSE_PIN 3

#define DRY_VAL 8200
#define WET_VAL 4000

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, LEDS_PIN, NEO_GRB + NEO_KHZ800);
const float stepValue = (float)(DRY_VAL - WET_VAL) / 256.0 / 6.0;

void setup() {
  Serial.begin(9600);

  leds.begin();
  leds.setBrightness(31);
}

void loop() {
  int wetness = analogRead(SENSE_PIN);
  Serial.println(wetness);

  int progress = 1536 - ((float)wetness - WET_VAL) / stepValue;

  int fullOnLeds = progress / 256 + 1;
  for (int i = 1; i < fullOnLeds; i++) {
    leds.setPixelColor(i, 0, 255, 0);
  }
  leds.setPixelColor(fullOnLeds, 0, progress % 256, 0);
  for (int i = fullOnLeds+1; i < LED_NUM; i++) {
    leds.setPixelColor(i, 0, 0, 0);
  }
  leds.show();
}
