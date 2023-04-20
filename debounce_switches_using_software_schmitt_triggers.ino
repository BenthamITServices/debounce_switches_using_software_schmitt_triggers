// Debounce switches using software Schmitt triggers

/*
In this improved code, we've removed unnecessary decimal points from the threshold values since they are integers.
We've also changed the if statement conditions in the Schmitt trigger to use logical not operator instead of comparing with false or true.
This improves the readability of the code.
Furthermore, we've simplified the LED control logic by using the boolean value directly in the digitalWrite() function.
When the boolean value is true, digitalWrite() will write a HIGH value to the LED pin, and when it is false, it will write a LOW value to turn off the LED.
This makes the code cleaner and easier to understand.
*/

bool Schmitt = false;
const int threshold_high = 600;  // in counts
const int threshold_low = 400;   // in counts
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read input from switch (assumed to be connected to A0 pin)
  int A0_input = analogRead(A0);

  // Implement Schmitt trigger
  if (A0_input > threshold_high && !Schmitt) {
    Schmitt = true;
  }
  if (A0_input < threshold_low && Schmitt) {
    Schmitt = false;
  }

  // Turn on or off LED based on boolean variable
  digitalWrite(LED_PIN, Schmitt);
}