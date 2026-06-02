## **8.9 Transmitter CRC configuration registers**

### **8.9.1 TxCrcPreset**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|TXPresetVal|TXPresetVal|TXPresetVal|TxCRCtype|TxCRCtype|TxCRCInvert|TxCRCEn|
|Access<br>rights|-|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **86 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6 to 4|TXPresetVal|Specifies the CRC preset value for transmission (see following table).|
|3 to 2|TxCRCtype|Defines which type of CRC (CRC8/CRC16/CRC5) is calculated:<br>**•** 00h -- CRC5<br>**•** 01h -- CRC8<br>**•** 02h -- CRC16<br>**•** 03h -- RFU|
|1|TxCRCInvert|if set, the resulting CRC is inverted and attached to the data frame<br>(ISO/IEC 3309)|
|0|TxCRCEn|if set, a CRC is appended to the data stream|


|TXPresetVal\[6...4\]|CRC16|CRC8|CRC5|
|---|---|---|---|
|0h|0000h|00h|00h|
|1h|6363h|12h|12h|
|2h|A671h|BFh|-|
|3h|FFFEh|FDh|-|
|4h|-|-|-|
|5h|-|-|-|
|6h|User defined|User defined|User defined|
|7h|FFFFh|FFh|1Fh|



**Remark:** User-defined CRC preset values can be configured by EEPROM (see section
Section 7.7.2.1, Table 37.

### **8.9.2 RxCrcCon**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxForceCRCWrite|RXPresetVal|RXPresetVal|RXPresetVal|RXCRCtype|RXCRCtype|RxCRCInvert|RxCRCEn|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|







|Bit|Symbol|Description|
|---|---|---|
|7|RxForceCrc<br>Write|If set, the received CRC byte(s) are copied to the FIFO.<br>If cleared CRC Bytes are only checked, but not copied to the FIFO.<br>This bit has to be always set in case of a not byte aligned CRC (e.g.<br>ISO/IEC 18000-3 mode 3/ EPC Class-1HF)|
|6 to 4|RXPresetVal|Defines the CRC preset value (Hex.) for transmission. (see following<br>table).|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **87 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|3 to 2|RxCRCtype|Defines which type of CRC (CRC8/CRC16/CRC5) is calculated:<br>**•** 00h -- CRC5<br>**•** 01h -- CRC8<br>**•** 02h -- CRC16<br>**•** 03h -- RFU|
|1|RxCrcInvert|If set, the CRC check is done for the inverted CRC.|
|0|RxCrcEn|If set, the CRC is checked and in case of a wrong CRC an error flag is<br>set. Otherwise the CRC is calculated but the error flag is not modified.|


|RXPresetVal\[6...4\]|CRC16|CRC8|CRC5|
|---|---|---|---|
|0h|0000h|00h|00h|
|1h|6363h|12h|12h|
|2h|A671h|BFh|-|
|3h|FFFEh|FDh|-|
|4h|-|-|-|
|5h|-|-|-|
|6h|User defined|User defined|User defined|
|7h|FFFFh|FFh|1Fh|

