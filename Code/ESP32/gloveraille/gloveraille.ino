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

  }
}

void loop() {
  
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

  
}
