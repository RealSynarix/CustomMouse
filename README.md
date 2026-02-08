# Custom Gaming Mouse: High-Performance DIY (PMW3360 + STM32)

A custom-engineered, ultra-lightweight gaming mouse featuring a high-performance optical sensor and an STM32 microcontroller. Designed for maximum precision, low latency, and a semi-ergonomic shape. This is ideal for gamers and casuals alike.

## 🚀 Overview
This project bridges the gap between enthusiast-grade hardware and DIY accessibility. By utilizing the **PMW3360** sensor (insane specs for price and ease of routing), and a custom **1.6mm PCB**, this mouse is optimized for a low center of gravity and high structural integrity. This mouse also fully custom built by me, and I self taught and looked at doccumentation and used google gemini for help in some aspects. 

### Why It Stands Out
* **Fully Custom** Firmware, Shell, and PCB are all designed by me alone.
* **Dual-Board Design:** Features a dedicated daughterboard for the side button, which allows you to toggle **HyprX** mode (more on that further down).
* **Custom Firmware:** Powered by STM32, my firmware is optimised as much as possible for the lowest latency and the most smooth mosue experience. It also has a built in macro i dubbed **HyprX**.
* **Native USB-C:** Modern, 6obust connectivity for power and data. If the usb cable is cut or broken, no need to repair or throw it out, its hot swappable and you can just unplug it!

## 🛠 Features & Specs
| Feature | Specification |
| :--- | :--- |
| **Sensor** | PixArt PMW3360 Optical |
| **MCU** | STM32 (ARM Cortex-M) |
| **Polling Rate** | 1000 Hz (Stable) |
| **Max DPI** | 12,000 DPI |
| **Default DPI** | 1,000 DPI |
| **Tracking Speed** | 250 IPS |
| **Acceleration** | 50 G |
| **Switches** | Kailh Mute Red (LMB/RMB/MMB/SB) |
| **Rotary Encoder** | TTC Gold Dustproof (24 Step) |

## 📐 Hardware Details
The PCB was designed in KiCad with a focus on a small size and cleanest routing. The schematic is also very polished.
* **Differential Pair Routing:** D+/D- lines matched to roughly <1mm-4mm for reliable USB communication.
* **Mechanicals:** Integrated 4-Pin header for easy firmware flashing and debugging.

## 💰 Cost Comparison
High-end "enthusiast" mice often retail for over $150. This project proves you can get superior performance for much less of a price.

| Item | This Project (DIY) | Popular "Pro" Mouse (Retail) |
| :--- | :--- | :--- |
| **PCB & Assembly (PCBA)** | $69.51 | N/A |
| **3D Printing (Shell)** | ~$2.00 | N/A |
| **Personally Soldered Components (Switches/Rotary Encoder/Sensor)** | ~$25 | N/A |
| **Total Cost** | **~$96** |

*Note: The DIY cost includes 5x PCBs (standard minimum order), making the cost-per-unit even lower if building multiple.*
