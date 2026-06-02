## **7.1 Interrupt controller**





The interrupt controller handles the enabling/disabling of interrupt requests. All of the
interrupts can be configured by firmware. Additionally, the firmware has possibilities to
trigger interrupts or clear pending interrupt requests. Two 8-bit interrupt registers IRQ0
and IRQ1 are implemented, accompanied by two 8-bit interrupt enable registers IRQ0En
and IRQ1En. A dedicated functionality of bit 7 to set and clear bits 0 to 6 in this interrupt
controller register is implemented.

The CLRC663 indicates certain events by setting bit IRQ in the register Status1Reg and
additionally, if activated, by pin IRQ. The signal on pin IRQ may be used to interrupt the
host using its interrupt handling capabilities. This allows the implementation of efficient
host software.

Table 4. shows the available interrupt bits, the corresponding source and the condition
for its activation. The interrupt bits Timer0IRQ, Timer1IRQ, Timer2IRQ, Timer3OIRQ, in
register IRQ1 indicate an interrupt set by the timer unit. The setting is done if the timer
underflows.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **9 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


The TxIRQ bit in register IRQ0 indicates that the transmission is finished. If the state
changes from sending data to transmitting the end of the frame pattern, the transmitter
unit sets the interrupt bit automatically.

The bit RxIRQ in register IRQ0 indicates an interrupt when the end of the received data is
detected.

The bit IdleIRQ in register IRQ0 is set if a command finishes and the content of the
command register changes to idle.

The register WaterLevel defines both - minimum and maximum warning levels - counting
from top and from bottom of the FIFO by a single value.

The bit HiAlertIRQ in register IRQ0 is set to logic 1 if the HiAlert bit is set to logic 1, that
means the FIFO data number has reached the top level as configured by the register
WaterLevel and bit WaterLevelExtBit.

The bit LoAlertIRQ in register IRQ0 is set to logic 1 if the LoAlert bit is set to logic 1, that
means the FIFO data number has reached the bottom level as configured by the register
WaterLevel.

The bit ErrIRQ in register IRQ0 indicates an error detected by the contactless UART
during receive. This is indicated by any bit set to logic 1 in register Error.

The bit LPCDIRQ in register IRQ0 indicates a card detected.

The bit RxSOFIRQ in register IRQ0 indicates a detection of a SOF or a subcarrier by the
contactless UART during receiving.

The bit GlobalIRQ in register IRQ1 indicates an interrupt occurring at any other interrupt
source when enabled.

|Interrupt bit|Interrupt source|Is set automatically, when|
|---|---|---|
|Timer0IRQ|Timer Unit|the timer register T0 CounterVal underflows|
|Timer1IRQ|Timer Unit|the timer register T1 CounterVal underflows|
|Timer2IRQ|Timer Unit|the timer register T2 CounterVal underflows|
|Timer3IRQ|Timer Unit|the timer register T3 CounterVal underflows|
|TxIRQ|Transmitter|a transmitted data stream ends|
|RxIRQ|Receiver|a received data stream ends|
|IdleIRQ|Command Register|a command execution finishes|
|HiAlertIRQ|FIFO-buffer pointer|the FIFO data number has reached the top level as<br>configured by the register WaterLevel|
|LoAlertIRQ|FIFO-buffer pointer|the FIFO data number has reached the bottom level as<br>configured by the register WaterLevel|
|ErrIRQ|contactless UART|a communication error had been detected|
|LPCDIRQ|LPCD|a card was detected when in low-power card detection<br>mode|
|RxSOFIRQ|Receiver|detection of a SOF or a subcarrier|
|GlobalIRQ|all interrupt sources|will be set if another interrupt request source is set|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **10 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
