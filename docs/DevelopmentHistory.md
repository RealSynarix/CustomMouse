# Developer Log: From Nothing To Something Great

### x/2/26: The Vision & The Pivot
Initially, I looked into the RP2040 MCU, but after community analysis and help from Reddit, I realized it was too complex to trace for a compact mouse footprint. I pivoted to the STM32G4 series for its speed and compact GPIO layout.

The PMW3360 sensor was a major hurdle. It required an external regulator to drop 5V to 3.3V to avoid frying the IC, and it took days of studying documentation to understand the SPI pin layout.

### x/2/26: Prototype V1 - "The Learning Tax"
I ordered my first PCB from JLCPCB and realized my mistakes only after it arrived:
* **Footprint Mismatch:** I used 4-pin button footprints for 2-pin buttons.
* **Mirroring Error:** I mirrored the pins on the daughterboard and mainboard connectors, making them impossible to connect.
* **Mechanical Errors:** The sizing for the scroll wheel housing (edge.cuts) was off.
* **Boot Failure:** I had no way to enter DFU mode easily, leading to hours of frustration trying to connect to the device via boot pins to no avail.

### 28/2/26: Revision V2 - Optimization
I completely re-evaluated the design based on the V1 failures (in just 2 days lol):
* **Hardware Fixes:** Corrected all footprints, added a dedicated DFU button, and included test pads for the clock and firmware reversion.
* **Weight Reduction:** Switched to 1.2mm PCB thickness.
* **Firmware Development:** Wrote ~800 bytes of compiled bare-metal C++ code (with collaborative help from Google Gemini, and ~300 lines of c++) optimized for the STM32’s 170MHz clock speed including all major features.

### 7/3/26: Final Assembly & Post-Processing
Currently I am waiting for the board to arrive and flash the firmware onto it. once it arrives in a few days and I do that, I will focus on the model of the 3D-printed shell in Black PETG using an Elegoo Neptune 4 Pro, and modeled via TinkerCAD. I am using a sanding process and other post-processing to remove layer lines and achieve a matte finish that looks like a professional injection-molded product for the final competition entry.
