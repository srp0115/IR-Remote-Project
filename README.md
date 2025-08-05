# IR-Remote-Project

This project implements a basic Arduino-based system that uses an IR remote to control three LEDs and display status messages on a 16x2 LCD screen. The project demonstrates basic hardware interaction with IR receivers, LEDs, and character LCDs using the Arduino platform.

## Features

- **Control LEDs with an IR Remote:**  
  - Button 0: Turn off all LEDs.
  - Button 1: Toggle LED 1.
  - Button 2: Toggle LED 2.
  - Button 3: Toggle LED 3.
  - FUNC/STOP: Clear the LCD display.

- **Display Status on LCD:**  
  Whenever a button is pressed, a relevant message is shown on the LCD.

## Hardware Requirements

- Arduino board (any compatible model)
- IR Receiver Module (connected to digital pin 5)
- IR Remote (with at least buttons 0, 1, 2, 3, FUNC/STOP)
- 3 LEDs (connected to digital pins 12, 11, and 10)
- 16x2 LCD (connected as follows):
  - RS: A5
  - E:  A4
  - D4: 6
  - D5: 7
  - D6: 8
  - D7: 9
- Resistors as needed for LEDs and IR receiver
- Breadboard and jumper wires

## Libraries Used

- [IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
- [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)

Install these libraries via the Arduino Library Manager if not already present.

## How It Works

1. **Setup:**  
   - Initializes the IR receiver, LCD, and LED pins.
2. **Loop:**  
   - Waits for IR commands.
   - Decodes button presses and performs the corresponding action:
     - Turns off all LEDs or toggles individual LEDs.
     - Updates the LCD with the current action/status.

## Pin Mapping

| Component      | Arduino Pin |
|----------------|------------|
| IR Receiver    | 5          |
| LED 1          | 12         |
| LED 2          | 11         |
| LED 3          | 10         |
| LCD RS         | A5         |
| LCD E          | A4         |
| LCD D4         | 6          |
| LCD D5         | 7          |
| LCD D6         | 8          |
| LCD D7         | 9          |

## Usage

1. Upload the `IRremoteproject.ino` sketch to your Arduino board.
2. Wire the components as described above.
3. Power on the Arduino.
4. Use your IR remote to control the LEDs and display.

## Customization

- You can remap the IR button codes to match your specific remote by updating the `#define IR_BUTTON_*` values in the code.
- Add more actions or output devices as desired by extending the `switch` statement in the main loop.

## License

This project is open source and free to use under the MIT License.

