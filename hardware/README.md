
These are some notes on the used harware:
   
This is a breadboard prototype for one of the sensor input (you need 5.1 zener diodes, 1M, 1.8k and 560 ohm resistors and an MCP3008 DAC), basically the 5v piezo input has to go into a voltage divider before going into the MCP3008 input, as the MP3008 runs at 3.3v:   
![alt tag](https://github.com/npisanti/ofxRPiezos/blob/master/hardware/breadboard.jpg)
   
The rPi 40pin GPIO has to be connected to the MCP3008 making these connections:   
```
(rPI)------->(MCP3008)   
GROUND------>DGND   
CE0--------->CS   
MOSI-------->DIN   
MISO-------->DOUT   
CLK--------->CLK   
GROUND------>AGND   
3.3V-------->VREF   
3.3V-------->VDD   
```

For the piezo cables you need 3.5mm mono jacks, and coaxial mono cables. The inner part of the cables goes to the inner part of the piezo and to the shorter of the two jack connections. You could also put some hot glue on the piezos for making the connections stronger.   
![alt tag](https://github.com/npisanti/ofxRPiezos/blob/master/hardware/jack.jpg)   
   
   
Here is my messy perfboard prototype of the shield, if you want to do somethings like this remember that from above the rPi GPIO are the same, but the MCP3008 pin will be mirrored.   
![alt tag](https://github.com/npisanti/ofxRPiezos/blob/master/hardware/perfboard.jpg)   
   
   
PS: if someone would ever try to make a better schematic file from those notes, i'm happy of every contribution.   
   
   
MCP3008 datasheet: https://cdn-shop.adafruit.com/datasheets/MCP3008.pdf   
