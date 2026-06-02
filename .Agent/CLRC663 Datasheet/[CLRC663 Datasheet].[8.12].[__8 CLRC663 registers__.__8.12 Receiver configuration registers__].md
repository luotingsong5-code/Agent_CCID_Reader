## **8.12 Receiver configuration registers**

### **8.12.1 RxSofD**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|RFU|SOF_En|SOFDetected|RFU|SubC_En|SubC_Detected|SubC_Present|
|Access<br>rights|-|-|r/w|dy|-|r/w|dy|r|


|Bit|Symbol|Description|
|---|---|---|
|7 to 6|RFU|-|
|5|SOF_En|If set and a SOF is detected an RxSOFIRQ is raised.|
|4|SOF_Detected|Shows that a SOF is or was detected. Can be cleared by SW.|
|3|RFU|-|
|2|SubC_En|If set and a subcarrier is detected an RxSOFIRQ is raised.|
|1|SubC_Detected|Shows that a subcarrier is or was detected. Can be cleared by SW.|
|0|SubC_Present|Shows that a subcarrier is currently detected.|

### **8.12.2 RxCtrl**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxAllowBits|RxMultiple|RxEOFType|EGT_Check|EMD_Sup|Baudrate|Baudrate|Baudrate|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **92 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|RxAllowBits|If set, data is written into FIFO even if CRC is enabled, and no<br>complete byte has been received.|
|6|RxMultiple|If set, RxMultiple is activated and the receiver will not terminate<br>automatically (refer Section Section 7.10.3.6.<br>If set to logic 1, at the end of a received data stream an error byte is<br>added to the FIFO. The error byte is a copy of the Error register.|
|5|RxEOFType|0: EOF as defined in the RxEOFSymbolReg is expected.<br>1: ISO/IEC14443B EOF is expected.<br>Note: Clearing this bit to 0 and clearing bit 0 and bit 1 in the<br>RxEOFSymbolReg disables the EOF check.|
|4|EGT_Check|If set to 1, the EGT is checked and if it is too long<br>a protocol error is set. (This is only valid for ISO/IEC14443 Type B).|
|3|EMD_Sup|Enables the EMD suppression according to ISO/IEC14443. If an error<br>occurs within the first three bytes, these three bytes are assumed to<br>be EMD, ignored and the FIFO is reset. A collision is treated as an<br>error as well If a valid SOF was received, the EMD_Sup is set and a<br>frame of less than 3 bytes had been received. RX_IRQ is not set in<br>this EMD error cases. If RxForceCRCWrite is set, the FIFO should not<br>be read out before three bytes are written into.|
|2 to 0|Baudrate|Defines the baud rate of the receiving signal.<br>2h: 26 kBd<br>3h: 52 kBd<br>4h: 106 kBd<br>5h: 212 kBd<br>6h: 424 kBd<br>7h: 847 kBd<br>all remaining values are RFU|


### **8.12.3 RxWait**

Selects internal receiver settings.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RxWaitEtu|RxWait|RxWait|RxWait|RxWait|RxWait|RxWait|RxWait|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|RXWaitEtu|If set to 0, the RxWait time is RxWait × 16/13.56 MHz.<br>If set to 1, the RxWait time is RxWait × (0.5/DBFreq).|
|6 to 0|RxWait|Defines the time after sending, where every input is ignored.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **93 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.12.4 RxThreshold**

Selects minimum threshold level for the bit decoder.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|MinLevel|MinLevel|MinLevel|MinLevel|MinLevelP|MinLevelP|MinLevelP|MinLevelP|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|MinLevel|Defines the MinLevel of the reception.<br>Note: The MinLevel should be higher than the noise level in the system.|
|3 to 0|MinLevelP|Defines the MinLevel of the phase shift detector unit.|

### **8.12.5 Rcv**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Rcv_Rx_single|Rx_ADCmode|SigInSel|SigInSel|RFU|RFU|CollLevel|CollLevel|
|Access<br>rights|r/w|r/w|r/w|r/w|-|-|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|Rcv_Rx_single|Single RXP Input Pin Mode;<br>0: Fully Differential<br>1: Quasi-Differential|
|6|Rx_ADCmode|Defines the operation mode of the Analog Digital Converter (ADC)<br>0: normal reception mode for ADC<br>1: LPCD mode for ADC|
|5 to 4|SigInSel|Defines input for the signal processing unit:<br>0h - idle<br>1h - internal analog block (RX)<br>2h - signal in over envelope (ISO/IEC14443A)<br>3h - signal in over s3c-generic|
|3 to 2|RFU|-|
|1 to 0|CollLevel|Defines the strength of a signal to be interpreted as a collision:<br>0h - Collision has at least 1/8 of signal strength<br>1h - Collision has at least 1/4 of signal strength<br>2h - Collision has at least 1/2 of signal strength<br>3h - Collision detection is switched off|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **94 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.12.6 RxAna**

This register allows setting the gain (rcv_gain) and high pass corner frequencies
(rcv_hpcf).






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|VMid_r_sel|VMid_r_sel|RFU|RFU|rcv_hpcf|rcv_hpcf|rcv_gain|rcv_gain|
|Access<br>rights|r/w|r/w|-|-|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7, 6|VMid_r_sel|Factory trim value, needs to be 0.|
|5, 4|RFU||
|3, 2|rcv_hpcf|The rcv_hpcf \[1:0\] signals allow 4 different settings of the base band<br>amplifier high pass cut-off frequency from ~40 kHz to ~300 kHz.|
|1 to 0|rcv_gain|With rcv_gain\[1:0\] four different gain settings from 30 dB and 60<br>dB can be configured (differential output voltage/differential input<br>voltage).|









|rcv_gain<br>(Hex.)|rcv_hpcf<br>(Hex.)|fl (kHz)|fU (MHz)|gain (dB20)|bandwidth<br>(MHz)|
|---|---|---|---|---|---|
|03|00|38|2.3|60|2.3|
|03|01|79|2.4|59|2.3|
|03|02|150|2.6|58|2.5|
|03|03|264|2.9|55|2.6|
|02|00|41|2.3|51|2.3|
|02|01|83|2.4|50|2.3|
|02|02|157|2.6|49|2.4|
|02|03|272|3.0|41|2.7|
|01|00|42|2.6|43|2.6|
|01|01|84|2.7|42|2.6|
|01|02|157|2.9|41|2.7|
|01|03|273|3.3|39|3.0|
|00|00|43|2.6|35|2.6|
|00|01|85|2.7|34|2.6|
|00|02|159|2.9|33|2.7|
|00|03|276|3.4|30|3.1|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **95 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
