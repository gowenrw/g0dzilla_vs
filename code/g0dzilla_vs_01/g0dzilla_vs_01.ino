// g0dzilla_vs badge code rev01

// Include Libraries
#include <Arduino.h>
#include <WiFi.h>
#include "Adafruit_NeoPixel.h"
#include "SPI.h"
#include <driver/adc.h>
#include <esp_wifi_types.h>
#include <esp_wifi.h>
// Include Games Library
//#include <g0dzilla_vs_lib.h>

// Pin Definitions
//
// NeoPixel Data Pins
#define NEO01_DATA 17
#define NEO02_DATA 16
// D10 Breath
// D11 Eye-Left
// D12 Eye-Right
// D13 Tail-Top
// D20 Back-Top
// D21 Back-Mid
// D22 Back-Bot
// D23 Tail-Bot
//
// One color LED Pins
#define LED_D1 32  // Breath
#define LED_D2 25  // Back-Top
#define LED_D3 27  // Back-Bot
#define LED_D4 14  // Tail
#define LED_D5 26  // Stomp
#define LED_D6 33  // Nuke
#define LED_D7 12  // Navy
#define LED_D8 5   // Army
//
// Built-in LED
#define LED_BI 22

//
// Capacitive Touch Pins
#define TCH01_PIN 4  // Monarch
#define TCH02_PIN 2  // Godzilla
#define TCH03_PIN 15 // VS
#define TCH04_PIN 13 // Minus-One

//
// Analog Inut Pins
#define JSAO01 34 // Left Front SAO
#define JSAO02 35 // Right Front SAO

// NeoPixel Properties
//
// Define NeoPixel Strips - (Num pixels, pin to send signals, pixel type, signal rate)
Adafruit_NeoPixel NEO01 = Adafruit_NeoPixel(4, NEO01_DATA, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel NEO02 = Adafruit_NeoPixel(4, NEO02_DATA, NEO_RGB + NEO_KHZ800);

// LED Variables
//
// Main LED mode 0=default 1=battleone 2=?
int main_led_mode = 0;
//
// Battle Color bitvector 1=red 2=green 4=blue (3=R&G 5=R&B 6=G&B 7=R&G&B)
int battle_color = 1;
//
// NeoPixel Big Color Value 32 bit = (W-8bit << 24) + (R-8bit << 16) + (G-8bit <<8) + (B-8bit)
uint32_t neo_big_color = 0;
uint8_t neo_col_whi = 0;
uint8_t neo_col_red = 0;
uint8_t neo_col_grn = 0;
uint8_t neo_col_blu = 0;

// PWM Properties
//
// Signal Frequency in Hz
const int freq = 1000;
// Duty Cycle Resolution in bits (1-16)
const int resolution = 8;
// PWM channel Assignment (0-15)
const int LED_D1_pwm = 1;
const int LED_D2_pwm = 2;
const int LED_D3_pwm = 3;
const int LED_D4_pwm = 4;
const int LED_D5_pwm = 5;
const int LED_D6_pwm = 6;
const int LED_D7_pwm = 7;
const int LED_D8_pwm = 8;

// Wireless Properties
//
// WIFI status codes
const char* wl_status_to_string(wl_status_t status) {
  switch (status) {
    case WL_NO_SHIELD: return "WL_NO_SHIELD";
    case WL_IDLE_STATUS: return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL: return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED: return "WL_SCAN_COMPLETED";
    case WL_CONNECTED: return "WL_CONNECTED";
    case WL_CONNECT_FAILED: return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST: return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED: return "WL_DISCONNECTED";
  }
}

// Capacitive Touch Properties
//
// Touch Thresholds
int Touch01_Threshold = 28;
int Touch02_Threshold = 28;
int Touch03_Threshold = 28;
int Touch04_Threshold = 28;
// Touch Initial Values
int Touch01_Value = 30;
int Touch02_Value = 30;
int Touch03_Value = 30;
int Touch04_Value = 30;
//
// Touch Counters
//
// Touch Iteration Counter
int Touch01_IntCount = 0;
int Touch02_IntCount = 0;
int Touch03_IntCount = 0;
int Touch04_IntCount = 0;
// Touch Loop Counter
int Touch01_LoopCount = 0;
int Touch02_LoopCount = 0;
int Touch03_LoopCount = 0;
int Touch04_LoopCount = 0;
// Touch Loop Threshold (Touch Held for X Loops of Main)
int Touch01_Loop_Threshold = 3;
int Touch02_Loop_Threshold = 3;
int Touch03_Loop_Threshold = 3;
int Touch04_Loop_Threshold = 3;

// Analog Input Values
int JSAO01_Value = 0;
int JSAO02_Value = 0;

// Loop Control Properties
//
// Main Loop LED Iteration Delay Time [in ms]
int LEDDelayTime = 15;
//
// Debug Serial - If set greater than 0 it writes to serial for debugging
// 0 = no debug text
// 1 = basic debug info once per main loop
// 2 = extra debug info
int DebugSerial = 2;

// //////////////////////////////////////////////////
//
// SETUP - RUN ONCE
//
// //////////////////////////////////////////////////
void setup(){
  // Add a delay to allow opening serial monitor
  delay(800);

  // setup the serial output baud rate
  Serial.begin(115200);

  if (DebugSerial >= 1) {
    Serial.println("Starting Setup");
  }

  // Turn Off WiFi/BT
  if (DebugSerial >= 2) {
    Serial.println("Turn Off WiFi / BlueTooth");
  }
  setModemSleep();

  // Configure LED PWM functionalitites per channel
  if (DebugSerial >= 2) {
    Serial.println("Configure PWM Channels");
  }
  ledcSetup(LED_D1_pwm, freq, resolution);
  ledcSetup(LED_D2_pwm, freq, resolution);
  ledcSetup(LED_D3_pwm, freq, resolution);
  ledcSetup(LED_D4_pwm, freq, resolution);
  ledcSetup(LED_D5_pwm, freq, resolution);
  ledcSetup(LED_D6_pwm, freq, resolution);
  ledcSetup(LED_D7_pwm, freq, resolution);
  ledcSetup(LED_D8_pwm, freq, resolution);

  // Attach the channel to the GPIO to be controlled
  if (DebugSerial >= 2) {
    Serial.println("Attach PWM Channels to LED Pins");
  }
  ledcAttachPin(LED_D1, LED_D1_pwm);
  ledcAttachPin(LED_D2, LED_D2_pwm);
  ledcAttachPin(LED_D3, LED_D3_pwm);
  ledcAttachPin(LED_D4, LED_D4_pwm);
  ledcAttachPin(LED_D5, LED_D5_pwm);
  ledcAttachPin(LED_D6, LED_D6_pwm);
  ledcAttachPin(LED_D7, LED_D7_pwm);
  ledcAttachPin(LED_D8, LED_D8_pwm);

  //Normal LED output
  if (DebugSerial >= 2) {
    Serial.println("Set Output for non-PWM LED Pins");
  }
  pinMode(LED_BI, OUTPUT);

  // Initialize the NeoPixels
  if (DebugSerial >= 2) {
    Serial.println("Initialize NeoPixels");
  }
  NEO01.begin();
  NEO02.begin(); 
  // Set Neopixel Brightness (0-255 scale)
  NEO01.setBrightness(170);
  NEO02.setBrightness(170);

  // Start all LEDs in OFF mode
  if (DebugSerial >= 2) {
    Serial.println("Turn OFF all LEDs");
  }
  ledAllOff();

  // Set a Random Seed
  int myrandseed = (analogRead(0) + analogRead(34) + (touchRead(TCH02_PIN) * 2) + (touchRead(TCH03_PIN)*3) + touchRead(TCH04_PIN));
  randomSeed(myrandseed);
  if (DebugSerial >= 2) {
    Serial.print("Set Random Seed "); Serial.println(myrandseed);
  }

  if (DebugSerial >= 1) {
    Serial.println(F("Setup Done!"));
  }

  // END OF SETUP
}

// //////////////////////////////////////////////////
//
// LOOP - MAIN 
//
// //////////////////////////////////////////////////
void loop(){
  if (DebugSerial >= 1) {
    Serial.println("******************** TOP OF MAIN LOOP ********************");
  }
  // Capacitive Touch Dynamic Threshold Adjustment
  // Adjust thresholds UP to account for assembly conditions and battery vs usb
  Touch01_Value = touchRead(TCH01_PIN);
  if ( (Touch01_Value / Touch01_Threshold) > 2 ) { Touch01_Threshold = int(Touch01_Threshold * 1.8); }
  Touch02_Value = touchRead(TCH02_PIN);
  if ( (Touch02_Value / Touch02_Threshold) > 2 ) { Touch02_Threshold = int(Touch02_Threshold * 1.8); }
  Touch03_Value = touchRead(TCH03_PIN);
  if ( (Touch03_Value / Touch03_Threshold) > 2 ) { Touch03_Threshold = int(Touch03_Threshold * 1.8); }
  Touch04_Value = touchRead(TCH04_PIN);
  if ( (Touch04_Value / Touch04_Threshold) > 2 ) { Touch04_Threshold = int(Touch04_Threshold * 1.8); }

  // //////////////////////////////////
  //     START OF ITERATION LOOP
  // //////////////////////////////////
  //
  // Iterate 0 to 254
  for(int i=0; i<255; i++){
    // Set position value to iteration value
    int pos = i;

    // DEBUG - Print current Iteration value to serial console for troubleshooting
    if (DebugSerial >= 2) {
      Serial.print(" Iteration="); Serial.print(i);
      Serial.print(" Pos="); Serial.print(pos);
    }

    //
    // TOUCH
    //
    // Read Touch Values
    Touch01_Value = touchRead(TCH01_PIN); // Monarch
    Touch02_Value = touchRead(TCH02_PIN); // Godzilla
    Touch03_Value = touchRead(TCH03_PIN); // VS
    Touch04_Value = touchRead(TCH04_PIN); // Minus-One
    //
    // **************************************************************
    //
    // Do Stuff If We Detect a Touch on TCH01_PIN
    if (Touch01_Value < Touch01_Threshold) {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T1_TCH="); Serial.print(Touch01_Value);
        Serial.print("/"); Serial.print(Touch01_Threshold);
        Serial.print("-"); Serial.print(Touch01_IntCount);
        Serial.print("/"); Serial.print(Touch01_LoopCount);
      }
      // STUFF - TCH01_PIN TOUCHED
      if (Touch01_IntCount == 0){
        // Put stuff to happen once per iteration loop here
      }
      // Put stuff to happen every iteration here
      Touch01_IntCount = 1;
      //
      //touchedDinosaurs();
    //
    // Do Stuff If We DONT Detect a Touch on TCH01_PIN
    } else {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T1="); Serial.print(Touch01_Value);
        Serial.print("/"); Serial.print(Touch01_Threshold);
        Serial.print("-"); Serial.print(Touch01_IntCount);
        Serial.print("/"); Serial.print(Touch01_LoopCount);
      }
      // STUFF - TCH01_PIN NOT TOUCHED
    }
    // **************************************************************
    //
    // Do Stuff If We Detect a Touch on TCH02_PIN
    if (Touch02_Value < Touch02_Threshold) {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T2_TCH="); Serial.print(Touch02_Value);
        Serial.print("/"); Serial.print(Touch02_Threshold);
        Serial.print("-"); Serial.print(Touch02_IntCount);
        Serial.print("/"); Serial.print(Touch02_LoopCount);
      }
      // STUFF - TCH02_PIN TOUCHED
      if (Touch02_IntCount == 0){
        // Put stuff to happen once per iteration loop here
        main_led_mode = main_led_mode + 1;
        if (main_led_mode > 1) { main_led_mode = 0; }
        setRandomColor();
      }
      // Put stuff to happen every iteration here
      Touch02_IntCount = 1;
      //
      //
    //
    // Do Stuff If We DONT Detect a Touch on TCH02_PIN
    } else {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T2="); Serial.print(Touch02_Value);
        Serial.print("/"); Serial.print(Touch02_Threshold);
        Serial.print("-"); Serial.print(Touch02_IntCount);
        Serial.print("/"); Serial.print(Touch02_LoopCount);
      }
      // STUFF - TCH02_PIN NOT TOUCHED
    }
    // **************************************************************
    //
    // Do Stuff If We Detect a Touch on TCH03_PIN
    if (Touch03_Value < Touch03_Threshold) {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T3_TCH="); Serial.print(Touch03_Value);
        Serial.print("/"); Serial.print(Touch03_Threshold);
        Serial.print("-"); Serial.print(Touch03_IntCount);
        Serial.print("/"); Serial.print(Touch03_LoopCount);
      }
      // STUFF - TCH03_PIN TOUCHED
      if (Touch03_IntCount == 0){
        // Put stuff to happen once per iteration loop here
      }
      // Put stuff to happen every iteration here
      Touch03_IntCount = 1;
      //
      //touched3000();
    //
    // Do Stuff If We DONT Detect a Touch on TCH03_PIN
    } else {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T3="); Serial.print(Touch03_Value);
        Serial.print("/"); Serial.print(Touch03_Threshold);
        Serial.print("-"); Serial.print(Touch03_IntCount);
        Serial.print("/"); Serial.print(Touch03_LoopCount);
      }
      // STUFF - TCH03_PIN NOT TOUCHED
    }
    // **************************************************************
    //
    // Do Stuff If We Detect a Touch on TCH04_PIN
    if (Touch04_Value < Touch04_Threshold) {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T4_TCH="); Serial.print(Touch04_Value);
        Serial.print("/"); Serial.print(Touch04_Threshold);
        Serial.print("-"); Serial.print(Touch04_IntCount);
        Serial.print("/"); Serial.print(Touch04_LoopCount);
      }
      // STUFF - TCH04_PIN TOUCHED
      if (Touch04_IntCount == 0){
        // Put stuff to happen once per iteration loop here
      }
      // Put stuff to happen every iteration here
      Touch04_IntCount = 1;
      //
      //
    //
    // Do Stuff If We DONT Detect a Touch on TCH04_PIN
    } else {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print(" T4="); Serial.print(Touch04_Value);
        Serial.print("/"); Serial.print(Touch04_Threshold);
        Serial.print("-"); Serial.print(Touch04_IntCount);
        Serial.print("/"); Serial.print(Touch04_LoopCount);
      }
      // STUFF - TCH04_PIN NOT TOUCHED
    }
    // **************************************************************
    //

    // Read Analog Input Values
    JSAO01_Value = analogRead(JSAO01);
    JSAO02_Value = analogRead(JSAO02);
    // Display Analog Values
    if (DebugSerial >= 2) {
      Serial.print(" SAO1="); Serial.print(JSAO01_Value);
      Serial.print(" SAO2="); Serial.print(JSAO02_Value);
    }

    if (main_led_mode == 0) {
      //
      // DEFAULT MODE
      //
      // First of three position groups i 0-84
      if (pos < 85) {
        //
        // LED FUNCTIONS
        eyes_neo_colorshift(pos, 1);
        g0dz_neo_colorshift(pos, 1);
        ledPwmDefault(pos, 1);
        BI_blink_two(pos);
      // Second of three position groups i 85-169 (pos-85 = 0-84)
      } else if (pos < 170) {
        pos = pos - 85;
        //
        // LED FUNCTIONS
        eyes_neo_colorshift(pos, 2);
        g0dz_neo_colorshift(pos, 2);
        ledPwmDefault(pos, 2);
        BI_blink_two(pos);
      // Third of three position groups i 170-254 (pos-170 = 0-84)
      } else {
        pos = pos -170;
        //
        // LED FUNCTIONS
        eyes_neo_colorshift(pos, 3);
        g0dz_neo_colorshift(pos, 3);
        ledPwmDefault(pos, 3);
        BI_blink_two(pos);
        // Split third group 3/4 (pos 0-42) for even number of transitions
        if (pos <43) {
          //
          //ledPwmDefault(pos, 3);
        // Split third group 4/4 (pos 43-84) for even number of transitions
        } else {
          //
          //ledPwmDefault(pos, 4);
        }
      }
    } else if (main_led_mode == 1) {
      //
      // BATTLE MODE
      //
      // First of three position groups i 0-84
      if (pos < 85) {
        //
        // LED FUNCTIONS
        g0dz_blast(pos, 1);
        // ledPwmTest(pos, 1);
        BI_blink_two(pos);
      // Second of three position groups i 85-169 (pos-85 = 0-84)
      } else if (pos < 170) {
        pos = pos - 85;
        //
        // LED FUNCTIONS
        g0dz_blast(pos, 2);
        // ledPwmTest(pos, 2);
        BI_blink_two(pos);
      // Third of three position groups i 170-254 (pos-170 = 0-84)
      } else {
        pos = pos -170;
        //
        // LED FUNCTIONS
        g0dz_blast(pos, 3);
        BI_blink_two(pos);
        // Split third group 3/4 (pos 0-42) for even number of transitions
        if (pos <43) {
          //
          // ledPwmTest(pos, 3);
        // Split third group 4/4 (pos 43-84) for even number of transitions
        } else {
          //
          // ledPwmTest(pos, 4);
        }
      }
    }

    // DEBUG - Print NEO color vars
    if (DebugSerial >= 2) {
      Serial.print(" C="); Serial.print(neo_col_red);
      Serial.print("/"); Serial.print(neo_col_grn);
      Serial.print("/"); Serial.print(neo_col_blu);
    }

    // DEBUG - Print LED mode
    if (DebugSerial >= 2) {
      Serial.print(" Mode="); Serial.print(main_led_mode);
    }

    // DEBUG - Print Carriage Return for iteration level debug output
    if (DebugSerial >= 2) {
      Serial.println();
    }

    // Display Neopixel values
    neo_show();

    // Pause the loop to display everything
    delay(LEDDelayTime);

    // END OF FOR ITERATION LOOP
  }
  // //////////////////////////////////
  //     END OF ITERATION LOOP
  // //////////////////////////////////

  // Touch Loop Counters - USE TBD
  if (Touch01_IntCount == 1) { Touch01_LoopCount++; Touch01_IntCount = 0; } else { Touch01_LoopCount = 0; }
  if (Touch02_IntCount == 1) { Touch02_LoopCount++; Touch02_IntCount = 0; } else { Touch02_LoopCount = 0; }
  if (Touch03_IntCount == 1) { Touch03_LoopCount++; Touch03_IntCount = 0; } else { Touch03_LoopCount = 0; }
  if (Touch04_IntCount == 1) { Touch04_LoopCount++; Touch04_IntCount = 0; } else { Touch04_LoopCount = 0; }

  // Turn off all LEDs at end of loop (Optional)
  // ledAllOff();

  // //////////////////////////////////////////////////
  //
  // Launch REACTION TIME GAME Alternate Mainline Code When
  // Touch01_LoopCount exceeds Touch01_Loop_Threshold
  //
  // //////////////////////////////////////////////////
  if (Touch01_LoopCount > Touch01_Loop_Threshold) {
    //
    Serial.println("LONG TOUCH DETECTED on TCH01 - JUMP TO ALTERNATE CODE");
    //
    ledAllOff();
    //
    Touch01_LoopCount = 0;
    //
    // Alternate code loop
    //reaction_time_game();
    //
    // END ALTERNATE MAIN LOOP
    Serial.println("****************************************");
    Serial.println("****** EXITING REACTION TIME GAME ******");
    Serial.println("****************************************");
    //
    ledAllOff();
    //
    Touch01_LoopCount = 0;
    //
    main_led_mode = 0;
    // Pause before exiting
    delay(100);
  }

  // //////////////////////////////////////////////////
  //
  // Launch BATT_CHRG_NOLED Alternate Mainline Code When
  // Touch02_LoopCount exceeds Touch02_Loop_Threshold
  //
  // //////////////////////////////////////////////////
  if (Touch02_LoopCount > Touch02_Loop_Threshold) {
    //
    Serial.println("LONG TOUCH DETECTED on TCH02 - JUMP TO ALTERNATE CODE");
    //
    ledAllOff();
    //
    Touch02_LoopCount = 0;
    //
    // Alternate code loop
    //batt_chrg_noled();
    //
    // END ALTERNATE MAIN LOOP
    Serial.println("****************************************");
    Serial.println("***** EXITING BATT_CHRG_NOLED MODE *****");
    Serial.println("****************************************");
    //
    ledAllOff();
    //
    Touch02_LoopCount = 0;
    //
    main_led_mode = 0;
    // Pause before exiting
    delay(100);
  }

  // //////////////////////////////////////////////////
  //
  // Launch CVD ADVENTURE GAME Alternate Mainline Code When
  // Touch04_LoopCount exceeds Touch04_Loop_Threshold
  //
  // //////////////////////////////////////////////////
  if (Touch04_LoopCount > Touch04_Loop_Threshold) {
    //
    Serial.println("LONG TOUCH DETECTED on TCH04 - JUMP TO ALTERNATE CODE");
    //
    ledAllOff();
    //
    Touch04_LoopCount = 0;
    //
    //
    // Alternate code loop
    //
    // Pause before turning on wifi
    delay(200);
    // Turn on wifi in ap mode
    wakeModemSleep();
    // Long Pause before launching alternate code to allow wifi to come active
    delay(4000);
    // Show Wifi Status
    Serial.println(" WiFi Status: "); Serial.println(wl_status_to_string(WiFi.status()));
    // Launch CVD ADVENTURE GAME alternate main line code
    //cvdAdventureMain();
    //flush_card_game();
    //
    // END ALTERNATE MAIN LOOP
    Serial.println("****************************************");
    Serial.println("*** EXITING CVD ADVENTURE GAME MODE ****");
    Serial.println("****************************************");
    //
    // Turn Off Wifi
    setModemSleep();
    // Pause after turning off wifi
    delay(500);
    //
    ledAllOff();
    //
    Touch04_LoopCount = 0;
    //
    main_led_mode = 0;
    // Pause before exiting
    delay(100);
  }

}
// //////////////////////////////////
//        END OF MAIN LOOP
// //////////////////////////////////


// //////////////////////////////////////////////////
//
// FUNCTIONS
//
// //////////////////////////////////////////////////
//
// WiFi & BT Functions
// //////////////////////////////////////////////////
void disableWiFi(){
    WiFi.disconnect(true);  // Disconnect from the network
    WiFi.mode(WIFI_OFF);    // Switch WiFi off
    Serial.println("WiFi disabled!");
}
//
void disableBluetooth(){
    btStop();
    Serial.println("Bluetooth stopped!");
}
//
void setModemSleep() {
    disableWiFi();
    disableBluetooth();
    setCpuFrequencyMhz(80);
}
//
void enableWiFi(){
    delay(200);
    // Switch Wifi ON in mode AP/STA/AP_STA
    WiFi.mode(WIFI_AP); // Defaulting to AP mode
    delay(200);
    Serial.println("WiFi Started!");
}
//
void wakeModemSleep() {
    setCpuFrequencyMhz(240);
    enableWiFi();
}
// //////////////////////////////////////////////////
//
// LED Functions
// //////////////////////////////////////////////////
void ledAllOff() {
  digitalWrite(LED_BI, HIGH); // HIGH = OFF?
  ledcWrite(LED_D1_pwm, 0);
  ledcWrite(LED_D2_pwm, 0);
  ledcWrite(LED_D3_pwm, 0);
  ledcWrite(LED_D4_pwm, 0);
  ledcWrite(LED_D5_pwm, 0);
  ledcWrite(LED_D6_pwm, 0);
  ledcWrite(LED_D7_pwm, 0);
  ledcWrite(LED_D8_pwm, 0);
  NEO01.setPixelColor(0, 0, 0, 0);
  NEO01.setPixelColor(1, 0, 0, 0);
  NEO01.setPixelColor(2, 0, 0, 0);
  NEO01.setPixelColor(3, 0, 0, 0);
  NEO01.show();
  NEO02.setPixelColor(0, 0, 0, 0);
  NEO02.setPixelColor(1, 0, 0, 0);
  NEO02.setPixelColor(2, 0, 0, 0);
  NEO02.setPixelColor(3, 0, 0, 0);
  NEO02.show();
}
//
void ledPwmAllOn() {
    ledcWrite(LED_D1_pwm, 255);
    ledcWrite(LED_D2_pwm, 255);
    ledcWrite(LED_D3_pwm, 255);
    ledcWrite(LED_D4_pwm, 255);
    ledcWrite(LED_D5_pwm, 255);
    ledcWrite(LED_D6_pwm, 255);
    ledcWrite(LED_D7_pwm, 255);
    ledcWrite(LED_D8_pwm, 255);
}
//
void ledPwmAllOff() {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
}
//
void setRandomColor() {
  // Basic Random numbers for on/off
  int colorrand41 = random(0-4); int colorrand42 = random(0-4); int colorrand43 = random(0-4);
  int colorrand4t = colorrand41 + colorrand42 + colorrand43;
  // Reset colors
  neo_col_whi = 0;
  neo_col_red = 0;
  neo_col_grn = 0;
  neo_col_blu = 0;
  // Set Red
  if (colorrand4t > 3) { neo_col_red = random(50, 255); }
  // Set Blue
  if (neo_col_red == 0 and colorrand4t > 1) { neo_col_blu = random(50, 255); } else if (colorrand4t > 3) { neo_col_blu = random(50, 255); }
  // Set Green
  if (neo_col_blu == 0 and colorrand4t > 3) { neo_col_grn = random(50, 255); } else if (colorrand4t > 5) { neo_col_grn = random(50, 255); }
  // Make sure at least one color is not zero
  if ((neo_col_red + neo_col_grn + neo_col_blu) == 0) { neo_col_red = 255; }
  // Set Color
  neo_big_color = (neo_col_whi << 24) + (neo_col_red << 16) + (neo_col_grn << 8) + neo_col_blu;
}
//
void setStaticColor(uint8_t sred, uint8_t sgrn, uint8_t sblu) {
  // Define colors
  neo_col_whi = 0;
  neo_col_red = sred;
  neo_col_grn = sgrn;
  neo_col_blu = sblu;
  // Make sure at least one color is not zero
  if ((neo_col_red + neo_col_grn + neo_col_blu) == 0) { neo_col_red = 255; }
  // Set Color
  neo_big_color = (neo_col_whi << 24) + (neo_col_red << 16) + (neo_col_grn << 8) + neo_col_blu;
}
//
void ledPwmTest(uint8_t pos, uint8_t pass) {
  // Pass 1&2 pos 0-84
  //
  // Pass 3 pos 0-42, make it 0-84
  if (pass == 3){ pos = pos * 2; }
  // Pass 4 pos 43-84, make it 0-84
  if (pass == 4){ pos = (pos - 42) * 2; }
  //
  if (pos <= 10) {
    ledcWrite(LED_D1_pwm, 255);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 10 and pos <= 20) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 255);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 20 and pos <= 30) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 255);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 30 and pos <= 40) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 255);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 40 and pos <= 50) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 255);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 50 and pos <= 60) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 255);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 60 and pos <= 70) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 255);
    ledcWrite(LED_D8_pwm, 0);
  } else if (pos > 70 and pos <= 80) {
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 255);
  } else { 
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
  }
}
//
void ledPwmDefault(uint8_t pos, uint8_t pass) {
  // lightlevel var used to set the pwm value
  uint8_t lightlevel = 0;
  if (pass == 1){
    if (pos <= 42) { lightlevel = (pos *6); }
    if (pos > 42) { lightlevel = 255 - (pos *6); }
    ledcWrite(LED_D5_pwm, int(lightlevel));
  }
  if (pass == 2){
    if (pos <= 42) { lightlevel = (pos *6); }
    if (pos > 42) { lightlevel = 255 - (pos *6); }
    ledcWrite(LED_D7_pwm, int(lightlevel));
    ledcWrite(LED_D8_pwm, int(lightlevel));
  }
  if (pass == 3){
    if (pos <= 42) { lightlevel = (pos *6); }
    if (pos > 42) { lightlevel = 255 - (pos *6); }
    ledcWrite(LED_D6_pwm, int(lightlevel));
  }
  ledcWrite(LED_D1_pwm, 0);
  ledcWrite(LED_D2_pwm, 0);
  ledcWrite(LED_D3_pwm, 0);
  ledcWrite(LED_D4_pwm, 0);
}
//
void neo_show() {
  // Display neopixel colors set by other functions
  NEO01.show();
  NEO02.show();
}
//
void neo_test(uint8_t pos, uint8_t pass) {
  //
  // Pass 1 pos 0-84
  if (pass == 1){
    // Red
    NEO01.setPixelColor(0, 255, 0, 0);
    NEO01.setPixelColor(1, 255, 0, 0);
    NEO01.setPixelColor(2, 255, 0, 0);
    NEO01.setPixelColor(3, 255, 0, 0);
    NEO02.setPixelColor(0, 255, 0, 0);
    NEO02.setPixelColor(1, 255, 0, 0);
    NEO02.setPixelColor(2, 255, 0, 0);
    NEO02.setPixelColor(3, 255, 0, 0);
  }
  // Pass 2 pos 0-84
  if (pass == 2){
    // Green
    NEO01.setPixelColor(0, 0, 255, 0);
    NEO01.setPixelColor(1, 0, 255, 0);
    NEO01.setPixelColor(2, 0, 255, 0);
    NEO01.setPixelColor(3, 0, 255, 0);
    NEO02.setPixelColor(0, 0, 255, 0);
    NEO02.setPixelColor(1, 0, 255, 0);
    NEO02.setPixelColor(2, 0, 255, 0);
    NEO02.setPixelColor(3, 0, 255, 0);
  }
  // Pass 3 pos 0-84
  if (pass == 3){
    // Blue
    NEO01.setPixelColor(0, 0, 0, 255);
    NEO01.setPixelColor(1, 0, 0, 255);
    NEO01.setPixelColor(2, 0, 0, 255);
    NEO01.setPixelColor(3, 0, 0, 255);
    NEO02.setPixelColor(0, 0, 0, 255);
    NEO02.setPixelColor(1, 0, 0, 255);
    NEO02.setPixelColor(2, 0, 0, 255);
    NEO02.setPixelColor(3, 0, 0, 255);
  }
}

//
void g0dz_blast(uint8_t pos, uint8_t pass) {
  //
  // Pass 1-3 pos 0-84
  if (pass < 4){
    NEO01.setPixelColor(0, 0, 0, 0);
    NEO01.setPixelColor(1, 0, 0, 0);
    NEO01.setPixelColor(2, 0, 0, 0);
    NEO02.setPixelColor(0, 0, 0, 0);
    NEO02.setPixelColor(1, 0, 0, 0);
    NEO02.setPixelColor(2, 0, 0, 0);
    NEO02.setPixelColor(3, 0, 0, 0);
    NEO01.setPixelColor(3, 0, 0, 0);
    // regular leds
    ledcWrite(LED_D1_pwm, 0);
    ledcWrite(LED_D2_pwm, 0);
    ledcWrite(LED_D3_pwm, 0);
    ledcWrite(LED_D4_pwm, 0);
    ledcWrite(LED_D5_pwm, 0);
    ledcWrite(LED_D6_pwm, 0);
    ledcWrite(LED_D7_pwm, 0);
    ledcWrite(LED_D8_pwm, 0);
    if (pos <= 5) {
      NEO02.setPixelColor(0, neo_big_color);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D2_pwm, 255);
    } else if (pos > 5 and pos <= 10) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, neo_big_color);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D3_pwm, 255);
    } else if (pos > 10 and pos <= 15) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, neo_big_color);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D4_pwm, 255);
    } else if (pos > 15 and pos <= 20) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, neo_big_color);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D2_pwm, 255);
    } else if (pos > 20 and pos <= 25) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, neo_big_color);
      ledcWrite(LED_D3_pwm, 255);
    } else if (pos > 25 and pos <= 30) {
      NEO02.setPixelColor(0, neo_big_color);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D4_pwm, 255);
    } else if (pos > 30 and pos <= 35) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, neo_big_color);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D2_pwm, 255);
    } else if (pos > 35 and pos <= 40) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, neo_big_color);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D3_pwm, 255);
    } else if (pos > 40 and pos <= 45) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, neo_big_color);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D4_pwm, 255);
    } else if (pos > 45 and pos <= 50) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, neo_big_color);
      ledcWrite(LED_D2_pwm, 255);
    } else if (pos > 50 and pos <= 55) {
      NEO02.setPixelColor(0, neo_big_color);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D3_pwm, 255);
    } else if (pos > 55 and pos <= 60) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, neo_big_color);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D4_pwm, 255);
    } else if (pos > 60 and pos <= 65) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, neo_big_color);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D2_pwm, 255);
    } else if (pos > 65 and pos <= 70) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, neo_big_color);
      NEO01.setPixelColor(3, 0, 0, 0);
      ledcWrite(LED_D3_pwm, 255);
    } else if (pos > 70 and pos <= 75) {
      NEO02.setPixelColor(0, 0, 0, 0);
      NEO02.setPixelColor(1, 0, 0, 0);
      NEO02.setPixelColor(2, 0, 0, 0);
      NEO02.setPixelColor(3, 0, 0, 0);
      NEO01.setPixelColor(3, neo_big_color);
      ledcWrite(LED_D4_pwm, 255);
    } else if (pos > 75 and pos <= 78) {
      NEO01.setPixelColor(0, neo_big_color);
      NEO01.setPixelColor(1, neo_big_color);
      NEO01.setPixelColor(2, neo_big_color);
      ledcWrite(LED_D1_pwm, 255);
      ledcWrite(LED_D5_pwm, 255);
      ledcWrite(LED_D6_pwm, 255);
    } else if (pos > 78 and pos <= 81) {
      NEO01.setPixelColor(0, 0, 0, 0);
      NEO01.setPixelColor(1, 0, 0, 0);
      NEO01.setPixelColor(2, 0, 0, 0);
      ledcWrite(LED_D1_pwm, 100);
      ledcWrite(LED_D5_pwm, 100);
      ledcWrite(LED_D6_pwm, 100);
    } else if (pos > 81) {
      NEO01.setPixelColor(0, neo_big_color);
      NEO01.setPixelColor(1, neo_big_color);
      NEO01.setPixelColor(2, neo_big_color);
      ledcWrite(LED_D1_pwm, 255);
      ledcWrite(LED_D5_pwm, 255);
      ledcWrite(LED_D6_pwm, 255);
    }
  }
}
//
void eyes_neo_colorshift(uint8_t pos, uint8_t pass) {
  // Pass 1 pos 0-84
  if (pass == 1){
    // Blue 255-0 Red 0-255
    NEO01.setPixelColor(1, int(pos*3), 0, int(255 - pos*3));
    NEO01.setPixelColor(2, int(pos*3), 0, int(255 - pos*3));
  }
  // Pass 2 pos 0-84
  if (pass == 2){
    // Red 255-0 Green 0-255
    NEO01.setPixelColor(1, int(255 - (pos*3)), int(pos*3), 0);
    NEO01.setPixelColor(2, int(255 - (pos*3)), int(pos*3), 0);
  }
  // Pass 3 pos 0-84
  if (pass == 3){
    // Green 255-0 Blue 0-255
    NEO01.setPixelColor(1, 0, int(255 - (pos*3)), int(pos*3));
    NEO01.setPixelColor(2, 0, int(255 - (pos*3)), int(pos*3));
  }
}
//
void g0dz_neo_colorshift(uint8_t pos, uint8_t pass) {
  // Pass 1 pos 0-84
  if (pass == 1){
    // Blue 255-0 Red 0-255
    NEO01.setPixelColor(0, int(pos*3), 0, int(255 - pos*3));
    NEO02.setPixelColor(2, int(pos*3), 0, int(255 - pos*3));
    // Red 255-0 Green 0-255
    NEO02.setPixelColor(0, int(255 - (pos*3)), int(pos*3), 0);
    NEO02.setPixelColor(3, int(255 - (pos*3)), int(pos*3), 0);
    // Green 255-0 Blue 0-255
    NEO02.setPixelColor(1, 0, int(255 - (pos*3)), int(pos*3));
    NEO01.setPixelColor(3, 0, int(255 - (pos*3)), int(pos*3));
  }
  // Pass 2 pos 0-84
  if (pass == 2){
    // Blue 255-0 Red 0-255
    NEO02.setPixelColor(1, int(pos*3), 0, int(255 - pos*3));
    NEO01.setPixelColor(3, int(pos*3), 0, int(255 - pos*3));
    // Red 255-0 Green 0-255
    NEO01.setPixelColor(0, int(255 - (pos*3)), int(pos*3), 0);
    NEO02.setPixelColor(2, int(255 - (pos*3)), int(pos*3), 0);
    // Green 255-0 Blue 0-255
    NEO02.setPixelColor(0, 0, int(255 - (pos*3)), int(pos*3));
    NEO02.setPixelColor(3, 0, int(255 - (pos*3)), int(pos*3));
  }
  // Pass 3 pos 0-84
  if (pass == 3){
    // Blue 255-0 Red 0-255
    NEO02.setPixelColor(0, int(pos*3), 0, int(255 - pos*3));
    NEO02.setPixelColor(3, int(pos*3), 0, int(255 - pos*3));
    // Red 255-0 Green 0-255
    NEO02.setPixelColor(1, int(255 - (pos*3)), int(pos*3), 0);
    NEO01.setPixelColor(3, int(255 - (pos*3)), int(pos*3), 0);
    // Green 255-0 Blue 0-255
    NEO01.setPixelColor(0, 0, int(255 - (pos*3)), int(pos*3));
    NEO02.setPixelColor(2, 0, int(255 - (pos*3)), int(pos*3));
  }
}
//
void BI_on() {
  digitalWrite(LED_BI, LOW); // LOW = ON?
}
//
void BI_off() {
  digitalWrite(LED_BI, HIGH); // HIGH = OFF?
}
//
void BI_blink_one(uint8_t pos) {
  if (pos <= 21) {
    digitalWrite(LED_BI, LOW); // LOW = ON?
  } else {
    digitalWrite(LED_BI, HIGH); // HIGH = OFF?
  }
}
//
void BI_blink_two(uint8_t pos) {
  if (pos <= 11) {
    digitalWrite(LED_BI, LOW); // LOW = ON?
  } else if (pos > 11 and pos <= 22) {
    digitalWrite(LED_BI, HIGH); // HIGH = OFF?
  } else if (pos > 22 and pos <= 33) {
    digitalWrite(LED_BI, LOW); // LOW = ON?
  } else {
    digitalWrite(LED_BI, HIGH); // HIGH = OFF?
  }
}
//
void batt_chrg_noled() {
  // Set an exit var
  bool batt_chrg_noled_active = true;
  //
  while (batt_chrg_noled_active) {
    BI_off();
    // Print Serial Message About Mode
    Serial.println("****************************************");
    Serial.println("****************************************");
    Serial.println("********* BATT_CHRG_NOLED MODE *********");
    Serial.println("****************************************");
    Serial.println("*** ACTIVATED BY LONG TOUCH ON TCH02 ***");
    Serial.println("***       THE LOGO SHAPE BUTTON      ***");
    Serial.println("****************************************");
    Serial.println("** LONG PRESS AGAIN TO EXIT THIS MODE **");
    Serial.println("****************************************");
    Serial.println("****************************************");
    // Pause
    delay(3500);
    // Turn on-board LED on briefly to show badge is still on
    BI_on();
    // Pause
    delay(500);
    //
    // Touch for exit mode settings
    //
    Touch02_Value = touchRead(TCH02_PIN);
    // Do Stuff If We Detect a Touch on TCH02_PIN
    if (Touch02_Value < Touch02_Threshold) {
      // DEBUG - Print current Touch value/threshold to serial console for troubleshooting
      if (DebugSerial >= 2) {
        Serial.print("T2_TCH="); Serial.print(Touch02_Value);
        Serial.print("/"); Serial.print(Touch02_Threshold);
        Serial.print("-"); Serial.println(Touch02_LoopCount);
      }
      // STUFF - TCH02_PIN TOUCHED
      Touch02_LoopCount++;
    //
    // Do Stuff If We DONT Detect a Touch on TCH02_PIN
    } else {
      // STUFF - TCH02_PIN NOT TOUCHED
      Touch02_LoopCount = 0;
    }
    if (Touch02_LoopCount > Touch02_Loop_Threshold) {
      batt_chrg_noled_active = false;
    }
  }
}
