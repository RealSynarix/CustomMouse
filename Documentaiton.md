The Concept:
I was tinkering with some hardware at my homelab and was thinking about what I could create that would help myself, and if mass produced the world. I was thinking about computer peripherals as those seemed like something I was feasible to work on, and I looked at my desktops mouse, and thought 'Wouldn't it be good if I could have silent clicks and a good feeling scroll wheel, aswell as a custom design and macros?' Alas my dream of a custom computer mouse was born. was 14 and 9 months old, and I had the technical know how in order to achieve it, but I never designed a PCB before, let alone knew what traces were and how to solder. I was more into digital stuff like Linux and programming, but I wanted to take my skills a step further. After about a month and a bit, I was able to conjure up a reasonable mouse PCB featuring a USB-C Female port for power and data, an SMT32 microcontroller unit, and a PMW3360 for the mouse sensor. I also had to choose the right compoentns based on affordability, ease of routing, power consumtion, technical specs, and physical footprint (size). I also wanted the components to be a mix of industry leading compoennts in the mouse field to ensure my mouse would be superior to any other in more ways than one. I wanted to focus on a tactile experience with low auditory levels so that it doesn't sound clanky and cheap, and also has a semi-ergonomic feel so that it doesn't strain your hand after continuous usage, while still being very light and durable, along with looking great. I wanted to design the 3D model, the PCB, and the Firmware all from scratch with the only help being documentation and self teaching. I will admit I did use artificial intelligence to help me source the parts and help when early prototyping the PCB, but after I got the jist of things I used documentation on GitHub, Reddit, and other repositories/forums.

The Design:
My custom mouse is designed to be better than all other computer mice in the overall aspects of it. its not better in one field, but all together its better. eg. its not the lightest, but its very light. Its not the most comfortable, but it is for me. Its not the best looking, but it still looks very good. The specs are not the absolute best, but it rivals them. This motto is the main reason why I decided to make this mouse, and it ended up being just right for me, and being better IMO than other industry leading high cost mouses out there. for example, factoring in all aspects like printing filament, pcb delivery and assembly, cost of compoentns, and the time it took, this mouse would be worth 100 dollars, but its better than some 200+ dollar mice. This mouse will incorporate a sleek matte black finish with a neon blue underglow and bleeding of the light through holes in the shell. The scroll wheel will be tactile with very defined steps, and the buttons on the mouse will be silent to the click and will have added grip to ensure maximum comfort. I also have a side button via a daughter board that when pressed will toggle a programmable macro, and also the shape of the shell has a thumb and ring finger rest to make sure that it feels comfortable even after hours of use. The mouse also encorporates a hotswappable cable system. Most mice with a usb-c port are wireless, and most wired mouse have the wire soldered to the mouse, but mine has a prt for a cable and if the cable breaks or doenst appeal in looks or length, you caan always unplug it and swap for a better one. This is very good becasue it reduces e-waste and people throwing away very good mice because the cable broke. Another thing to mention that is very important, is the fact that this is entirely open-source. I daily drive Linux on my desktop and hate things beig closed source or propriety or has a licnese on it, and I want everything I make for people (most) to be open-source to help out the community. By making this open-source fellow hobbyists can engage and edit my PCB to tailor it to their needs, aswell as read and edit or use the firmware I wrote. Also, if someone doenst like the feel of the mouse or has a physical disability, they can get someone or themselves to download the model of my mouse and edit it in CAD and get it 3D printed so it fits just the way they want.

The Issues & Solutions:
I have faced numerous issues throughout this and its pretty evident considering I have never designed a PCB before and I also am not great at 3D modelling, and I also have never written in <INSERT FIRMWARE LANGUAGE> before which was used for the firmware. Anyway, the first main issue I had was what compoents to use. At first I thought of using the RP2040 MCU which powered the raspberry pi pico series, but after analysis and issues with it and help from reddit, I found out that its far to complex for a mouse and would be hell to trace. I ended up using the STM32G431KBT6 which was not only lacking many unnessisary GPIO pins meaning less time tracing and more compact board design, but it was also considerably faster and better for a product like a mouse. The mosue buttons and encoder and other things like LEDs capacitors, resistors, regulators, etc. were straight forward and I had no issues with it. The sensor was a pain though. I chose the PMW3360DM-T2QU because of its fast speeds and specs, and relatively low cost ($15-$25 AUD) while being in the upper most specced out sensors you can buy. The main issue was wiring this sensor. it needed an external regulator to lower the voltage from 5v to 3.3v because it would fry the IC if I didn't, and it took lots of documentation to understand the pin layout. The last issue I had with the pcb was the shape (edge.cuts) and the usb-c port. The board requires a hole for the scroll wheel, and a small yet large sizing for the shell of the mouse, and the right positioning of stuff like buttons and the sensor. This was a pain to get right and took many fusturating days to get right. The usb-c port (and debug pins) is at the time of writing this the most prominent issue. They are rotated the wrong way in the JLCPCB fabrication site, and the usb-c port is not the right model for the footprint and is too far down the board. The rotation is an easy fix, an engineer can easily notice it, but it costs more for them to hand check the parts. The main issue was the usb-c port. <EXPLAIN HOW FIXED AND WHY IT WAS BAD>

The Prototype/Final Product:
After designing the 3D model in my CAD of choice (Fusion 360), I then assembled the pcb in it and all other parts, and then renederd it with materials im using for a look at it realistically. Now comes the most anxious part, ordering the PCB and assembling the shell and everything in real life. After I recived the PCB I had to manually solder a few components to the board as I already owned them and wanted to save costs on the BOM. After that, I had to put the PCB into the mouse and sand edges to ensure it was smooth and the compoennts fit. after assembling the mouse, it did not work! The issue was not that I did anything wrong, but that the MCU had no idea what todo after it got powered because I did not write and flash any firmware to it. The feel and looks of the mouse were exactly as I visioned and I was very pleased with the results, but I did have todo a lot of post processing of the 3D print to ensure that it would be optimal.

The Firmware:
After assembly, I had to take it apart and connect the debug pins I put on the pcb. after connecting to my computer and IDE of choice, I then had to watch many tutorials of thick accent Indians in order to some what understand what I was doing. In the end I decided to get some help form my AI agent I used at the start tha helped me with the PCB design (Google Gemini), and after an hour or so, I had custom written <INSERT FIRMWARE LANGAUGE> Code that was easy to read, highly optimised for a gaming mouse, and had the exact macro I envisioned.

The Information:
Overall, this mouse was a product of vision, determination, self teaching, heavy documentation reading, and personal development. I am very satisfied with the mouse's end result and hope to get a good spot in this competition. I did not make this mouse for this competition but for a hobby (like everything I have done regarding EE and SD), but I saw the website and thought I had a pretty good shot! Anyway, here are the technical specifications of my mouse:

SPECS:

Polling Rate:
IPS:
DPI:
Latency:

PCB:

MCU: STM32G431KBT6
SENSOR: PMW3360DM-T2QU
BTNS: Kailh Mute Push Buttons
COST:

3D MODEL:

WEIGHT:
COST:
DESIGN: Ultra-Light with a profound shape
FILAMENT: Matte Black PETG
SHAPE: Semi-Ergo and optimised for claw grip users

POST-PROCESSING:

Weight Reduced:
Looks:
Time:

OVERALL:

Worth It: 100%, Not only did I learn so many practical things, but I will never need to buy a computer mouse ever again, and I can also mass produce this if I want and potentially get lots of money.
Weight:
Size:
Cost:
Feasibility:  Very Challenging. If I had prior knowledge on PCB design and 3D modelling, I would rank this Hard.
Open-Source: Yes, on my GitHub