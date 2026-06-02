# **Tables**



Tab. 1. Quick reference data CLRC66301HN and
CLRC66302HN ..................................................4
Tab. 2. Quick reference data CLRC66303HN ............... 4
Tab. 3. Ordering information ..........................................5
Tab. 4. Pin description ...................................................7
Tab. 5. Interrupt sources ............................................. 10
Tab. 6. Communication overview for ISO/IEC 14443
type A and read/write mode for MIFARE
Classic .............................................................13
Tab. 7. Communication overview for ISO/IEC 14443
B reader/writer .................................................15
Tab. 8. Communication overview for FeliCa reader/
writer ................................................................16
Tab. 9. FeliCa framing and coding .............................. 16
Tab. 10. Communication overview for ISO/IEC 15693
reader/writer reader to label ............................16
Tab. 11. Communication overview for ISO/IEC 15693
reader/writer label to reader ............................17
Tab. 12. Communication overview for EPC/UID ............17
Tab. 13. Communication overview for Passive
communication mode ...................................... 19
Tab. 14. Framing and coding overview ......................... 19
Tab. 15. Connection scheme for detecting the
different interface types ...................................20
Tab. 16. Byte Order for MOSI and MISO ...................... 21
Tab. 17. Byte Order for MOSI and MISO ...................... 21
Tab. 18. Address byte 0 register; address MOSI ...........21
Tab. 19. Timing conditions SPI ..................................... 22
Tab. 20. Settings of BR_T0 and BR_T1 ........................23
Tab. 21. Selectable transfer speeds ..............................23
Tab. 22. UART framing ................................................. 23
Tab. 23. Byte Order to Read Data ................................ 24
Tab. 24. Byte Order to Write Data ................................ 24
Tab. 25. Timing parameter I2CL ................................... 29
Tab. 26. SPI SAM connection ....................................... 31
Tab. 27. Boundary scan command ............................... 31
Tab. 28. Boundary scan path of the CLRC663 ..............34
Tab. 29. Settings for TX1 and TX2 ............................... 38
Tab. 30. Setting residual carrier and modulation
index by TXamp.set_residual_carrier ..............38
Tab. 31. Configuration for single or differential
receiver ............................................................41
Tab. 32. Register configuration of CLRC663 active
antenna concept (DIGITAL) ............................ 42
Tab. 33. Register configuration of CLRC663 active
antenna concept (Antenna) .............................42
Tab. 34. EEPROM memory organization ...................... 45
Tab. 35. Production area (Page 0) ................................45
Tab. 36. Product ID overview of CLRC663 family ......... 46
Tab. 37. Configuration area (Page 0) ............................46
Tab. 38. Interface byte .................................................. 46
Tab. 39. Interface bits ....................................................47
Tab. 40. Tx and Rx arrangements in the register set
protocol area ................................................... 47
Tab. 41. Register reset values (Hex.) (Page0) .............. 47



Tab. 42. Register reset values (Hex.)(Page1 and
page 2) ............................................................48
Tab. 43. Crystal requirements recommendations ..........49
Tab. 44. Divider values for selected frequencies
using the integerN PLL ................................... 50
Tab. 45. Command set ..................................................53
Tab. 46. Predefined protocol overview RX For more
protocol details, please refer to . .....................57
Tab. 47. Predefined protocol overview TX For more
protocol details, please refer to . .....................57
Tab. 48. Behavior of register bits and their
designation ...................................................... 60
Tab. 49. CLRC663 registers overview ...........................60
Tab. 50. Command register (address 00h) ....................63
Tab. 51. Command bits .................................................63
Tab. 52. HostCtrl register (address 01h); ...................... 64
Tab. 53. HostCtrl bits .....................................................64
Tab. 54. FIFOControl register (address 02h); ............... 64
Tab. 55. FIFOControl bits ..............................................64
Tab. 56. WaterLevel register (address 03h); .................65
Tab. 57. WaterLevel bits ............................................... 65
Tab. 58. FIFOLength register (address 04h); reset
value: 00h ........................................................66
Tab. 59. FIFOLength bits .............................................. 66
Tab. 60. FIFOData register (address 05h); ................... 66
Tab. 61. FIFOData bits ..................................................66
Tab. 62. IRQ0 register (address 06h); reset value:
00h .................................................................. 67
Tab. 63. IRQ0 bits ......................................................... 67
Tab. 64. IRQ1 register (address 07h) ............................67
Tab. 65. IRQ1 bits ......................................................... 68
Tab. 66. IRQ0En register (address 08h) ....................... 68
Tab. 67. IRQ0En bits .....................................................68
Tab. 68. IRQ1EN register (address 09h); ......................69
Tab. 69. IRQ1EN bits .................................................... 69
Tab. 70. Error register (address 0Ah) ............................69
Tab. 71. Error bits ..........................................................70
Tab. 72. Status register (address 0Bh) ......................... 70
Tab. 73. Status bits ....................................................... 71
Tab. 74. RxBitCtrl register (address 0Ch); .................... 71
Tab. 75. RxBitCtrl bits ................................................... 71
Tab. 76. RxColl register (address 0Dh); ........................72
Tab. 77. RxColl bits .......................................................72
Tab. 78. TControl register (address 0Eh) ......................73
Tab. 79. TControl bits ....................................................73
Tab. 80. T0Control register (address 0Fh); ................... 73
Tab. 81. T0Control bits ..................................................74
Tab. 82. T0ReloadHi register (address 10h); ................ 74
Tab. 83. T0ReloadHi bits ...............................................74
Tab. 84. T0ReloadLo register (address 11h); ................75
Tab. 85. T0ReloadLo bits .............................................. 75
Tab. 86. T0CounterValHi register (address 12h) ...........75
Tab. 87. T0CounterValHi bits ........................................ 75
Tab. 88. T0CounterValLo register (address 13h) .......... 75
Tab. 89. T0CounterValLo bits ........................................76
Tab. 90. T1Control register (address 14h); ................... 76



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **165 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_



Tab. 91. T1Control bits ..................................................76
Tab. 92. T0ReloadHi register (address 15h) ................. 76
Tab. 93. T1ReloadHi bits ...............................................77
Tab. 94. T1ReloadLo register (address 16h) .................77
Tab. 95. T1ReloadLo bits .............................................. 77
Tab. 96. T1CounterValHi register (address 17h) ...........77
Tab. 97. T1CounterValHi bits ........................................ 77
Tab. 98. T1CounterValLo register (address 18h) .......... 77
Tab. 99. T1CounterValLo bits ........................................78
Tab. 100. T2Control register (address 19h) .................... 78
Tab. 101. T2Control bits ..................................................78
Tab. 102. T2ReloadHi register (address 1Ah) .................78
Tab. 103. T2ReloadHi bits ...............................................79
Tab. 104. T2ReloadLo register (address 1Bh) ................ 79
Tab. 105. T2ReloadLo bits .............................................. 79
Tab. 106. T2CounterValHi register (address 1Ch) .......... 79
Tab. 107. T2CounterValHi bits ........................................ 79
Tab. 108. T2CounterValLo register (address 1Dh) ..........79
Tab. 109. T2CounterValLo bits ........................................80
Tab. 110. T3Control register (address 1Eh) ....................80
Tab. 111. T3Control bits ..................................................80
Tab. 112. T3ReloadHi register (address 1Fh); ................ 81
Tab. 113. T3ReloadHi bits ...............................................81
Tab. 114. T3ReloadLo register (address 20h) .................81
Tab. 115. T3ReloadLo bits .............................................. 81
Tab. 116. T3CounterValHi register (address 21h) ...........81
Tab. 117. T3CounterValHi bits ........................................ 81
Tab. 118. T3CounterValLo register (address 22h) .......... 82
Tab. 119. T3CounterValLo bits ........................................82
Tab. 120. T4Control register (address 23h) .................... 82
Tab. 121. T4Control bits ..................................................82
Tab. 122. T4ReloadHi register (address 24h) ................. 83
Tab. 123. T4ReloadHi bits ...............................................83
Tab. 124. T4ReloadLo register (address 25h) .................83
Tab. 125. T4ReloadLo bits .............................................. 83
Tab. 126. T4CounterValHi register (address 26h) ...........84
Tab. 127. T4CounterValHi bits ........................................ 84
Tab. 128. T4CounterValLo register (address 27h) .......... 84
Tab. 129. T4CounterValLo bits ........................................84
Tab. 130. TXMode register (address 28h) ...................... 84
Tab. 131. TXMode bits ....................................................84
Tab. 132. TxAmp register (address 29h) .........................85
Tab. 133. TxAmp bits ...................................................... 85
Tab. 134. TxCon register (address 2Ah) .........................85
Tab. 135. TxCon bits .......................................................86
Tab. 136. Txl register (address 2Bh) ...............................86
Tab. 137. Txl bits .............................................................86
Tab. 138. TXCrcPreset register (address 2Ch) ............... 86
Tab. 139. TxCrcPreset bits ..............................................86
Tab. 140. Transmitter CRC preset value configuration ....87
Tab. 141. RxCrcCon register (address 2Dh) ...................87
Tab. 142. RxCrcCon bits .................................................87
Tab. 143. Receiver CRC preset value configuration ....... 88
Tab. 144. TxDataNum register (address 2Eh) .................88
Tab. 145. TxDataNum bits .............................................. 88
Tab. 146. TxDataModWidth register (address 2Fh) ........ 89
Tab. 147. TxDataModWidth bits ......................................89
Tab. 148. TxSym10BurstLen register (address 30h) .......89
Tab. 149. TxSym10BurstLen bits .................................... 89



Tab. 150. TxWaitCtrl register (address 31h); reset
value: C0h .......................................................90
Tab. 151. TXWaitCtrl bits ................................................ 90
Tab. 152. TxWaitLo register (address 32h) .....................91
Tab. 153. TxWaitLo bits .................................................. 91
Tab. 154. FrameCon register (address 33h) ................... 91
Tab. 155. FrameCon bits .................................................91
Tab. 156. RxSofD register (address 34h) ........................92
Tab. 157. RxSofD bits ..................................................... 92
Tab. 158. RxCtrl register (address 35h) ..........................92
Tab. 159. RxCtrl bits ........................................................93
Tab. 160. RxWait register (address 36h) ........................ 93
Tab. 161. RxWait bits ......................................................93
Tab. 162. RxThreshold register (address 37h) ................94
Tab. 163. RxThreshold bits ............................................. 94
Tab. 164. Rcv register (address 38h) ..............................94
Tab. 165. Rcv bits ........................................................... 94
Tab. 166. RxAna register (address 39h) ......................... 95
Tab. 167. RxAna bits .......................................................95
Tab. 168. Effect of gain and high-pass corner register
settings ............................................................ 95
Tab. 169. SerialSpeed register (address3Bh); reset
value: 7Ah ....................................................... 96
Tab. 170. SerialSpeed bits .............................................. 96
Tab. 171. RS232 speed settings .....................................96
Tab. 172. LFO_Trimm register (address 3Ch) ................ 97
Tab. 173. LFO_Trimm bits .............................................. 97
Tab. 174. PLL_Ctrl register (address3Dh) .......................97
Tab. 175. PLL_Ctrl register bits .......................................97
Tab. 176. Setting of feedback divider PLLDiv_FB \[1:0\] ....98
Tab. 177. PLLDiv_Out register (address 3Eh) ................ 98
Tab. 178. PLLDiv_Out bits .............................................. 98
Tab. 179. Setting for the output divider ratio
PLLDiv_Out \[7:0\] .............................................98
Tab. 180. LPCD_QMin register (address 3Fh) ................99
Tab. 181. LPCD_QMin bits ............................................. 99
Tab. 182. LPCD_QMax register (address 40h) ............... 99
Tab. 183. LPCD_QMax bits ............................................ 99
Tab. 184. LPCD_IMin register (address 41h) ................100
Tab. 185. LPCD_IMin bits ............................................. 100
Tab. 186. LPCD_Result_I register (address 42h) ..........100
Tab. 187. LPCD_Result_I bits .......................................100
Tab. 188. LPCD_Result_Q register (address 43h) ........100
Tab. 189. LPCD_Result_Q bits ..................................... 101
Tab. 190. LPCD_Options register (address 3Ah) ..........101
Tab. 191. LPCD_Options ...............................................101
Tab. 192. PinEn register (address 44h) ........................ 102
Tab. 193. PinEn bits ......................................................102
Tab. 194. PinOut register (address 45h) ....................... 102
Tab. 195. PinOut bits .....................................................103
Tab. 196. PinIn register (address 46h) ..........................103
Tab. 197. PinIn bits ....................................................... 103
Tab. 198. SigOut register (address 47h) ....................... 103
Tab. 199. SigOut bits .....................................................104
Tab. 200. TxBitMod register (address 48h) ...................105
Tab. 201. TxBitMod bits ................................................ 105
Tab. 202. TxDataCon (address 4Ah) ............................ 105
Tab. 203. TxDataCon bits ............................................. 106
Tab. 204. TxDataMod register (address 4Bh) ............... 106



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **166 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_



Tab. 205. TxDataMod bits ............................................. 107
Tab. 206. TxSymFreq (address 4Ch) ............................107
Tab. 207. TxSymFreq bits ............................................. 107
Tab. 208. TxSym0_H (address 4Dh) .............................108
Tab. 209. TxSym0_H bits ..............................................108
Tab. 210. TxSym0_L (address 4Eh) ............................. 108
Tab. 211. TxSYM0_L bits ..............................................109
Tab. 212. TxSym1_H (address 4Fh) ............................. 109
Tab. 213. TxSym1_H bits ..............................................109
Tab. 214. TxSym1_L (address 50h) ..............................109
Tab. 215. TxSym1_L bits .............................................. 109
Tab. 216. TxSYM2 (address 51h) ................................. 109
Tab. 217. TxSym2 bits .................................................. 109
Tab. 218. TxSym3 (address 52h) ..................................110
Tab. 219. TxSym3 bits .................................................. 110
Tab. 220. TxSym10Len (address 53h) ..........................110
Tab. 221. TxSym10Len bits ...........................................110
Tab. 222. TxSym32Len (address 54h) ..........................110
Tab. 223. TxSym32Len bits ...........................................110
Tab. 224. TxSym10BurstCtrl register (address 55h) ..... 111
Tab. 225. TxSym10BurstCtrl bits ...................................111
Tab. 226. TxSym10Mod register (address 56h) ............ 111
Tab. 227. TxSym10Mod bits ..........................................111
Tab. 228. TxSym32Mod register (address 57h) ............ 112
Tab. 229. TxSym32Mod bits ..........................................112
Tab. 230. RxBitMod (address 58h) ............................... 113
Tab. 231. RxBitMod bits ................................................ 113
Tab. 232. RxEofSym (address 59h) .............................. 114
Tab. 233. RxEOFSym bits .............................................114
Tab. 234. RxSyncValH register (address5Ah) ...............114
Tab. 235. RxSyncValH bits ............................................114
Tab. 236. RxSyncValL register (address 5Bh) .............. 114
Tab. 237. RxSyncValL bits ............................................ 115
Tab. 238. RxSyncMode register (address 5Ch) ............ 115
Tab. 239. RxSyncMod bits ............................................ 115
Tab. 240. RxMod register (address 5Dh) ...................... 115
Tab. 241. RxMod bits .................................................... 116
Tab. 242. RxCorr register (address 5Eh) ...................... 116
Tab. 243. RxCorr bits .................................................... 116
Tab. 244. FabCali register (address 5Fh) ......................116
Tab. 245. FabCali bits ................................................... 117
Tab. 246. Version register (address 7Fh) ......................117
Tab. 247. Version bits ................................................... 117
Tab. 248. Limiting values .............................................. 118
Tab. 249. Operating conditions CLRC66301HN and
CLRC66302HN ..............................................119
Tab. 250. Operating conditions CLRC66303HN ............119
Tab. 251. Thermal characteristics ................................. 120
Tab. 252. Characteristics ...............................................121
Tab. 253. SPI timing characteristics ..............................124
Tab. 254. I2C-bus timing in fast mode and fast mode
plus ................................................................124



Tab. 255. ISO/IEC14443-A 106 / MIFARE Classic
(Protocol Number 00) ....................................131
Tab. 256. ISO/IEC14443-A 212/ MIFARE Classic
(Protocol Number 01) ....................................132
Tab. 257. ISO/IEC14443-A 424/ MIFARE Classic
(Protocol Number 02) ....................................132
Tab. 258. ISO/IEC14443-A 848/ MIFARE Classic
(Protocol Number 03) ....................................133
Tab. 259. ISO/IEC14443-B 106 Classic (Protocol
Number 04) ................................................... 134
Tab. 260. ISO/IEC14443-B 212 Classic (Protocol
Number 05) ................................................... 135
Tab. 261. ISO/IEC14443-B 424, (Protocol Number 06) ..135
Tab. 262. ISO/IEC14443-B 848, (Protocol Number 07) ..136
Tab. 263. JIS X 6319-4 (FeliCa) 212, (Protocol
Number 08) ................................................... 137
Tab. 264. JIS X 6319-4 (FeliCa) 424, (Protocol
Number 09) ................................................... 138
Tab. 265. ISO/IEC15693 SLI 1/4 - SSC- 26, (Protocol
Number 10) ................................................... 138
Tab. 266. ISO/IEC15693 SLI 1/4 - SSC- 53, (Protocol
Number 11) ................................................... 139
Tab. 267. SO/IEC15693 SLI 1/256 - DSC, (Protocol
Number 12) ................................................... 140
Tab. 268. EPC/UID - SSC -26, (Protocol Number 13) ... 141
Tab. 269. EPC-V2 - 2/424 (Protocol Number 14) ..........141
Tab. 270. EPC-V2 - 4/424, (Protocol Number 15) .........142
Tab. 271. EPC-V2 - 2/848, (Protocol Number 16) .........143
Tab. 272. EPC-V2 - 4/848, (Protocol Number 17) .........144
Tab. 273. Jewel, (Protocol Number 18) .........................144
Tab. 274. ISO/IEC14443-A 106 / MIFARE Classic ........145
Tab. 275. ISO/IEC14443-A 212/ MIFARE Classic .........146
Tab. 276. ISO/IEC14443-A 424/ MIFARE Classic .........146
Tab. 277. ISO/IEC14443-A 848/ MIFARE Classic .........147
Tab. 278. ISO/IEC14443-B 106 .....................................148
Tab. 279. ISO/IEC14443-B 212 .....................................148
Tab. 280. ISO/IEC14443-B 424 .....................................149
Tab. 281. ISO/IEC14443-B 848 .....................................149
Tab. 282. JIS X 6319-4 (FeliCa) 212 ............................ 150
Tab. 283. JIS X 6319-4 (FeliCa) 424 ............................ 151
Tab. 284. ISO/IEC15693 SLI 1/4 - SSC- 26 ..................151
Tab. 285. ISO/IEC15693 SLI 1/4 - SSC-53 ...................152
Tab. 286. ISO/IEC15693 SLI 1/256 - DSC ....................152
Tab. 287. EPC/UID - SSC -26 ...................................... 153
Tab. 288. EPC-V2 - 2/424 .............................................153
Tab. 289. EPC-V2 - 4/424 .............................................154
Tab. 290. EPC-V2 - 2/848 .............................................155
Tab. 291. EPC-V2 - 4/848 .............................................155
Tab. 292. Jewel ............................................................. 156
Tab. 293. ISO/IEC14443 - B 106 EMVCo Optimized .... 156
Tab. 294. Abbreviations .................................................158
Tab. 295. Revision history .............................................161



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **167 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
