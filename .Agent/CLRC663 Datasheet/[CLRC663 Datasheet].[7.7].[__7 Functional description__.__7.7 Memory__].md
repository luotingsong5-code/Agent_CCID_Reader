## **7.7 Memory**

### **7.7.1 Memory overview**

The CLRC663 implements three different memories: EEPROM, FIFO and Registers.

At startup, the initialization of the registers which define the behavior of the IC is
performed by an automatic copy of an EEPROM area (read/write EEPROM section1
and section2, register reset) into the registers. The behavior of the CLRC663 can be
changed by executing the command LoadProtocol, which copies a selected default
protocol from the EEPROM (read-only EEPROM section4, register Set Protocol area)
into the registers.

The read/write EEPROM section2 can be used to store any user data or predefined
register settings. These predefined settings can be copied with the command
"LoadRegister" into the internal registers.

The FIFO is used as Input/Out buffer and is able to improve the performance of a system
with limited interface speed.

### **7.7.2 EEPROM memory organization**

The CLRC663 has implemented a EEPROM non-volatile memory with a size of 8
kB.The EEPROM is organized in pages of 64 bytes. One page of 64 bytes can be
programmed at a time. Defined purposes had been assigned to specific memory areas


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **44 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


of the EEPROM, which are called Sections. Five sections 0..4 with different purpose do
exist.









|Section|Page|Byte<br>addresses|Access<br>rights|Memory content|
|---|---|---|---|---|
|0|0|00 to 31|r|product information and configuration|
|0|0|32 to 63|r/w|product configuration|
|1|1 to 2|64 to 191|r/w|register reset|
|2|3 to 95|192 to 6143|r/w|free|
|3|96 to 111|6144 to 7167|w|MIFARE Classic key|
|4|112 to 128|7168 to 8191|r|Register Set Protocol (RSP)|


The following figure shows the structure of the EEPROM:




**【总览信息】**
本图定义了该硬件设备中 EEPROM（电可擦除可编程只读存储器）的扇区内存布局（Sector Arrangement）。

**【核心组成部件】**
该 EEPROM 被划分为以下逻辑区域：
- **Section 0**：生产与配置区（Production and config）
- **Section 1**：寄存器复位区（Register reset）
- **Section 2**：空闲区（Free）
- **Section 3**：MIFARE Classic 密钥区（MIFARE Classic key area, MKA）
- **Section 4_TX**：发送响应区（RSP-Area for TX）
- **Section 4_RX**：接收响应区（RSP-Area for RX）

**【数据流向与交互】**
由于原图为静态内存映射图，无动态时序，其拓扑结构表达如下：

**EEPROM 内存空间映射表**
| 扇区标识 (Section) | 逻辑功能定义 | 属性/用途 |
| :--- | :--- | :--- |
| Section 0 | Production and config | 生产与配置数据 |
| Section 1 | Register reset | 寄存器复位值 |
| Section 2 | Free | 未分配/预留空间 |
| Section 3 | MIFARE Classic key area (MKA) | MIFARE Classic 安全密钥存储 |
| Section 4_TX | RSP-Area for TX | 发送端响应数据存储 |
| Section 4_RX | RSP-Area for RX | 接收端响应数据存储 |

**内存层级拓扑 (ASCII)**
```text
EEPROM Memory Space
└── Sector Arrangement
    ├── \[Section 0\] ──> Production/Config Data
    ├── \[Section 1\] ──> Reset Values for Registers
    ├── \[Section 2\] ──> Unallocated (Free)
    ├── \[Section 3\] ──> MIFARE Classic Keys (MKA)
    └── \[Section 4\]
        ├── \[4_TX\] ──> TX Response Buffer/Storage
        └── \[4_RX\] ──> RX Response Buffer/Storage
```

**【功能总结性陈述】**
- **事实描述**：该 EEPROM 采用了分段存储管理，涵盖了从工厂配置（Section 0）、系统初始化参数（Section 1）、预留空间（Section 2）到特定协议密钥存储（Section 3）以及通信响应缓冲区（Section 4_TX/RX）的完整布局。
- **工程推论**：
    1. \[工程推论\] 出现 “MIFARE Classic key area” 明确表明该芯片具备 NFC/RFID 读写功能，且支持 MIFARE Classic 标准的加密通信。
    2. \[工程推论\] Section 1 (Register reset) 的存在意味着该硬件在启动或软复位时，会从 EEPROM 将预设值加载至系统寄存器中，以实现配置的持久化。
    3. \[工程推论\] Section 4 被显式拆分为 TX 和 RX 响应区，表明其在处理通信协议时采用了双缓冲（Double Buffering）或对称的响应机制，用于暂存发送和接收的响应报文。
    4. \[工程推论\] Section 2 为 “Free” 状态，通常用于支持未来固件升级时的参数扩展或作为临时数据的 Scratchpad 区域。


#### **7.7.2.1 Product information and configuration - Page 0**

The first EEPROM page includes production data as well as configuration information.







|Address<br>(Hex.)|0|1|2|3|4|5|6|7|
|---|---|---|---|---|---|---|---|---|
|00|ProductID|ProductID|ProductID|Version|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|
|08|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Manufacturer<br>Data|
|10|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|
|18|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|ManufacturerData|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **45 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


ProductID: Identifier for this CLRC663 product or derivative, only address 01h shall be
evaluated for identifying the Product CLRC663, address 00h and 02h shall be ignored by
software.

Please note, that the silicon version CLRC66301, CLRC66302, CLRC66303 and
derivatives can be identified on register address 7Fh, it is not coded in the EEPROM
production area.

|Address 01h|Product ID|
|---|---|
|CLRC663|01h|
|MFRC631|C0h|
|MFRC630|80h|
|SLRC610|20h|



Version: This register indicates the version of the EEPROM initialization data during
production.

Unique IDentifier: Unique serial number code for this device

Manufacturer Data: This data is programmed during production. The content is not
intended to be used by any application and might not be constant for different devices.
Therefore the content needs to be considered to be undefined.







|Address<br>(Hex.)|0|1|2|3|4|5|6|7|
|---|---|---|---|---|---|---|---|---|
|20|I2C_Address|Interface|I2C SAM_Address|DefaultProtRx|DefaultProtTx|-|TxCRCPreset|TxCRCPreset|
|28|RxCRCPreset|RxCRCPreset|-|-|-|-|-|-|
|30|-|-|-|-|-|-|-|-|
|38|-|-|-|-|-|-|-|-|


I \[2\] C-Address

Two possibilities exist to define the address of the I \[2\] C interface. This can be done either
by configuring the pins IF0, IF2 (address is then 10101xx, xx is defined by the interface
pins IF0, IF2) or by writing value into the I \[2\] C address area. The selection, which of this
2-information pin configuration or EEPROM content - is used as I \[2\] C-address is done at
EEPROM address 21h (Interface, bit4)


Interface

This section describes the interface byte configuration.


**Table 38. Interface byte**

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||I2C_HSP|-|-|I2C_Address|Boundary Scan|Host|Host|Host|
|access rights|r/w|RFU|RFU|r/w|r/w|-|-|-|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **46 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_


**Table 39. Interface bits**











|Bit|Symbol|Description|
|---|---|---|
|7|I2C_HSP|when cleared, the high-speed mode is used<br>when set, the high speed+ mode is used (default)|
|6, 5|RFU<br>|-|
|4|I2C_Address|when cleared, the pins are used (default)<br>when set, the EEPROM is used|
|3|Boundary<br>Scan|when cleared, the boundary scan interface is ON (default)<br>when set, the boundary scan is OFF|
|2 to 0|Host|000b - RS232<br>001b - I2C<br>010b - SPI<br>011b - I2CL<br>1xxb - pin selection|


I \[2\] C_SAM_Address

The I \[2\] C SAM Address is always defined by the EEPROM content.

The Register Set Protocol (RSP) Area contains settings for the TX registers (16 bytes)
and for the RX registers (8 bytes).


**Table 40. Tx and Rx arrangements in the register set protocol area**

|Section|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|
|---|---|---|---|---|---|---|---|---|
|Section 4 TX|Tx0|Tx0|Tx1|Tx1|TX2|TX2|Tx3|Tx3|
|Section 4 TX|Tx4|Tx4|Tx5|Tx5|TX6|TX6|TX7|TX7|
|Section 4 Rx|RX0|RX1|RX2|RX3|RX4|RX5|RX6|RX7|
|Section 4 Rx|RX8|RX9|RX10|RX11|RX12|RX13|RX14|RX15|



TxCrcPreset

The data bits are sent by the analog module and are automatically extended by a CRC.

### **7.7.3 EEPROM initialization content LoadProtocol**

The CLRC663 EEPROM is initialized at production with values which are used to reset
certain registers of the CLRC663 to default settings by copying the EEPROM content
to the registers. Only registers or bits with "read/write" or "dynamic" access rights are
initialized with this default values copied from the EEPROM.

Note that the addresses used for copying reset values from EEPROM to registers are
dependent on the configured protocol and can be changed by the user.

|Address|0 (8)|1 (9)|2 (A)|3 (B)|4 (C)|5 (D)|6 (E)|7 (F)|
|---|---|---|---|---|---|---|---|---|
|Function|Product ID|Product ID|Product ID|Version|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **47 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Address|0 (8)|1 (9)|2 (A)|3 (B)|4 (C)|5 (D)|6 (E)|7 (F)|
|---|---|---|---|---|---|---|---|---|
|00|XX|see table 34|XX|XX|XX|XX|XX|XX|
|Function|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Unique Identifier|Factory trim<br>value|
|08|XX|XX|XX|XX|XX|XX|XX|XX|
|Function|TrimLFO|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|
|10|XX|XX|XX|XX|XX|XX|XX|XX|
|Function|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|
|18....|XX|XX|XX|XX|XX|XX|XX|XX|
||Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|Factory trim values|
|....38|XX|XX|XX|XX|XX|XX|XX|XX|



The register reset values are configuration parameters used after startup of the IC.
They can be changed to modify the default behavior of the device. In addition to these
register reset values, is the possibility to load settings for various users implemented
protocols.The load protocol command is used for this purpose.











































|Address|0 (8)|1 (9)|2 (A)|3 (B)|4 (C)|5 (D)|6 (E)|7 (F)|
|---|---|---|---|---|---|---|---|---|
||Command|HostCtrl|FiFoControl|WaterLevel|FiFoLength|FiFoData|IRQ0|IRQ1|
|40|40|00|80|05|00|00|00|00|
||IRQ0En|IRQ1En|Error|Status|RxBitCtrl|RxColl|TControl|T0Control|
|48|10|00|00|00|00|00|00|00|
||T0ReloadHi|T0ReloadLo|T0Counter<br>ValHi|T0Counter<br>ValLo|T1Control|T1ReloadHi|T1ReloadLo|T1Counter<br>ValHi|
|50|00|80|00|00|00|00|80|00|
||T1Counter<br>ValLo|T2Control|T2ReloadHi|T2ReloadLo|T2Counter<br>ValHi|T2Counter<br>ValLo|T3Control|T3ReloadHi|
|58|00|00|00|80|00|00|00|00|
||T3ReloadLo|T3Counter<br>ValHi|T3Counter<br>ValHi|T4Control|T4ReloadHi|T4ReloadLo|T4Counter<br>ValHi|T4Counter<br>ValLo|
|60|80|00|00|00|00|80|00|00|
||DrvMode|TxAmp|DrvCon|Txl|TxCRC<br>Preset|RxCRC<br>Preset|TxDataNum|TxModWith|
|68|86|15|11|06|18|18|08|27|
||TxSym10<br>BurstLen|TxWaitCtrl|TxWaitLo|FrameCon|RxSofD|RxCtrl|RxWait|RxThres<br>hold|
|70|00|C0|12|CF|00|04|90|3F|
||Rcv|RxAna|RFU|SerialSpeed|LFO_trimm|PLL_Ctrl|PLL_Div|LPCD_QMin|
|78|12|0A|00|7A|80|04|20|48|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **48 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_























|Address|0 (8)|1 (9)|2 (A)|3 (B)|4 (C)|5 (D)|6 (E)|7 (F)|
|---|---|---|---|---|---|---|---|---|
||LPCD_<br>QMax|LPCD_IMin|LPCD<br>_result_I|LPCD<br>_result_Q|PadEn|PadOut|PadIn|SigOut|
|80|12|88|00|00|00|00|00|00|
||TxBitMod|RFU|TxDataCon|TxDataMod|TxSymFreq|TxSym0H|TySym0L|TxSym1H|
|88|20|xx|04|50|40|00|00|00|
||TxSym1L|TxSym2|TxSym3|TxSym10Le<br>ngth|TxSym32Le<br>ngth|TxSym32Bu<br>rstCtrl|TxSym10M<br>od|TxSym32M<br>od|
|90|0x00|0x00|0x00|0x00|0x00|0x00|0x00|0x50|
||RxBitMod|RxEOFSym|RxSyncValH|RxSyncValL|RxSyncMod|RxMod|RXCorr|FabCal|
|98|0x02|0x00|0x00|0x01|0x00|0x08|0x08|0xB2|
