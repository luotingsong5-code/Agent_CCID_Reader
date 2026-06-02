## **8.10 Transmitter data configuration registers**

### **8.10.1 TxDataNum**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|RFU-|RFU-|KeepBitGrid|DataEn|TxLastBits|TxLastBits|TxLastBits|
|Access<br>rights||||r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 5|RFU|-|
|4|KeepBitGrid|If set, the time between consecutive transmissions starts is a multiple<br>of one ETU. If cleared, consecutive transmissions can even start<br>within one ETU|
|3|DataEn|If cleared - it is possible to send a single symbol pattern.<br>If set - data is sent.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **88 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|2 to 0|TxLastBits|Defines how many bits of the last data byte to be sent. If set to 000b,<br>all bits of the last data byte are sent.<br>Note - bits are skipped at the end of the byte.<br>Example - Data byte B2h (sent LSB first).<br>TxLastBits = 011b (3h) => 010b (LSB first) is sent<br>TxLastBits = 110b (6h) => 010011b (LSB first) is sent|


### **8.10.2 TxDATAModWidth**

Transmitter data modulation width register






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|DModWidth|DModWidth|DModWidth|DModWidth|DModWidth|DModWidth|DModWidth|DModWidth|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|DModWidth|Specifies the length of a pulse for sending data with enabled pulse<br>modulation. The length is given by the number of carrier clocks + 1.<br>A pulse can never be longer than from the start of the pulse to the<br>end of the bit. The starting position of a pulse is given by the setting<br>of TxDataMod.DPulseType. Note: This register is only used if Miller<br>modulation (ISO/IEC 14443A PCD) is used. The settings are also<br>used for the modulation width of start and/or stop symbols.|

### **8.10.3 TxSym10BurstLen**

If a protocol requires a burst (an unmodulated subcarrier) the length can be defined with
this TxSymBurstLen, the value high or low can be defined by TxSym10BurstCtrl.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|Sym1Burst Len|Sym1Burst Len|Sym1Burst Len|RFU|Sym0Burst Len|Sym0Burst Len|Sym0Burst Len|
|Access<br>rights|-|r/w|r/w|r/w|-|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **89 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6 to 4|Sym1BurstLen|Specifies the number of bits issued for symbol 1 burst. The 3 bits<br>encodes a range from 8 to 256 bit:<br>00h - 8bit<br>01h - 16bit<br>02h - 32bit<br>04h - 48bit<br>05h - 64bit<br>06h - 96bit<br>07h - 128bit<br>08h - 256bit|
|3|RFU|-|
|2 to 0|Sym0BurstLen|Specifies the number of bits issued for symbol 1 burst. The 3 bits<br>encodes a range from 8 to 256 bit:<br>00h - 8bit<br>01h - 16bit<br>02h - 32bit<br>03h - 48bit<br>04h - 64bit<br>05h - 96bit<br>06h - 128bit<br>07h - 256bit|


### **8.10.4 TxWaitCtrl**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|TxWaitStart|TxWaitEtu|TxWait High|TxWait High|TxWait High|TxStopBitLength|TxStopBitLength|TxStopBitLength|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|TxWaitStart|If cleared, the TxWait time is starting at the End of the send data<br>(TX).<br>If set, the TxWait time is starting at the End of the received data<br>(RX).|
|6|TxWaitEtu|If cleared, the TxWait time is TxWait × 16/13.56 MHz.<br>If set, the TxWait time is TxWait × 0.5 / DBFreq (DBFreq is the<br>frequency of the bit stream as defined by TxDataCon).|
|5 to 3|TxWait High|Bit extension of TxWaitLo. TxWaitCtrl bit 5 is MSB.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **90 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|2 to 0|TxStopBitLength|Defines stop-bits and EGT (= stop-bit + extra guard time EGT) to<br>be sent:<br>0h: no stop-bit, no EGT<br>1h: 1 stop-bit, no EGT<br>2h: 1 stop-bit + 1 EGT<br>3h: 1 stop-bit + 2 EGT<br>4h: 1 stop-bit + 3 EGT<br>5h: 1 stop-bit + 4 EGT<br>6h: 1 stop-bit + 5 EGT<br>7h: 1 stop-bit + 6 EGT<br>Note: This is only valid for ISO/IEC14443 Type B|


### **8.10.5 TxWaitLo**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|TxWaitLo|TxWaitLo|TxWaitLo|TxWaitLo|TxWaitLo|TxWaitLo|TxWaitLo|TxWaitLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|TxWaitLo|Defines the minimum time between receive and send or between two<br>send data streams<br>Note: TxWait is a 11bit register (additional 3 bits are in the TxWaitCtrl<br>register)!<br>See also TxWaitEtu and TxWaitStart.|
