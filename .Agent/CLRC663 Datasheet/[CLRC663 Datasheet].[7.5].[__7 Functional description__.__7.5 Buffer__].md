## **7.5 Buffer**

### **7.5.1 Overview**

A 512 × 8-bit FIFO buffer is implemented in the CLRC663. It buffers the input and output
data stream between the host and the internal state machine of the CLRC663. Thus, it
is possible to handle data streams with lengths of up to 512 bytes without taking timing
constraints into account. The FIFO can also be limited to a size of 255 bytes. In this case
all the parameters (FIFO length, Watermark...) require a single byte only for definition. In
case of a 512 byte FIFO length, the definition of this value requires 2 bytes.

### **7.5.2 Accessing the FIFO buffer**

When the μ-Controller starts a command, the CLRC663 may, while the command is in
progress, access the FIFO-buffer according to that command. Physically only one FIFObuffer is implemented, which can be used in input and output direction. Therefore the μController has to take care, not to access the FIFO buffer in a way that corrupts the FIFO
data.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **35 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **7.5.3 Controlling the FIFO buffer**

Besides writing to and reading from the FIFO buffer, the FIFO-buffer pointers might be
reset by setting the bit FIFOFlush in FIFOControl to 1. Consequently, the FIFOLevel bits
are set to logic 0, the actually stored bytes are not accessible any more and the FIFO
buffer can be filled with another 512 bytes (or 255 bytes if the bit FIFOSize is set to 1)
again.

### **7.5.4 Status Information about the FIFO buffer**

The host may obtain the following data about the FIFO-buffers status:

**•** Number of bytes already stored in the FIFO-buffer. Writing increments, reading
decrements the FIFO level: FIFOLength in register FIFOLength (and FIFOControl
Register in 512 byte mode)

**•** Warning, that the FIFO-buffer is almost full: HiAlert in register FIFOControl according
to the value of the water level in register WaterLevel (Register 02h bit \[2\], Register 03h
bit\[7:0\])

**•** Warning, that the FIFO-buffer is almost empty: LoAlert in register FIFOControl
according to the value of the water level in register WaterLevel (Register 02h bit \[2\],
Register 03h bit\[7:0\])

**•** FIFOOvl bit indicates, that bytes were written to the FIFO buffer although it was already
full: ErrIRQ in register IRQ0.

WaterLevel is one single value defining both HiAlert (counting from the FIFO top) and
LoAlert (counting from the FIFO bottom). The CLRC663 can generate an interrupt signal
if:

**•** LoAlertIRQEn in register IRQ0En is set to logic 1 it will activate pin IRQ when LoAlert in
the register FIFOControl changes to 1.

**•** HiAlertIRQEN in register IRQ0En is set to logic 1 it will activate pin IRQ when HiAlert in
the register FIFOControl changes to 1.

The bit HiAlert is set to logic 1 if maximum water level bytes (as set in register
WaterLevel) or less can be stored in the FIFO-buffer. It is generated according to the
following equation:


(2)

The bit LoAlert is set to logic 1 if water level bytes (as set in register WaterLevel) or less
are actually stored in the FIFO-buffer. It is generated according to the following equation:


(3)


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **36 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
