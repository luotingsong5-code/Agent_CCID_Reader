## **8.8 Transmitter driver configuration registers**

### **8.8.1 TxMode**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Tx2Inv|Tx1Inv|-|-|TxEn|TxClk Mode|TxClk Mode|TxClk Mode|
|Access<br>rights|r/w|r/w|RFU|RFU|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|Tx2Inv|Inverts transmitter 2 at TX2 pin|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **84 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|6|Tx1Inv|Inverts transmitter 1 at TX1 pin|
|5||RFU|
|4|-|RFU|
|3|TxEn|If set to 1 both transmitter pins are enabled|
|2 to 0|TxClkMode|Transmitter clock settings. Codes 011b and 0b110 are not supported.<br>This register defines, if the output is operated in open-drain, push-pull,<br>at high impedance or pulled to a fix high or low level.|


### **8.8.2 TxAmp**

With the set_cw_amplitude register, output power can be traded off against power supply
rejection. Spending more headroom leads to better power supply rejection ration and
better accuracy of the modulation degree.

With CwMax set, the voltage of TX1 will be pulled to the maximum possible. This register
overrides the settings made by set_cw_amplitude.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|set_cw_amplitude|set_cw_amplitude|-|set_residual_carrier|set_residual_carrier|set_residual_carrier|set_residual_carrier|set_residual_carrier|
|Access<br>rights|r/w|r/w|RFU|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 6|set_cw_amplitude|Allows reducing the output amplitude of the transmitter by a fix<br>value.<br>Four different preset values that are subtracted from TVDD<br>can be selected:<br>0: TVDD -100 mV<br>1: TVDD -250 mV<br>2: TVDD -500 mV<br>3: TVDD-1000 mV|
|5|RFU|-|
|4 to 0|set_residual_ carrier|Set the residual carrier percentage. refer to section<br>Section 7.6.2.|

### **8.8.3 TxCon**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|OvershootT2|OvershootT2|OvershootT2|OvershootT2|CwMax|TxInv|TxSel|TxSel|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **85 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 4|OvershootT2|Specifies the length (number of carrier clocks) of the additional<br>modulation for overshoot prevention. Refer to sectionSection 7.6.2.1.|
|3|Cwmax|Set amplitude of continuous wave carrier to the maximum.<br>If set, set_cw_amplitude in Register TxAmp has no influence on the<br>continuous amplitude.|
|2|TxInv|If set, the resulting modulation signal defined by TxSel is inverted|
|1 to 0|TxSel|Defines which signal is used as source for modulation<br>00b ... no modulation<br>01b ... TxEnvelope<br>10b ... SigIn<br>11b ... RFU|


### **8.8.4 Txl**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|OvershootT1|OvershootT1|OvershootT1|OvershootT1|tx_set_iLoad|tx_set_iLoad|tx_set_iLoad|tx_set_iLoad|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|OvershootT1|Overshoot value for Timer1. Refer to SectionSection 7.6.2.1.|
|3 to 0|tx_set_iLoad|Factory trim value, sets the expected Tx load current. This value is<br>used to control the modulation index in an optimized way dependent<br>on the expected TX load current.|
