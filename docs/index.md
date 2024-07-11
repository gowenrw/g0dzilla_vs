---
layout: default
---

![Hero Image](Hero.gif)

# G0dzilla VS Badge

Welcome to the G0dzilla VS Badge website.

This badge was designed for the DEFCON 32 security conference in August 2024.

On this page you will find all the details about this badge including an operations guide, an assembly guide (for those building the badge from a kit), and a detailed review of the art and cicuit design and pcb design.

-- [@alt_bier](https://twitter.com/alt_bier)  - [My Contact Info](https://gowen.net/about)

---

![Touch Image](HeroTouch.gif)

# Details

The badge theme was based on the fact that I love Godzilla and the movie Godzilla Minus One that was released in 2023 inspired me to do something with this theme.

Since I make badges I figured this would be my medium.  However, I made a previous badge that had Godzilla on it so if I was going to revisit this theme it was going to have to be bigger and better.

Having Godzilla fight different monsters that can be changed out since they are addons was the idea I had to bring a Godzilla badge to the next level.

This badge includes an ESP32 Wemos Lolin32 development board, eight neopixel addressable LEDs, eight traditional white LEDs, and four capacitive touch areas, four female SAO connectors (two of which are powered), and three PCBs stacked together, all powered by a LIPO battery.  And that is just the main badge!

This badge also includes four Shitty Addons (SAOs) which are the monsters that Godzilla will fight.  These addons each have two traditional white LEDs and a male hooded SAO connector.  The SAOs also utilize one of the GPIO pins to send specific voltage back to the badge per SAO.  This allows for the main badge to detect which monsters are connected to it. 

Since the ESP Dev board has an embedded battery charge circuit the schematic for the badge is fairly simple.
The PCB layout and tracing was a challenge due to all the solder mask voids and capacitive touch areas.

# Kit Assembly

Assembly Instructions for the G0dzilla VS Badge kit can be found here: [G0dzilla VS Badge Assembly Instructions](assembly.md)

An assembly video can be found here:
TBD

![Badge_Kit](AssemblyPicture31sm.jpg)
