## **8.1 Register bit behavior**

Depending on the functionality of a register, the access conditions to the register can
vary. In principle, bits with same behavior are grouped in common registers. The access
conditions are described in the table below:

|Address|Register name|Function|
|---|---|---|
|00h|Command|Starts and stops command execution|
|01h|HostCtrl|Host control register|
|02h|FIFOControl|Control register of the FIFO|
|03h|WaterLevel|Level of the FIFO underflow and overflow warning|
|04h|FIFOLength|Length of the FIFO|
|05h|FIFOData|Data In/Out exchange register of FIFO buffer|
|06h|IRQ0|Interrupt register 0|
|07h|IRQ1|Interrupt register 1|
|08h|IRQ0En|Interrupt enable register 0|
|09h|IRQ1En|Interrupt enable register 1|
|0Ah|Error|Error bits showing the error status of the last command execution|
|0Bh|Status|Contains status of the communication|
|0Ch|RxBitCtrl|Control register for anticollision adjustments for bit oriented protocols|
|0Dh|RxColl|Collision position register|
|0Eh|TControl|Control of Timer 0..3|


|Abbreviation|Behavior|Description|
|---|---|---|
|r/w|read and write|These bits can be written and read via the host interface. Since<br>they are used only for control purposes, the content is not<br>influenced by the state machines but can be read by internal<br>state machines.|
|dy|dynamic|These bits can be written and read via the host interface. They<br>can also be written automatically by internal state machines, for<br>example Command register changes its value automatically after<br>the execution of the command.|
|r|read only|These register bits indicate hold values which are determined by<br>internal states only.|
|w|write only|Reading these register bits always returns zero.|
|RFU|-|These bits are reserved for future use and must not be changed.<br>In case of a required write access, it is recommended to write a<br>logic 0.|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **60 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Address|Register name|Function|
|---|---|---|
|0Fh|T0Control|Control of Timer0|
|10h|T0ReloadHi|High register of the reload value of Timer0|
|11h|T0ReloadLo|Low register of the reload value of Timer0|
|12h|T0CounterValHi|Counter value high register of Timer0|
|13h|T0CounterValLo|Counter value low register of Timer0|
|14h|T1Control|Control of Timer1|
|15h|T1ReloadHi|High register of the reload value of Timer1|
|16h|T1ReloadLo|Low register of the reload value of Timer1|
|17h|T1CounterValHi|Counter value high register of Timer1|
|18h|T1CounterValLo|Counter value low register of Timer1|
|19h|T2Control|Control of Timer2|
|1Ah|T2ReloadHi|High byte of the reload value of Timer2|
|1Bh|T2ReloadLo|Low byte of the reload value of Timer2|
|1Ch|T2CounterValHi|Counter value high byte of Timer2|
|1Dh|T2CounterValLo|Counter value low byte of Timer2|
|1Eh|T3Control|Control of Timer3|
|1Fh|T3ReloadHi|High byte of the reload value of Timer3|
|20h|T3ReloadLo|Low byte of the reload value of Timer3|
|21h|T3CounterValHi|Counter value high byte of Timer3|
|22h|T3CounterValLo|Counter value low byte of Timer3|
|23h|T4Control|Control of Timer4|
|24h|T4ReloadHi|High byte of the reload value of Timer4|
|25h|T4ReloadLo|Low byte of the reload value of Timer4|
|26h|T4CounterValHi|Counter value high byte of Timer4|
|27h|T4CounterValLo|Counter value low byte of Timer4|
|28h|DrvMod|Driver mode register|
|29h|TxAmp|Transmitter amplifier register|
|2Ah|DrvCon|Driver configuration register|
|2Bh|Txl|Transmitter register|
|2Ch|TxCrcPreset|Transmitter CRC control register, preset value|
|2Dh|RxCrcPreset|Receiver CRC control register, preset value|
|2Eh|TxDataNum|Transmitter data number register|
|2Fh|TxModWidth|Transmitter modulation width register|
|30h|TxSym10BurstLen|Transmitter symbol 1 + symbol 0 burst length register|
|31h|TXWaitCtrl|Transmitter wait control|
|32h|TxWaitLo|Transmitter wait low|
|33h|FrameCon|Transmitter frame control|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **61 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Address|Register name|Function|
|---|---|---|
|34h|RxSofD|Receiver start of frame detection|
|35h|RxCtrl|Receiver control register|
|36h|RxWait|Receiver wait register|
|37h|RxThreshold|Receiver threshold register|
|38h|Rcv|Receiver register|
|39h|RxAna|Receiver analog register|
|3Ah|RFU|No function implemented for CLRC66301 and CLRC66302|
|3Ah|LPCD_Options|For CLRC66303: Options for LPCD configuration|
|3Bh|SerialSpeed|Serial speed register|
|3Ch|LFO_Trimm|Low-power oscillator trimming register|
|3Dh|PLL_Ctrl|IntegerN PLL control register, for microcontroller clock output adjustment|
|3Eh|PLL_DivOut|IntegerN PLL control register, for microcontroller clock output adjustment|
|3Fh|LPCD_QMin|Low-power card detection Q channel minimum threshold|
|40h|LPCD_QMax|Low-power card detection Q channel maximum threshold|
|41h|LPCD_IMin|Low-power card detection I channel minimum threshold|
|42h|LPCD_I_Result|Low-power card detection I channel result register|
|43h|LPCD_Q_Result|Low-power card detection Q channel result register|
|44h|PadEn|PIN enable register|
|45h|PadOut|PIN out register|
|46h|PadIn|PIN in register|
|47h|SigOut|Enables and controls the SIGOUT Pin|
|48h|TxBitMod|Transmitter bit mode register|
|49h|RFU|-|
|4Ah|TxDataCon|Transmitter data configuration register|
|4Bh|TxDataMod|Transmitter data modulation register|
|4Ch|TxSymFreq|Transmitter symbol frequency|
|4Dh|TxSym0H|Transmitter symbol 0 high register|
|4Eh|TxSym0L|Transmitter symbol 0 low register|
|4Fh|TxSym1H|Transmitter symbol 1 high register|
|50h|TxSym1L|Transmitter symbol 1 low register|
|51h|TxSym2|Transmitter symbol 2 register|
|52h|TxSym3|Transmitter symbol 3 register|
|53h|TxSym10Len|Transmitter symbol 1 + symbol 0 length register|
|54h|TxSym32Len|Transmitter symbol 3 + symbol 2 length register|
|55h|TxSym10BurstCtrl|Transmitter symbol 1 + symbol 0 burst control register|
|56h|TxSym10Mod|Transmitter symbol 1 + symbol 0 modulation register|
|57h|TxSym32Mod|Transmitter symbol 3 + symbol 2 modulation register|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **62 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Address|Register name|Function|
|---|---|---|
|58h|RxBitMod|Receiver bit modulation register|
|59h|RxEofSym|Receiver end of frame symbol register|
|5Ah|RxSyncValH|Receiver synchronisation value high register|
|5Bh|RxSyncValL|Receiver synchronisation value low register|
|5Ch|RxSyncMod|Receiver synchronisation mode register|
|5Dh|RxMod|Receiver modulation register|
|5Eh|RxCorr|Receiver correlation register|
|5Fh|FabCal|Calibration register of the receiver, calibration performed at production|
|48h-5Fh|RFU|-|
|7Fh|Version|Version and subversion register|

