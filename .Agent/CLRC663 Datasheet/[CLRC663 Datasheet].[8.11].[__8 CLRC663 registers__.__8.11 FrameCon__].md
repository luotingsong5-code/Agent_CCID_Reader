## **8.11 FrameCon**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|TxParityEn|RxParityEn|-|-|StopSym|StopSym|StartSym|StartSym|
|Access<br>rights|r/w|r/w|RFU|RFU|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|TxParityEn|If set, a parity bit is calculated and appended to each byte<br>transmitted.|
|6|RxParityEn|If set, the parity calculation is enabled. The parity is not transferred to<br>the FIFO.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **91 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|5 to 4|-|RFU|
|3 to 2|StopSym|Defines which symbol is sent as stop-symbol:<br>**•** 0h: No symbol is sent<br>**•** 1h: Symbol0 is sent<br>**•** 2 h symbol1 is sent<br>**•** 3h Symbol2 is sent|
|1 to 0|StartSym|Defines which symbol is sent as start-symbol:<br>**•** 0h: No Symbol is sent<br>**•** 1h: Symbol0 is sent<br>**•** 2 h: Symbol1 is sent<br>**•** 3h: Symbol2 is sent|

