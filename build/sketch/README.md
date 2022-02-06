#line 1 "D:\\git\\bluefruit\\README.md"
# E-INK OVER BLUETOOTH
Eink over BLE project written to run on the [Adafruit playground Bluefruit](https://www.adafruit.com/product/4333)

When I bought some box full of goodies from Adafruit, they added in a couple of free gifts and the Adafruit Playground Bluefruit was one of them. 

I will start of using the Arduino IDE to program and leverage the simplicity of using the `.ino` `setup()` and `loop()` functions. It's also more convenient at this time than to solder on wires to the bottom side debug pins that directly tie to the 

To successfully compile this project, install Arduino 1.8.19 then install the latest board support from Adafruit. Using older Arduino IDE with the latest Adafruit board support causes a compilation error where some modules can't be reached.  

Something to keep in mind is that the two buttons and the switch are active HIGH and not active LOW as it's been for most development boards out there. set the pin to use the internal pull down for it to work.