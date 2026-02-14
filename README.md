# Fully DIY Gaming Mouse

A custom-built, ultra-lightweight gaming mouse featuring the **PixArt PMW3360** high-performance sensor and an **STM32** microcontroller. I designed this from the ground up for maximum precision/smoothness, near zero latency, and a semi-ergonomic feel. 

## 🚀 Project Overview
This project is the result of a deep dive into peripheral engineering. I self-taught the PCB design and firmware development by studying datasheets and documentation to create a mouse that rivals top-tier retail options. This took roughly 3 months of work, and during this time I learned (Self Taught) Kicad, Fusion360 + TinkerCAD, Electrical Schematics, Trace Routing, and much more. I would also like to say that my main motives for making this is due to consumer level mice being very expensive for good hardware, and the big tech who makes them not even making them opensource and bloated with windows specific software. My aim is to make an opensource and easy to repair and build mouse that is significantly cheaper and better and also does not have any software and works right after the firmware is flashed.

The build uses a **1.6mm HASL PCB** which provides great structural integrity and a low center of gravity for a balanced, tactile feel.

### Why This Project?
* **100% Custom:** I designed the firmware, the 3D-printable shell, and the PCB architecture myself.
* **Dual-Board Setup:** I used a dedicated daughterboard for the side buttons to keep the main shell clean and modular.
* **Low Latency Firmware:** My custom STM32 firmware is written for the fastest possible input response and smooth tracking.
* **HyprX Macro Engine:** A custom hardware-level macro suite I built that toggles via the side button.
* **True USB-C:** A modern interface that makes the mouse "hot-swappable." If your cable ever dies, just plug in a new one and keep playing.

## 🛠 Features & Specs
| Feature | Specification |
| :--- | :--- |
| **Sensor** | PixArt PMW3360 Optical |
| **MCU** | STM32G431KBT6 (170MHz ARM Cortex-M4) |
| **Polling Rate** | 1000 Hz (1ms delay) |
| **DPI Range** | 100 – 12,000 DPI (Default: 1,000) |
| **Click Latency** | <0.5ms (Industry Sda is ~5ms) |
| **Tracking Speed** | 250 IPS |
| **Acceleration** | 50 G |
| **Primary Switches** | Kailh Mute Red (LMB / RMB / MMB / SB) |
| **Scroll Wheel** | TTC Gold Dustproof Encoder (24 Step) |
| **Interface** | USB-C Full-Speed (Wired) |

## 📐 Hardware Details
I designed the PCB in **KiCad** with a major focus on clean routing and a small footprint.
* **Signal Integrity:** USB D+/D- lines are decently length-matched to ensure stable 1000Hz polling without data errors.
* **Debugging:** I integrated a 4-pin SWD header so I can flash and debug firmware on the fly.
* **Sensor Stability:** I used specific decoupling caps and isolated the power rails for the PMW3360 to stop any sensor jitter before it starts.



## 🔥 HyprX Macro System
I coded a unique hardware toggle into the firmware I dub **HyprX**. 
* **The Toggle:** Controlled via the side button.
* **LED Feedback:** The mouse glows "Neon Blue" by default, but switches to "Blazing Red" when HyprX is active.
* **The Macros:** * **Scroll Up:** Maps every step of the 24-step TTC Gold encoder to an LMB click.
    * **Scroll Down:** Executes a rapid-fire RMB spam.
* **Reset:** Press the side button again to go back to normal scrolling and blue lighting.

## 💰 Cost Analysis
High-end mice usually cost **$150.00+**. This build shows you can get better specs and full repairability for way less.

| Item | My Build Cost |
| :--- | :--- |
| **PCB & PCBA (5 Units)** | $69.51 |
| **3D Printed Shell** | ~$2.00 |
| **Custom Parts*** | ~$25.00 |
| **Total Build Cost** | **~$96.51** |

*\*Includes: PMW3360 sensor, TTC Gold Encoder, and Kailh Mute switches.*

*Note: Depending on the PCBS purchased and if you solder yourself, you can save even more money! These price points are all in AUD*
