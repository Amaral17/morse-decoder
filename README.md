# Morse Code Translator with ESP32

A simple Morse code translator built with an ESP32, two push buttons, and an I2C LCD display.

The project translates Morse code sequences into alphabetic characters and displays the decoded message on an LCD screen. The design follows the original telegraph concept by using a single input button for Morse code entry, while a second button is provided to clear the display for improved usability.

## Features

- Morse code input using a single button
- Real-time translation to alphabetic characters
- LCD display output
- Clear screen functionality using a dedicated button
- ESP32-based implementation
- Fully simulated in Wokwi

## Hardware Components

- ESP32
- 16x2 I2C LCD Display
- 2 Push Buttons
- Breadboard and jumper wires

## How It Works

- The red button is used to enter Morse code signals.
- Short presses represent dots (`.`).
- Long presses represent dashes (`-`).
- The system decodes each Morse sequence into its corresponding letter.
- Decoded characters are displayed on the LCD screen.
- The blue button clears the display.

## project's simulation:

https://wokwi.com/projects/455127461757803521
