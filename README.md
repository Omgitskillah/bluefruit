# E-INK OVER BLUETOOTH
Eink over BLE project written to run on the [Adafruit playground Bluefruit](https://www.adafruit.com/product/4333)

When I bought some box full of goodies from Adafruit, they added in a couple of free gifts and the Adafruit Playground Bluefruit was one of them. 

Will start of using the Arduino IDE to program and leverage the simplicity of using the `.ino` `setup()` and `loop()` functions. It's also more convenient at this time than to solder on wires to the bottom side debug pins that directly tie to the 

To successfully compile this project, install Arduino 1.8.19 then install the latest board support from Adafruit. Using older Arduino IDE with the latest Adafruit board support causes a compilation error where some modules can't be reached.


> :warning: **If you have been following this repo till now, I'd like to let you know that I quit using the Arduino IDE with the board and opting to use segger studio to go around some of the problems I have encountered so far. The main issue that prompted this is the pin mapping to the buttons. I found that accessing the pins via digitalRead(...) does not work for the two buttons and the switch. I will update this repo once I setup a new project on Segger**