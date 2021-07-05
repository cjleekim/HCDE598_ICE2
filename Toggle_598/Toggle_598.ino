// Toggling example

/*
  Example of how to toggle (flip back and forth between on and off)
  the state of a variable.
  -- Andy Davidson
  -- adavid7@uw.edu

  This example uses the Button Library (see demo programs in that) to
  turn an LED on and off with each click of the button.

  See ButtonLib docs for how to connect a button to the the Arduino.

  Open the Serial Monitor window to see debugging trace messages.

  Modified for ESP32 6.30.21 Brock Craft
*/
#include <Button.h>

// define pin number for an LED as an indicator and the pin for the button
const int buttonPin = 14;     // the number of the pushbutton pin
const int ledPin =  32;      // the number of the LED pin

Button btn (buttonPin, INPUT_PULLUP);  // initializes the button

boolean lightsOn = false;  // indicates whether LED is currently on or off

void setup()
{
  // housekeeping
  Serial.begin(115200);
  Serial.println("\n\n*** starting toggle demo");
  pinMode(ledPin, OUTPUT);
}

void loop()
{

  // check the button state to see if it was clicked

  int action = btn.checkButtonAction();
  if (action == Button::CLICKED) {
    Serial.println("button clicked");

    // if it was, simply flip the state of the boolean (true/false)
    // variable that indicates whether the buzzer should be on or off.

    // "!" is the logical "not" operator that inverts a boolean variable
    // see  https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/

    lightsOn = ! lightsOn;

    Serial.print("LED is now: ");
    Serial.println(lightsOn);
  }

  // now simply set the LED on or off, depending on the current state

  if (lightsOn) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
