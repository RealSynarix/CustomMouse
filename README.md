# Fully DIY Gaming Mouse

A custom-engineered, ultra-lightweight gaming mouse featuring a high-performance **PixArt PMW3360** optical sensor and an **STM32** (ARM Cortex-M) microcontroller. Designed for maximum precision, ultra-low latency, and a semi-ergonomic form factor, this project is built for competitive gamers and hardware enthusiasts alike.

## 🚀 Project Overview
This project bridges the gap between enthusiast-grade hardware and DIY accessibility. Developed through self-taught engineering—utilizing official documentation and AI-assisted troubleshooting—this mouse is a ground-up realization of modern peripheral design.

The build utilizes a **1.6mm FR4 PCB** optimized for high structural integrity and a low center of gravity, ensuring a balanced and tactile user experience.

### Why It Stands Out
* **Fully Bespoke Design:** The firmware, 3D-printable shell, and PCB architecture were all designed from scratch.
* **Dual-Board Architecture:** Features a dedicated daughterboard for side-button inputs, optimizing internal space and modularity.
* **Optimized Firmware:** Custom STM32-based firmware designed for ultra-low input latency and high-speed cursor tracking.
* **HyprX Macro Engine:** A unique, hardware-level macro suite toggled via the side button for specialized gameplay.
* **Native USB-C Connectivity:** Robust and modern interface. The design is "hot-swappable"—if your cable breaks, you can simply replace it without needing to repair or discard the mouse.

## 🛠 Features & Specs
| Feature | Specification |
| :--- | :--- |
| **Sensor** | PixArt PMW3360 Optical |
| **MCU** | STM32 (ARM Cortex-M Series) |
| **Polling Rate** | 1000 Hz (Stable) |
| **DPI Range** | 100 – 12,000 DPI (Default: 1,000) |
| **Tracking Speed** | 250 IPS |
| **Acceleration** | 50 G |
| **Primary Switches** | Kailh Mute Red (LMB / RMB / MMB / SB) |
| **Scroll Wheel** | TTC Gold Dustproof Encoder (24 Step) |
| **Interface** | USB-C (Data + Power) |

## 📐 Hardware Details
The PCB was designed in **KiCad**, focusing on a compact footprint and clean routing.
* **Signal Integrity:** USB D+/D- differential pairs are length-matched within a tolerance of <1mm to ensure error-free communication at high polling rates.
* **Mechanicals:** Integrated 4-pin SWD header allows for rapid firmware flashing and real-time debugging.
* **Stability:** Optimized decoupling capacitors and power rail isolation for the PMW3360 to eliminate sensor jitter.



## 🔥 HyprX Macro System
The custom firmware includes a unique hardware-level toggle known as **HyprX**. 
* **Activation:** Toggled via a dedicated side button.
* **Visual Feedback:** Internal LEDs transition from "Neon Blue" (Default Mode) to "Blazing Red" (HyprX Active).
* **Macro Functions:** * **Scroll Up:** Maps each of the 24 steps of the TTC Gold encoder to a Left Mouse Button (LMB) click.
    * **Scroll Down:** Executes rapid-fire Right Mouse Button (RMB) spamming.
* **Toggle Off:** Pressing the side button again reverts the mouse to standard scrolling and default lighting.

## 💰 Cost Analysis
High-end "Pro" mice often retail for over **$150.00**. This project delivers equivalent performance with the added benefit of repairability and full user control over the hardware.

| Item | DIY Project Cost | Retail "Pro" Mouse |
| :--- | :--- | :--- |
| **PCB & PCBA (5 Units)** | $69.51 | N/A |
| **3D Printed Shell** | ~$2.00 | N/A |
| **Custom Components*** | ~$25.00 | N/A |
| **Total Build Cost** | **~$96.51** | **$150.00+** |

*\*Includes specialized components: PMW3360 sensor, TTC Gold Encoder, and Kailh Mute switches.*

*Note: The DIY cost includes a minimum order of 5 PCBs, making the cost-per-unit significantly lower for subsequent builds.*
