# Arduino Inverter: Working Principle

The Arduino-based inverter described in your summary operates by converting a low-voltage DC input (12V) into a high-voltage AC output (220V) using a combination of transistors, resistors, capacitors, and a transformer. Here's a detailed explanation of how it works:

## Working Principle

### 1. **Basic Operation**
The inverter utilizes two NPN transistors (Q1 and Q2) to create an alternating current (AC) output from a direct current (DC) source. The Arduino microcontroller controls the switching of these transistors, which alternately connect the transformer primary winding to the DC supply.

### 2. **Transistor Switching**
- **Transistors Q1 and Q2**: These act as electronic switches. The Arduino sends PWM signals to the bases of these transistors through 1.5 kΩ resistors connected to pins D9 and D10.
- When the Arduino outputs a HIGH signal on pin D9, Q1 turns ON, allowing current to flow from the 12V supply through Q1 into one end of the transformer primary winding.
- Simultaneously, when pin D10 is HIGH, Q2 turns ON, allowing current to flow through the other end of the transformer primary winding.

This switching creates a magnetic field in the transformer, which induces an AC voltage in the secondary winding.

### 3. **Capacitors for Stability**
- **C1 (100 µF)**: This capacitor smooths out fluctuations in the DC supply voltage, ensuring a stable input for the transistors.
- **C2 (100 µF)**: Placed across the primary winding of the transformer, this capacitor helps stabilize the switching current and reduces voltage spikes that could damage the transistors.

### 4. **Transformer Action**
The transformer steps up the voltage from 12V DC to 220V AC:
- The primary winding is connected to the collectors of Q1 and Q2.
- As Q1 and Q2 switch on and off alternately, they create an alternating magnetic field in the transformer core.
- This alternating magnetic field induces a voltage in the secondary winding of the transformer, resulting in an output voltage of approximately 220V AC.

### 5. **Output Measurement**
After building the circuit:
- The output from the secondary winding can be measured using a multimeter set to AC voltage mode.
- It is essential to ensure that all connections are secure and that safety precautions are followed when working with high voltages.

## Summary
In essence, this Arduino-based inverter works by using PWM signals to control two transistors that alternately connect a transformer to a DC power source. This setup converts low-voltage DC into high-voltage AC, making it suitable for powering AC devices from a DC source. The use of capacitors helps stabilize voltage levels during operation, ensuring efficient performance. Always remember to handle high voltages with care!
