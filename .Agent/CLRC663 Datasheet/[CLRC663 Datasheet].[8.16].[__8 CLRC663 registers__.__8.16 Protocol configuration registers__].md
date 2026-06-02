## **8.16 Protocol configuration registers**

### **8.16.1 TxBitMod**









|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|TxMSBFirst|RFU|TxParity<br>Type|RFU|TxStopBitType|RFU|TxStartBitType|TxStartBitEn|
|Access<br>rights|r/w|-|r/w|-|r/w|-|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|TxMSBFirst|If set, data is interpreted MSB first for data transmission. If cleared,<br>data is interpreted LSB first.|
|6|RFU|-|
|5|TxParityType|Defines the type of the parity bit. If set to 1, odd parity is calculated,<br>otherwise even parity is calculated.|
|4|RFU|-|
|3|TxStopBitType|Defines the type of the stop-bit (0b: logic zero / 1b: logic one).|
|2|RFU|-|
|1|TxStartBitType|Defines the type of the start-bit (0b: logic zero / 1b: logic one).|
|0|TxStartBitEn|If set to 1, a start-bit will be sent.|

### **8.16.2 TxDataCon**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|DCodeType|DCodeType|DCodeType|DCodeType|DSCFreq|DBFreq|DBFreq|DBFreq|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **105 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 4|DCodeType|Specifies the type of encoding of data to be used:<br>0h - no special coding<br>1h - collider datastream is decoded<br>2h - RFU 3h - RFU<br>4h - return to zero code - pulse at first position<br>5h - return to zero code - pulse at 2nd position<br>6h - return to zero code - pulse at 3rd position<br>7h - return to zero code - pulse at 4th position<br>8h - 1 out of 4 coding<br>9h - 1 out of 256 code (range 0 - 255) \[ICODE SLI\]<br>Ah - 1 out of 256 code (range 0 - 255; 00h is encoded with no<br>modulation, value 256 not used) \[ICODE 1\]<br>Bh - 1 out of 256 code (range 0 - 255; 00h is encoded with a pulse on<br>last position) \[ICODE quite value\]<br>Ch- Pulse internal encoded (PIE) \[ISO/IEC 18000-3 mode 3/ EPC<br>Class-1HF\]<br>Dh - RFU<br>Eh - RFU<br>Fh - RFU|
|3|DSCFreq|Specifies the subcarrier frequency of the used envelope.<br>0h - 424 kHz<br>1h - 848 kHz<br>Note: This setting is only relevant, if an envelope is used which<br>involves a subcarrier, e.g. Manchester with subcarrier coding.|
|2 to 0|DBFreq|Specifies the frequency of the bit stream:<br>0h - RFU<br>1h - RFU<br>2h - 26 kHz<br>3h - 53 kHz<br>4h - 106 kHz<br>5h - 212 kHz<br>6h - 424 kHz<br>7h - 848 kHz|


### **8.16.3 TxDataMod**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Frame step|DMillerEn|DPulseType|DPulseType|DInvert|DEnvType|DEnvType|DEnvType|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **106 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|Framestep|If set to 1, at every start of transmission, each byte of data is sent<br>in a separate frame. SOF and EOF are appended to the data byte<br>according to the framing settings. After one byte is transmitted, the<br>TxEncoder waits for a new start trigger to continue with the next byte<br>(trigger is generated automatically). If set to 0, transmission is done<br>in the used way, where after a start trigger all data bytes are sent and<br>the framing is done for the complete data stream only once.|
|6|DMillerEn|If set, pulse modulation is applied according to modified miller code.<br>Note: This bit is intended to be set if DPulseType is 1h.|
|5 to 4|DPulseType|Specifies which type of pulse modulation is selected.<br>0 h - no pulse modulation<br>1h - pulse starts at beginning of bit<br>2h - pulse starts at beginning of second bit half<br>3h - pulse starts at beginning of third bit quarter<br>Note: If DMillerEn is set, DPulseType must be set to 1h.|
|3|DInvert|If set the envelope of data is inverted.|
|2 to 0|DEnvType|Specifies the type of envelope used for transmission of data packets.<br>The selected envelope type is applied to the pseudo bit stream.<br>0h - Direct output<br>1h - Manchester code<br>2h - Manchester code with subcarrier<br>3h - BPSK<br>4h - RZ (pulse of half bit length at beginning of second half of bit)<br>5h - RZ (pulse of half bit length at beginning of bit)<br>6h - RFU<br>7h - RFU|


### **8.16.4 TxSymFreq**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|S32SCFreq|S32BFreq|S32BFreq|S32BFreq|S10SCFreq|S10BFreq|S10BFreq|S10BFreq|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|S32SCFreq|Specifies the frequency of the subcarrier of symbol2 and symbol3:<br>0b ... 424 kHz<br>1b ... 848 kHz|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **107 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6 to 4|S32BFreq|Specifies the frequency of the bit stream of symbol2 and symbol3:<br>000b ... RFU<br>001b ... RFU<br>010b ... 26 kHz<br>011b ... 53 kHz<br>100b ... 106 kHz<br>101b ... 212 kHz<br>110b ... 424 kHz<br>111b ... 848 kHz|
|3|S10SCFreq|Specifies the frequency of the subcarrier of symbol0 and symbol1:<br>0b ...424 kHz<br>1b ...848 kHz|
|2 to 0|S10BFreq|Specifies the frequency of the bit stream of symbol0 and symbol1:<br>000b ... RFU<br>001b ... RFU<br>010b ... 26 kHz<br>011b ... 53 kHz<br>100b ... 106 kHz<br>101b ... 212 kHz<br>110b ... 424 kHz<br>111b ... 848 kHz|


### **8.16.5 TxSym0**

The two Registers TxSym0_H and TxSym0_L create a 16-bit register that contains the
pattern for Symbol0.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol0_H|Symbol0_H|Symbol0_H|Symbol0_H|Symbol0_H|Symbol0_H|Symbol0_H|Symbol0_H|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|




|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol0_H|Higher 8 bits of symbol definition for Symbol0.|






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol0_L|Symbol0_L|Symbol0_L|Symbol0_L|Symbol0_L|Symbol0_L|Symbol0_L|Symbol0_L|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **108 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol0_L|Lower 8 bits of symbol definition for Symbol0.|


### **8.16.6 TxSym1**

The two Registers TxSym1_H and TxSym1_L create a 16 bit register that contains the
pattern for Symbol1.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol1_H|Symbol1_H|Symbol1_H|Symbol1_H|Symbol1_H|Symbol1_H|Symbol1_H|Symbol1_H|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|




|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol1_H|Higher 8 bits of symbol definition for Symbol1.|






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol1_L|Symbol1_L|Symbol1_L|Symbol1_L|Symbol1_L|Symbol1_L|Symbol1_L|Symbol1_L|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol1_L|Lower 8 bits of symbol definition for Symbol1.|

### **8.16.7 TxSym2**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol2|Symbol2|Symbol2|Symbol2|Symbol2|Symbol2|Symbol2|Symbol2|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol2|Symbol definition for Symbol2.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **109 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.16.8 TxSym3**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Symbol3|Symbol3|Symbol3|Symbol3|Symbol3|Symbol3|Symbol3|Symbol3|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|Symbol3|Symbol definition for Symbol3.|

### **8.16.9 TxSym10Len**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Sym1Len|Sym1Len|Sym1Len|Sym1Len|Sym0Len|Sym0Len|Sym0Len|Sym0Len|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|Sym1Len|Specifies the number of valid bits of the symbol definition of Symbol1.<br>The range is from 1 bit (0h) to 16 bits (Fh).|
|3 to 0|Sym0Len|Specifies the number of valid bits of the symbol definition of Symbol0.<br>The range is from 1 bit (0h) to 16 bits (Fh).|

### **8.16.10 TxSym32Len**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|Sym3Len|Sym3Len|Sym3Len|RFU|Sym2Len|Sym2Len|Sym2Len|
|Access<br>rights|-|r/w|r/w|r/w|-|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|
|6 to 4|Sym3Len|Specifies the number of valid bits of the symbol definition of Symbol3.<br>The range is from 1 bit (0h) to 8 bits (7h).|
|3|RFU|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **110 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|2 to 0|Sym2Len|Specifies the number of valid bits of the symbol definition of Symbol2.<br>The range is from 1 bit (0h) to 8 bits (7h).|


### **8.16.11 TxSym10BurstCtrl**











|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|Sym1BurstType|Sym1BurstOnly|Sym1BurstEn|RFU|Sym0Burst<br>Type|Sym0B<br>urstOnly|Sym0B<br>urstEn|
|Access<br>rights|-|r/w|r/w|r/w|-|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|
|6|Sym1BurstType|Specifies the type of the burst of Symbol1 (logical zero / logical<br>one).|
|5|Sym1BurstOnly|If set to 1 Symbol1 consists only of a burst and no symbol<br>pattern.|
|4|Sym1BurstEn|Enables the burst of symbol 1 of the length defined in<br>TxSym10BurstLen.|
|3|RFU|-|
|2|Sym0BurstType|Specifies the type of the burst of symbol 0 (logical zero / logical<br>one).|
|1|Sym0BurstOnly|If set to 1, symbol 0 consists only of a burst and no symbol<br>pattern.|
|0|Sym0BurstEn|Enables the burst of symbol 0 of the length defined in<br>TxSym10BurstLen.|

### **8.16.12 TxSym10Mod Reg**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|S10MillerEn|S10PulseType|S10PulseType|S10Inv|S10EnvType|S10EnvType|S10EnvType|
|Access<br>rights|-|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **111 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6|S10MillerEn|If set, pulse modulation is applied according to modified miller code.<br>Note: This bit shall be set only if S10PulseType is set to 1h.|
|5 to 4|S10PulseType|Specifies which type of pulse modulation is selected:<br>0h - no pulse modulation<br>1h - pulse starts at beginning of bit<br>2h - pulse starts at beginning of second bit half<br>3h - pulse starts at beginning of third bit quarter|
|3|S10Inv|If set. the output of Symbol0 and Symbol1 is inverted.|
|2 to 0|S10EnvType|Specifies the type of envelope used for transmission of Symbol0<br>and Symbol1. The pseudo bit stream is logically combined with the<br>selected envelope type.<br>0h - Direct output<br>1h - Manchester code<br>2h - Manchester code with subcarrier<br>3h - BPKSK<br>4h - RZ return zero, pulse of half bit length at beginning of second half<br>of bit<br>5h - RZ return zero, pulse of half bit length at beginning of second half<br>of bit<br>6h - RFU<br>7h - RFU|


### **8.16.13 TxSym32Mod**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|S32MillerEn|S32PulseType|S32PulseType|S32Inv|S32EnvType|S32EnvType|S32EnvType|
|Access<br>rights|-|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|
|6|S32MillerEn|If set, pulse modulation is applied according to modified miller code.<br>Note: This bit shall be set only if S32PulseType is set to 1h.|
|5 to 4|S32PulseType|Specifies which type of pulse modulation is selected:<br>0h - no pulse modulation<br>1h - pulse starts at beginning of bit<br>2h - pulse starts at beginning of second bit half<br>3h - pulse starts at beginning of third bit quarter|
|3|S32Inv|If set. the output of Symbol2 and Symbol3 is inverted.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **112 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|2 to 0|S32EnvType|Specifies the type of envelope used for transmission of symbol 0<br>and symbol 1. The bit stream is logically combined with the selected<br>envelope type.<br>0h - Direct output<br>1h - Manchester code<br>2h - Manchester code with subcarrier<br>3h - BPSK<br>4h - RZ return zero, pulse of half bit length at beginning of second half<br>of bit)<br>5h - RZ return zero, pulse of half bit length at beginning of bit)<br>6h to 7h RFU|

