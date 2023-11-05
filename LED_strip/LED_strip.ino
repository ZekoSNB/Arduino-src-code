#include<IRremote.h>
#include<FastLED.h>
#include "libraries/settings.h"


#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define DATA_PIN 2

void setup() {
    IrReceiver.begin(DATA_PIN, ENABLE_LED_FEEDBACK);
    init(RED_PIN, GREEN_PIN, BLUE_PIN);
    Serial.begin(9600);
}

void loop(){
    EVERY_N_MILLISECONDS(100){
    if (IrReceiver.decode()){
        uint16_t command = IrReceiver.decodedIRData.command;
        Serial.println(command);
        command_receive(command);
        
        IrReceiver.resume();
    }
    }
    

}