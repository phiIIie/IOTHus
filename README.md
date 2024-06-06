# Project README

## Project Overview

This project utilizes an OLED display, DHT11 sensor, and an RTC module to display the current time, date, temperature, and humidity. The user can navigate between different display modes using two buttons. The project is built using Arduino, and it leverages several libraries to facilitate the functionalities of the components.

## Libraries and Versions

The following libraries are used in this project:

- **SPI** (comes with Arduino IDE)
- **Wire** (comes with Arduino IDE)
- **Adafruit GFX Library** (version 1.10.10)
- **Adafruit SSD1306** (version 2.5.7)
- **DHT sensor library** (version 1.4.1)
- **RTClib** (version 1.12.5)

Ensure you have these libraries installed in your Arduino IDE. You can install them via the Library Manager in the Arduino IDE.

## Installation

1. **Install the required libraries:**
   - Open the Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries...**
   - Search for each library listed above and click "Install" for each.

2. **Connect the hardware components:**
   - **OLED Display:**
     - Connect VCC to 3.3V
     - Connect GND to GND
     - Connect SCL to A5 (or the corresponding I2C SCL pin on your board)
     - Connect SDA to A4 (or the corresponding I2C SDA pin on your board)
   - **DHT11 Sensor:**
     - Connect VCC to 5V
     - Connect GND to GND
     - Connect Data Pin to Digital Pin 3
   - **RTC Module:**
     - Connect VCC to 5V
     - Connect GND to GND
     - Connect SCL to A5 (or the corresponding I2C SCL pin on your board)
     - Connect SDA to A4 (or the corresponding I2C SDA pin on your board)
   - **Buttons:**
     - Connect one side of each button to GND
     - Connect the other side of Button 1 to Digital Pin 5
     - Connect the other side of Button 2 to Digital Pin 6

3. **Upload the code to the Arduino:**
   - Open the Arduino IDE.
   - Copy and paste the provided code into a new sketch.
   - Connect your Arduino board to your computer.
   - Select the correct board and port from the **Tools** menu.
   - Click the **Upload** button.

## Functionality

### Display Modes

The project has two main display modes:

1. **Time/Date Mode:**
   - Displays the current time in HH:MM:SS format.
   - Displays the current day of the week.
   - Displays the current date in DD/MM/YYYY format.

2. **Temperature/Humidity Mode:**
   - Displays the current temperature in Celsius.
   - Displays the current humidity percentage.

### Navigation

- **Button 1:** Navigate up through the menu options.
- **Button 2:** Navigate down through the menu options.

### Code Explanation

- **Setup:**
  - Initializes the OLED display, DHT sensor, and RTC module.
  - Configures the buttons as input with pull-up resistors.
  
- **Loop:**
  - Displays the selected information based on the current menu selection.
  - Checks for button presses to update the menu selection.

- **Display Functions:**
  - `displayTimeDate()`: Shows the current time and date on the OLED.
  - `displayTemperatureHumidity()`: Shows the current temperature and humidity on the OLED.
  - `displayMenu()`: Shows the menu with available options.

## Conclusion

This project provides a simple and interactive way to display time, date, temperature, and humidity using an OLED display, DHT11 sensor, and RTC module. The easy-to-use navigation buttons make it user-friendly and convenient to switch between display modes.
