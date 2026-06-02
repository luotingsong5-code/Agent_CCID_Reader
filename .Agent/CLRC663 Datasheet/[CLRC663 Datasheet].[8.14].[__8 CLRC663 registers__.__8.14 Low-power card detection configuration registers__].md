## **8.14 Low-power card detection configuration registers**

The LPCD registers contain the settings for the low-power card detection. The setting
for LPCD_IMax (6 bits) is done by the two highest bits (bit 7, bit 6) of the registers
LPCD_QMin, LPCD_QMax and LPCD_IMin each.

### **8.14.1 LPCD_QMin**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|LPCD_IMax.5|LPCD_IMax.4|LPCD_QMin|LPCD_QMin|LPCD_QMin|LPCD_QMin|LPCD_QMin|LPCD_QMin|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7, 6|LPCD_IMax|Defines the highest two bits of the higher border for the LPCD. If the<br>measurement value of the I channel is higher than LPCD_IMax, an<br>LPCD interrupt request is indicated by bit IRQ0.LPCDIRQ.|
|5 to 0|LPCD_QMin|Defines the lower border for the LPCD. If the measurement value of<br>the Q channel is higher than LPCD_QMin, an LPCDinterrupt request<br>is indicated by bit IRQ0.LPCDIRQ.|

### **8.14.2 LPCD_QMax**








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|LPCD_IMax.3|LPCD_IMax.2|LPCD_QMax|LPCD_QMax|LPCD_QMax|LPCD_QMax|LPCD_QMax|LPCD_QMax|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|LPCD_IMax.3|Defines the bit 3 of the high border for the LPCD. If the<br>measurement value of the I channel is higher than LPCD IMax, an<br>LPCD IRQ is raised.|
|6|LPCD_IMax.2|Defines the bit 2 of the high border for the LPCD. If the<br>measurement value of the I channel is higher than LPCD IMax, an<br>LPCD IRQ is raised.|
|5 to 0|LPCD_QMax|Defines the high border for the LPCD. If the measurement value of<br>the Q channel is higher than LPCD QMax, an LPCD IRQ is raised.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **99 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.14.3 LPCD_IMin**





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|LPCD_IMax.1|LPCD_IMax.0|LPCD_IMin|LPCD_IMin|LPCD_IMin|LPCD_IMin|LPCD_IMin|LPCD_IMin|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 6|LPCD_IMax|Defines lowest two bits of the higher border for the low-power card<br>detection (LPCD). If the measurement value of the I channel is higher<br>than LPCD IMax, an LPCD IRQ is raised.|
|5 to 0|LPCD_IMin|Defines the lower border for the low power card detection. If the<br>measurement value of the I channel is lower than LPCD IMin, an<br>LPCD IRQ is raised.|

### **8.14.4 LPCD_Result_I**







|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU-|RFU-|LPCD_Result_I|LPCD_Result_I|LPCD_Result_I|LPCD_Result_I|LPCD_Result_I|LPCD_Result_I|
|Access<br>rights|-|-|r|r|r|r|r|r|


|Bit|Symbol|Description|
|---|---|---|
|7 to 6|RFU|-|
|5 to 0|LPCD_Result_I|Shows the result of the last low-power card detection (I-Channel).|

### **8.14.5 LPCD_Result_Q**












|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU|LPCD_I<br>RQ_Clr|LPCD_Reslult_Q|LPCD_Reslult_Q|LPCD_Reslult_Q|LPCD_Reslult_Q|LPCD_Reslult_Q|LPCD_Reslult_Q|
|Access<br>rights|-|r/w|r|r|r|r|r|r|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **100 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|RFU|-|
|6|LPCD_IRQ_Clr|If set no LPCD IRQ is raised any more until the next low-power<br>card detection procedure. Can be used by software to clear the<br>interrupt source.|
|5 to 0|LPCD_Result_Q|Shows the result of the last low power card detection (Q-<br>Channel).|


### **8.14.6 LPCD_Options**

This register is available on the CLRC66303 only. For silicon versions CLRC66301 and
CLRC66302 this register on address 3AH is RFU.










|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|RFU<br>-|RFU<br>-|RFU<br>-|RFU<br>-|LPCD_TX_HIGH|LPCD_FILTER|LPCD_Q_<br>UNSTABLE|LPCD_I_UNSTABLE|
|Access<br>rights|Access<br>rights|Access<br>rights|Access<br>rights|Access<br>rights|r/w|r/w|r|r|



|Bit|Symbol|Description|
|---|---|---|
|7 to 4|RFU|-|
|3|LPCD_TX_HIGH|If set, the TX-driver will be the same as VTVDDduring LPCD. This will allow for<br>a better LPCD detection range (higher transmitter output voltage) at the cost of<br>a higher current consumption. If this bit is cleared, the output voltage at the TX<br>drivers will be = TVDD- 0.4V. If this bit is set, the output voltage at the TX drivers<br>will be = VTVDD.|
|2|LPCD_FILTER|If set, The LPCD decision is based on the result of a filter which allows<br>to remove noise from the evaluated signal in I and Q channel. Enabling<br>LPCD_FILTER allows compensating for noisy conditions at the cost of a longer<br>RF-ON time required for sampling. The total maximum LPCD sampling time is<br>4.72us.|
|1|LPCD_Q_UNSTABLE|If bit 2 of this register is set, bit 1 indicates that the Q-channel ADC value was<br>changing during the LPCD measuring time. Note: Only valid if LPCD_FILTER<br>(bit 2) = 1. This information can be used by the host application for configuration<br>of e.g. the threshold LPCD_QMax or inverting the TX drivers.|
|0|LPCD_I_UNSTABLE|If bit 2 of this register is set, bit 0 Indicates that the I-channel ADC value was<br>changing during the LPCD measuring time. Note: Only valid if LPCD_FILTER<br>(bit2) = 1. This information can be used by the host application for configuration<br>of e.g. the threshold LPCD_IMax or inverting the TX drivers.|
