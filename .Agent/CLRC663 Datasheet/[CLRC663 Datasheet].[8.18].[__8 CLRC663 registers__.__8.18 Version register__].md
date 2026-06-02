## **8.18 Version register**

### **8.18.1 Version**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Version|Version|Version|Version|SubVersion|SubVersion|SubVersion|SubVersion|
|Access<br>rights|r|r|r|r|r|r|r|r|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|Version|Includes the version of the CLRC663 silicon.|
|||CLRC66301: 0x1|
|||CLRC66302: 0x1|
|||CLRC66303: 0x1|
|3 to 0|SubVersion|Includes the subversion of the CLRC663 silicon.|
|||CLRC66301: 0x8|
|||CLRC66302: 0x8 -No difference of the silicon between versions<br>CLRC66301 and CLRC66302|
|||CLRC66303: 0xA<br>LPCD_OPTIONS register had been added compared to earlier<br>version of the CLRC663. Default configuration for LoadProtocol<br>updated for improved performance. User EEPROM initialized with<br>data. Transmitter driver allows higher ITVDD than lower SubVersions.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **117 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
