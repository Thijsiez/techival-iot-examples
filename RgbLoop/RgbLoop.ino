#include <Adafruit_NeoPixel.h>

#define LEDS_PIN 16
#define LED_NUM 7
#define SENSE_PIN 3

#define DRY_VAL 8200
#define WET_VAL 4000

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, LEDS_PIN, NEO_GRB + NEO_KHZ800);
//(256 - 32) = 224 steps so that the brightness is at least 32, so the LEDs don't flicker
const float stepValue = (float)(DRY_VAL - WET_VAL) / 224.0;
int rgb[3] = {255, 0, 0};

void setup() {
  Serial.begin(9600);

  leds.begin();
}

void loop() {
  for (int decrease = 0; decrease < 3; decrease++) {
    int increase = decrease == 2 ? 0 : decrease + 1;
    for (int fade = 0; fade < 255; fade++) {
      rgb[decrease]--;
      rgb[increase]++;

      int dryness = analogRead(SENSE_PIN);
      Serial.println(dryness);

      int brightness = 256 - ((float)dryness - WET_VAL) / stepValue;

      leds.setBrightness(brightness);
      for (int i = 1; i < LED_NUM; i++) {
        leds.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
      }
      leds.show();

      //Slow down the color fade
      delay(10);
    }
  }
}
