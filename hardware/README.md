
WARNING!!!! THIS IS A WORK IN PROGRESS!!!! READ THIS FIRST:
at the moment the following schematics are wrong, the piezos output in a range that is more than 3.3v (the vref for the mcp3008 in this configuration). At the moment i will try putting voltage dividers for scaling down each of the piezo voltage to keep it in range (with 3.3k & 1.8k resistors), then i will update this README.md


These are some notes on the used harware:
   
This is a breadboard prototype of the needed shield (you need 5.1 zener diodes, 1Mohm resistors and an MCP3008 DAC) :   
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
