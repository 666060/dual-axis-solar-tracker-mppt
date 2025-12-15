# dual-axis-solar-tracker-mppt
A dual-axis solar tracker system with MPPT for maximum energy efficiency

## Overview
This project is a **dual-axis solar tracker** combined with a **Maximum Power Point Tracking (MPPT)** system for Arduino.  
The tracker automatically adjusts the position of solar panels to follow the sun and maximize energy efficiency.

---

## Features
- **Dual-axis solar tracking** using four LDR sensors.
- **MPPT P&O (Perturb & Observe) algorithm** to optimize solar panel output.
- Adjustable **sensitivity** and **speed** for smooth tracking.
- Real-time monitoring via **Serial Monitor**.

---

## Hardware Required
- Arduino UNO
- 2 Servo motors (for horizontal and vertical movement)
- 4 LDR sensors
- Voltage and current sensors for MPPT
- Solar panel
- Motor driver (if required)
- Jumper wires and breadboard

---

## Software
- Arduino IDE
- Libraries:
  - `Servo.h` for controlling servos

---

## Wiring
- **Servo Motors**
  - Horizontal servo → Pin 9
  - Vertical servo → Pin 10
- **LDR Sensors**
  - Top-left → A0
  - Top-right → A1
  - Bottom-left → A2
  - Bottom-right → A3
- **MPPT Sensors**
  - Voltage → A1
  - Current → A0
  - PWM Output → Pin 9

> Adjust the pin numbers according to your setup.

---

## How It Works
1. **Solar Tracking**
   - Reads LDR sensor values to determine the brightest direction.
   - Moves servos horizontally and vertically to align the panel with the sun.
2. **MPPT Algorithm**
   - Uses Perturb & Observe (P&O) method.
   - Continuously adjusts PWM to maintain maximum power output.
3. **Monitoring**
   - Prints voltage, current, power, and PWM duty cycle to Serial Monitor.

---

## Usage
1. Upload the Arduino code to your Arduino UNO.
2. Ensure all sensors and servos are connected properly.
3. Open the Serial Monitor at 9600 baud to observe MPPT readings.
4. Adjust the LDR sensitivity and servo speed if needed (via A4 and A5 pins).

---

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## Contributors

- [Fatma Mohsen El Saber](https://www.linkedin.com/in/fatma-elsaber-9ab1b830b?utm_source=share_via&utm_content=profile&utm_medium=member_android)  
- [Sama Mohamed Rashad](https://www.linkedin.com/in/sama-mohamed-005425357?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)  
- [Zamzam Ali Sarhan](https://www.linkedin.com/in/zamzam-ali-6314b4372?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BMtnGzqh3TPiQYCLysbAGTw%3D%3D)  
- [Aisha Bilal Ibrahim]([https://www.linkedin.com/in/aisha-belal-10b78b376?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app) 
- [Hoda Mahmoud Shalaby](https://www.linkedin.com/in/hoda-mahmoud-b3327736b?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)  
- [Fatma Nagah Abdel Azim](https://www.linkedin.com/in/fatma-nagah-b437a236b?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)  
- [Fatma Emad Eldin]([https://www.linkedin.com/in/fatema-emad/](https://www.linkedin.com/in/fatma-emad228?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=ios_app))  
- [Nasreen Ashraf Al-Omari](https://www.linkedin.com/in/nesreen-elemairy-a9078635a?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)  


