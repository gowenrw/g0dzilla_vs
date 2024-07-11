---
layout: default
---

![Hero Image](images/Hero.jpg)

# G0dzilla VS Badge

Welcome to the G0dzilla VS Badge website.

This badge was designed for the DEFCON 32 security conference in August 2024.

On this page you will find all the details about this badge including an operations guide, an assembly guide (for those building the badge from a kit), and a detailed review of the art and cicuit design and pcb design.

-- [@alt_bier](https://twitter.com/alt_bier)  - [My Contact Info](https://gowen.net/about)

---

![Touch Image](images/HeroTouch.gif)

# Details

The badge theme was based on the fact that I love Godzilla and the movie Godzilla Minus One that was released in 2023 inspired me to do something with this theme.

Since I make badges I figured this would be my medium.  However, I made a previous badge that had Godzilla on it so if I was going to revisit this theme it was going to have to be bigger and better.

Having Godzilla fight different monsters that can be changed out since they are addons was the idea I had to bring a Godzilla badge to the next level.

This badge includes an ESP32 Wemos Lolin32 development board, eight neopixel addressable LEDs, eight traditional white LEDs, and four capacitive touch areas, four female SAO connectors (two of which are powered), and three PCBs stacked together, all powered by a LIPO battery.  And that is just the main badge!

[![Badge Assembled](images/BadgeAssembled01sm.jpg)](images/BadgeAssembled01.jpg)
[![Badge Assembled](images/BadgeAssembled02sm.jpg)](images/BadgeAssembled02.jpg)

This badge also includes four Shitty Addons (SAOs) which are the monsters that Godzilla will fight.  These addons each have two traditional white LEDs and a male hooded SAO connector.
The SAOs also utilize one of the GPIO pins to send specific voltage back to the badge per SAO.  This allows for the main badge to detect which monsters are connected to it.
Up to two of the four SAOs can be connected to the front of the badge to fight Godzilla.
In order to keep the SAOs from getting separated from the badge we included mini SAO lanyards that attach them to the badge and there are two SAO connectors on the back of the badge (not powered) that act as a green room for monsters not currently in the fight.

[![Badge with SAOs](images/BadgeAssembled03sm.jpg)](images/BadgeAssembled03.jpg)
[![SAO Mothra](images/Mothra01sm.jpg)](images/Mothra01.jpg)
[![SAO King Ghidorah](images/KingGhidorah01sm.jpg)](images/KingGhidorah01.jpg)
[![SAO Rodan](images/Rodan01sm.jpg)](images/Rodan01.jpg)
[![SAO Hedorah](images/Hedorah01sm.jpg)](images/Hedorah01.jpg)

Since the ESP Dev board has an embedded battery charge circuit the schematic for the main badge was fairly simple.
The schematic for the SAO PCB had a challenge in that these were to be four seperate circuits but rules checks were complaining about 3V and GND not being connected between them.  I solved this by using four seperate 3V and GND power nets.
The PCB layout and tracing was a challenge due to all the solder mask voids and capacitive touch areas and the fact that there were four seperate PCBs (seven if you consider the SAO PCB breaks out to four) that all had to align perfectly with each other for when they were assembled together.

[![Schematic badge](images/g0dzilla_vs_schematic_rev1sm.jpg)](images/g0dzilla_vs_schematic_rev1.jpg)
[![Schematic SAOs](images/g0dzilla_vs_sao1_schematic_rev1sm.jpg)](images/g0dzilla_vs_sao1_schematic_rev1.jpg)
[![PCB Front](images/g0dzilla_vs_pcb_front_rev1sm.jpg)](images/g0dzilla_vs_pcb_front_rev1.jpg)
[![PCB Middle](images/g0dzilla_vs_pcb_mid_rev1sm.jpg)](images/g0dzilla_vs_pcb_mid_rev1.jpg)
[![PCB Rear](images/g0dzilla_vs_pcb_rear_rev1sm.jpg)](images/g0dzilla_vs_pcb_rear_rev1.jpg)
[![PCB SAOs](images/g0dzilla_vs_pcb_sao1_rev1sm.jpg)](images/g0dzilla_vs_pcb_sao1_rev1.jpg)

# Kit Assembly

Assembly Instructions for the G0dzilla VS Badge kit can be found here: [G0dzilla VS Badge Assembly Instructions](assembly.md)

An assembly video can be found here:
TBD

[![Badge_Kit](images/BadgeKit01sm.jpg)](images/BadgeKit01.jpg)
[![Badge_Kit](images/BadgeKit02sm.jpg)](images/BadgeKit02.jpg)
[![Badge_Kit](images/BadgeKit03sm.jpg)](images/BadgeKit03.jpg)


