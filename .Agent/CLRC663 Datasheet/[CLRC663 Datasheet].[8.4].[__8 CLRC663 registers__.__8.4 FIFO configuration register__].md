## **8.4 FIFO configuration register**

### **8.4.1 FIFOControl**

FIFOControl defines the characteristics of the FIFO












|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|FIFOSize|HiAlert|LoAlert|FIFOFlush|RFU|WaterLe<br>velExtBit|FIFOLengthExtBits|FIFOLengthExtBits|
|Access<br>rights|r/w|r|r|w|-|r/w|r|r|


|Bit|Symbol|Description|
|---|---|---|
|7|FIFOSize|Set to logic 1, FIFO size is 255 bytes;<br>Set to logic 0, FIFO size is 512 bytes.<br>It is recommended to change the FIFO size only, when the FIFO<br>content had been cleared.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **64 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6|HiAlert|Set to logic 1, when the number of bytes stored in the FIFO buffer<br>fulfils the following equation:<br>HiAlert = (FIFOSize - FIFOLength) <= WaterLevel|
|5|LoAlert|Set to logic 1, when the number of bytes stored in the FIFO buffer<br>fulfils the following conditions:<br>LoAlert =1 if FIFOLength <= WaterLevel|
|4|FIFOFlush|Set to logic 1 clears the FIFO buffer. Reading this bit will always<br>return 0|
|3|RFU|-|
|2|WaterLevelExtBit|Defines the bit 8 (MSB) for the waterlevel (extension of register<br>WaterLevel). This bit is only evaluated in the 512-byte FIFO mode.<br>Bits 7..0 are defined in register WaterLevel.|
|1 to 0|FIFOLengthExtBits|Defines the bit9 (MSB) and bit8 for the FIFO length (extension of<br>FIFOLength). These two bits are only evaluated in the 512-byte<br>FIFO mode. The bits 7..0 are defined in register FIFOLength.|


### **8.4.2 WaterLevel**

Defines the level for FIFO under- and overflow warning levels.This register is extended
by 1 bit in FIFOControl in case the 512-byte FIFO mode is activated by setting bit
FIFOControl.FIFOSize.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|WaterLevelBits|WaterLevelBits|WaterLevelBits|WaterLevelBits|WaterLevelBits|WaterLevelBits|WaterLevelBits|WaterLevelBits|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 0|WaterLevelBits|Sets a level to indicate a FIFO-buffer state which can be read<br>from bits HighAlert and LowAlert in the FifoControl. In 512-byte<br>FIFO mode, the register is extended by bit WaterLevelExtBit in the<br>FIFOControl. This functionality can be used to avoid a FIFO buffer<br>overflow or underflow:<br>The bit HiAlert bit in FIFO Control is read logic 1, if the number of<br>bytes in the FIFO-buffer is equal or less than the number defined by<br>the waterlevel configuration.<br>The bit LoAlert bit in FIFO control is read logic 1, if the number of<br>bytes in the FIFO buffer is equal or less than the number defined by<br>the waterlevel configuration.<br>Note: For the calculation of HiAlert and LoAlert, see register<br>description of these bits (see sectionSection 8.4.1).|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **65 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.4.3 FIFOLength**

Number of bytes in the FIFO buffer. In 512-byte mode, this register is extended by
FIFOControl.FifoLength.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|FIFOLength|FIFOLength|FIFOLength|FIFOLength|FIFOLength|FIFOLength|FIFOLength|FIFOLength|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|FIFOLength|Indicates the number of bytes in the FIFO buffer. In 512-byte mode<br>this register is extended by the bits FIFOLength in the FIFOControl<br>register. Writing to the FIFOData register increments, reading<br>decrements the number of available bytes in the FIFO.|

### **8.4.4 FIFOData**

In- and output of FIFO buffer. Contrary to any read/write access to other addresses,
reading or writing to the FIFO address does not increment the address pointer. Writing
to the FIFOData register increments, reading decrements the number of bytes present in
the FIFO.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|FIFOData|FIFOData|FIFOData|FIFOData|FIFOData|FIFOData|FIFOData|FIFOData|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|


|Bit|Symbol|Description|
|---|---|---|
|7 to 0|FIFOData|Data input and output port for the internal FIFO buffer. Refer to<br>Section 7.5 "Buffer".|
