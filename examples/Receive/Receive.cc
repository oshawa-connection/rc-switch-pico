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
    const uint RADIO_RECIEVER_PIN = 17;
    gpio_init(RADIO_RECIEVER_PIN);
    
    RCSwitch rcSwitch = RCSwitch();
    rcSwitch.enableReceive(RADIO_RECIEVER_PIN);

    while (true) {
        if (rcSwitch.available()) {
            std::cout << "VALUE RECEIVED: " << rcSwitch.getReceivedValue() << std::endl;
            std::cout << "PROTOCOL RECIEVED: " << rcSwitch.getReceivedProtocol() << std::endl;
            std::cout << "BIT LENGTH RECIEVED: " << rcSwitch.getReceivedBitlength() << std::endl;
            std::cout << "PULSELENGTH RECIEVED: " << rcSwitch.getReceivedDelay() << std::endl;
            rcSwitch.resetAvailable();
            
            sleep_ms(100);
        }
    }

    return 0;
}