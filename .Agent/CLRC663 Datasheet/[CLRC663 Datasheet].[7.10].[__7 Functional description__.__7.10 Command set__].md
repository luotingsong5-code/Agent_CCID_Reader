## **7.10 Command set**

### **7.10.1 General**

The behavior is determined by a state machine capable to perform a certain set of
commands. By writing a command-code to the command register, the command is
executed.

Arguments and/or data necessary to process a command, are exchanged via the FIFO
buffer.

**•** Each command that needs a certain number of arguments will start processing only
when it has received the correct number of arguments via the FIFO buffer.

**•** The FIFO buffer is not cleared automatically at command start. It is recommended to
write the command arguments and/or the data bytes into the FIFO buffer and start the
command afterwards.

**•** Each command may be stopped by the host by writing a new command code into the
command register e.g.: the Idle-Command.

### **7.10.2 Command set overview**







|Command|No.|Parameter (bytes)|Short description|
|---|---|---|---|
|Idle|00h|-|no action, cancels current command execution|
|LPCD|01h|-|low-power card detection|
|LoadKey|02h|(keybyte1),(keybyte2), (keybyte3),<br>(keybyte4), (keybyte5),(keybyte6);|reads a MIFARE Classic key (size of 6 bytes) from<br>FIFO buffer ant puts it into Key buffer|
|MFAuthent|03h|60h or 61h, (block address), (card<br>serial number byte0),(card serial<br>number byte1), (card serial number<br>byte2),(card serial number byte3);|performs the MIFARE Classic authentication|
|AckReq|04h|-|performs a query, an Ack and a Req-Rn for ISO/IEC<br>18000-3 mode 3/ EPC Class-1 HF|
|Receive|05h|-|activates the receive circuit|
|Transmit|06h|bytes to send: byte1, byte2,....|transmits data from the FIFO buffer|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **53 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_



















|Command|No.|Parameter (bytes)|Short description|
|---|---|---|---|
|Transceive|07h|bytes to send: byte1, byte2,....|transmits data from the FIFO buffer and automatically<br>activates the receiver after transmission finished|
|WriteE2|08h|addressH, addressL, data;|gets one byte from FIFO buffer and writes it to the<br>internal EEPROM|
|WriteE2Page|09h|(page Address), data0,<br>\[data1 ..data63\];|gets up to 64 bytes (one EEPROM page) from the FIFO<br>buffer and writes it to the EEPROM|
|ReadE2|0Ah|addressH, address L, length;|reads data from the EEPROM and copies it into the<br>FIFO buffer|
|LoadReg|0Ch|(EEPROM addressH), (EEPROM<br>addressL), RegAdr, (number of<br>Register to be copied);|reads data from the internal EEPROM and initializes<br>the CLRC663 registers. EEPROM address needs to be<br>within EEPROM sector 2|
|LoadProtocol|0Dh|(Protocol number RX), (Protocol<br>number TX);|reads data from the internal EEPROM and initializes the<br>CLRC663 registers needed for a Protocol change|
|LoadKeyE2|0Eh|KeyNr;|copies a key from the EEPROM into the key buffer|
|StoreKeyE2|0Fh|KeyNr, byte1,byte2, byte3, byte4,<br>byte5,byte6;|stores a MIFARE Classic key (size of 6 bytes) into the<br>EEPROM|
|ReadRNR|1Ch|-|Copies bytes from the Random Number generator into<br>the FIFO until the FiFo is full|
|Soft Reset|1Fh|-|resets the CLRC663|

### **7.10.3 Command functionality**

#### **7.10.3.1 Idle command**

Command (00h);

This command indicates that the CLRC663 is in idle mode. This command is also used to
terminate the actual command.

#### **7.10.3.2 LPCD command**

Command (01h);

This command performs a low-power card detection and/or an automatic trimming of
the LFO. After wake-up from standby, the values of the sampled I and Q channels are
compared with the min/max threshold values in the registers. If it exceeds the limits, an
LPCD_IRQ will be raised. After the LPCD command the standby is activated, if selected.

#### **7.10.3.3 Load key command**

Command (02h), Parameter1 (key byte1),..., Parameter6 (key byte6);

Loads a MIFARE Classic key (6 bytes) for Authentication from the FIFO into the cryptounit.

Abort condition: Less than 6 bytes written to the FIFO.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **54 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **7.10.3.4 MFAuthent command**

Command (03h), Parameter1 (Authentication command code 60h or 61h), Parameter2
(block address), Parameter3 (card serial number byte0), Parameter4 (card serial number
byte1), Parameter5 (card serial number byte2), Parameter6 (card serial number byte3);

This command handles the MIFARE Classic authentication in Reader/Writer mode to
ensure a secure communication to any MIFARE classic card.

When the MFAuthent command is active, any FIFO access is blocked. Anyhow if there is
access to the FIFO, the bit WrErr in the Error register is set.

This command terminates automatically when the MIFARE Classic card is authenticated
and the bit MFCrypto1On is set to logic 1.

This command does not terminate automatically, when the card does not answer,
therefore the timer should be initialized to automatic mode. In this case, beside the bit
IdleIRQ the bit TimerIRQ can be used as termination criteria. During authentication
processing the bits RxIRQ and TxIRQ are blocked. The Crypto1On shows if the
authentication was successful. The Crypto1On is always valid.

In case, there is an error during authentication, the bit ProtocolErr in the Error register is
set to logic 1 and the bit Crypto1On in register Status2Reg is set to logic 0.

#### **7.10.3.5 AckReq command**

Command (04h);

Performs a Query (Full command must be written into the FIFO); an Ack and a ReqRn
command. All answers to the command will be written into the FIFO. The error flag is
copied after the answer into the FIFO.

This command terminates automatically and the then active state is idle.

#### **7.10.3.6 Receive command**

Command (05h);

The CLRC663 activates the receiver path and waits for any data stream to be received,
according to its register settings. The registers must be set before starting this command
according to the used protocol and antenna configuration. The correct settings have to be
chosen before starting the command.

This command terminates automatically when the received data stream ends. This
is indicated either by the end of frame pattern or by the length byte depending on the
selected framing and speed.

**Remark:** If the bit RxMultiple in the RxModeReg register is set to logic 1, the Receive
command does not terminate automatically. It has to be terminated by activating any
other command in the CommandReg register (see Section 8.17.6).

#### **7.10.3.7 Transmit command**

Command (06h); data to transmit

The content of the FIFO is transmitted immediately after starting the command. Before
transmitting the FIFO, all relevant registers have to be set to transmit data.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **55 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


This command terminates automatically when the FIFO gets empty. It can be terminated
by any other command written to the command register.

#### **7.10.3.8 Transceive command**

Command (07h); data to transmit

This command transmits data from FIFO buffer and automatically activates the receiver
after a transmission is finished.

Each transmission process starts by writing the command into CommandReg.

**Remark:** If the bit RxMultiple in register RxModeReg is set to logic 1, this command will
never leave the receiving state, because the receiving will not be cancelled automatically.

#### **7.10.3.9 WriteE2 command**

Command (08h), Parameter1 (addressH), Parameter2 (addressL), Parameter3 (data);

This command writes one byte into the EEPROM. If the FIFO contains no data, the
command will wait until the data is available.

Abort condition: Address-parameter outside of allowed range 0x00 – 0x7F.

#### **7.10.3.10 WriteE2PAGE command**

Command (09h), Parameter1 (page address), Parameter2..63 (data0, data1...data63);

This command writes up to 64 bytes into the EEPROM. The addresses are not allowed
to wrap over a page border. If this is the case, this additional data be ignored and stays
in the fifo. The programming starts after 64 bytes are read from the FIFO or the FIFO is
empty.

Abort condition: Insufficient parameters in FIFO; Page address parameter outside of
range 0x00 – 0x7F.

#### **7.10.3.11 ReadE2 command**

Command (0Ah), Parameter1 (addressH), Parameter2 (addressL), Parameter3 (length);

Reads up to 256 bytes from the EEPROM to the FIFO. If a read operation exceeds the
address 1FFFh, the read operation continues from address 0000h.

Abort condition: Insufficient parameter in FIFO; Address parameter outside of range.

#### **7.10.3.12 LoadReg command**

Command (0Ch), Parameter1 (EEPROM addressH),Parameter2 (EEPROM addressL),
Parameter3 (RegAdr), Parameter4 (number);

Read a defined number of bytes from the EEPROM and copies the value into the
Register set, beginning at the given address RegAdr.

Abort condition: Insufficient parameter in FIFO; Address parameter outside of range.

#### **7.10.3.13 LoadProtocol command**

Command (0Dh), Parameter1 (Protocol number RX), Parameter2 (Protocol number TX);


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **56 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


Reads out the EEPROM Register Set Protocol Area and overwrites the content of the
Rx- and Tx- related registers. These registers are important for a Protocol selection.

Abort condition: Insufficient parameter in FIFO















|Protocol<br>Number<br>(decimal)|Protocol|Receiver speed<br>\[kbits/s\]|Receiver Coding|
|---|---|---|---|
|00|ISO/IEC14443 A|106|Manchester SubC|
|01|ISO/IEC14443 A|212|BPSK|
|02|ISO/IEC14443 A|424|BPSK|
|03|ISO/IEC14443 A|848|BPSK|
|04|ISO/IEC14443 B|106|BPSK|
|05|ISO/IEC14443 B|212|BPSK|
|06|ISO/IEC14443 B|424|BPSK|
|07|ISO/IEC14443 B|848|BPSK|
|08|FeliCa|212|Manchester|
|09|FeliCa|424|Manchester|
|10|ISO/IEC15693|26|SSC|
|11|ISO/IEC15693|52|SSC|
|12|ISO/IEC15693|26|DSC|
|13|EPC/UID|26|SSC|
|14|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|212|2/424|
|15|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|106|4/424|
|16|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|424|2/848|
|17|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|212|4/848|
|18|Jewel|-|-|



\[1\] For more protocol details, please refer to Section 7.









|Protocol<br>Number<br>(decimal)|Protocol|Transmitter speed<br>\[kbits/s\]|Transmitter Coding|
|---|---|---|---|
|00|ISO/IEC14443 A|106|Miller|
|01|ISO/IEC14443 A|212|Miller|
|02|ISO/IEC14443 A|424|Miller|
|03|ISO/IEC14443 A|848|Miller|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **57 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_















|Protocol<br>Number<br>(decimal)|Protocol|Transmitter speed<br>\[kbits/s\]|Transmitter Coding|
|---|---|---|---|
|04|ISO/IEC14443 B|106|NRZ|
|05|ISO/IEC14443 B|212|NRZ|
|06|ISO/IEC14443 B|424|NRZ|
|07|ISO/IEC14443 B|848|NRZ|
|08|FeliCa|212|Manchester|
|09|FeliCa|424|Manchester|
|10|ISO/IEC15693|26|1/4|
|11|ISO/IEC15693|26|1/4|
|12|ISO/IEC15693|1,66|1/256|
|13|EPC/UID|53|Unitray|
|14|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|-|based on Tari value,<br>ASK, PIE|
|15|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|-|based on Tari value,<br>ASK, PIE|
|16|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|-|based on Tari value,<br>ASK, PIE|
|17|ISO/IEC 18000-3 mode 3/<br>EPC Class-1 HF|-|based on Tari value,<br>ASK, PIE|
|18|Jewel|-|-|



\[1\] For more protocol details, please refer to Section 7.

#### **7.10.3.14 LoadKeyE2 command**

Command (0Eh), Parameter1 (key number);

Loads a MIFARE Classic key for authentication from the EEPROM into the crypto 1 unit.

Abort condition: Insufficient parameter in FIFO; KeyNr is outside the MIFARE Classic key
area.

#### **7.10.3.15 StoreKeyE2 command**

Command (0Fh), Parameter1 (KeyNr), Parameter2(keybyte1), Parameter3(keybyte2),
Parameter4(keybyte3), Parameter5(keybyte4), Parameter6(keybyte5), Parameter7
(keybyte6);

Stores MIFARE Classic keys into the EEPROM. The key number parameter indicates
the first key (n) in the MKA that will be written. If more than one MIFARE Classic key is
available in the FIFO then the next key (n+1) will be written until the FIFO is empty. If an
incomplete key (less than 6 bytes) is written into the FIFO, this key will be ignored and
will remain in the FIFO.

Abort condition: Insufficient parameter in FIFO; KeyNr is outside the MKA;


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **58 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **7.10.3.16 GetRNR command**

Command (1Ch);

This command is reading Random Numbers from the random number generator of the
CLRC663. The Random Numbers are copied to the FIFO until the FIFO is full.

#### **7.10.3.17 SoftReset command**

Command (1Fh);

This command is performing a soft reset. Triggered by this command all the default
values for the register setting will be read from the EEPROM and copied into the register
set.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **59 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
