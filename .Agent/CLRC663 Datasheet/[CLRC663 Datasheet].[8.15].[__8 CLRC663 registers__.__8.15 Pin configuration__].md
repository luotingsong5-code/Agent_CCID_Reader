## **8.15 Pin configuration**

CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **101 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.15.1 PinEn**





















|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|SIGIN_EN /<br>OUT7|CLKOUT_EN /<br>OUT6|IFSEL1_EN /<br>OUT5|IFSEL0_EN /<br>OUT4|TCK_EN /<br>OUT 3|TMS_EN /<br>OUT2|TDI_EN /<br>OUT1|TDO_EN /<br>OUT0|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|SIGIN_EN / OUT7|Enables the output functionality on SIGIN (pin 5). The pin is<br>then used as output.|
|6|CLKOUT_EN / OUT6|Enables the output functionality of the CLKOUT (pin 22). The<br>pin is then used as output. The CLKOUT function is switched<br>off.|
|5|IFSEL1_EN / OUT5|Enables the output functionality of the IFSEL1 (pin 27). The<br>pin is then used as output.|
|4|IFSEL0_EN / OUT4|Enables the output functionality of the IFSEL0 (pin 26). The<br>pin is then used as output.|
|3|TCK_EN / OUT3|Enables the output functionality of the TCK (pin 4) of the<br>boundary scan interface. The pin is then used as output. If<br>the boundary scan is activated in EEPROM, this bit has no<br>function.|
|2|TMS_EN / OUT2|Enables the output functionality of the TMS (pin 2) of the<br>boundary scan interface. The pin is then used as output. If<br>the boundary scan is activated in EEPROM, this bit has no<br>function.|
|1|TDI_EN / OUT1|Enables the output functionality of the TDI (pin 1) of the<br>boundary scan interface. The pin is then used as output. If<br>the boundary scan is activated in EEPROM, this bit has no<br>function.|
|0|TDO_EN / OUT0|Enables the output functionality of the TDO(pin 3) of the<br>boundary scan interface. The pin is then used as output. If<br>the boundary scan is activated in EEPROM, this bit has no<br>function.|

### **8.15.2 PinOut**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|SIGIN_OUT|CLKOUT_OUT|IFSEL1_OUT|IFSEL0_OUT|TCK_OUT|TMS_OUT|TDI_OUT|TDO_OUT|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **102 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|SIGIN_OUT|Output buffer of the SIGIN pin|
|6|CLKOUT_OUT|Output buffer of the CLKOUT pin|
|5|IFSEL1_OUT|Output buffer of the IFSEL1 pin|
|4|IFSEL0_OUT|Output buffer of the IFSEL0 pin|
|3|TCK_OUT|Output buffer of the TCK pin|
|2|TMS_OUT|Output buffer of the TMS pin|
|1|TDI_OUT|Output buffer of the TDI pin|
|0|TDO_OUT|Output buffer of the TDO pin|


### **8.15.3 PinIn**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|SIGIN_IN|CLKOUT_IN|IFSEL1_IN|IFSEL0_IN|TCK_IN|TMS_IN|TDI_IN|TDO_IN|
|Access<br>rights|r|r|r|r|r|r|r|r|


|Bit|Symbol|Description|
|---|---|---|
|7|SIGIN_IN|Input buffer of the SIGIN pin|
|6|CLKOUT_IN|Input buffer of the CLKOUT pin|
|5|IFSEL1_IN|Input buffer of the IFSEL1 pin|
|4|IFSEL0_IN|Input buffer of the IFSEL0 pin|
|3|TCK_IN|Input buffer of the TCK pin|
|2|TMS_IN|Input buffer of the TMS pin|
|1|TDI_IN|Input buffer of the TDI pin|
|0|TDO_IN|Input buffer of the TDO pin|

### **8.15.4 SigOut**












|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Pad<br>Speed|RFU|RFU|RFU|SigOutSel|SigOutSel|SigOutSel|SigOutSel|
|Access<br>rights|r/w|-|-|-|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **103 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|PadSpeed|If set, the I/O pins are supporting a fast switching mode.The fast mode<br>for the I/O’s will increase the peak current consumption of the device,<br>especially if multiple I/Os are switching at the same time. The power<br>supply needs to be designed to deliver this peak current.|
|6 to 4|RFU|-|
|3 to 0|SIGOutSel|0h, 1h - The pin SIGOUT is 3-state<br>2h - The pin SIGOUT is 0<br>3h - The pin SIGOUT is 1<br>4h - The pin SIGOUT shows the TX-envelope<br>5h - The pin SIGOUT shows the TX-active signal<br>6h - The pin SIGOUT shows the S3C (generic) signal<br>7h - The pin SIGOUT shows the RX-envelope<br>(only valid for ISO/IEC 14443A, 106 kBd)<br>8h - The pin SIGOUT shows the RX-active signal<br>9h - The pin SIGOUT shows the RX-bit signal|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **104 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
