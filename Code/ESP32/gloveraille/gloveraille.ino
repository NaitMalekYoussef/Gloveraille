/**
   This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
*/
#include <BleKeyboard.h>





//BleKeyboard bleKeyboard;
BleKeyboard bleKeyboard("Gloveraille", "USF111", 100);

// array that will hold the user input
int alpha[6] = {0};
int x=0;
int pins[9] = {18, 4, 12, 13, 14, 15, 25, 26, 27}; //array with only the used pins


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  //only set the used pins as input with pullups
  for (int p : pins) {
    pinMode(p, INPUT_PULLUP);

    // attachInterrupt(p, ISR, FALLING);
  }
}

void ISR() {
  for (int p : pins )
    if (!digitalRead(p)) {
      delay(1000);
      // if the GPIO pin is <8 then the user is still taping the letter
      if (p < 16)
        update_letter(p);

      // if the GPIO pin is 11 then the user want to show a character
      if (p == 27)
        print_letter('a');  // a for alphabet and n for numbers

      // if the GPIO pin is 12 then the user want to show a number
      if (p == 26)
        print_letter('n');  // a for alphabet and n for numbers

      // if the GPIO pin is 13 then the user want to edit the character or press the Enter button
      if (p == 25)
        print_letter('e');
    }

  delay(1000);

}
void loop() {
  /*if(bleKeyboard.isConnected()) {
    Serial.println("Sending 'Hello world'...");
    bleKeyboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    //
    // Below is an example of pressing multiple keyboard modifiers
    // which by default is commented out.

    }*/
  for (int p : pins )
    if (!digitalRead(p)) {
      delay(500);
      // if the GPIO pin is <8 then the user is still taping the letter
      if (p < 16)
        update_letter(p);

      // if the GPIO pin is 11 then the user want to show a character
      if (p == 27)
        print_letter('a');  // a for alphabet and n for numbers

      // if the GPIO pin is 12 then the user want to show a number
      if (p == 26)
        print_letter('n');  // a for alphabet and n for numbers

      // if the GPIO pin is 13 then the user want to edit the character or press the Enter button
      if (p == 25)
        print_letter('e');
    }

  delay(10);

  //Serial.println("Waiting 5 seconds...");
  //delay(5000);
}

/*
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
*/
