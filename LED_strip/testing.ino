#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 60
#define BRIGHTNESS 255

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
uint8_t pallete_index = 0;

DEFINE_GRADIENT_PALETTE (heatmap_gp){
    0, 255, 255, 255, //white
   50, 255,   0, 255, // purple
  150, 252, 108, 103, //pink
  225, 255,   0,   0,
  255,   0,   0, 255
};

CRGBPalette16 pal = heatmap_gp;


void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}
void loop()
{


  fill_palette(leds, NUM_LEDS, pallete_index, 255/NUM_LEDS, pal, 255, LINEARBLEND);
  EVERY_N_MILLISECONDS(60){
    pallete_index++;
  }

  FastLED.show();
}
