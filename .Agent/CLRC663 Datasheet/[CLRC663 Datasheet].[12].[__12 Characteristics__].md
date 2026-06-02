# **12 Characteristics**
































|Symbol|Parameter|Conditions|Col4|Min|Typ|Max|Unit|
|---|---|---|---|---|---|---|---|
|**Current consumption**|**Current consumption**|**Current consumption**||||||
|IDD|supply current|IDD = AVDD+DVDD;modem<br>on (transmitter and<br>receiver are switched on)||-|17|20|mA|
|IDD|supply current|IDD = AVDD+DVDD; modem<br>off (transmitter and<br>receiver are switched off)||-|0.45|0.5|mA|
|IDD(PVDD)|PVDD supply current|no load on digital pins,<br>leakage current only||-|0.5|5|μA|
|IDD(TVDD)|TVDD supply current|CLRC66301HN,<br>CLRC66302HN||-|100|250|mA|
|IDD(TVDD)|TVDD supply current|CLRC66303HN||-|250|350|mA|
|Ipd|power-down current|All OUTx pins floating||||||
|Ipd|power-down current|ambient temp = +25 °C||-|40|400|nA|
|Ipd|power-down current|ambient temp = -40°C...<br>+85°C||-|1.5|2.1|μA|
|Ipd|power-down current|CLRC66303: ambient temp<br>= +105 °C||-|3.5|5.2|μA|
|Istby|standby current|All OUTx pins floating||||||
|||ambient temp = 25 °C,<br>IVDD+ITVDD+ IPVDD||-|3|6|μA|
|||ambient temp = -40°C...<br>+105°C, Istby = IVDD+ITVDD+<br>IPVDD||-|5.25|26|26|
|ILPCD(sleep)|LPCD sleep current|All OUTx pins floating||||||
|ILPCD(sleep)|LPCD sleep current|LFO active, no RF field on,<br>ambient temp = 25 °C|\[1\]|-|3.3|6.3|μA|
|ILPCD(averag|e)LPCD average current|All OUTx pins floating,<br>TxLoad = 50 ohms.<br>LPCD_FILTER = 0; Rfon<br>duration = 10 us, RF-off<br>duration 300ms; VTVDD =<br>3.0V; Tamb = 25°C; ILPCD =<br>IVDD+ITVDD+ IPVDD||||||
|ILPCD(averag|e)LPCD average current|LPCD_TX_HIGH = 0,||-|12|-|μA|
|ILPCD(averag|e)LPCD average current|LPCD_TX_HIGH = 1||-|23|-|-|
|tRFON|RF-on time during LPCD|LPCD_TX_HIGH = 0;<br>TVDD=5.0 V<br>T=25°C;||-|10|-|μs|
|||LPCD_TX_HIGH = 1;<br>TVDD=5.0 V; T=25°C||-|50|-|μs|
|**Buffer capacitors on AVDD,DVDD**|**Buffer capacitors on AVDD,DVDD**|**Buffer capacitors on AVDD,DVDD**||||||



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **121 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_































|Symbol|Parameter|Conditions|Col4|Min|Typ|Max|Unit|
|---|---|---|---|---|---|---|---|
|CL|external buffer capacitor|AVDD||220|470|-|nF|
|CL|external buffer capacitor|DVDD||220|470|-|nF|
|**I/O pin characteristics SIGIN/OUT7, SIGOUT, CLKOUT/OUT6,**<br>**IFSEL0/OUT4, IFSEL1/OUT5, TCK/OUT3, TMS/OUT2, TDI/**<br>**OUT1, TDO/OUT0, IRQ, IF0, IF1, IF2, SCL2, SDA2**|**I/O pin characteristics SIGIN/OUT7, SIGOUT, CLKOUT/OUT6,**<br>**IFSEL0/OUT4, IFSEL1/OUT5, TCK/OUT3, TMS/OUT2, TDI/**<br>**OUT1, TDO/OUT0, IRQ, IF0, IF1, IF2, SCL2, SDA2**|**I/O pin characteristics SIGIN/OUT7, SIGOUT, CLKOUT/OUT6,**<br>**IFSEL0/OUT4, IFSEL1/OUT5, TCK/OUT3, TMS/OUT2, TDI/**<br>**OUT1, TDO/OUT0, IRQ, IF0, IF1, IF2, SCL2, SDA2**||||||
|ILI|input leakage current|output disabled||0.0|50|500|nA|
|VIL|low-level input voltage|||-0.5|-|0.3 x VDD(PVDD)|V|
|VIH|high-level input voltage|||0.7 x<br>VDD(PVDD)|VDD(PVD|D)VDD(PVDD) + 0.5|V|
|VOL|low-level output voltage|||0.0|0.0|0.4|V|
|VOH|high-level output voltage|If pins are used as output<br>OUTx, IOH = 4 mA driving<br>current for each pin||VDD(PVDD)-0.4|VDD(PVD|D)VDD(PVDD)|V|
|Ci|input capacitance|||0.0|2.5|4.5|pF|
|**Pin characteristics PDOWN**|**Pin characteristics PDOWN**|**Pin characteristics PDOWN**||||||
|VIL|low-level input voltage|||0.0|0.0|0.4|V|
|VIH|high-level input voltage|||0.6 x VPVDD|VDD(PVD|D)VDD(PVDD)|V|
|**Pull-up resistance for TCK, TMS, TDI, IF2**|**Pull-up resistance for TCK, TMS, TDI, IF2**|**Pull-up resistance for TCK, TMS, TDI, IF2**||||||
|Rpu|pull-up resistance|||50|72|120|KΩ|
|**Pin characteristics AUX 1, AUX 2**|**Pin characteristics AUX 1, AUX 2**|**Pin characteristics AUX 1, AUX 2**||||||
|Vo|output voltage|||0.0|-|1.8|V|
|CL|load capacitance|||0.0|-|400|pF|
|**Pin characteristics RXP, RXN**|**Pin characteristics RXP, RXN**|**Pin characteristics RXP, RXN**||||||
|Vpp|input voltage|||0|1.65|1.8|V|
|Ci|input capacitance|||2|3.5|5|pF|
|Vmod(pp)|modulation voltage|Vmod(pp) = Vi(pp)(max) - Vi(pp)<br>(min)||-|2.5|-|mV|
|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|**Pins TX1 and TX2**|
|Vo|output voltage|||Vss(TVSS)|-|VDD(TVDD)|V|
|Ro|output resistance|CLRC66301, CLRC66302:<br>T=25°C, VDD(TVDD) = 5.0V||-|1.5|-|Ω|
|Ro|output resistance|CLRC66303: T=25°C,<br>VDD(TVDD) = 5.0V||-|1.2|-|Ω|
|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|**Clock frequency Pin CLKOUT**|
|fclk|clock frequency|configured to 27.12 MHz||-|27.12|-|MHz|
|δclk|clock duty cycle|||-|50|-|%|
|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|**Crystal connection XTAL1, XTAL2**|
|Vo(p-p)|peak-to-peak output<br>voltage|pin XTAL1||-|1.0|-|V|
|Vi|input voltage|pin XTAL1||0.0|-|1.8|V|


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **122 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_





















|Symbol|Parameter|Conditions|Col4|Min|Typ|Max|Unit|
|---|---|---|---|---|---|---|---|
|Ci|input capacitance|pin XTAL1||-|3|-|pF|
|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|**Crystal requirements**|
|fxtal|crystal frequency|ISO/IEC14443 compliancy||27.12-14kHz|27.12|27.12+14kHz|MHz|
|ESR|equivalent series<br>resistance|||-|50|100|Ω|
|CL|load capacitance|||-|10|-|pF|
|Pxtal<br>|crystal power dissipation<br>|||-<br>|50|100|μW|
|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|**Input characteristics I/O Pin Characteristics IF3-SDA in I2**C configuration|
|ILI|input leakage current|output disabled||-|2|100|nA|
|VIL|LOW-level input voltage|||-0.5|-|+0.3 VDD(PVDD)|V|
|VIH|HIGH-level input voltage|||0.7 VDD(PVDD)|-|VDD(PVDD) + 0.5|V|
|VOL|LOW-level output voltage|IOL = 3 mA||-|-|0.3|V|
|IOL|LOW-level output current|VOL = 0.4 V; Standard<br>mode, Fast mode||4|-|-|mA|
|IOL|LOW-level output current|VOL = 0.6 V; Standard<br>mode, Fast mode||6|-|-|mA|
|tf(o)|output fall time|Standard mode, Fast<br>mode, CL < 400 pF||-|-|250|ns|
|tf(o)|output fall time|Fast mode +; CL < 550 pF||-|-|120|ns|
|tSP|pulse width of spikes that<br>must be suppressed by<br>the input filter|||0|-|50|ns|
|Ci|input capacitance|||-|3.5|5|pF|
|CL|load capacitance|Standard mode||-|-|400|pF|
|CL|load capacitance|Fast mode||-|-|550|pF|
|tEER|EEPROM data retention<br>time|Tamb = +55 °C||10<br>|-|-|year|
|NEEC|EEPROM endurance<br>(number of programming<br>cycles)|under all operating<br>conditions||5 x 105|-|-|cycle|



\[1\] Ipd is the total current for all supplies.









CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **123 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_




你好。我是资深硬件工程师，已对提供的图片（Figure 34. Pin RX input voltage）完成精准解析。

**1. 【总览信息】**
本图定义了接收引脚（Pin RX）的输入电压波形特性，重点描述了在 $13.56\text{ MHz}$ 载波信号上的幅度调制（Amplitude Modulation）参数及其相对于中点电压 $VMID$ 的电平分布。

**2. 【核心组成部件】**
*   **载波信号 (Carrier)**：频率为 $13.56\text{ MHz}$ 的正弦/方波调制信号。
*   **参考电压电平**：
    *   $VMID$：信号的中心参考电压（Common-mode Voltage）。
    *   $0\text{ V}$：绝对零电平参考线。
*   **电压幅值参数**：
    *   $V_{i(p-p)(max)}$：最大峰峰值电压（未调制状态）。
    *   $V_{i(p-p)(min)}$：最小峰峰值电压（调制凹陷状态）。
    *   $V_{mod}$：调制深度/电压偏移量。

**3. 【数据流向与交互】**

由于本图为电压特性图而非逻辑时序图，其交互关系体现为载波幅度与调制状态的映射关系。

**表 1：Pin RX 信号电平参数定义**

| 参数符号 | 物理含义 | 测量基准 | 状态关联 |
| :--- | :--- | :--- | :--- |
| $V_{i(p-p)(max)}$ | 最大峰峰值电压 | 波形顶端 $\leftrightarrow$ 波形底端 | 无调制/空闲状态 |
| $V_{i(p-p)(min)}$ | 最小峰峰值电压 | 波形调制低点 $\leftrightarrow$ 波形调制低点 | 调制激活状态 (Active) |
| $V_{mod}$ | 调制幅度 | 峰值 $\leftrightarrow$ 调制后峰值 | 决定调制深度 |
| $VMID$ | 中点电压 | $0\text{ V} \rightarrow VMID$ | 信号中心偏移量 |

**信号拓扑关系 (ASCII 图解)：**
```text
\[载波源: 13.56MHz\] 
       $\downarrow$
\[调制环节\] $\rightarrow$ (改变 Vp-p 产生 Vmod)
       $\downarrow$
\[Pin RX 输入端\] $\rightarrow$ (中心偏置于 VMID, 范围在 0V 与 Vpp_max 之间)
```

**4. 【功能总结性陈述】**

**事实描述**：
1. 信号工作在 $13.56\text{ MHz}$ 的载波频率下。
2. 信号呈现差分对称结构（或经偏置处理），中心点为 $VMID$。
3. 调制方式为幅度调制，通过改变峰峰值（从 $V_{i(p-p)(max)}$ 降低至 $V_{i(p-p)(min)}$）来传递信息。
4. $V_{mod}$ 定义了从最大幅值到调制后幅值的下降量。

**工程推论**：
1. \[工程推论\] 载波频率 $13.56\text{ MHz}$ 是典型的 NFC (Near Field Communication) 或 RFID (ISO 14443/15693) 标准频率，该引脚极大概率为 NFC 读写器芯片的接收端（RX）。
2. \[工程推论\] 这种通过降低载波幅值来编码的方式，符合典型的“负载调制（Load Modulation）”特征，表明该 RX 引脚用于检测由标签（Tag）端引起的载波幅度波动。
3. \[工程推论\] 引入 $VMID$ 而非直接以 $0\text{ V}$ 为基准，表明内部采用了差分输入结构或使用了电容耦合，旨在提高共模抑制比（CMRR）并增强抗噪声能力。









