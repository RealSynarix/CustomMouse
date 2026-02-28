# Cobalt-X Zero - v1.1.4

A custom-built, ultra-lightweight gaming mouse featuring the **PixArt PMW3360** high-performance sensor and an **STM32** microcontroller. I designed this from the ground up for maximum precision/smoothness, near zero latency, and a semi-ergonomic feel. 

## 🚀 Project Overview
This project is the result of a deep dive into peripheral engineering. At 15 (14yrs 10mths), I self-taught the PCB design and firmware development by studying datasheets and documentation to create a mouse that rivals top-tier retail options. This took roughly 3 months of work, and during this time I learned (Self Taught) Kicad, Fusion360 + TinkerCAD, Electrical Schematics, Trace Routing, and much more. I would also like to say that my main motives for making this is due to consumer level mice being very expensive for good hardware, and the big tech who makes them not even making them opensource and bloated with windows specific software. My aim is to make an opensource and easy to repair and build mouse that is significantly cheaper and better and also does not have any software and works right after the firmware is flashed.

The build uses a **1.6mm HASL PCB** which provides great structural integrity and a low center of gravity for a balanced, tactile feel.

### Why This Project?
* **100% Custom:** I designed the firmware, the 3D-printable shell, and the PCB architecture myself.
* **Dual-Board Setup:** I used a dedicated daughterboard for the side buttons to keep the main shell clean and modular.
* **Low Latency Firmware:** My custom STM32 firmware is written for the fastest possible input response and smooth tracking.
* **HyprX Macro:** A custom hardware-level macro I built that toggles via the side button.
* **True USB-C:** A modern interface that makes the mouse "hot-swappable." If your cable ever dies, just plug in a new one and keep playing.
* **Superior Customization:** This project has a feature not seen in any other mice on the market, a custom config file to edit parameters of the mouse easily without custom software or flashing of firmware.

## 🛠 Features & Specs
| Feature | Specification |
| :--- | :--- |
| **Sensor** | PixArt PMW3360 Optical |
| **MCU** | STM32G431KBT6 (170MHz ARM Cortex-M4) |
| **Polling Rate** | 4000 Hz |
| **DPI Range** | 100 – 12,000 DPI (Default: 1,000) |
| **Click Latency** | <0.5ms (Industry Sda is ~5ms) |
| **Tracking Speed** | 250 IPS |
| **Acceleration** | 50 G |
| **Push Buttons** | Kailh Mute Red (LMB / RMB / MMB / MAC / DFU) |
| **Scroll Wheel** | TTC Gold Dustproof Encoder (24 Step) |
| **Interface** | USB-C Full-Speed (Wired) |
| **Customization** | Custom config file which eliminates bloated software |

## 📐 Hardware Details
I designed the PCB in **KiCad** with a major focus on clean routing and a small footprint.
* **Signal Integrity:** USB D+/D- lines are perfectly length-matched to ensure stable 4000Hz polling without data errors.
* **Debugging:** I integrated 3 debug pads so you can revert after a bad flash, and a easy to use (like a pi pico) button that held and plugged in enters DFU mode for flashing.
* **Sensor Stability:** I used specific decoupling caps and isolated the power rails for the PMW3360 to stop any sensor jitter before it starts.

## 🔥 HyprX Macro System
I coded a unique hardware toggle into the firmware I dub **HyprX**. 
* **The Toggle:** Controlled via the side button.
* **LED Feedback:** The mouse glows "Neon Blue" by default, but switches to "Blazing Red" when HyprX is active.
* **The Macros:** * **Scroll Up:** Maps every step of the 24-step TTC Gold encoder to an LMB click.
    * **Scroll Down:** Executes a rapid-fire RMB spam.
* **Reset:** Press the side button again to go back to normal scrolling and blue lighting.
