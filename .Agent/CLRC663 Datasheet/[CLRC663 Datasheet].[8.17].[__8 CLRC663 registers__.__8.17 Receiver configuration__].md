## **8.17 Receiver configuration**

### **8.17.1 RxBitMod**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|RFU|RxStopOnInvPar|RxStopOnLength|RxMSBFirst|RxStopBitEn|RxParityType|RFU|
|Access<br>rights|-|-|r/w|r/w|r/w|r/w|r/w|-|


|Bit|Symbol|Description|
|---|---|---|
|7 to 6|RFU|-|
|5|RxStopOnInvPar|If set to 1, inverse parity bit is a stop condition.|
|4|RxStopOnLength|If set to 1, data reception stops when the number of received<br>bytes reach the defined frame length. The value for the<br>frame length is taken from the first data-byte received.|
|3|RxMSBFirst|If set to 1, data bytes are interpreted MSB first for data<br>reception, which means data is converted at the CLCoPro<br>interface. If this bit is set to 0, data is interpreted LSB first.|
|2|RxStopBitEn|If set, a stop-bit is expected and will be checked and<br>extracted from data stream. Additionally on detection of<br>a stop-bit a reset signal for the demodulator is generator<br>to enable a resynchronization of the demodulator. If the<br>expected stop-bit is incorrect, a frame error flag is set and<br>the reception is aborted.<br>Note: A stop bit is always considered to be a logic 1|
|1|RxParityType|Defines which type of the parity-bit is calculated:<br>If cleared: Even parity<br>If set: Odd parity|
|0|RFU|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **113 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.17.2 RxEofSym**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|RxEOFSymbol|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|





|Bit|Symbol|Description|
|---|---|---|
|7 to 0|RxEOF<br>Symbol|This value defines the pattern of the EOF symbol with a maximum<br>length of 4 bit. Every tuple of 2 bits of the RxEOFSymbol encodes<br>one bit of the EOF symbol. A 00 tuple closes the symbol. In this way<br>symbols with less than 4 bits can be defined, starting with the bit0<br>and bit1. The leftmost active symbol pattern is processed first, which<br>means the pattern is expected first. If the bit0 and bit1 are both zero,<br>the EOF symbol is disabled. The following mapping is defined:<br>0h - no symbol bit<br>1h - zero value<br>2h - one value<br>3h - collision<br>Example:<br>1Dh: Zero-Collision-Zero<br>E8h: No symbol because two LSBits are zero|

### **8.17.3 RxSyncValH**










|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxSyncValH|RxSyncValH|RxSyncValH|RxSyncValH|RxSyncValH|RxSyncValH|RxSyncValH|RxSyncValH|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|RxSyncValH|Defines the high byte of the Start Of Frame (SOF) pattern, which must<br>be in front of the receiving data.|

### **8.17.4 RxSyncValL**

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxSyncValL|RxSyncValL|RxSyncValL|RxSyncValL|RxSyncValL|RxSyncValL|RxSyncValL|RxSyncValL|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **114 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|RxSyncValL|Defines the low byte of the Start Of Frame (SOF) Pattern, which must<br>be in front of the receiving data.|

### **8.17.5 RxSyncMod**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|SyncLen|SyncLen|SyncLen|SyncLen|SyncNegEdge|LastSyncHalf|SyncType|SyncType|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|SyncLen|Defines how many Bits of registers RxSyncValH and RxSyncValL are<br>valid. For ISO/IEC 14443B set to 0.|
|3|SyncNegEdge|Is used for SOF with no correlation peak. The first negative edge of<br>the correlation is used for defining the bit grid.|
|2|LastSyncHalf|The last Bit of the Sync mode has only half of the length compared to<br>all other bits. (ISO/IEC 18000-3 mode 3/ EPC Class-1HF).|
|1 to 0|SyncType|0: all 16 bits of SyncVal are interpreted as burst.<br>1: a nibble of bits is interpreted as one bit in following way:<br>{data, coll} data = zero or one; coll = 1 means a collision on this bit.<br>Note: if Coll = 1 the value of data is ignored.<br>2: the synchronization is done at every start bit of each byte (type B)<br>3: RFU|

### **8.17.6 RxMod**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|RFU|PreFilter|RectFilter|SyncHigh|CorrInv|FSK|BPSK|
|Access<br>rights|-|-|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **115 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 6|-|RFU|
|5|PreFilter|If set 4 samples are combined to one data. (average).|
|4|RectFilter|If set, the ADC-values are changed to a more rectangular wave<br>shape.|
|3|SyncHigh|Defines if the bit grid is fixed at maximum (1) or at minimum (0) value<br>of the correlation.|
|2|CorrInv|Defines a logical for Manchester coding:<br>0: subcarrier / no subcarrier.|
|1|FSK|If set to 1, the demodulation scheme is set to FSK.|
|0|BPSK|If set to 1, the modulation scheme is BPSK.|


### **8.17.7 RxCorr**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|CorrFreq|CorrFreq|CorrSpeed|CorrSpeed|CorrLen|RFU|RFU|RFU|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|-|-|-|


|Bit|Symbol|Description|
|---|---|---|
|7, 6|CorrFreq|0h - 212 kHz<br>1h - 424 kHz<br>2h - 848 kHz<br>3h - 848 kHz|
|5, 4|CorrSpeed|Defines the number of clocks used for one correlation.<br>0h - ISO/IEC 14443<br>1h - ICODE 53 kBd, FeliCa 424 kBd<br>2h - ICODE 26 kBd, FeliCa 212 kBd<br>3h - RFU|
|3|CorrLen|Defines the length of the correlation data. (64 or 32 values).<br>If set the lengths of the correlation data is 32 values. (ISO/IEC<br>18000-3 mode 3/ EPC Class-1HF, 2 Pulse Manchester 848 kHz<br>subcarrier).|
|2 to 0|RFU|-|

### **8.17.8 FabCali**



|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|FabCali|FabCali|FabCali|FabCali|FabCali|FabCali|FabCali|FabCali|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **116 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|FabCali|Fabrication calibration of the receiver.<br>NOTE: do not change boot value.|
