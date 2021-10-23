# RcSwitch
A port of the brilliant [RC-Switch](https://github.com/sui77/rc-switch) library to the raspberry pi pico.

It allows you to send and recieve radio signals from 433/315Mhz devices like radio controlled power sockets, using cheap radio modules.

This works for both recieving and transmitting. Check out the examples for code for both of these.

## Building
This library can be developed on any platform that the pico-sdk works on, through cmake.

In the root directory, make sure that the pico-sdk is on your path and run
```bash
cmake .
```

then change directory into `examples/recieve`, then run 
```bash
make
```
which will spit out your uf2 file.

## Issues
If you experience an error while using this library, please raise an issue here on Github and I'll try to help out. Pull requests are also very welcome!