// #include "settings.h"
// #include <IRremote.hpp>

// #define IR_RECEIVE_PIN 2

// void setup(){
//     Serial.begin(9660);
//     IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
// }

// void loop(){
//     if (IrReceiver.decode()) {
//     uint16_t command = IrReceiver.decodedIRData.command;
//     command_receive(command);
//     delay(250);  // wait a bit
//     IrReceiver.resume();
//   }
// }