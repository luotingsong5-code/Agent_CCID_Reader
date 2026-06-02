## **16.1 LoadProtocol command register initialization**

The RF configuration is loaded with the command Load Protocol. The tables below
show the register configuration as performed by this command for each of the protocols.
Antenna specific configurations are not covered by this register settings.

The CLRC66301 and CLRC66302 is not initialized for any antenna configuration. For this
product the antenna configuration needs to be done by firmware.

The CLRC66303 antenna configuration in the user EEPROM is described in the chapter
Section 16.2.

|Value for register|Value (hex)|
|---|---|
|TxBitMod|20|
|RFU|00|
|TxDataCon|04|
|TxDataMod|50|
|TxSymFreq|40|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|00|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|50|
|RxBitMod|02|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|00|
|RxMod|08|
|RxCorr|80|
|FabCal|B2|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **131 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxBitMod|20|
|RFU|00|
|TxDataCon|05|
|TxDataMod|50|
|TxSymFreq|50|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|00|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|50|
|RxBitMod|22|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|00|
|RxMod|0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|20|
|RFU|00|
|TxDataCon|06|
|TxDataMod|50|
|TxSymFreq|60|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **132 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|00|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|50|
|RxBitMod|22|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|00|
|RxMod|0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|20|
|RFU|00|
|TxDataCon|07|
|TxDataMod|50|
|TxSymFreq|70|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|00|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|50|
|RxBitMod|22|
|RxEofSym|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **133 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|00|
|RxMod|0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|09|
|RFU|00|
|TxDataCon|04|
|TxDataMod|08|
|TxSymFreq|04|
|TxSym0H|00|
|TxSym0L|03|
|TxSym1H|00|
|TxSym1L|01|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|AB|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|08|
|TxSym32Mod|00|
|RxBitMod|04|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|02|
|RxMod|CLRC66301, CLRC66302: 1D|
|RxMod|CLRC663003: 0D|
|RxCorr|80|
|FabCal|B2|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **134 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxBitMod|09|
|RFU|00|
|TxDataCon|05|
|TxDataMod|08|
|TxSymFreq|05|
|TxSym0H|00|
|TxSym0L|03|
|TxSym1H|00|
|TxSym1L|01|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|AB|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|08|
|TxSym32Mod|00|
|RxBitMod|04|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|02|
|RxMod|CLRC66301, CLRC66302: 1D|
|RxMod|CLRC66303: 0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|09|
|RFU|00|
|TxDataCon|06|
|TxDataMod|08|
|TxSymFreq|06|
|TxSym0H|00|
|TxSym0L|03|
|TxSym1H|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **135 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxSym1L|01|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|AB|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|08|
|TxSym32Mod|00|
|RxBitMod|04|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|02|
|RxMod|CLRC66301, CLRC66302: 1D|
|RxMod|CLRC66303: 0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|09|
|RFU|00|
|TxDataCon|07|
|TxDataMod|08|
|TxSymFreq|07|
|TxSym0H|00|
|TxSym0L|03|
|TxSym1H|00|
|TxSym1L|01|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|AB|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|08|
|TxSym32Mod|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **136 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|RxBitMod|04|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|02|
|RxMod|CLRC66301, CLRC66302: 1D|
|RxMod|CLRC66303: 0D|
|RxCorr|80|
|FabCal|B2|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|05|
|TxDataMod|01|
|TxSymFreq|05|
|TxSym0H|B2|
|TxSym0L|4D|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|0F|
|TxSym32Len|00|
|TxSym10BurstCtrl|01|
|TxSym10Mod|01|
|TxSym32Mod|00|
|RxBitMod|18|
|RxEofSym|00|
|RxSyncValH|B2|
|RxSyncValL|4D|
|RxSyncMod|F0|
|RxMod|19|
|RxCorr|20|
|FabCal|B0|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **137 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|06|
|TxDataMod|01|
|TxSymFreq|06|
|TxSym0H|B2|
|TxSym0L|4D|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|0F|
|TxSym32Len|00|
|TxSym10BurstCtrl|01|
|TxSym10Mod|01|
|TxSym32Mod|00|
|RxBitMod|18|
|RxEofSym|00|
|RxSyncValH|B2|
|RxSyncValL|4D|
|RxSyncMod|F0|
|RxMod|19|
|RxCorr|50|
|FabCal|B0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|00|
|RFU|00|
|TxDataCon|83|
|TxDataMod|04|
|TxSymFreq|40|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **138 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxSym2|84|
|TxSym3|02|
|TxSym10Len|00|
|TxSym32Len|37|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|00|
|RxEofSym|1D|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|00|
|RxMod|24|
|RxCorr|60|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|00|
|RFU|00|
|TxDataCon|83|
|TxDataMod|04|
|TxSymFreq|40|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|84|
|TxSym3|02|
|TxSym10Len|00|
|TxSym32Len|37|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|00|
|RxEofSym|1D|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **139 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|00|
|RxMod|24|
|RxCorr|40|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|00|
|RFU|00|
|TxDataCon|83|
|TxDataMod|04|
|TxSymFreq|40|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|
|TxSym2|81|
|TxSym3|02|
|TxSym10Len|00|
|TxSym32Len|37|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|00|
|RxEofSym|1D|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|00|
|RxMod|26|
|RxCorr|60|
|FabCal|F0|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **140 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|44|
|TxDataMod|00|
|TxSymFreq|44|
|TxSym0H|08|
|TxSym0L|22|
|TxSym1H|08|
|TxSym1L|28|
|TxSym2|8A|
|TxSym3|02|
|TxSym10Len|BB|
|TxSym32Len|37|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|08|
|RxEofSym|0B|
|RxSyncValH|00|
|RxSyncValL|00|
|RxSyncMod|08|
|RxMod|04|
|RxCorr|50|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|C5|
|TxDataMod|00|
|TxSymFreq|05|
|TxSym0H|68|
|TxSym0L|41|
|TxSym1H|01|
|TxSym1L|A1|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **141 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|8E|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|08|
|RxEofSym|0B|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|04|
|RxMod|0C|
|RxCorr|40|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|C5|
|TxDataMod|00|
|TxSymFreq|05|
|TxSym0H|68|
|TxSym0L|41|
|TxSym1H|01|
|TxSym1L|A1|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|8E|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|08|
|RxEofSym|0B|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **142 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|04|
|RxMod|0C|
|RxCorr|50|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|C5|
|TxDataMod|00|
|TxSymFreq|05|
|TxSym0H|68|
|TxSym0L|41|
|TxSym1H|01|
|TxSym1L|A1|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|8E|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|08|
|RxEofSym|0B|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|04|
|RxMod|0C|
|RxCorr|88|
|FabCal|F0|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **143 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxBitMod|80|
|RFU|00|
|TxDataCon|C5|
|TxDataMod|00|
|TxSymFreq|05|
|TxSym0H|68|
|TxSym0L|41|
|TxSym1H|01|
|TxSym1L|A1|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|8E|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|00|
|RxBitMod|08|
|RxEofSym|0B|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|04|
|RxMod|0C|
|RxCorr|80|
|FabCal|F0|


|Value for register|Value (hex)|
|---|---|
|TxBitMod|00|
|RFU|00|
|TxDataCon|04|
|TxDataMod|D0|
|TxSymFreq|40|
|TxSym0H|00|
|TxSym0L|00|
|TxSym1H|00|
|TxSym1L|00|



CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **144 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

|Value for register|Value (hex)|
|---|---|
|TxSym2|00|
|TxSym3|00|
|TxSym10Len|00|
|TxSym32Len|00|
|TxSym10BurstCtrl|00|
|TxSym10Mod|00|
|TxSym32Mod|50|
|RxBitMod|02|
|RxEofSym|00|
|RxSyncValH|00|
|RxSyncValL|01|
|RxSyncMod|00|
|RxMod|08|
|RxCorr|80|
|FabCal|F0|

