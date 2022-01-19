#include <iostream>
#include "pico/stdlib.h"
#include "../../radio-switch.h"

/*
Simple example of recieving radio remote signals.
This will help you to tell what your remote is sending out 
so you can recreate it :) 
*/
int main() {
    stdio_init_all();
    const uint RADIO_RECEIVER_PIN = 17;
    gpio_init(RADIO_RECEIVER_PIN);
    
    RCSwitch rcSwitch = RCSwitch();
    rcSwitch.enableReceive(RADIO_RECEIVER_PIN);

    while (true) {
        if (rcSwitch.available()) {
            std::cout << "VALUE RECEIVED: " << rcSwitch.getReceivedValue() << std::endl;
            std::cout << "PROTOCOL RECEIVED: " << rcSwitch.getReceivedProtocol() << std::endl;
            std::cout << "BIT LENGTH RECEIVED: " << rcSwitch.getReceivedBitlength() << std::endl;
            std::cout << "PULSELENGTH RECEIVED: " << rcSwitch.getReceivedDelay() << std::endl;
            rcSwitch.resetAvailable();
            
            sleep_ms(100);
        }
    }

    return 0;
}