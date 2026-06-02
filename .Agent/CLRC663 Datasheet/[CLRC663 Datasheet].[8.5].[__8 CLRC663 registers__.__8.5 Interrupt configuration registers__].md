## **8.5 Interrupt configuration registers**

The Registers IRQ0 register and IRQ1 register implement a special functionality to avoid
the unintended modification of bits.

The mechanism of changing register contents requires the following consideration:
IRQ(x).Set indicates, if a set bit on position 0 to 6 shall be cleared or set. Depending
on the content of IRQ(x).Set, a write of a 1 to positions 0 to 6 either clears or sets the
corresponding bit. With this register, the application can modify the interrupt status which
is maintained by the CLRC663.



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **66 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


Bit 7 indicates, if the intended modification is a setting or clearance of a bit. Any 1 written
to a bit position 6...0 will trigger the setting or clearance of this bit as defined by bit 7.
Example: writing FFh sets all bits 6..0, writing 7Fh clears all bits 6..0 of the interrupt
request register

### **8.5.1 IRQ0 register**

Interrupt request register 0.





|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Set|HiAlertIRQ|LoAlertIRQ|IdleIRQ|TxIRQ|RxIRQ|ErrIRQ|RxSOF<br>IRQ|
|Access<br>rights|w|dy|dy|dy|dy|dy|dy|dy|


|Bit|Symbol|Description|
|---|---|---|
|7|Set|1: writing a 1 to a bit position 6..0 sets the interrupt request<br>0: Writing a 1 to a bit position 6..0 clears the interrupt request|
|6|HiAlertIRQ|Set, when bit HiAlert in register Status1Reg is set. In opposition to HiAlert,<br>HiAlertIRQ stores this event.|
|5|LoAlertIRQ|Set, when bit LoAlert in register Status1 is set. In opposition to LoAlert,<br>LoAlertIRQ stores this event.|
|4|IdleIRQ|Set, when a command terminates by itself e.g. when the Command<br>changes its value from any command to the Idle command. If an unknown<br>command is started, the Command changes its content to the idle state and<br>the bit IdleIRQ is set. Starting the Idle command by the Controller does not<br>set bit IdleIRQ.|
|3|TxIRQ|Set, when data transmission is completed, which is immediately after the<br>last bit is sent.|
|2|RxIRQ|Set, when the receiver detects the end of a data stream.<br>Note: This flag is no indication that the received data stream is correct. The<br>error flags have to be evaluated to get the status of the reception.|
|1|ErrIRQ|Set, when the one of the following errors is set:<br>FifoWrErr, FiFoOvl, ProtErr, NoDataErr, IntegErr.|
|0|RxSOFlrq|Set, when a SOF or a subcarrier is detected.|

### **8.5.2 IRQ1 register**

Interrupt request register 1.








|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Set|GlobalIRQ|LPCD_IRQ|Timer4IRQ|Timer3IRQ|Timer2IRQ|Timer1IRQ|Timer0IRQ|
|Access<br>rights|w|dy|dy|dy|dy|dy|dy|dy|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **67 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Bit|Symbol|Description|
|---|---|---|
|7|Set|1: writing a 1 to a bit position 5..0 sets the interrupt request<br>0: Writing a 1 to a bit position 5..0 clears the interrupt request|
|6|GlobalIRQ|Set, if an enabled IRQ occurs.|
|5|LPCD_IRQ|Set if a card is detected in Low-power card detection sequence.|
|4|Timer4IRQ|Set to logic 1 when Timer4 has an underflow.|
|3|Timer3IRQ|Set to logic 1 when Timer3 has an underflow.|
|2|Timer2IRQ|Set to logic 1 when Timer2 has an underflow.|
|1|Timer1IRQ|Set to logic 1 when Timer1 has an underflow.|
|0|Timer0IRQ|Set to logic 1 when Timer0 has an underflow.|


### **8.5.3 IRQ0En register**

Interrupt request enable register for IRQ0. This register allows defining if an interrupt
request is processed by the CLRC663.






|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|IRQ_Inv|Hi AlertIRQEn|LoAlertIRQEn|IdleIRQEn|TxIRQEn|RxIRQEn|ErrIRQEn|RxSOF<br>IRQEn|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|IRQ_Inv|Set to one the signal of the IRQ pin is inverted|
|6|Hi AlerIRQEn|Set to logic 1, it allows the High Alert interrupt Request (indicated by the<br>bit HiAlertIRQ) to be propagated to the GlobalIRQ|
|5|Lo AlertIRQEn|Set to logic 1, it allows the Low Alert Interrupt Request (indicated by the<br>bit LoAlertIRQ) to be propagated to the GlobalIRQ|
|4|IdleIRQEn|Set to logic 1, it allows the Idle interrupt request (indicated by the bit<br>IdleIRQ) to be propagated to the GlobalIRQ|
|3|TxIRQEn|Set to logic 1, it allows the transmitter interrupt request (indicated by the<br>bit TxtIRQ) to be propagated to the GlobalIRQ|
|2|RxIRQEn|Set to logic 1, it allows the receiver interrupt request (indicated by the bit<br>RxIRQ) to be propagated to the GlobalIRQ|
|1|ErrIRQEn|Set to logic 1, it allows the Error interrupt request (indicated by the bit<br>ErrorIRQ) to be propagated to the GlobalIRQ|
|0|RxSOFIRQEn|Set to logic 1, it allows the RxSOF interrupt request (indicated by the bit<br>RxSOFIRQ) to be propagated to the GlobalIRQ|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **68 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **8.5.4 IRQ1En**

Interrupt request enable register for IRQ1.















|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|IRQPushPull|IRQPinEn|LPCD_IRQEn|Timer4<br>IRQEn|Timer3<br>IRQEn|Timer2<br>IRQEn|Timer1<br>IRQEn|Timer0<br>IRQEn|
|Access<br>rights|r/w|r/w|r/w|r/w|r/w|r/w|r/w|r/w|


|Bit|Symbol|Description|
|---|---|---|
|7|IRQPushPull|Set to 1 the IRQ-pin acts as PushPull pin, otherwise it acts as<br>OpenDrain pin|
|6|IRQPinEN|Set to logic 1, it allows the global interrupt request (indicated by the bit<br>GlobalIRQ) to be propagated to the interrupt pin|
|5|LPCD_IRQEN|Set to logic 1, it allows the LPCDinterrupt request (indicated by the bit<br>LPCDIRQ) to be propagated to the GlobalIRQ|
|4|Timer4IRQEn|Set to logic 1, it allows the Timer4 interrupt request (indicated by the bit<br>Timer4IRQ) to be propagated to the GlobalIRQ|
|3|Timer3IRQEn|Set to logic 1, it allows the Timer3 interrupt request (indicated by the bit<br>Timer3IRQ) to be propagated to the GlobalIRQ|
|2|Timer2IRQEn|Set to logic 1, it allows the Timer2 interrupt request (indicated by the bit<br>Timer2IRQ) to be propagated to the GlobalIRQ|
|1|Timer1IRQEn|Set to logic 1, it allows the Timer1 interrupt request (indicated by the bit<br>Timer1IRQ) to be propagated to the GlobalIRQ|
|0|Timer0IRQEn|Set to logic 1, it allows the Timer0 interrupt request (indicated by the bit<br>Timer0IRQ) to be propagated to the GlobalIRQ|
