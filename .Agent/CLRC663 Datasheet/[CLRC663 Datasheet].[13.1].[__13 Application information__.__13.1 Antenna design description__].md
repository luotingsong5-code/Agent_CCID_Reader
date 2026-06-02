## **13.1 Antenna design description**

The matching circuit for the antenna consists of an EMC low pass filter (L0 and C0), a
matching circuitry (C1 and C2), and a receiving circuits (R1 = R3, R2 = R4, C3 = C5
and C4 = C6;), and the antenna itself. The receiving circuit component values need to
be designed for operation with the CLRC663. A re-use of dedicated antenna designs
done for other products without adaptation of component values will result in degraded
performance.

### **13.1.1 EMC low pass filter**

The MIFARE product-based system operates at a frequency of 13.56 MHz. This
frequency is derived from a quartz oscillator to clock the CLRC663 and is also the
basis for driving the antenna with the 13.56 MHz energy carrier. This will not only
cause emitted power at 13.56 MHz but will also emit power at higher harmonics. The
international EMC regulations define the amplitude of the emitted power in a broad
frequency range. Thus, an appropriate filtering of the output signal is necessary to fulfill
these regulations.

**Remark:** The PCB layout has a major influence on the overall performance of the filter.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **126 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

### **13.1.2 Antenna matching**

Due to the impedance transformation of the given low pass filter, the antenna coil has to
be matched to a certain impedance. The matching elements C1 and C2 can be estimated
and have to be fine-tuned depending on the design of the antenna coil.

The correct impedance matching is important to provide the optimum performance.
The overall quality factor has to be considered to guarantee a proper ISO/IEC 14443
communication scheme. Environmental influences have to be considered as well as
common EMC design rules.

For details, refer to the NXP application notes.

### **13.1.3 Receiving circuit**

The internal receiving concept of the CLRC663 makes use both side-bands of the
subcarrier load modulation of the card response via a differential receiving concept (RXP,
RXN). No external filtering is required.

It is recommended using the internally generated VMID potential as the input potential
of pin RX. This DC voltage level of VMID has to be coupled to the Rx-pins via R2 and
R4. To provide a stable DC reference voltage capacitances C4, C6 has to be connected
between VMID and ground. Refer to Figure 36.

Considering the (AC) voltage limits at the Rx-pins the AC voltage divider of R1 + C3 and
R2 as well as R3 + C5 and R4 has to be designed. Depending on the antenna coil design
and the impedance matching, the voltage at the antenna coil varies from antenna design
to antenna design. Therefore the recommended way to design the receiving circuit is to
use the given values for R1(= R3), R2 (= R4), and C3 (= C5) from the above mentioned
application note, and adjust the voltage at the RX-pins by varying R1(= R3) within the
given limits.

**Remark:** R2 and R4 are AC-wise connected to ground (via C4 and C6).

### **13.1.4 Antenna coil**

The precise calculation of the antenna coils’ inductance is not practicable but the
inductance can be **estimated** using the following formula. We recommend designing an
antenna either with a circular or rectangular shape.


(4)

**•** I1 - Length in cm of one turn of the conductor loop

**•** D1 - Diameter of the wire or width of the PCB conductor respectively

**•** K - Antenna shape factor (K = 1.07 for circular antennas and K = 1.47 for square
antennas)

**•** L1 - Inductance in nH

**•** N1 - Number of turns

**•** Ln: Natural logarithm function

The actual values of the **antenna inductance, resistance, and capacitance at 13.56**
**MHz** depend on various parameters such as:


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **127 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


**•** antenna construction (Type of PCB)

**•** thickness of conductor

**•** distance between the windings

**•** shielding layer

**•** metal or ferrite in the near environment

Therefore a measurement of those parameters under real life conditions, or at least a
rough measurement and a tuning procedure are highly recommended to guarantee a
reasonable performance. For details, refer to the above mentioned application notes.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **128 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
