## **8.2 Command configuration**

### **8.2.1 Command**

Starts and stops command execution.










|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|Symbol|Standby|Modem<br>Off|RFU|Command|Command|Command|Command|Command|
|Access<br>rights|dy|r/w|-|dy|dy|dy|dy|dy|



|Bit|Symbol|Description|
|---|---|---|
|7|Standby|Set to 1, the IC is entering power-down mode.|
|6|ModemOff|Set to logic 1, the receiver and the transmitter circuit is powering<br>down.|
|5|RFU|-|
|4 to 0|Command|Defines the actual command for the CLRC663.|
