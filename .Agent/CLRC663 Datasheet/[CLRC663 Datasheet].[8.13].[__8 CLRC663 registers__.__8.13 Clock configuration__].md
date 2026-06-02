## **8.13 Clock configuration**

### **8.13.1 SerialSpeed**

This register allows setting speed of the RS232 interface. The default speed is set to
115.2 kbit/s. The transmission speed of the interface can be changed by modifying
the entries for BR_T0 and BR_T1. The transfer speed can be calculated by using the
following formulas:

BR_T0 = 0: transfer speed = 27.12 MHz / (BR_T1 + 1)

BR_T0 > 0: transfer speed = 27.12 MHz / (BR_T1 + 33) / 2^(BR_T0 - 1)

The framing is implemented with 1 start bit, 8 data bits and 1 stop bit. A parity bit is not
used. Transfer speeds above 1228.8 kbit/s are not supported.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|BR_T0|BR_T0|BR_T0|BR_T1|BR_T1|BR_T1|BR_T1|BR_T1|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 5|BR_T0|BR_T0 = 0: transfer speed = 27.12 MHz / (BR_T1 + 1)<br>BR_T0 > 0: transfer speed = 27.12 MHz / (BR_T1 + 33) / 2^(BR_T0 - 1)|
|4 to 0|BR_T1|BR_T0 = 0: transfer speed = 27.12 MHz / (BR_T1 + 1)<br>BR_T0 > 0: transfer speed = 27.12 MHz / (BR_T1 + 33) / 2^(BR_T0 - 1)|


|Transfer speed (kbit/s)|SerialSpeed register content (Hex.)|
|---|---|
|7.2|FA|
|9.6|EB|
|14.4|DA|
|19.2|CB|
|38.4|AB|
|57.6|9A|
|115.2|7A|
|128.0|74|
|230.4|5A|
|460.8|3A|
|921.6|1C|
|1228.8|15|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **96 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.13.2 LFO_Trimm**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|LFO_trimm|LFO_trimm|LFO_trimm|LFO_trimm|LFO_trimm|LFO_trimm|LFO_trimm|LFO_trimm|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|LFO_trimm|Trimm value. Refer to SectionSection 7.8.3.<br>Note: If the trimm value is increased, the frequency of the oscillator<br>decreases.|

### **8.13.3 PLL_Ctrl Register**

The PLL_Ctrl register implements the control register for the IntegerN PLL. Two stages
exist to create the ClkOut signal from the 27.12 MHz input. In the first stage, the 27.12
MHz input signal is multiplied by the value defined in PLLDiv_FB and divided by two, and
the second stage divides this frequency by the value defined by PLLDIV_Out.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|ClkOutSel|ClkOutSel|ClkOutSel|ClkOutSel|ClkOut_En|PLL_PD|PLLDiv_FB|PLLDiv_FB|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7 to 4|CLkOutSel|**•** 0h - pin CLKOUT is used as I/O<br>**•** 1h - pin CLKOUT shows the output of the analog PLL<br>**•** 2h - pin CLKOUT is hold on 0<br>**•** 3h - pin CLKOUT is hold on 1<br>**•** 4h - pin CLKOUT shows 27.12 MHz from the crystal<br>**•** 5h - pin CLKOUT shows 13.56 MHz derived from the crystal<br>**•** 6h - pin CLKOUT shows 6.78 MHz derived from the crystal<br>**•** 7h - pin CLKOUT shows 3.39 MHz derived from the crystal<br>**•** 8h - pin CLKOUT is toggled by the Timer0 overflow<br>**•** 9h - pin CLKOUT is toggled by the Timer1 overflow<br>**•** Ah - pin CLKOUT is toggled by the Timer2 overflow<br>**•** Bh - pin CLKOUT is toggled by the Timer3 overflow<br>**•** Ch...Fh - RFU|
|3|ClkOut_En|Enables the clock at Pin CLKOUT|
|2|PLL_PD|PLL power down|
|1-0|PLLDiv_FB|PLL feedback divider|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **97 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit 1|Bit 0|Division|
|---|---|---|
|0|0|23 (VCO frequency 312 MHz)|
|0|1|27 (VCO frequency 366 MHz)|
|1|0|28 (VCO frequency 380 Mhz)|
|1|1|23 (VCO frequency 312 Mhz)|


### **8.13.4 PLLDiv_Out**






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|PLLDiv_Out|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|PLLDiv_Out|PLL output divider factor; refer to Section Section 7.8.2.|


|Value|Division|
|---|---|
|0|RFU|
|1|RFU|
|2|RFU|
|3|RFU|
|4|RFU|
|5|RFU|
|6|RFU|
|7|RFU|
|8|8|
|9|9|
|10|10|
|...|...|
|253|253|
|254|254|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **98 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
