# Web Server Lights Control

This project is a simple web server running on an ESP32 that allows you to control two lights and two fans using a relay module. The web interface lets you turn the devices on and off from any browser on the same network.

## Features

- Control two lights
- Control two fans
- Web-based interface
- Uses a relay module for safe switching

## Hardware Requirements

- ESP32 board
- Relay module (2-channel or 4-channel)
- 2 lights (or simulated using LEDs)
- 2 fans (or simulated using additional LEDs)
- Jumper wires
- Breadboard (optional)

## Pin Configuration

- Light 1: GPIO 16
- Light 2: GPIO 17
- Fan 1: GPIO 18
- Fan 2: GPIO 19
- Relay module connected to the corresponding GPIO pins

## Software Requirements

- MicroPython installed on the ESP32
- Any IDE that supports MicroPython (like Thonny, uPyCraft, or the Arduino IDE)

## Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/KUMARESAN-PANDA/WEB_SERVER_LIGHT_CONTROL
