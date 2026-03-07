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

### 28/2/26: Revision V2 - The Flow-State Optimization
I completely re-evaluated and rebuilt the design based on the V1 failures. Rather than taking days or weeks, I finished the entire schematic rework and PCB re-routing in a single 7-hour session. 

I entered a complete "flow-state" so I had no breaks, was hyper-focused, and had total recall of every niche technical detail. By the end of the afternoon, I had executed:
* **Hardware Fixes:** Corrected all button footprints and fixed the mirrored daughterboard connectors.
* **New Features:** Added a dedicated DFU button and test pads for clock/firmware reversion.
* **Weight Reduction:** Optimized for 1.2mm PCB thickness. Also removed the daugherboard for less space and no cables.
* **Firmware:** Developed ~800 bytes of bare-metal C++ (~300 lines) optimized for the 170MHz clock.

### 7/3/26: Final Assembly & Post-Processing
Currently I am waiting for the board to arrive and flash the firmware onto it. once it arrives in a few days and I do that, I will focus on the model of the 3D-printed shell in Black PETG using an Elegoo Neptune 4 Pro, and modeled via TinkerCAD. I am using a sanding process and other post-processing to remove layer lines and achieve a matte finish that looks like a professional injection-molded product for the final competition entry.
