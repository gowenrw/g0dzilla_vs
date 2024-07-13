---
layout: default
---

# G0dzilla VS Badge Kit Assembly Instructions

Welcome to the G0dzilla VS Badge kit assembly instructions.

This page will detail what comes in the badge kit and step by step instructions to build your badge. 

-- [@alt_bier](https://twitter.com/alt_bier)  - [My Contact Info](https://gowen.net/about)

## Badge Distribution Packages

The badges have been distributed in two different packages

* KIT - This is a kit that requires DIY soldering/assembly of all components
* ASS - This is a Fully Assembled ready to wear badge

## Component List

This is the list of components that are provided in the kit

* Main Kit Bag (20x25cm-8x10in Black & Holographic) Containing:
  * 3x PCBs (front, middle, and rear) separated with paper
  * Badge Component Bag (10x15cm-4x6in Mylar) Containing:
    * Small Component Bag #1 (4x5cm-1.5x2in Clear) Containing:
      * 6x Black Nylon Standoff and M3 Screw sets
    * Small Component Bag (5x7cm-2x2.8in Red) Containing:
      * 1x Lipo Battery 103040
      * 1x JST mini PH Connector Wire
      * 4x Rubber Band Size #8 (2 req. 2 spare)
    * Small Bag (5x8cm-2x3in Clear) Containing:
      * 1x Lanyand
    * Small Component Bag (6x9cm-2.4x3.5in Mylar) Containing:
      * 1x ESP32 WeMos Lolin32 Dev Board
      * 2x Header Male 2.54mm 1x13 Pin Strip
    * Small Component Bag (8x12cm-3.2x4.7in Mylar) Containing:
      * 8x WS2812D 5mm 4-Pin Addressable Neopixel LED
      * 8x White 3mm 2-pin LED
      * 8x 100nF Ceramic Disc Capacitor
      * 10x 47 Ohm 6.2mm Metal Film Resistor
      * 2x 100K Ohm 6.2mm Metal Film Resistor
      * 1x SS12D00 3-Pin SPDT Right Angle Switch
      * 4x Header Male 2.54mm 1x2 Pin Right Angle Strip
      * 4x Header Female 2.54mm 2x3 Pin Keyed (SAO)
  * Badge Component Bag (10x15cm-4x6in Mylar) Containing:
    * 1x PCB panel (which breaks apart into four small SAO PCBs) Note: This PCB might have broken apart during shipping, but this is not a problem as breaking is required for assembly.
    * 4x Mini 2in Lanyard with tiny keyring
    * Small Component Bag (6x9cm-2.4x3.5in Mylar) Labeled "Mothra SAO" Containing:
      * 2x White 3mm 2-pin LED
      * 2x 47 Ohm 6.2mm Metal Film Resistor
      * 1x 10K Ohm 6.2mm Metal Film Resistor
      * 1x Header Male 2.54mm 2x3 Pin Keyed Hooded (SAO)
    * Small Component Bag (6x9cm-2.4x3.5in Mylar) Labeled "King Ghidorah SAO" Containing:
      * 2x White 3mm 2-pin LED
      * 2x 47 Ohm 6.2mm Metal Film Resistor
      * 1x 47K Ohm 6.2mm Metal Film Resistor
      * 1x Header Male 2.54mm 2x3 Pin Keyed Hooded (SAO)
    * Small Component Bag (6x9cm-2.4x3.5in Mylar) Labeled "Rodan SAO" Containing:
      * 2x White 3mm 2-pin LED
      * 2x 47 Ohm 6.2mm Metal Film Resistor
      * 1x 100K Ohm 6.2mm Metal Film Resistor
      * 1x Header Male 2.54mm 2x3 Pin Keyed Hooded (SAO)
    * Small Component Bag (6x9cm-2.4x3.5in Mylar) Labeled "Hedorah SAO" Containing:
      * 2x White 3mm 2-pin LED
      * 2x 47 Ohm 6.2mm Metal Film Resistor
      * 1x 220K Ohm 6.2mm Metal Film Resistor
      * 1x Header Male 2.54mm 2x3 Pin Keyed Hooded (SAO)
  * 2x Sticker (Not Required for badge Assembly)

[![Badge_Kit](images/BadgeKit01sm.jpg)](images/BadgeKit01.jpg)
[![Badge_Kit](images/BadgeKit02sm.jpg)](images/BadgeKit02.jpg)
[![Badge_Kit](images/BadgeKit03sm.jpg)](images/BadgeKit03.jpg)

## Assembly Steps for the Badge

* All the badge components will be added to the middle PCB board
  * Identify the middle PCB board and use this for all the following steps up to the stack assembly.
  * Any reference to the back side of the PCB is talking about the side of the middle PCB that has the Monarch and Godzilla Minus one Logos in copper.
  * Any reference to the front side of the PCB is talking about the side of the middle PCB that has the Japanese text "Godzilla VS" in copper.

[![Components](images/AssemblyPic01sm.jpg)](images/AssemblyPic01.jpg)
[![PCB Mid Front](images/AssemblyPic02sm.jpg)](images/AssemblyPic02.jpg)
[![PCB Mid Back](images/AssemblyPic03sm.jpg)](images/AssemblyPic03.jpg)

* Resistors
  * The ten 47-Ohm resistors are labeled R1-R8, R10 and R20 on the back side of the PCB
  * The two 100K-Ohm resistors are labeled R32 and R32 on the back side of the PCB
  * Resistors are non-polar so they can be placed in either direction.
  * Place all the resistors into the back side of the PCB bending thier legs outward on the front side to hold them in place
  * Solder all the resistor connections on the front side of the PCB.
  * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![Resistors](images/AssemblyPic04sm.jpg)](images/AssemblyPic04.jpg)
[![Resistors](images/AssemblyPic05sm.jpg)](images/AssemblyPic05.jpg)

* One Color (White) 3mm 2 pin LEDs
  * The eight traditional one color (white) 2 pin LEDs are easy to solder.
  * LEDs are polar and must be placed in the proper direction.  They have one leg longer than the other to indicate the cathode and anode legs.
    * The PCB silk has drawings of the short and long pin positions as a guide for each LED.
    * The PCB solder pad shapes provide another guide as the short leg should always go in the square hole
  * Three of these LEDs are labeled D6-8 on the back side of the PCB
    * These LEDs need to be bent over for specific positioning on the PCB so be careful with placement
    * Place these LEDs into thier labeled positions on the back side of the PCB
    * Make sure to align the LEDs properly using the silk guide to place short leg in square hole, folding the LEDs in the direction indicated to place the body of the LED over the solder mask void on the PCB
    * Solder all the LED connections
    * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)
  * Five of these LEDs are labeled D1-5 on the frront side of the PCB
    * Place these LEDs into thier labeled positions on the back side of the PCB
    * Make sure to align the LEDs properly using the silk guide to place short leg in square hole
    * Solder all the LED connections
    * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![White LEDs](images/AssemblyPic06sm.jpg)](images/AssemblyPic06.jpg)
[![White LEDs](images/AssemblyPic07sm.jpg)](images/AssemblyPic07.jpg)
[![White LEDs](images/AssemblyPic08sm.jpg)](images/AssemblyPic08.jpg)
[![White LEDs](images/AssemblyPic09sm.jpg)](images/AssemblyPic09.jpg)
[![White LEDs](images/AssemblyPic10sm.jpg)](images/AssemblyPic10.jpg)
[![White LEDs](images/AssemblyPic11sm.jpg)](images/AssemblyPic11.jpg)

* Addressable Neopixel 5mm 4-Pin LEDs
  * The eight Neopixel LEDs are a bit more difficult to solder given the pins are close together
  * These LEDs are polar and must be placed in the proper direction.  Each of the four legs has a different length.  One leg is longer than all the others in one of the middle positions away from the shortest leg.
    * The PCB silk has drawings of all four legs with thier lengths and positions as a guide for each LED.
    * The PCB solder pad shapes provide another guide as the longest leg should always go towards the square hole (one position over from it)
  * These eight LEDs are labeled D10-13, and D20-23 on the frot side of the PCB
  * Place the LEDs in thier designated places on the front side of the PCB
    * Make sure to align the LEDs properly using the silk guide to place longest leg one position over from the square hole
    * Solder all the LED connections
    * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![Neopixel LEDs](images/AssemblyPic12sm.jpg)](images/AssemblyPic12.jpg)
[![Neopixel LEDs](images/AssemblyPic13sm.jpg)](images/AssemblyPic13.jpg)
[![Neopixel LEDs](images/AssemblyPic14sm.jpg)](images/AssemblyPic14.jpg)

* Capacitors
  * The eight capacitors are tan colored 2.5mm wide 2 pin 100nF non-polar ceramic disc capacitors (that look like Ibuprofen tablets) which are labeled C10-13, and C20-23 on the back side of the PCB
  * Place all the capacitors in thier designated places on the PCB bending legs out to hold in place
  * These are non-polar so they can be placed in either direction.
  * Solder all the capacitor connections
  * The large ground plane makes one of the pins take a bit longer to heat up and the thin legs and larger pads make for uneven heating.  So, take a little more time to make sure these have a good connection.
  * Watch the position of your iron as you solder these since they are close to LEDs that you don't want to damage.
  * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![Capacitors](images/AssemblyPic15sm.jpg)](images/AssemblyPic15.jpg)
[![Capacitors](images/AssemblyPic16sm.jpg)](images/AssemblyPic16.jpg)
[![Capacitors](images/AssemblyPic17sm.jpg)](images/AssemblyPic17.jpg)

* Switch for battery power
  * The battery power switch is a 3-pin SPDT switch with a 5mm lever and right angle pins
  * Place the switch in its designated place on the back side of the PCB with the lever pointing towards the PCB edge. 
  * You might need to tilt it a bit to allow the pins to stick through the PCB enough to easily solder them.
  * Solder all the switch connections

[![Switch](images/AssemblyPic18sm.jpg)](images/AssemblyPic18.jpg)
[![Switch](images/AssemblyPic19sm.jpg)](images/AssemblyPic19.jpg)
[![Switch](images/AssemblyPic20sm.jpg)](images/AssemblyPic20.jpg)

* Battery Holder Right Angle Male Headers
  * The four 2.54mm 1x2 Pin Right Angle Male Headers are used with a rubber band to secure the lipo battery and are labeled J2-5 on the back side of the PCB
  * Place the short side of the header pins into the designated positions on the PCB with the long side pointing away from where the battery will be placed later.
  * Solder all the connections
  * It may be tricky to solder them while keeping them from pressing against the PCB, try soldering only one pin then adjust the header while applying heat to that pin

[![Male90](images/AssemblyPic21sm.jpg)](images/AssemblyPic21.jpg)
[![Male90](images/AssemblyPic22sm.jpg)](images/AssemblyPic22.jpg)
[![Male90](images/AssemblyPic23sm.jpg)](images/AssemblyPic23.jpg)

* SAO Female Keyed 2x3 Headers
  * The four 2.54mm 2x3 Pin Keyed Female Headers are labeled JSAO1-2 on the front side of the PCB and JSAO3-4 on the back side of the PCB
  * The two headers on the back side of the PCB will be placed further towards the middle of the PCB than the two on the front side which are placed closer to the edges of the PCB.
  * All of the headers should be placed with thier key notch towards the top of the PCB as indicated by the drawing in the PCB silk (which might be difficult to see given all the art near it).
  * It is best to place and solder each of these individually

[![BadgeSAOs](images/AssemblyPic24sm.jpg)](images/AssemblyPic24.jpg)
[![BadgeSAOs](images/AssemblyPic25sm.jpg)](images/AssemblyPic25.jpg)
[![BadgeSAOs](images/AssemblyPic26sm.jpg)](images/AssemblyPic26.jpg)
[![BadgeSAOs](images/AssemblyPic27sm.jpg)](images/AssemblyPic27.jpg)
[![BadgeSAOs](images/AssemblyPic28sm.jpg)](images/AssemblyPic28.jpg)
[![BadgeSAOs](images/AssemblyPic29sm.jpg)](images/AssemblyPic29.jpg)
[![BadgeSAOs](images/AssemblyPic30sm.jpg)](images/AssemblyPic30.jpg)
[![BadgeSAOs](images/AssemblyPic31sm.jpg)](images/AssemblyPic31.jpg)

* The ESP32 development board
  * This is a 26 pin ESP32 WeMos Lolin32 development board with two 1x13 pin male header strips
  * Place the male header pins into the ESP32 dev board with the longer pins being inserted into the board (which is inverse of how they would normally be attached if plugging this into female headers or a bread board)
  * Placing this onto a small bread board while soldering ensures that the headers maintain the required 90 degree angle.  Otherwise you should solder only one pin on each side adjusting the angle while applying heat to get a 90 degree angle before continuing with the remaining pins.
  * Solder all the connections on the ESP dev board
  * When cooled place the ESP32 dev board into the back side of the PCB
  * Make sure to place the ESP32 in its designated place on the PCB and ensure it is aligned properly according to the silk drawing on the badge PCB (look at the USB and Battery connector symbols drawn in silkscreen)
  * Solder all the connections

[![ESP32Dev](images/AssemblyPic32sm.jpg)](images/AssemblyPic32.jpg)
[![ESP32Dev](images/AssemblyPic33sm.jpg)](images/AssemblyPic33.jpg)
[![ESP32Dev](images/AssemblyPic34sm.jpg)](images/AssemblyPic34.jpg)
[![ESP32Dev](images/AssemblyPic35sm.jpg)](images/AssemblyPic35.jpg)
[![ESP32Dev](images/AssemblyPic36sm.jpg)](images/AssemblyPic36.jpg)
[![ESP32Dev](images/AssemblyPic37sm.jpg)](images/AssemblyPic37.jpg)
[![ESP32Dev](images/AssemblyPic38sm.jpg)](images/AssemblyPic38.jpg)

* ESP32 Battery Power Wires
  * The ESP32 power wire connections are labeled J1 on the back side of the PCB
  * The ESP32 development board has a JST mini PH battery power connector which needs to be connected to J1 on the PCB
  * The JST mini PH connector is keyed allowing it to only be plugged into the ESP32 dev board one way
  * You can plug the connector into the ESP32 dev board to measure where to cut these wires to size, do not cut them too short or leave too much slack.
  * Disconnect the connector before attaching and soldering the wires.
  * WARNING: Unfourtunatley the JST mini PH Connector Wires that were available for this project had the red and black wires in the WRONG positions for this ESP32 dev board.
    * This means that the red wire which is usually an indication of Positive power is actually aligned with the Ground/Negative power terminal on the ESP32 dev board and visa versa for the black wire.
    * When connecting these wires to the badge PCB J1 pads you will need to connect the RED TO GND (round pad) and BLACK TO + (square pad)
    * Failure to do this will result in REVERSE POLARITY that will DESTROY the ESP32 dev board.
    * Reminder labels have been attached to these wires as a WARNING
  * Solder the connections
  * When cooled trim any excess wire at the top of the solder joints (do not cut into the solder joint)
  * Verify that the connector can reach to be plugged into the ESP32 dev board (you might need to twist the connector around to line it up)
  * Be sure to disconnect this connector since we do not want it connected when working with the LIPO Battery

[![ESPpower](images/AssemblyPic39sm.jpg)](images/AssemblyPic39.jpg)
[![ESPpower](images/AssemblyPic40sm.jpg)](images/AssemblyPic40.jpg)
[![ESPpower](images/AssemblyPic41sm.jpg)](images/AssemblyPic41.jpg)
[![ESPpower](images/AssemblyPic42sm.jpg)](images/AssemblyPic42.jpg)
[![ESPpower](images/AssemblyPic43sm.jpg)](images/AssemblyPic43.jpg)

* LIPO Battery
  * The LIPO Battery has a charge so you need to be careful when working with it
    * Make sure not to touch the battery wires together by only stripping and soldering one wire at a time
    * Make sure battery power will not be applied to the badge by ensuring the ESP32 battery connector is disconnected and the badge switch is in the off position (towards the center of the badge)
  * The battery power wire connections are labeled BT1 on the back side of the PCB
  * Strip the tip of the BLACK battery wire and insert it into BT1 on the badge PCB in GND (round pad)
  * Solder this wire to the PCB
  * Strip the tip of the RED battery wire and insert it into BT1 on the badge PCB in + (square pad)
  * Solder this wire to the PCB
  * Place the battery onto the PCB within the designated square drawn in silk on the PCB
  * Attach a rubber band over the battery between the male header pins in J2 and J5
  * Attach a rubber band over the battery between the male header pins in J3 and J4
  * Plug in the ESP32 power connector

[![LIPO](images/AssemblyPic44sm.jpg)](images/AssemblyPic44.jpg)
[![LIPO](images/AssemblyPic45sm.jpg)](images/AssemblyPic45.jpg)
[![LIPO](images/AssemblyPic46sm.jpg)](images/AssemblyPic46.jpg)
[![LIPO](images/AssemblyPic47sm.jpg)](images/AssemblyPic47.jpg)
[![LIPO](images/AssemblyPic48sm.jpg)](images/AssemblyPic48.jpg)

* Testing
  * Turn on the badge and make sure all the LEDs light up
  * If any of them do not then turn the badge off, make any necessary corrections and try again.
  * Turn the badge off when done before connecting the three PCBs

[![Test](images/AssemblyPic49sm.jpg)](images/AssemblyPic49.jpg)

* PCB Stack Assembly
  * Attach all the standoffs to the middle PCB using M3 screws
    * Take note of which standoffs need to go on which side of the middle PCB
    * The higher side holes are aligned with the rear PCB so these standoffs will go on the back side of the middle PCB
    * The lower side holes (near the power switch) are aligned with the front PCB so these standoffs will go on the front side of the middle PCB
    * The bottom holes have the centered one aligned with the front PCB and the off center one aligned with the rear PCB so place those standoffs in the proper sides of the middle PCB
  * Attach the rear PCB to the middle PCB using M3 screws into the standoffs
  * Attach the front PCB to the middle PCB using M3 screws into the standoffs
  * Screw down the M3 screws resonably tight so they do not come loose easily, but DO NOT over tighten as this could strip the plastic screw or even crack the PCB

[![Stack](images/AssemblyPic50sm.jpg)](images/AssemblyPic50.jpg)
[![Stack](images/AssemblyPic51sm.jpg)](images/AssemblyPic51.jpg)
[![Stack](images/AssemblyPic52sm.jpg)](images/AssemblyPic52.jpg)
[![Stack](images/AssemblyPic53sm.jpg)](images/AssemblyPic53.jpg)
[![Stack](images/AssemblyPic54sm.jpg)](images/AssemblyPic54.jpg)
[![Stack](images/AssemblyPic55sm.jpg)](images/AssemblyPic55.jpg)
[![Stack](images/AssemblyPic56sm.jpg)](images/AssemblyPic56.jpg)

## Assembly Steps for the SAOs

* Break apart the PCBs on the mouse bites
  * To provide an even break line placing one PCB on a hard surface (like a desk) and pushing down on the other PCB works well
  * Break off the mouse bites from the PCB(s) that they are still attached to
  * Mini pliers are helpful but not required
  * The rough edges can be filed or sanded down if a smooth edge is preferred

[![SAOPanel](images/AssemblyPic58sm.jpg)](images/AssemblyPic58.jpg)
[![SAOPanel](images/AssemblyPic59sm.jpg)](images/AssemblyPic59.jpg)
[![SAOPanel](images/AssemblyPic60sm.jpg)](images/AssemblyPic60.jpg)
[![SAOPanel](images/AssemblyPic61sm.jpg)](images/AssemblyPic61.jpg)

* All of these SAOs are almost identical in assembly
  * The only real difference being the resistance value of a single resistor on the SAO
  * The component labels reflect the SAO number in them so that R1 on the second SAO would be labeled R21 and D1 on the third SAO would be labeled D31
  * The following instructions will reference the components simply without the SAO number (e.g. R1, D1)

* Resistors
  * Each SAO has two 47-Ohm resistors labeled R1-R2 on the PCB
  * Each SAO has one unique value resistor labeled R3 on the PCB
    * Mothra = 10K Ohm
    * King Ghidorah = 47K Ohm
    * Rodan = 100K Ohm
    * Hedorah = 220K Ohm
  * Resistors are non-polar so they can be placed in either direction.
  * Place all the resistors into the back side of the PCB bending thier legs outward on the front side to hold them in place
  * Solder all the resistor connections on the front side of the PCB.
  * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![Resistors](images/AssemblyPic62sm.jpg)](images/AssemblyPic62.jpg)
[![Resistors](images/AssemblyPic63sm.jpg)](images/AssemblyPic63.jpg)

* One Color (White) 3mm 2 pin LEDs
  * LEDs are polar and must be placed in the proper direction.  They have one leg longer than the other to indicate the cathode and anode legs.
    * The PCB silk has drawings of the short and long pin positions as a guide for each LED.
    * The PCB solder pad shapes provide another guide as the short leg should always go in the square hole
  * Each SAO has two of these LEDs labeled D1-2 on the PCB
    * These LEDs need to be bent over for specific positioning on the PCB so be careful with placement
    * Place these LEDs into thier labeled positions on the back side of the PCB
    * Make sure to align the LEDs properly using the silk guide to place short leg in square hole, folding the LEDs in the direction indicated to place the body of the LED over the solder mask void on the PCB
    * Solder all the LED connections
    * When cooled cut the component legs off at the top of the solder joints (do not cut into the solder joint)

[![LEDs](images/AssemblyPic64sm.jpg)](images/AssemblyPic64.jpg)
[![LEDs](images/AssemblyPic65sm.jpg)](images/AssemblyPic65.jpg)
[![LEDs](images/AssemblyPic66sm.jpg)](images/AssemblyPic66.jpg)

* SAO Male Keyed Hooded 2x3 Headers
  * Each SAO has a 2.54mm 2x3 Pin Keyed Hooded Male Header are labeled JSAO on the back side of the PCB
  * The header should be placed with the key notch towards the top of the PCB as indicated by the drawing in the PCB silk
  * Solder all the header connections

[![SAOMale](images/AssemblyPic67sm.jpg)](images/AssemblyPic67.jpg)
[![SAOMale](images/AssemblyPic68sm.jpg)](images/AssemblyPic68.jpg)
[![SAOMale](images/AssemblyPic69sm.jpg)](images/AssemblyPic69.jpg)

## Final Assembly Steps

* Optional SAO Mini Lanyards
  * Place a mini lanyard on each SAO
    * Insert the thread side of the lanyard into on of the bottom SAO holes extending a small loop of lanyard thread
    * Feed the keyring side of the lanyard through the loop and pull tight
  * Connect the tiny keyrings from the SAO lanyards to the badge middle PCB holes at the bottom edge
    * Pry open the tiny keyring extending it over the edge of the badge PCB
    * Work the end of the keyring into the hole and work it around until the keyring is closed again connected to the badge
    * The keyrings are difficult to attach to the PCB but mini pliers can help
    * Only one keyring on each side needs to be connected to the PCB, the other two can be connected to the first two rings which is much easier to do

[![SAOminiLanyard](images/AssemblyPic70sm.jpg)](images/AssemblyPic70.jpg)
[![SAOminiLanyard](images/AssemblyPic71sm.jpg)](images/AssemblyPic71.jpg)
[![SAOminiLanyard](images/AssemblyPic72sm.jpg)](images/AssemblyPic72.jpg)
[![SAOminiLanyard](images/AssemblyPic73sm.jpg)](images/AssemblyPic73.jpg)

* Attach the badge lanyard
  * Attach the lanyard to the rear PCB of the badge using the lanyard aligator clips

[![Lanyard](images/AssemblyPic74sm.jpg)](images/AssemblyPic74.jpg)

* Enjoy!

[![Complete](images/AssemblyPic57sm.jpg)](images/AssemblyPic57.jpg)
