#include <IRremote.hpp>

// --- IR Receiver Pin ---
#define IR_PIN 11

// --- Button Codes ---
#define BTN_1    0x45
#define BTN_2    0x46
#define BTN_3    0x47
#define BTN_4    0x44
#define BTN_5    0x40
#define BTN_6    0x43
#define BTN_7    0x07
#define BTN_8    0x15
#define BTN_9    0x09
#define BTN_OKAY 0x1C  // function_10()

// --- Pin Definitions ---
#define PIN_1 2
#define PIN_2 3
#define PIN_3 4
#define PIN_4 5
#define PIN_5 6
#define PIN_6 7
#define PIN_7 8
#define PIN_8 13

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);
  pinMode(PIN_6, OUTPUT);
  pinMode(PIN_7, OUTPUT);
  pinMode(PIN_8, OUTPUT);
}

// --- Individual Button Functions ---
void function_1() {
  Serial.println("Button 1 - Pin 2 ON");
  analogWrite(PIN_1, 128);
}

void function_2() {
  Serial.println("Button 2 - Pin 3 ON");
  analogWrite(PIN_2, 128);
}

void function_3() {
  Serial.println("Button 3 - Pin 4 ON");
  analogWrite(PIN_3, 128);
}

void function_4() {
  Serial.println("Button 4 - Pin 5 ON");
  analogWrite(PIN_4, 128);
}

void function_5() {
  Serial.println("Button 5 - Pin 6 ON");
  analogWrite(PIN_5, 50);
}

void function_6() {
  Serial.println("Button 6 - Pin 7 ON");
  analogWrite(PIN_6, 50);
}

void function_7() {
  Serial.println("Button 7 - Pin 8 ON");
  analogWrite(PIN_7, 50);
}

void function_8() {
  Serial.println("Button 8 - Pin 9 ON");
  analogWrite(PIN_8, 50);
}



void function_10() {
  Serial.println("OKAY - All pins OFF");

  analogWrite(PIN_1, 0);
  analogWrite(PIN_2, 0);
  analogWrite(PIN_3, 0);
  analogWrite(PIN_4, 0);
  analogWrite(PIN_5, 0);
  analogWrite(PIN_6, 0);
  analogWrite(PIN_7, 0);
  analogWrite(PIN_8, 0);
}

void loop() {
  if (IrReceiver.decode()) {
    uint8_t code = IrReceiver.decodedIRData.command;

    switch (code) {
      case BTN_1:    function_1(); break;
      case BTN_2:    function_2(); break;
      case BTN_3:    function_3(); break;
      case BTN_4:    function_4(); break;
      case BTN_5:    function_5(); break;
      case BTN_6:    function_6(); break;
      case BTN_7:    function_7(); break;
      case BTN_8:    function_8(); break;
      case BTN_OKAY: function_10(); break;

      default:
        Serial.print("Unknown code: 0x");
        Serial.println(code, HEX);
    }

    IrReceiver.resume();
  }
}

