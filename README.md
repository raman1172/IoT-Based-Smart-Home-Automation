# IoT-Based Smart Home Automation

A smart home system using ESP8266 and Blynk IoT platform to control appliances remotely and monitor temperature & humidity in real-time.

## Features
- Remote control of appliances (e.g., lights, fans)
- Real-time temperature and humidity monitoring
- Wireless communication over WiFi
- User-friendly mobile app interface using Blynk

## Components Used
- ESP8266 NodeMCU Board
- DHT11 Temperature & Humidity Sensor
- Relay Module (to control appliances)
- Jumper wires and Breadboard

## Circuit Diagram
Refer to `docs/circuit_diagram.png` for wiring details.

## Setup Instructions
1. Install Arduino IDE.
2. Add ESP8266 board support via Board Manager.
3. Install Blynk and DHT sensor libraries.
4. Update `smart_home.ino` with your WiFi SSID, password, and Blynk Auth Token.
5. Upload the firmware to the ESP8266 board.
6. Configure the Blynk app on your mobile device using the provided template ID and Auth Token.

## Usage
- Use the mobile app to toggle the relay (appliance ON/OFF).
- View live sensor data for temperature and humidity on the app.
- Relay automatically switches an appliance connected via the relay module.

## Folder Structure
- `firmware/` - Arduino source code `smart_home.ino`
- `docs/` - Circuit diagram and wiring instructions
- `outputs/` - Screenshot of Blynk app interface showing sensor data and controls

## License
This project is open-source under the MIT License.
