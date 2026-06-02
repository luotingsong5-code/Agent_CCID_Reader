## **8.3 SAM configuration register**

### **8.3.1 HostCtrl**

Via the HostCtrl Register the interface access right can be controlled


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **63 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RegEn|BusHost|BusSAM|RFU|SAMInterface|SAMInterface|RFU|RFU|
|Access<br>rights|dy|r/w|r/w|-|r/w|r/w|-|-|


|Bit|Symbol|Description|
|---|---|---|
|7|RegEn|If this bit is set to logic 1, the register HostCtrl_reg can be changed<br>at the next register access. The next write access clears this bit<br>automatically.|
|6|BusHost|Set to logic 1, the bus is controlled by the host. This bit cannot be set<br>together with the bit BusSAM. This bit can only be set if the bit RegEn<br>is previously set.|
|5|BusSAM|Set to logic 1, the bus is controlled by the SAM. This bit cannot be<br>set together with BusHost. This bit can only be set if the bit RegEn is<br>previously set.|
|4|RFU|-|
|3 to 2|SAMInterface|0h:SAM Interface switched off<br>1h:SAM Interface SPI active<br>2h:SAM Interface I2CL active<br>3h:SAM Interface I2C active|
|1 to 0|RFU|-|
