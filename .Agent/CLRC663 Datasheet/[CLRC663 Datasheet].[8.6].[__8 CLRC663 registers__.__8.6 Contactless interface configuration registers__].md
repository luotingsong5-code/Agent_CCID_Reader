## **8.6 Contactless interface configuration registers**

### **8.6.1 Error**

Error register.








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|EE_Err|FiFoWrErr|FIFOOvl|MinFrameErr|NoDataErr|CollDet|ProtErr|IntegErr|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **69 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_







|Bit|Symbol|Description|
|---|---|---|
|7|EE_Err|An error appeared during the last EEPROM command. For<br>details see the descriptions of the EEPROM commands|
|6|FIFOWrErr|Data was written into the FIFO, during a transmission of a possible<br>CRC, during "RxWait", "Wait for data" or "Receiving" state, or during an<br>authentication command. The Flag is cleared when a new CL command is<br>started. If RxMultiple is active, the flag is cleared after the error flags have<br>been written to the FIFO.|
|5|FIFOOvl|Data is written into the FIFO when it is already full. The data that is already<br>in the FIFO remains untouched. All data that is written to the FIFO after this<br>Flag is set to 1 will be ignored.|
|4|Min<br>FrameErr|A valid SOF was received, but afterwards less than 4 bits of data were<br>received.<br>Note: Frames with less than 4 bits of data are automatically discarded and<br>the RxDecoder stays enabled. Furthermore no RxIRQ is set. The same is<br>valid for less than 3 bytes, if the EMD suppression is activated<br>Note: MinFrameErr is automatically cleared at the start of a receive or<br>transceive command. In case of a transceive command, it is cleared at the<br>start of the receiving phase ("Wait for data" state)|
|3|NoDataErr|Data should be sent, but no data is in FIFO|
|2|CollDet|A collision has occurred. The position of the first collision is shown in the<br>register RxColl.<br>Note: CollDet is automatically cleared at the start of a receive or transceive<br>command. In case of a transceive command, it is cleared at the start of the<br>receiving phase ("Wait for data" state).<br>Note: If a collision is part of the defined EOF symbol, CollDet is not set to 1.|
|1|ProtErr|A protocol error has occurred. A protocol error can be a wrong stop bit,<br>a missing or wrong ISO/IEC14443B EOF or SOF or a wrong number of<br>received data bytes. When a protocol error is detected, data reception is<br>stopped.<br>Note: ProtErr is automatically cleared at start of a receive or transceive<br>command. In case of a transceive command, it is cleared at the start of the<br>receiving phase ("Wait for data" state).<br>Note: When a protocol error occurs the last received data byte is not written<br>into the FIFO.|
|0|IntegErr|A data integrity error has been detected. Possible cause can be a wrong<br>parity or a wrong CRC. In case of a data integrity error the reception is<br>continued.<br>Note: IntegErr is automatically cleared at start of a Receive or Transceive<br>command. In case of a Transceive command, it is cleared at the start of the<br>receiving phase ("Wait for data" state).<br>Note: If the NoColl bit is set, also a collision is setting the IntegErr.|

### **8.6.2 Status**

Status register.

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|-|-|Crypto1On|-|-|ComState|ComState|ComState|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **70 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Access<br>rights|RFU|RFU|dy|RFU|RFU|r|r|r|



|Bit|Symbol|Description|
|---|---|---|
|7 to 6|-|RFU|
|5|Crypto1On|Indicates if the MIFARE Classic Crypto is on. Clearing this bit is switching<br>the MIFARE Cassic Crypto off. The bit can only be set by the MFAuthent<br>command.|
|4 to 3|-|RFU|
|2 to 0|ComState|ComState shows the status of the transmitter and receiver state machine:|
|2 to 0|ComState|000b ... Idle|
|2 to 0|ComState|001b ... TxWait|
|2 to 0|ComState|011b ... Transmitting|
|2 to 0|ComState|101b ... RxWait|
|2 to 0|ComState|110b ... Wait for data|
|2 to 0|ComState|111b ... Receiving|
|2 to 0|ComState|100b ... not used|

### **8.6.3 RxBitCtrl**





Receiver control register.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|ValuesAfterColl|RxAlign|RxAlign|RxAlign|NoColl|RxLastBits|RxLastBits|RxLastBits|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|w|w|w|






|Bit|Symbol|Description|
|---|---|---|
|7|ValuesAfter<br>Coll|If cleared, every received bit after a collision is replaced by a zero. This<br>function is needed for ISO/IEC14443 anticollision|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **71 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6 to 4|RxAlign|Used for reception of bit oriented frames: RxAlign defines the bit position<br>length for the first bit received to be stored. Further received bits are<br>stored at the following bit positions.<br>Example:<br>RxAlign = 0h - the LSB of the received bit is stored at bit 0, the second<br>received bit is stored at bit position 1.<br>RxAlign = 1h - the LSB of the received bit is stored at bit 1, the second<br>received bit is stored at bit position 2.<br>RxAlign = 7h - the LSB of the received bit is stored at bit 7, the second<br>received bit is stored in the following byte at position 0.<br>Note: If RxAlign = 0, data is received byte-oriented, otherwise bit-<br>oriented.|
|3|NoColl|If this bit is set, a collision will result in an IntegErr|
|2 to 0|RxLastBits|Defines the number of valid bits of the last data byte received in bit-<br>oriented communications. If zero the whole byte is valid.<br>Note: These bits are set by the RxDecoder in a bit-oriented<br>communication at the end of the communication. They are reset at start<br>of reception.|


### **8.6.4 RxColl**

Receiver collision register.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|CollPosValid|CollPos|CollPos|CollPos|CollPos|CollPos|CollPos|CollPos|
|Access<br>rights|r|r|r|r|r|r|r|r|







|Bit|Symbol|Description|
|---|---|---|
|7|CollPos<br>Valid|If set to 1, the value of CollPos is valid. Otherwise no collision is detected or<br>the position of the collision is out of the range of bits CollPos.|
|6 to 0|CollPos|These bits show the bit position of the first detected collision in a received<br>frame (only data bits are interpreted). CollPos can only be displayed for the<br>first 8 bytes of a data stream.<br>Example:<br>00h indicates a bit collision in the 1st bit<br>01h indicates a bit collision in the 2nd bit<br>08h indicates a bit collision in the 9th bit (1st bit of 2nd byte)<br>3Fh indicates a bit collision in the 64th bit (8th bit of the 8th byte)<br>These bits shall only be interpreted in Passive communication mode at 106<br>kbit/s or ISO/IEC 14443 type A and read /write mode for MIFARE Classic or<br>ISO/IEC 15693/ICODE SLI read/write mode if bit CollPosValid is set.<br>Note: If RxBitCtrl.RxAlign is set to a value different to 0, this value is<br>included in the CollPos.<br>Example: RxAlign = 4h, a collision occurs in the 4th received bit (which is<br>the last bit of that UID byte). The CollPos = 7h in this case.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **72 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
