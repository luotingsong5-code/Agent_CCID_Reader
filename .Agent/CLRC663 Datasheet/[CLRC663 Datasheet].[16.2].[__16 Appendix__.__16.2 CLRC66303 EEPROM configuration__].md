## **16.2 CLRC66303 EEPROM configuration**

The CLRC66303 user EEPROM had been initalized with useful values for configuration
of the chip using a typical 65x65mm antenna. These values stored in EEPROM can be
used to configure the CLRC66303 with the command LoadReg.Typically, some of this
entries will be required to be modified compared to the preset values to achieve the best
RF performance for a specific antenna.

The registers 0x28...0x39 are relevant for configuration of the Antenna. For each
supported protocol, a dedicated preset configuration is available. To ensure compatibility
between products of the CLRC663 family, all products of the family use the same
default settings which are initialized in EEPROM, even if some of this protocols are not
supported by the product family member and cannot be used.

Alternatively, the registers can be initialized by individual register write commands.

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|C0|8E|
|TxAmp|C1|12|
|DrvCon|C2|39|
|TxI|C3|0A|
|TXCrcPreset|C4|18|
|RXCrcPreset|C5|18|
|TxDataNum|C6|0F|
|TxModWidth|C7|21|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **145 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|TxSym10BurstLen|C8|00|
|TxWaitCtrl|C9|C0|
|TxWaitLo|CA|12|
|TxFrameCon|CB|CF|
|RxSofD|CC|00|
|RxCtrl|CD|04|
|RxWait|CE|90|
|RxThreshold|CF|5C|
|Rcv|D0|12|
|RxAna|D1|0A|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|D4|8E|
|TxAmp|D5|D2|
|DrvCon|D6|11|
|TxI|D7|0A|
|TXCrcPreset|D8|18|
|RXCrcPreset|D9|18|
|TxDataNum|DA|0F|
|TxModWidth|DB|10|
|TxSym10BurstLen|DC|00|
|TxWaitCtrl|DD|C0|
|TxWaitLo|DE|12|
|TxFrameCon|DF|CF|
|RxSofD|E0|00|
|RxCtrl|E1|05|
|RxWait|E2|90|
|RxThreshold|E3|3C|
|Rcv|E4|12|
|RxAna|E5|0B|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|E8|8F|
|TxAmp|E9|DE|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **146 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvCon|EA|11|
|TxI|EB|0F|
|TXCrcPreset|EC|18|
|RXCrcPreset|ED|18|
|TxDataNum|EE|0F|
|TxModWidth|EF|07|
|TxSym10BurstLen|F0|00|
|TxWaitCtrl|F1|C0|
|TxWaitLo|F2|12|
|TxFrameCon|F3|CF|
|RxSofD|F4|00|
|RxCtrl|F5|06|
|RxWait|F6|90|
|RxThreshold|F7|2B|
|Rcv|F8|12|
|RxAna|F9|0B|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0100|8F|
|TxAmp|0101|DB|
|DrvCon|0102|21|
|TxI|0103|0F|
|TXCrcPreset|0104|18|
|RXCrcPreset|0105|18|
|TxDataNum|0106|0F|
|TxModWidth|0107|02|
|TxSym10BurstLen|0108|00|
|TxWaitCtrl|0109|C0|
|TxWaitLo|010A|12|
|TxFrameCon|010B|CF|
|RxSofD|010C|00|
|RxCtrl|010D|07|
|RxWait|010E|90|
|RxThreshold|010F|3A|
|Rcv|0110|12|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **147 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|RxAna|0111|0B|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0114|8F|
|TxAmp|0115|0E|
|DrvCon|0116|09|
|TxI|0117|0A|
|TXCrcPreset|0118|7B|
|RXCrcPreset|0119|7B|
|TxDataNum|011A|08|
|TxModWidth|011B|00|
|TxSym10BurstLen|011C|00|
|TxWaitCtrl|011D|01|
|TxWaitLo|011E|00|
|TxFrameCon|011F|05|
|RxSofD|0120|00|
|RxCtrl|0121|34|
|RxWait|0112|90|
|RxThreshold|0113|6F|
|Rcv|0114|12|
|RxAna|0115|03|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0128|8F|
|TxAmp|0129|0E|
|DrvCon|012A|09|
|TxI|012B|0A|
|TXCrcPreset|012C|7B|
|RXCrcPreset|012D|7B|
|TxDataNum|012E|08|
|TxModWidth|012F|00|
|TxSym10BurstLen|0130|00|
|TxWaitCtrl|0131|01|
|TxWaitLo|0132|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **148 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|TxFrameCon|0133|05|
|RxSofD|0134|00|
|RxCtrl|0135|35|
|RxWait|0136|90|
|RxThreshold|0137|3F|
|Rcv|0138|12|
|RxAna|0139|03|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0140|8F|
|TxAmp|0141|0F|
|DrvCon|0142|09|
|TxI|0143|0A|
|TXCrcPreset|0144|7B|
|RXCrcPreset|0145|7B|
|TxDataNum|0146|08|
|TxModWidth|0147|00|
|TxSym10BurstLen|0148|00|
|TxWaitCtrl|0149|01|
|TxWaitLo|014A|00|
|TxFrameCon|014B|05|
|RxSofD|014C|00|
|RxCtrl|014D|36|
|RxWait|014E|90|
|RxThreshold|014F|3F|
|Rcv|0150|12|
|RxAna|0151|03|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0154|8F|
|TxAmp|0155|10|
|DrvCon|0156|09|
|TxI|0157|0A|
|TXCrcPreset|0158|7B|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **149 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|RXCrcPreset|0159|7B|
|TxDataNum|015A|08|
|TxModWidth|015B|00|
|TxSym10BurstLen|015C|00|
|TxWaitCtrl|015D|01|
|TxWaitLo|015E|00|
|TxFrameCon|015F|05|
|RxSofD|0160|00|
|RxCtrl|0161|37|
|RxWait|0162|90|
|RxThreshold|0163|3F|
|Rcv|0164|12|
|RxAna|0165|03|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0168|8F|
|TxAmp|0169|17|
|DrvCon|016A|01|
|TxI|016B|06|
|TXCrcPreset|016C|09|
|RXCrcPreset|016D|09|
|TxDataNum|016E|08|
|TxModWidth|016F|00|
|TxSym10BurstLen|0170|03|
|TxWaitCtrl|0171|80|
|TxWaitLo|0172|12|
|TxFrameCon|0173|01|
|RxSofD|0174|00|
|RxCtrl|0175|05|
|RxWait|0176|86|
|RxThreshold|0177|3F|
|Rcv|0178|12|
|RxAna|0179|02|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **150 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0180|8F|
|TxAmp|0181|17|
|DrvCon|0182|01|
|TxI|0183|06|
|TXCrcPreset|0184|09|
|RXCrcPreset|0185|09|
|TxDataNum|0186|08|
|TxModWidth|0187|00|
|TxSym10BurstLen|0188|03|
|TxWaitCtrl|0189|80|
|TxWaitLo|018A|12|
|TxFrameCon|018B|01|
|RxSofD|018C|00|
|RxCtrl|018D|06|
|RxWait|018E|86|
|RxThreshold|018F|3F|
|Rcv|0190|12|
|RxAna|0191|02|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0194|89|
|TxAmp|0195|10|
|DrvCon|0196|09|
|TxI|0197|0A|
|TXCrcPreset|0198|7B|
|RXCrcPreset|0199|7B|
|TxDataNum|019A|08|
|TxModWidth|019B|00|
|TxSym10BurstLen|019C|00|
|TxWaitCtrl|019D|88|
|TxWaitLo|019E|A9|
|TxFrameCon|019F|0F|
|RxSofD|01A0|00|
|RxCtrl|01A1|02|
|RxWait|01A2|9C|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **151 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|RxThreshold|01A3|74|
|Rcv|01A4|12|
|RxAna|01A5|07|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|01A8|89|
|TxAmp|01A9|10|
|DrvCon|01AA|09|
|TxI|01AB|0A|
|TXCrcPreset|01AC|7B|
|RXCrcPreset|01AD|7B|
|TxDataNum|01AE|08|
|TxModWidth|016F|00|
|TxSym10BurstLen|01B0|00|
|TxWaitCtrl|01B1|88|
|TxWaitLo|01B2|A9|
|TxFrameCon|01B3|0F|
|RxSofD|01B4|00|
|RxCtrl|01B5|03|
|RxWait|01B6|9C|
|RxThreshold|01B7|74|
|Rcv|01B8|12|
|RxAna|01B9|03|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|01C0|8E|
|TxAmp|01C1|10|
|DrvCon|01C2|01|
|TxI|01C3|06|
|TXCrcPreset|01C4|7B|
|RXCrcPreset|01C5|7B|
|TxDataNum|01C6|08|
|TxModWidth|01C7|00|
|TxSym10BurstLen|01C8|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **152 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|TxWaitCtrl|01C9|88|
|TxWaitLo|01CA|A9|
|TxFrameCon|01CB|0F|
|RxSofD|01CC|00|
|RxCtrl|01CD|02|
|RxWait|01CE|10|
|RxThreshold|01CF|44|
|Rcv|01D0|12|
|RxAna|01D1|06|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|01D4|8F|
|TxAmp|01D5|10|
|DrvCon|01D6|01|
|TxI|01D7|06|
|TXCrcPreset|01D8|74|
|RXCrcPreset|01D9|7B|
|TxDataNum|01DA|18|
|TxModWidth|01DB|00|
|TxSym10BurstLen|01DC|00|
|TxWaitCtrl|01DD|50|
|TxWaitLo|01DE|5C|
|TxFrameCon|01DF|0F|
|RxSofD|01E0|00|
|RxCtrl|01E1|03|
|RxWait|01E2|10|
|RxThreshold|01E3|4E|
|Rcv|01E4|12|
|RxAna|01E5|06|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|01E8|8F|
|TxAmp|01E9|10|
|DrvCon|01EA|09|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **153 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|TxI|01EB|0A|
|TXCrcPreset|01EC|11|
|RXCrcPreset|01ED|91|
|TxDataNum|01EE|09|
|TxModWidth|01EF|00|
|TxSym10BurstLen|01F0|00|
|TxWaitCtrl|01F1|80|
|TxWaitLo|01F2|12|
|TxFrameCon|01F3|01|
|RxSofD|01F4|00|
|RxCtrl|01F5|03|
|RxWait|01F6|A0|
|RxThreshold|01F7|56|
|Rcv|01F8|12|
|RxAna|01F9|0F|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0200|8F|
|TxAmp|0201|10|
|DrvCon|0202|09|
|TxI|0203|0A|
|TXCrcPreset|0204|11|
|RXCrcPreset|0205|91|
|TxDataNum|0206|09|
|TxModWidth|0207|00|
|TxSym10BurstLen|0208|00|
|TxWaitCtrl|0209|80|
|TxWaitLo|020A|12|
|TxFrameCon|020B|01|
|RxSofD|020C|00|
|RxCtrl|020D|03|
|RxWait|020E|A0|
|RxThreshold|020F|56|
|Rcv|0210|12|
|RxAna|0211|0F|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **154 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0214|8F|
|TxAmp|0215|D0|
|DrvCon|0216|01|
|TxI|0217|0A|
|TXCrcPreset|0218|11|
|RXCrcPreset|0219|91|
|TxDataNum|021A|09|
|TxModWidth|021B|00|
|TxSym10BurstLen|021C|00|
|TxWaitCtrl|021D|80|
|TxWaitLo|021E|12|
|TxFrameCon|021F|01|
|RxSofD|0220|00|
|RxCtrl|0221|05|
|RxWait|0222|A0|
|RxThreshold|0223|26|
|Rcv|0224|12|
|RxAna|0225|0E|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0228|8F|
|TxAmp|0229|D0|
|DrvCon|022A|01|
|TxI|022B|0A|
|TXCrcPreset|022C|11|
|RXCrcPreset|022D|91|
|TxDataNum|022E|09|
|TxModWidth|022F|00|
|TxSym10BurstLen|0230|00|
|TxWaitCtrl|0231|80|
|TxWaitLo|0232|12|
|TxFrameCon|0233|01|
|RxSofD|0234|00|
|RxCtrl|0235|05|
|RxWait|0236|A0|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **155 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|RxThreshold|0237|26|
|Rcv|0238|12|
|RxAna|0239|0E|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0240|8E|
|TxAmp|0241|15|
|DrvCon|0242|11|
|TxI|0243|06|
|TXCrcPreset|0244|18|
|RXCrcPreset|0245|18|
|TxDataNum|0246|0F|
|TxModWidth|0247|20|
|TxSym10BurstLen|0248|00|
|TxWaitCtrl|0249|40|
|TxWaitLo|024A|09|
|TxFrameCon|024B|4F|
|RxSofD|024C|00|
|RxCtrl|024D|04|
|RxWait|024E|8F|
|RxThreshold|024F|32|
|Rcv|0250|12|
|RxAna|0251|0A|


|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|DrvMode|0254|8F|
|TxAmp|0255|0E|
|DrvCon|0256|09|
|TxI|0257|0A|
|TXCrcPreset|0258|7B|
|RXCrcPreset|0259|7B|
|TxDataNum|025A|08|
|TxModWidth|025B|00|
|TxSym10BurstLen|025C|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **156 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|EEPROM address (hex)|Value (hex)|
|---|---|---|
|TxWaitCtrl|025D|01|
|TxWaitLo|025E|00|
|TxFrameCon|025F|05|
|RxSofD|0260|00|
|RxCtrl|0261|34|
|RxWait|0262|90|
|RxThreshold|0263|9F|
|Rcv|0264|12|
|RxAna|0265|03|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **157 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
