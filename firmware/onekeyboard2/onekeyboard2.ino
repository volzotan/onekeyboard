#include "Keyboard.h"

#ifdef DEBUG
  #define DEBUG_PRINT(x) SerialUSB.print("["); SerialUSB.print(millis()/1000); SerialUSB.print("] "); SerialUSB.println (x)
#else
  #define DEBUG_PRINT(x)
#endif

// ---------------------------------------------

// #define DEBUG

#define START_DELAY 5  // in seconds

// pin mapping if treated as an Arduino Zero:

#define PIN_BUTTON  10 // PA18
#define PIN_LED     A5 // PB02

// ---------------------------------------------

int buttonPrevState = LOW;
int button;

void setup() {

    SerialUSB.begin(9600);

    DEBUG_PRINT("INIT");

    pinMode(PIN_BUTTON,  INPUT);
    pinMode(PIN_LED,     OUTPUT);

    for (int i=0; i<START_DELAY; i++) {
        digitalWrite(PIN_LED, HIGH);
        delay(500);
        digitalWrite(PIN_LED, LOW);
        delay(500);
    }

    #ifdef DEBUG
        while (!SERIAL_PORT) {;}
    #endif
}

void loop() {

    button = digitalRead(PIN_BUTTON);

    if (buttonPrevState == LOW && button == HIGH) {

        Keyboard.begin();

        digitalWrite(PIN_LED, HIGH);

        Keyboard.press(KEY_LEFT_CTRL);
        delay(10);
        Keyboard.press(KEY_LEFT_GUI);
        delay(10);
        Keyboard.press('q');
        delay(10);
        Keyboard.releaseAll();
        delay(500);

        digitalWrite(PIN_LED, LOW);

        Keyboard.end();
    }

    buttonPrevState = button;
}
