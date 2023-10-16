# Temperature-Controlled Fan System

## Project Overview
This project is a Temperature-Controlled Fan System designed using the ATmega32 microcontroller. The system automatically controls a fan based on the temperature readings from an LM35 temperature sensor. The project is developed under the supervision of "Eng Mohamed Tarek" at "Edges for Training."

## Features
- Real-time temperature monitoring using an LM35 sensor.
- Precise temperature calculations within the microcontroller.
- Display of temperature readings on an LCD screen.
- Fan control based on temperature conditions:
  - <30°C: Fan is turned off.
  - ≥30°C: Fan operates at 25% speed.
  - ≥60°C: Fan operates at 50% speed.
  - ≥90°C: Fan operates at 75% speed.
  - ≥120°C: Fan operates at 100% speed.
- Fan control achieved through PWM signal generation.
- Layered software architecture: HAL, MCAL, Application layer.
- Implemented drivers for ADC, GPIO, LCD, Temperature Sensor, and DC-Motor.
- Detailed project documentation for reference.

## Repository Contents
- **/Source_Code:** Contains the source code for the project.
- **/Datasheets:** Datasheets related to components used in the project.
- **/Documentation:** Detailed project documentation and design files.

## Getting Started
1. Clone this repository to your local machine using:
git clone https://github.com/KareemMoneeam/Fan_Controller_System.git

2. Open the project source code in your preferred development environment (e.g., Atmel Studio, AVR-GCC).

3. Compile and program the code onto your ATmega32 microcontroller.

4. Connect the LM35 sensor, LCD, and DC-Motor according to the specified pin configurations.

5. Power on the system and observe the fan's temperature-controlled operation.

## Contact
For any questions or inquiries related to this project, please feel free to connect with me:
- Email: kareemmoneeam@outlook.com
- LinkedIn: (https://www.linkedin.com/in/KareemMoneeam/)

**Thank you for checking out the Temperature-Controlled Fan System project!**
