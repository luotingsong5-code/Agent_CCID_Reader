## **6.1 Pin description**

|Pin|Symbol|Type|Description|
|---|---|---|---|
|1|TDO / OUT0|O|test data output for boundary scan interface / general purpose output 0|
|2|TDI / OUT1|I|test data input boundary scan interface / general purpose output 1|
|3|TMS / OUT2|I|test mode select boundary scan interface / general purpose output 2|
|4|TCK / OUT3|I|test clock boundary scan interface / general purpose output 3|
|5|SIGIN /OUT7|I/O|Contactless communication interface output. / general purpose output 7|
|6|SIGOUT|O|Contactless communication interface input.<br>|
|7|DVDD|PWR|digital power supply buffer\[1\]|
|8|VDD|PWR|power supply<br>|
|9|AVDD|PWR|analog power supply buffer\[1\]|
|10|AUX1|O|auxiliary outputs: Pin is used for analog test signal|
|11|AUX2|O|auxiliary outputs: Pin is used for analog test signal|
|12|RXP|I|receiver input pin for the received RF signal.|
|13|RXN|I|receiver input pin for the received RF signal.<br>|
|14|VMID|PWR|internal receiver reference voltage\[1\]|
|15|TX2|O|transmitter 2: delivers the modulated 13.56 MHz carrier|
|16|TVSS|PWR|transmitter ground, supplies the output stage of TX1, TX2|
|17|TX1|O|transmitter 1: delivers the modulated 13.56 MHz carrier|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **7 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Pin|Symbol|Type|Description|
|---|---|---|---|
|18|TVDD|PWR|transmitter voltage supply|
|19|XTAL1|I|crystal oscillator input: Input to the inverting amplifier of the oscillator. This pin is<br>also the input for an externally generated clock (fosc = 27.12 MHz)|
|20|XTAL2|O|crystal oscillator output: output of the inverting amplifier of the oscillator|
|21|PDOWN|I|Power Down (RESET)|
|22|CLKOUT / OUT6|O|clock output / general purpose output 6|
|23|SCL|O|Serial Clock line|
|24|SDA|I/O|Serial Data Line|
|25|PVDD|PWR|pad power supply|
|26|IFSEL0 / OUT4|I|host interface selection 0 / general purpose output 4|
|27|IFSEL1 / OUT5|I|host interface selection 1 / general purpose output 5|
|28|IF0|I/O|interface pin, multifunction pin: Can be assigned to host interface RS232, SPI,<br>I2C, I2C-L<br>|
|29|IF1|I/O|interface pin, multifunction pin: Can be assigned to host interface SPI, I2C, I2C-L|
|30|IF2|I/O|interface pin, multifunction pin: Can be assigned to host interface RS232, SPI,<br>I2C, I2C-L|
|31|IF3|I/O|interface pin, multifunction pin: Can be assigned to host interface RS232, SPI,<br>I2C, I2C-L|
|32|IRQ|O|interrupt request: output to signal an interrupt event|
|33|VSS|PWR|ground and heat sink connection|



\[1\] This pin is used for connection of a buffer capacitor. Connection of a supply voltage might damage the device.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **8 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
