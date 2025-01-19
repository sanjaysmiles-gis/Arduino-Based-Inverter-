# Arduino-Based Inverter: DC to AC Conversion

## Technical Overview

This repository contains a comprehensive technical analysis and implementation details for an Arduino-based DC to AC inverter system, capable of converting 12V DC to  AC using PWM (Pulse Width Modulation) Using Arduino.

## Circuit Analysis

### Core Components Technical Specifications

#### 1. Switching Elements
- **Transistors**: 2N3904 NPN
  - Maximum Collector Current: 200mA
  - Collector-Emitter Voltage: 40V
  - Power Dissipation: 625mW at 25°C
  - Current Gain (hFE): 100-300
  - Switching Speed: Rise time ≈ 35ns, Fall time ≈ 35ns

#### 2. Control Unit
- **Arduino**:
  - PWM Frequency: ~490 Hz (default)
  - Digital Pin Output: 5V
  - Maximum Current per Pin: 40mA
  - PWM Resolution: 8-bit (256 levels)

#### 3. Passive Components
- **Base Resistors**: 1.5kΩ ±5%
  - Power Rating: 0.25W
  - Current Limitation: ~2.33mA (I = (5V - 0.7V)/1.5kΩ)

- **Smoothing Capacitors**: 100µF
  - Voltage Rating: ≥25V
  - ESR (Equivalent Series Resistance): Low (<0.5Ω)
  - Ripple Current Rating: >500mA

### Circuit Operation Analysis

#### 1. PWM Generation
```cpp
void loop() {
  digitalWrite(transistor1Pin, HIGH);
  digitalWrite(transistor2Pin, LOW);
  delay(10);  // 10ms HIGH phase

  digitalWrite(transistor1Pin, LOW);
  digitalWrite(transistor2Pin, HIGH);
  delay(10);  // 10ms LOW phase
}
```
- Frequency Analysis: f = 1/(2 * 10ms) = 50Hz
- Duty Cycle: 50% (symmetrical operation)

#### 2. Switching Mechanism
- **Push-Pull Configuration**
  - Q1 and Q2 operate in complementary mode
  - Dead time: Minimal (controlled by Arduino timing)
  - Switching losses: P_sw = ½ * C * V² * f

#### 3. Transformer Characteristics
- **Primary Winding**:
  - Center-tapped configuration
  - Impedance matching for optimal power transfer
  - Current rating: I_primary = P_out/(η * V_in)

- **Secondary Winding**:
  - Step-up ratio ≈ 18.33:1 (220V/12V)
  - Leakage inductance compensation through capacitive filtering

## Safety Considerations

### High Voltage Safety
1. **Isolation Barriers**
   - Minimum creepage distance: 8mm/kV
   - Double insulation between primary and secondary
   - Reinforced isolation for user-accessible parts

2. **Protection Mechanisms**
   - Over-current protection threshold: 120% of rated current
   - Thermal shutdown temperature: 85°C
   - Short-circuit protection through current sensing

## Future Enhancements

1. **Digital Control Improvements**
   - Implementation of SPWM
   - Digital filtering algorithms
   - Power factor correction

2. **Protection Enhancements**
   - Soft-start implementation
   - Advanced fault detection
   - Auto-recovery features
