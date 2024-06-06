#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <RTClib.h>

// Define OLED display
#define SCREEN_WIDTH 128 // OLED display width in pixels
#define SCREEN_HEIGHT 64 // OLED display height in pixels
#define OLED_RESET 4 // Reset pin
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define DHT sensor pin and type
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define buttons
#define button1 5
#define button2 6
#define button3 7

// RTC
RTC_DS3231 rtc;

// Menu selection
int menuSelection = 1; // 1: Time/Date, 2: Temp/Humidity
int currentScreen = 0; // 0: Menu, 1: Time/Date, 2: Temp/Humidity

// Days of the week
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;) // Don't proceed, loop forever
      ;
  }

  // Initialize DHT sensor
  dht.begin();

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  // Set button pins as input with pull-up resistors
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void loop() {
  // Display menu or selected information based on menuSelection
  switch (currentScreen) {
    case 0:
      displayMenu();
      break;
    case 1:
      displayTimeDate();
      break;
    case 2:
      displayTemperatureHumidity();
      break;
  }

  // Check button presses
  if (digitalRead(button1) == LOW) {
    if (currentScreen == 0) {
      menuSelection--;
      if (menuSelection < 1) {
        menuSelection = 2; // Wrap around to last option
      }
    } else {
      currentScreen = 0; // Go back to menu from any screen
    }
    delay(200); // Debounce delay
  }

  if (digitalRead(button2) == LOW) {
    if (currentScreen == 0) {
      menuSelection++;
      if (menuSelection > 2) {
        menuSelection = 1; // Wrap around to first option
      }
    } else {
      currentScreen = 0; // Go back to menu from any screen
    }
    delay(200); // Debounce delay
  }

  if (digitalRead(button3) == LOW) {
    if (currentScreen == 0) {
      currentScreen = menuSelection; // Select option from menu
    } else {
      currentScreen = 0; // Go back to menu
    }
    delay(200); // Debounce delay
  }
}

void displayTimeDate() {
  DateTime now = rtc.now();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  String formattedTime = "";
  if (now.hour() < 10) {
    formattedTime += "0";
  }
  formattedTime += String(now.hour());

  formattedTime += ":";

  if (now.minute() < 10) {
    formattedTime += "0";
  }
  formattedTime += String(now.minute());

  formattedTime += ":";

  if (now.second() < 10) {
    formattedTime += "0";
  }
  formattedTime += String(now.second());

  display.print(formattedTime);
  display.println();
  display.println(daysOfTheWeek[now.dayOfTheWeek()]);
  display.print(now.day(), DEC);
  display.print("/");
  display.print(now.month(), DEC);
  display.print("/");
  display.print(now.year(), DEC);
  display.display();
}

void displayTemperatureHumidity() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  if (isnan(temperature) || isnan(humidity)) {
    display.println(F("Error"));
    display.println(F("reading"));
    display.println(F("DHT11"));
  } else {
    display.print(F("Temp: "));
    display.print(temperature);
    display.println(F(" C"));

    display.print(F("Hum: "));
    display.print(humidity);
    display.println(F(" %"));
  }

  display.display();
}

void displayMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.println("Menu:");
  display.setCursor(0, 16);
  display.println("1. Time/Date");
  display.setCursor(0, 32);
  display.println("2. Temp/Humidity");

  // Highlight selected option with a box
  switch (menuSelection) {
    case 1:
      display.drawRect(0, 16, 128, 8, WHITE); // Draw box for "Time/Date"
      break;
    case 2:
      display.drawRect(0, 32, 128, 8, WHITE); // Draw box for "Temp/Humidity"
      break;
  }

  display.display();
}
