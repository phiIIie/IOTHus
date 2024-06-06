# Arduino Menu System

This Arduino program implements a menu system on an OLED display, allowing users to navigate between displaying the current time/date and temperature/humidity readings from a DHT11 sensor.

## Features

- Displays a menu with options to view time/date or temperature/humidity.
- Utilizes buttons to navigate the menu and select options.
- Displays the current time and date fetched from an RTC module.
- Retrieves temperature and humidity readings from a DHT11 sensor.
- Supports navigating back to the main menu from any screen.

## Hardware Requirements

- Arduino board (e.g., Arduino Zero)
- OLED display (128x64 pixels)
- DHT11 temperature and humidity sensor
- RTC module (DS3231)

## Libraries Used

- `SPI.h` (1.8.14)
- `Wire.h` (1.8.14)
- `Adafruit_GFX.h` (1.11.9)
- `Adafruit_SSD1306.h` (2.5.10)
- `DHT.h` (1.4.6)
- `RTClib.h` (2.1.4)

## Setup Instructions

1. Connect the OLED display, DHT11 sensor, and RTC module to the Arduino board according to the pin configurations in the code.
2. Install the required libraries (listed above) in your Arduino IDE.
3. Upload the provided code to your Arduino board.

## Usage

1. Upon startup, the OLED display will show a menu with options:
   - **1. Time/Date**: Displays the current time and date.
   - **2. Temp/Humidity**: Displays the current temperature and humidity readings.
2. Use the buttons connected to the Arduino (button1, button2, and button3) to navigate between menu options:
   - Press button1 to move up in the menu.
   - Press button2 to move down in the menu.
   - Press button3 to select an option from the menu or return to the menu from any screen.
3. Follow the on-screen instructions to view the desired information.

## Author

Phillip Marek Hansen

## Notes

- Ensure all required libraries are properly installed in your Arduino IDE to avoid compilation errors.
- Adjust pin configurations in the code if your hardware setup differs from the default configuration.
