# **1 General description**


CLRC663, the high performance multi-protocol NFC frontend.

The CLRC663 multi-protocol NFC frontend IC supports the following operating modes

**•** Read/write mode supporting ISO/IEC 14443 type A and MIFARE Classic
communication mode

**•** Read/write mode supporting ISO/IEC 14443B

**•** Read/write mode supporting JIS X 6319-4 (comparable with FeliCa \[1\] (see Section 20.5)
scheme)

**•** Passive initiator mode according to ISO/IEC 18092

**•** Read/write mode supporting ISO/IEC 15693

**•** Read/write mode supporting ICODE EPC UID/ EPC OTP

**•** Read/write mode supporting ISO/IEC 18000-3 mode 3/ EPC Class-1 HF

The CLRC663’s internal transmitter is able to drive a reader/writer antenna designed
to communicate with ISO/IEC 14443A and MIFARE Cassic IC-based cards and
transponders without additional active circuitry. The digital module manages the
complete ISO/IEC 14443A framing and error detection functionality (parity and CRC).

The CLRC663 supports MIFARE Classic with 1 kB memory, MIFARE Classic with 4 kB
memory, MIFARE Ultralight, MIFARE Ultralight C, MIFARE Plus and MIFARE DESFire
products. The CLRC663 supports higher transfer speeds of the MIFARE product family
up to 848 kbit/s in both directions.

The CLRC663 supports layer 2 and 3 of the ISO/IEC 14443B reader/writer
communication scheme except anticollision. The anticollision needs to be implemented in
the firmware of the host controller as well as in the upper layers.

The CLRC663 is able to demodulate and decode FeliCa coded signals. The FeliCa
receiver part provides the demodulation and decoding circuitry for FeliCa coded signals.
The CLRC663 handles the FeliCa framing and error detection such as CRC. The
CLRC663 supports FeliCa higher transfer speeds of up to 424 kbit/s in both directions.

The CLRC663 is supporting the P2P passive initiator mode in accordance with ISO/IEC
18092.

The CLRC663 supports the vicinity protocol according to ISO/IEC15693, EPC UID and
ISO/IEC 18000-3 mode 3/ EPC Class-1 HF.

The following host interfaces are supported:

**•** Serial Peripheral Interface (SPI)

**•** Serial UART (similar to RS232 with voltage levels dependent on pin voltage supply)

**•** I \[2\] C-bus interface (two versions are implemented: I2C and I2CL)

1 In the following the word FeliCa is used for JIS X 6319-4


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


The CLRC663 supports the connection of a secure access module (SAM). A dedicated
separate I2C interface is implemented for a connection of the SAM. The SAM can be
used for high secure key storage and acts as a very performant crypto-coprocessor. A
dedicated SAM is available for connection to the CLRC663.

In this document the term „MIFARE Classic card“ refers to a MIFARE Classic IC-based
contactless card.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **2 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
