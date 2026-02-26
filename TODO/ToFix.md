### **v1.0.0**

### 1. LED Component Mismatch (WS2812B vs. Analog)
* **Issue:** The PCB is designed for **Addressable RGB (WS2812B)** with `VDD`, `VSS`, `DIN`, and `DOUT` traces. The current physical LEDs are **Standard 4-pin Analog RGB**.
* **The Problem:** These are electrically incompatible. Standard LEDs lack the internal IC needed to interpret the data stream.
* **Action:** Purchase **WS2812B-F5 (5mm Through-Hole)** addressable LEDs. 
* **Verification:** Ensure the new LEDs have a visible black square (the IC) inside the glass dome.

### 2. LED #3 (D3) Pinout Correction
* **Issue:** The footprint for the third LED (`D3`) has a layout error.
* **The Problem:** The current pin arrangement will either break the data chain or cause a direct short circuit across the power rails ($V_{DD}$ to $V_{SS}$).
* **Action:** Re-route `D3` to match the serial data flow of `D1` and `D2`.

### 3. Tactile Switch Orientation (2-pin vs. 4-pin)
* **Issue:** PCB was designed for **4-pin tactile switches**, but **2-pin switches** are being used for LMB, MMB, RMB, and Side Buttons.
* **The Problem:** The switches need to be rotated 90° or placed diagonally to ensure the internal bridge connects the "Signal" pad to the "Ground" pad.
* **Action:** Update the footprint to a dedicated 2-pin version or rotate the physical push buttons so that 1 pin is on ground and 1 pin is on the data line.

### 4. Scroll Wheel Edge.Cuts
* **Issue:** The internal `Edge.Cuts` hole for the scroll wheel is not proportional.
* **The Problem:** While it fits smaller wheels, the scaling is inefficient and leaves unnecessary gaps. If the wheel is normal sized it wont fit, and if made smaller there is a large gap.
* **Action:** Re-measure to ensure a normal sized scroll wheel fits, and mode traces and components accordingly.

### 5. Daughterboard Connector (Mirrored Pins)
* **Issue:** The pins are mirrored on the motherboard becasue I was mistaken with how the connector was setup.
* **The Problem:** While it fits and seems fine, the ground on the DB is 3.3v on the MB and the data pins are swapped. This would cause an immedient short.
* **Action:** Re-evaluate pins and ensure propper layout.

### 6. Firmware Jumper Pins & BOOT0/NRST
* **Issue:** The 4-pin header that is used to flash firmware is not working as expected and the way I have setup the booting of the device has made it nrarly impossible to manage.
* **The Problem:** I cannot get the device to allow firmware modification and injection, and If i cannot do it then it is not good enough for an end user either.
* **Action:** Remove the 4-pin header and use a button or other means as to boot into firmware/development mode.
