# Flappy Bird - Arduino Game 🎮

An interactive implementation of the classic **Flappy Bird** game using an **Arduino Uno** and a **128×64 OLED display**.

## Project Description

This project recreates the popular Flappy Bird game on an Arduino Uno equipped with a 128×64 SSD1306 OLED display. The player controls the bird's vertical position using a potentiometer and must avoid randomly generated obstacle columns. A push button allows the game to be restarted after a Game Over.

## Features

- ✅ Fully functional Flappy Bird game on an OLED display
- ✅ Analog bird control using a potentiometer (Pin A0)
- ✅ Custom bitmap graphics
- ✅ Score tracking system
- ✅ Progressive difficulty (increasing obstacle speed)
- ✅ Game Over screen displaying the final score
- ✅ Countdown before the game starts (3, 2, 1)
- ✅ Dynamo Electronics startup logo

## Components Used

- **Arduino Uno** – Main microcontroller
- **SSD1306 OLED Display** – 128×64 pixels (I2C communication)
- **10 kΩ Potentiometer** – Controls the bird's vertical movement
- **Push Button** – Restarts the game
- **Breadboard** – Circuit assembly
- **Jumper Wires** – Electrical connections

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| OLED SDA | A4 (I2C) |
| OLED SCL | A5 (I2C) |
| Potentiometer | A0 |
| Reset Button | 2 |
| OLED RESET | 4 |

## Required Libraries

```cpp
#include <Wire.h>              // I2C communication
#include <Adafruit_GFX.h>      // Graphics library
#include <Adafruit_SSD1306.h>  // SSD1306 OLED driver
```

### Installing the Libraries

1. Open **Arduino IDE**
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for **Adafruit SSD1306**
4. Install both:
   - Adafruit SSD1306
   - Adafruit GFX Library

## How to Play

1. Upload the sketch to your **Arduino Uno**.
2. Connect the components according to the circuit diagram.
3. Power the Arduino.
4. Wait for the startup screen with the Dynamo Electronics logo.
5. Move the potentiometer to control the bird's height.
6. Avoid the obstacle columns.
7. Earn **1 point** for every pair of columns successfully passed.
8. If the bird collides with an obstacle, the **Game Over** screen will appear.
9. Press the push button to restart the game.

## Game Mechanics

### Bird Movement

- **Potentiometer (A0):** Controls the bird's vertical position.
- Input range: **0–1023**
- Screen position: **0–45 pixels**

### Obstacles

- Randomly generated obstacle columns.
- **30-pixel gap** between the upper and lower columns.
- Movement speed increases after each obstacle passed.

### Collision Detection

A collision is detected when the bird touches any obstacle within the defined collision area, resulting in an immediate **Game Over**.

### Scoring

- +1 point for each obstacle pair successfully passed.
- Final score displayed on the Game Over screen.
- Difficulty increases progressively with speed.

## Code Structure

```text
setup()          Initializes the OLED display and hardware
loop()           Main game loop
dibujoLogo()     Displays the startup logo
conteo()         3-2-1 countdown before the game starts
gameOver()       Displays the Game Over screen and waits for restart
flashSequence()  Auxiliary demonstration function
```

## Graphics Included

- **myBitmap6** – Small bird sprite (20×19 pixels)
- **myBitmap7** – Dynamo Electronics logo (61×58 pixels)
- **myBitmap** – Large bird sprite for the startup screen (40×40 pixels)

## Future Improvements

- 🔊 Add sound effects using a buzzer
- 🏆 Save the highest score in EEPROM
- 🎨 Add more animations and sprite designs
- 📊 Display the current speed during gameplay
- 🎮 Include multiple difficulty levels
- 📱 Support motion control using an accelerometer or gyroscope

## Technical Specifications

- **OLED I2C Address:** `0x3C` (configurable)
- **I2C Speed:** 400 kHz (default)
- **Initial Game Speed:** 1 pixel/frame
- **Speed Increment:** +3 after each obstacle
- **Refresh Rate:** Approximately 60–100 FPS (depending on game speed)

## Troubleshooting

| Problem | Solution |
|---------|----------|
| OLED display does not turn on | Check the I2C wiring (SDA/SCL). |
| Bird does not move | Verify the potentiometer connection to A0. |
| Game does not restart | Check the push button connected to pin 2. |
| Distorted graphics | Press the Arduino RESET button. |

## Technologies

- Arduino Uno
- Arduino IDE
- Embedded Systems
- C/C++
- SSD1306 OLED Display
- I2C Communication
- Adafruit GFX Library
- Adafruit SSD1306 Library
- Game Development
- Digital Electronics
```
