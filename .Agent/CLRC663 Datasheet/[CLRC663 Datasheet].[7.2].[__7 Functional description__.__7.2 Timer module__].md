## **7.2 Timer module**

Timer module overview

The CLRC663 implements five timers. Four timers -Timer0 to Timer3 - have an input
clock that can be configured by register T(x)Control to be 13.56 MHz, 212 kHz, (derived
from the 27.12 MHz quartz) or to be the underflow event of the fifth Timer (Timer4). Each
timer implements a counter register which is 16 bit wide. A reload value for the counter
is defined in a range of 0000h to FFFFh in the registers TxReloadHi and TxReloadLo.
The fifth timer Timer4 is intended to be used as a wake-up timer and is connected to the
internal LFO (Low Frequency Oscillator) as input clock source.

The TControl register allows the global start and stop of each of the four timers Timer0
to Timer3. Additionally, this register indicates if one of the timers is running or stopped.
Each of the five timers implements an individual configuration register set defining timer
reload value (e.g. T0ReloadHi,T0ReloadLo), the timer value (e.g. T0CounterValHi,
T0CounterValLo) and the conditions which define start, stop and clockfrequency (e.g.
T0Control).

The external host may use these timers to manage timing relevant tasks. The timer unit
may be used in one of the following configurations:

**•** Time-out counter

**•** Watch-dog counter

**•** Stop watch

**•** Programmable one-shot timer

**•** Periodical trigger

The timer unit can be used to measure the time interval between two events or to
indicate that a specific event has occurred after an elapsed time. The timer register
content is modified by the timer unit, which can be used to generate an interrupt to allow
a host to react on this event.

The counter value of the timer is available in the registers T(x)CounterValHi,
T(x)CounterValLo. The content of these registers is decremented at each timer clock.

If the counter value has reached a value of 0000h and the interrupts are enabled for this
specific timer, an interrupt will be generated as soon as the next clock is received.

If enabled, the timer event can be indicated on the pin IRQ (interrupt request). The bit
Timer(x)IRQ can be set and reset by the host controller. Depending on the configuration,
the timer will stop counting at 0000h or restart with the value loaded from registers
T(x)ReloadHi, T(x)ReloadLo.

The counting of the timer is indicated by bit TControl.T(x)Running.

The timer can be started by setting bits TControl.T(x)Running and
TControl.T(x)StartStopNow or stopped by setting the bits TControl.T(x)StartStopNow and
clearing TControl.T(x)Running.

Another possibility to start the timer is to set the bit T(x)Mode.T(x)Start. This can be
useful if dedicated protocol requirements need to be fulfilled.

### **7.2.1 Timer modes**


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **11 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_

#### **7.2.1.1 Time-Out- and Watch-Dog-Counter**

Having configured the timer by setting _register T(x)ReloadValue_ and starting the counting
of Timer(x) by setting bit TControl.T(x)StartStop and TControl.T(x)Running, the timer unit
decrements the _T(x)CounterValue_ Register beginning with the configured start event. If
the configured stop event occurs before the Timer(x) underflows (e.g. a bit is received
from the card), the timer unit stops (no interrupt is generated).

If no stop event occurs, the timer unit continues to decrement the counter registers until
the content is zero and generates a timer interrupt request at the next clock cycle. This
allows indicating to a host that the event did not occur during the configured time interval.

#### **7.2.1.2 Wake-up timer**

The wake-up Timer4 allows to wake-up the system from standby after a predefined time.
The system can be configured in such a way that it is entering the standby mode again in
case no card had been detected.

This functionality can be used to implement a low-power card detection (LPCD). For
the low-power card detection, it is recommended to set T4Control.T4AutoWakeUp
and T4Control.T4AutoRestart, to activate the Timer4 and automatically set the system
in standby. The internal low frequency oscillator (LFO) is then used as input clock
for this Timer4. If a card is detected, the host-communication can be started. If bit
T4Control.T4AutoWakeUp is not set, the CLRC663 will not enter the standby mode again
in case no card is detected but stays fully powered.

#### **7.2.1.3 Stop watch**

The elapsed time between a configured start- and stop event may be measured by the
CLRC663 timer unit. By setting the registers _T(x)ReloadValueHi, T(x)ReloadValueLo_ the
timer starts to decrement as soon as activated. If the configured stop event occurs, the
timer stops decrementing. The elapsed time between start and stop event can then be
calculated by the host dependent on the timer interval TTimer:


(1)


If an underflow occurred which can be identified by evaluating the corresponding IRQ bit,
the performed time measurement according to the formula above is not correct.

#### **7.2.1.4 Programmable one-shot timer**

The host configures the interrupt and the timer, starts the timer and waits for the interrupt
event on pin IRQ. After the configured time, the interrupt request will be raised.

#### **7.2.1.5 Periodical trigger**

If the bit _T(x)Control.T(x)AutoRestart is set and the interrupt is activated_, an interrupt
request will be indicated periodically after every elapsed timer period.


CLRC663 All information provided in this document is subject to legal disclaimers. © NXP B.V. 2018. All rights reserved.
**Product data sheet** **Rev. 4.7 — 12 September 2018**
**COMPANY PUBLIC** **171147** **12 / 171**


**NXP Semiconductors** **CLRC663**

**High performance multi-protocol NFC frontend CLRC663 and CLRC663** _**plus**_
