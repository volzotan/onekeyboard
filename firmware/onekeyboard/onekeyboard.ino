#include "Keyboard.h"

#ifdef DEBUG
  #define DEBUG_PRINT(x) SerialUSB.print("["); SerialUSB.print(millis()/1000); SerialUSB.print("] "); SerialUSB.println (x)
#else
  #define DEBUG_PRINT(x)
#endif

// ---------------------------------------------

#define DEBUG

#define START_DELAY 5000

#define PIN_BUTTON  10 // PA18
#define PIN_LED     A5 // PB02

// ---------------------------------------------

int buttonPrevState = LOW;

void setup() {

    SerialUSB.begin(9600);

    DEBUG_PRINT("INIT");

    pinMode(PIN_BUTTON,  INPUT);
    pinMode(PIN_LED,     OUTPUT);

    delay(START_DELAY);

    // #ifdef DEBUG
    //     while (!SERIAL_PORT) {;}
    //     DEBUG_PRINT("INIT 2");
    // #endif


    Keyboard.begin();
    // Keyboard.end();
}

void loop() {

    int button = digitalRead(PIN_BUTTON);

    if (buttonPrevState == LOW && button == HIGH) {

        // Keyboard.press('b');
        // delay(10);
        // Keyboard.releaseAll();
        // delay(500);

        Keyboard.press(KEY_LEFT_CTRL);
        delay(10);
        Keyboard.press(KEY_LEFT_GUI);
        delay(10);
        Keyboard.press('q');
        delay(10);
        Keyboard.releaseAll();
        delay(500);

        // SerialUSB.println(digitalRead(PIN_BUTTON));
    }

    buttonPrevState = button;
}
