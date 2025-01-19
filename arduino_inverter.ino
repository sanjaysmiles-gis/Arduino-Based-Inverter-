/*
 * Arduino-Based DC to AC Inverter
 * 
 * This code implements a DC to AC inverter using Arduino PWM signals to control
 * two transistors in a push-pull configuration. The circuit converts 12V DC to AC
 * using PWM modulation at 50Hz frequency.
 * 
 * Circuit Components:
 * - Arduino Uno/Nano
 * - 2x 2N3904 NPN transistors (Q1, Q2)
 * - 2x 1.5 kΩ resistors
 * - Center-tapped transformer
 * - 2x 100 µF capacitors
 * 
 * Pin Configuration:
 * - Pin D9: Connected to Base of Q1 through 1.5 kΩ resistor
 * - Pin D10: Connected to Base of Q2 through 1.5 kΩ resistor
 */

// Define the PWM pins connected to the bases of Q1 and Q2
const int pwmPinQ1 = 9;  // Pin connected to Base of Q1 through 1.5 kΩ resistor
const int pwmPinQ2 = 10; // Pin connected to Base of Q2 through 1.5 kΩ resistor

// Set the frequency for PWM (50 Hz for inverter-like AC signal)
const int frequency = 50;  // 50 Hz frequency (AC mains frequency)

void setup() {
  // Set the pins as output
  pinMode(pwmPinQ1, OUTPUT);
  pinMode(pwmPinQ2, OUTPUT);

  // Start with both transistors off
  digitalWrite(pwmPinQ1, LOW);
  digitalWrite(pwmPinQ2, LOW);

  // Set PWM pins to 50 Hz (Arduino Uno defaults to 490Hz or 976Hz, which can be overridden using timers)
  // To set the PWM frequency to 50Hz, we will need to use a direct timer manipulation

  // Set PWM frequency for pin 9 and 10
  setPwmFrequency(pwmPinQ1, 50);
  setPwmFrequency(pwmPinQ2, 50);
}

void loop() {
  // Continuously toggle the output to create the push-pull configuration

  // Turn on Q1 and off Q2 (one cycle)
  digitalWrite(pwmPinQ1, HIGH);
  digitalWrite(pwmPinQ2, LOW);
  delay(10);  // Keep Q1 on for 10ms

  // Turn off Q1 and on Q2 (next cycle)
  digitalWrite(pwmPinQ1, LOW);
  digitalWrite(pwmPinQ2, HIGH);
  delay(10);  // Keep Q2 on for 10ms

  // This loop creates the alternating signal at 50Hz
}

// Function to adjust the PWM frequency for the Arduino pins
void setPwmFrequency(int pin, int frequency) {
  if (pin == 9 || pin == 10) {
    // For pins 9 and 10 (Arduino Uno), we can modify the Timer1 settings.
    // This will change the PWM frequency to around 50Hz
    int prescaler = 256;
    long pwmPeriod = 16000000L / (prescaler * frequency);
    
    // Set the PWM frequency for pin 9 and 10 using direct timer control
    if (pin == 9) {
      TCCR1B = (TCCR1B & 0xF8) | 0x01;  // Reset to a prescaler of 1
      OCR1A = pwmPeriod - 1;  // Set the PWM period for pin 9
    } else if (pin == 10) {
      TCCR1B = (TCCR1B & 0xF8) | 0x01;  // Reset to a prescaler of 1
      OCR1B = pwmPeriod - 1;  // Set the PWM period for pin 10
    }
  }
}
