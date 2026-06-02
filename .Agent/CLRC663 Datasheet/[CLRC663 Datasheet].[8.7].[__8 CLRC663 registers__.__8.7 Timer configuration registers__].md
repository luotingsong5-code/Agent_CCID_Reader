## **8.7 Timer configuration registers**

### **8.7.1 TControl**

Control register of the timer section.

The TControl implements a special functionality to avoid the not intended modification of
bits.

Bit 3..0 indicates, which bits in the positions 7..4 are intended to be modified.

Example: writing FFh sets all bits 7..4, writing F0h does not change any of the bits 7..4














|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3Running|T2Running|T1Running|T0Running|T3Start<br>StopNow|T2Start<br>StopNow|T1Start<br>StopNow|T0Start<br>StopNow|
|Access<br>rights|dy|dy|dy|dy|w|w|w|w|



|Bit|Symbol|Description|
|---|---|---|
|7|T3Running|Indicates Timer3 is running.If the bit T3startStopNow is set/reset, this<br>bit and the timer can be started/stopped|
|6|T2Running|Indicates Timer2 is running. If the bit T2startStopNow is set/reset, this<br>bit and the timer can be started/stopped|
|5|T1Running|Indicates tTmer1 is running. If the bit T1startStopNow is set/reset, this<br>bit and the timer can be started/stopped|
|4|T0Running|Indicates Timer0 is running. If the bit T0startStopNow is set/reset, this<br>bit and the timer can be started/stopped|
|3|T3StartStop<br>Now|The bit 7 of TControl T3Running can be modified if set|
|2|T2StartStop<br>Now|The bit 6of TControl T2Running can be modified if set|
|1|T1StartStop<br>Now|The bit 5of TControl T1Running can be modified if set|
|0|T0StartStop<br>Now|The bit 4 of TControl T0Running can be modified if set|

### **8.7.2 T0Control**





Control register of the Timer0.

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T0StopRx|-|T0Start|T0Start|T0AutoRestart|-|T0Clk|T0Clk|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **73 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Access<br>rights|r/w|RFU|r/w|r/w|r/w|RFU|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|T0StopRx|If set, the timer stops immediately after receiving the first 4 bits. If<br>cleared the timer does not stop automatically.<br>Note: If LFO Trimming is selected by T0Start, this bit has no effect.|
|6|-|RFU|
|5 to 4|T0Start|00b: The timer is not started automatically<br>01 b: The timer starts automatically at the end of the transmission<br>10 b: Timer is used for LFO trimming without underflow (Start/Stop on<br>PosEdge)<br>11 b: Timer is used for LFO trimming with underflow (Start/Stop on<br>PosEdge)|
|3|T0AutoRestart|1: the timer automatically restarts its count-down from<br>T0ReloadValue, after the counter value has reached the value zero.<br>0: the timer decrements to zero and stops.<br>The bit Timer1IRQ is set to logic 1 when the timer underflows.|
|2|-|RFU|
|1 to 0|T0Clk|00 b: The timer input clock is 13.56 MHz.<br>01 b: The timer input clock is 211,875 kHz.<br>10 b: The timer input clock is an underflow of Timer2.<br>11 b: The timer input clock is an underflow of Timer1.|

#### **8.7.2.1 T0ReloadHi**

High byte reload value of the Timer0.








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T0Reload Hi|T0Reload Hi|T0Reload Hi|T0Reload Hi|T0Reload Hi|T0Reload Hi|T0Reload Hi|T0Reload Hi|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T0ReloadHi|Defines the high byte of the reload value of the timer. With the start<br>event, the timer loads the value of the registers T0ReloadValHi,<br>T0ReloadValLo. Changing this register affects the timer only at the<br>next start event.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **74 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **8.7.2.2 T0ReloadLo**

Low byte reload value of the Timer0.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T0ReloadLo|T0ReloadLo|T0ReloadLo|T0ReloadLo|T0ReloadLo|T0ReloadLo|T0ReloadLo|T0ReloadLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to0|T0ReloadLo|Defines the low byte of the reload value of the timer. With the<br>start event, the timer loads the value of the T0ReloadValHi,<br>T0ReloadValLo. Changing this register affects the timer only at the<br>next start event.|

#### **8.7.2.3 T0CounterValHi**

High byte of the counter value of Timer0.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T0CounterValHi|T0CounterValHi|T0CounterValHi|T0CounterValHi|T0CounterValHi|T0CounterValHi|T0CounterValHi|T0CounterValHi|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|





|Bit|Symbol|Description|
|---|---|---|
|7to0|T0Counter<br>ValHi|High byte value of the Timer0.<br>This value shall not be read out during reception.|

#### **8.7.2.4 T0CounterValLo**





Low byte of the counter value of Timer0.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T0CounterValLo|T0CounterValLo|T0CounterValLo|T0CounterValLo|T0CounterValLo|T0CounterValLo|T0CounterValLo|T0CounterValLo|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **75 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T0CounterValLo|Low byte value of the Timer0.<br>This value shall not be read out during reception.|


#### **8.7.2.5 T1Control**

Control register of the Timer1.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T1StopRx|-|T1Start|T1Start|T1AutoRestart|-|T1Clk|T1Clk|
|Access<br>rights|r/w|RFU|r/w|r/w|r/w|RFU|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|T1StopRx|If set, the timer stops after receiving the first 4 bits. If cleared, the<br>timer is not stopped automatically.<br>Note: If LFO trimming is selected by T1start, this bit has no effect.|
|6|-|RFU|
|5 to 4|T1Start|00b: The timer is not started automatically<br>01 b: The timer starts automatically at the end of the transmission<br>10 b: Timer is used for LFO trimming without underflow (Start/Stop on<br>PosEdge)<br>11 b: Timer is used for LFO trimming with underflow (Start/Stop on<br>PosEdge)|
|3|T1AutoRestart|Set to logic 1, the timer automatically restarts its countdown from<br>T1ReloadValue, after the counter value has reached the value zero.<br>Set to logic 0 the timer decrements to zero and stops.<br>The bit Timer1IRQ is set to logic 1 when the timer underflows.|
|2|-|RFU|
|1 to 0|T1Clk|00 b: The timer input clock is 13.56 MHz<br>01 b: The timer input clock is 211,875 kHz.<br>10 b: The timer input clock is an underflow of Timer0<br>11 b: The timer input clock is an underflow of Timer2|

#### **8.7.2.6 T1ReloadHi**

High byte (MSB) reload value of the Timer1.








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T1ReloadHi|T1ReloadHi|T1ReloadHi|T1ReloadHi|T1ReloadHi|T1ReloadHi|T1ReloadHi|T1ReloadHi|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **76 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T1ReloadHi|Defines the high byte reload value of the Timer 1. With the start event,<br>the timer loads the value of the T1ReloadValHi and T1ReloadValLo.<br>Changing this register affects the Timer only at the next start event.|


#### **8.7.2.7 T1ReloadLo**

Low byte (LSB) reload value of the Timer1.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T1ReloadLo|T1ReloadLo|T1ReloadLo|T1ReloadLo|T1ReloadLo|T1ReloadLo|T1ReloadLo|T1ReloadLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T1ReloadLo|Defines the low byte of the reload value of the Timer1. Changing this<br>register affects the timer only at the next start event.|

#### **8.7.2.8 T1CounterValHi**

High byte (MSB) of the counter value of byte Timer1.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T1CounterValHi|T1CounterValHi|T1CounterValHi|T1CounterValHi|T1CounterValHi|T1CounterValHi|T1CounterValHi|T1CounterValHi|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|





|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T1Counter<br>ValHi|High byte of the current value of the Timer1.<br>This value shall not be read out during reception.|

#### **8.7.2.9 T1CounterValLo**





Low byte (LSB) of the counter value of byte Timer1.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T1CounterValLo|T1CounterValLo|T1CounterValLo|T1CounterValLo|T1CounterValLo|T1CounterValLo|T1CounterValLo|T1CounterValLo|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **77 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T1Counter<br>ValLo|Low byte of the current value of the counter 1.<br>This value shall not be read out during reception.|

#### **8.7.2.10 T2Control**





Control register of the Timer2.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T2StopRx|-|T2Start|T2Start|T2AutoRestart|-|T2Clk|T2Clk|
|Access<br>rights|r/w|RFU|r/w|r/w|r/w|RFU|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|T2StopRx|If set the timer stops immediately after receiving the first 4 bits. If<br>cleared indicates, that the timer is not stopped automatically.<br>Note: If LFO Trimming is selected by T2Start, this bit has no effect.|
|6|-|RFU|
|5 to 4|T2Start|00 b: The timer is not started automatically.<br>01 b: The timer starts automatically at the end of the transmission.<br>10 b: Timer is used for LFO trimming without underflow (Start/Stop on<br>PosEdge).<br>11 b: Timer is used for LFO trimming with underflow (Start/Stop on<br>PosEdge).|
|3|T2AutoRestart|Set to logic 1, the timer automatically restarts its countdown from<br>T2ReloadValue, after the counter value has reached the value<br>zero. Set to logic 0 the timer decrements to zero and stops. The bit<br>Timer2IRQ is set to logic 1 when the timer underflows|
|2|-|RFU|
|1 to 0|T2Clk|00 b: The timer input clock is 13.56 MHz.<br>01 b: The timer input clock is 212 kHz.<br>10 b: The timer input clock is an underflow of Timer0<br>11b: The timer input clock is an underflow of Timer1|

#### **8.7.2.11 T2ReloadHi**

High byte of the reload value of Timer2.








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T2ReloadHi|T2ReloadHi|T2ReloadHi|T2ReloadHi|T2ReloadHi|T2ReloadHi|T2ReloadHi|T2ReloadHi|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **78 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T2ReloadHi|Defines the high byte of the reload value of the Timer2. With the<br>start event, the timer load the value of the T2ReloadValHi and<br>T2ReloadValLo. Changing this register affects the timer only at the<br>next start event.|


#### **8.7.2.12 T2ReloadLo**

Low byte of the reload value of Timer2.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T2ReloadLo|T2ReloadLo|T2ReloadLo|T2ReloadLo|T2ReloadLo|T2ReloadLo|T2ReloadLo|T2ReloadLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T2ReloadLo|Defines the low byte of the reload value of the Timer2. With the<br>start event, the timer load the value of the T2ReloadValHi and<br>T2RelaodVaLo. Changing this register affects the timer only at the<br>next start event.|

#### **8.7.2.13 T2CounterValHi**

High byte of the counter register of Timer2.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T2CounterValHi|T2CounterValHi|T2CounterValHi|T2CounterValHi|T2CounterValHi|T2CounterValHi|T2CounterValHi|T2CounterValHi|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|





|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T2Counter<br>ValHi|High byte current counter value of Timer2.<br>This value shall not be read out during reception.|

#### **8.7.2.14 T2CounterValLoReg**





Low byte of the current value of Timer 2.

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T2CounterValLo|T2CounterValLo|T2CounterValLo|T2CounterValLo|T2CounterValLo|T2CounterValLo|T2CounterValLo|T2CounterValLo|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **79 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|





|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T2Counter<br>ValLo|Low byte of the current counter value of Timer1Timer2.<br>This value shall not be read out during reception.|

#### **8.7.2.15 T3Control**





Control register of the Timer 3.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3StopRx|-|T3Start|T3Start|T3AutoRestart|-|T3Clk|T3Clk|
|Access<br>rights|r/w|RFU|r/w|r/w|r/w|RFU|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|T3StopRx|If set, the timer stops immediately after receiving the first 4 bits. If<br>cleared, indicates that the timer is not stopped automatically.<br>Note: If LFO Trimming is selected by T3Start, this bit has no effect.|
|6|-|RFU|
|5 to 4|T3Start|00b - timer is not started automatically<br>01 b - timer starts automatically at the end of the transmission<br>10 b - timer is used for LFO trimming without underflow (Start/Stop on<br>PosEdge)<br>11 b - timer is used for LFO trimming with underflow (Start/Stop on<br>PosEdge).|
|3|T3AutoRestart|Set to logic 1, the timer automatically restarts its countdown from<br>T3ReloadValue, after the counter value has reached the value zero.<br>Set to logic 0 the timer decrements to zero and stops.<br>The bit Timer1IRQ is set to logic 1 when the timer underflows.|
|2|-|RFU|
|1 to 0|T3Clk|00 b - the timer input clock is 13.56 MHz.<br>01 b - the timer input clock is 211,875 kHz.<br>10 b - the timer input clock is an underflow of Timer0<br>11 b - the timer input clock is an underflow of Timer1|

#### **8.7.2.16 T3ReloadHi**

High byte of the reload value of Timer3.



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **80 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3ReloadHi|T3ReloadHi|T3ReloadHi|T3ReloadHi|T3ReloadHi|T3ReloadHi|T3ReloadHi|T3ReloadHi|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T3ReloadHi|Defines the high byte of the reload value of the Timer3. With the<br>start event, the timer load the value of the T3ReloadValHi and<br>T3ReloadValLo. Changing this register affects the timer only at the<br>next start event.|

#### **8.7.2.17 T3ReloadLo**

Low byte of the reload value of Timer3.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3ReloadLo|T3ReloadLo|T3ReloadLo|T3ReloadLo|T3ReloadLo|T3ReloadLo|T3ReloadLo|T3ReloadLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T3ReloadLo|Defines the low byte of the reload value of Timer3. With the<br>start event, the timer load the value of the T3ReloadValHi and<br>T3RelaodValLo. Changing this register affects the timer only at the<br>next start event.|

#### **8.7.2.18 T3CounterValHi**

High byte of the current counter value the 16-bit Timer3.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3CounterValHi|T3CounterValHi|T3CounterValHi|T3CounterValHi|T3CounterValHi|T3CounterValHi|T3CounterValHi|T3CounterValHi|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|








|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T3Counter<br>ValHi|High byte of the current counter value of Timer3.<br>This value shall not be read out during reception.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **81 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **8.7.2.19 T3CounterValLo**

Low byte of the current counter value the 16-bit Timer3.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T3CounterValLo|T3CounterValLo|T3CounterValLo|T3CounterValLo|T3CounterValLo|T3CounterValLo|T3CounterValLo|T3CounterValLo|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|





|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T3Counter<br>ValLo|Low byte current counter value of Timer3.<br>This value shall not be read out during reception.|

#### **8.7.2.20 T4Control**





The wake-up timer T4 activates the system after a given time. If enabled, it can start the
low-power card detection function.
















|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T4Running|T4Start<br>StopNow|T4Auto<br>Trimm|T4Auto<br>LPCD|T4Auto<br>Restart|T4AutoWakeUp|T4Clk|T4Clk|
|Access<br>rights|dy|w|r/w|r/w|r/w|r/w|r/w|r/w|







|Bit|Symbol|Description|
|---|---|---|
|7|T4Running|Shows if the timer T4 is running. If the bit T4StartStopNow is set,<br>this bit and the timer T4 can be started/stopped.|
|6|T4Start<br>StopNow|if set, the bit T4Running can be changed.|
|5|T4AutoTrimm|If set to one, the timer activates an LFO trimming procedure when it<br>underflows. For the T4AutoTrimm function, at least one timer (T0 to<br>T3) has to be configured properly for trimming (T3 is not allowed if<br>T4AutoLPCD is set in parallel).|
|4|T4AutoLPCD|If set to one, the timer activates a low-power card detection<br>sequence. If a card is detected an interrupt request is raised and<br>the system remains active if enabled. If no card is detected the<br>CLRC663 enters the Power down mode if enabled. The timer is<br>automatically restarted (no gap). Timer 3 is used to specify the time<br>where the RF field is enabled to check if a card is present. Therefore<br>you may not use Timer 3 for T4AutoTrimm in parallel.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **82 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|3|T4AutoRestart|Set to logic 1, the timer automatically restarts its countdown from<br>T4ReloadValue, after the counter value has reached the value<br>zero. Set to logic 0 the timer decrements to zero and stops. The bit<br>Timer4IRQ is set to logic 1 at timer underflow.|
|2|T4AutoWakeUp|If set, the CLRC663 wakes up automatically, when the timer T4 has<br>an underflow. This bit has to be set if the IC should enter the Power<br>down mode after T4AutoTrimm and/or T4AutoLPCD is finished and<br>no card has been detected. If the IC should stay active after one of<br>these procedures, this bit has to be set to 0.|
|1 to 0|T4Clk|00b - the timer input clock is the LFO clock<br>01b - the timer input clock is the LFO clock/8<br>10b - the timer input clock is the LFO clock/16<br>11b - the timer input clock is the LFO clock/32|


#### **8.7.2.21 T4ReloadHi**

High byte of the reload value of the 16-bit timer 4.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T4ReloadHi|T4ReloadHi|T4ReloadHi|T4ReloadHi|T4ReloadHi|T4ReloadHi|T4ReloadHi|T4ReloadHi|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T4ReloadHi|Defines high byte for the reload value of timer 4. With the start event,<br>the timer 4 loads the T4ReloadVal. Changing this register affects the<br>timer only at the next start event.|

#### **8.7.2.22 T4ReloadLo**

Low byte of the reload value of the 16-bit timer 4.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T4ReloadLo|T4ReloadLo|T4ReloadLo|T4ReloadLo|T4ReloadLo|T4ReloadLo|T4ReloadLo|T4ReloadLo|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T4ReloadLo|Defines the low byte of the reload value of the timer 4. With the start<br>event, the timer loads the value of the T4ReloadVal. Changing this<br>register affects the timer only at the next start event.|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **83 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **8.7.2.23 T4CounterValHi**

High byte of the counter value of the 16-bit timer 4.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T4CounterValHi|T4CounterValHi|T4CounterValHi|T4CounterValHi|T4CounterValHi|T4CounterValHi|T4CounterValHi|T4CounterValHi|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T4CounterValHi|High byte of the current counter value of timer 4.|

#### **8.7.2.24 T4CounterValLo**

Low byte of the counter value of the 16-bit timer 4.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|T4CounterValLo|T4CounterValLo|T4CounterValLo|T4CounterValLo|T4CounterValLo|T4CounterValLo|T4CounterValLo|T4CounterValLo|
|Access<br>rights|dy|dy|dy|dy|dy|dy|dy|dy|



|Bit|Symbol|Description|
|---|---|---|
|7 to 0|T4CounterValLo|Low byte of the current counter value of the timer 4.|
