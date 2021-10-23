#include <iostream>
#include "pico/stdlib.h"
#include "../../radio-switch.h"

/*A simple example of transmitting "on" and "off" codes*/
int main() {
    // Change this to be whatever pin is plugged into your "DATA" pin.
    const uint RADIO_TRANSMIT_PIN = 16;
    
    // You will need to change all of these values for your remote + plug.
    // You should first run the "recieve" example
    // to test out what your remote sends out.
    const uint PULSE_LENGTH = 169; // set this to PULSELENGTH RECIEVED
    const uint REPEAT_TRANSMIT = 20; // set this to whatever works best for you.
    const uint PROTOCOL = 1; // set this to PROTOCOL RECIEVED
    const uint BIT_LENGTH = 24; // set this to BIT LENGTH RECIEVED
    const uint ON_CODE = 1398067; // set this to VALUE RECEIVED when you press the on button
    const uint OFF_CODE = 1398076; // set this to VALUE RECEIVED when you press the off button

    stdio_init_all();
    // Although calling enableTransmit sets the direction, we still need to init the pin.
    gpio_init(RADIO_TRANSMIT_PIN);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(RADIO_TRANSMIT_PIN);
    mySwitch.setProtocol(PROTOCOL);
    mySwitch.setPulseLength(PULSE_LENGTH);
    mySwitch.setRepeatTransmit(REPEAT_TRANSMIT);


    while(true) {
        mySwitch.send(ON_CODE,BIT_LENGTH);
        std::cout << "ON" << std::endl;
        sleep_ms(20000);
        mySwitch.send(OFF_CODE,BIT_LENGTH);
        std::cout << "OFF" << std::endl;
        sleep_ms(20000);
    }
    return 0;
}