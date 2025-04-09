# Boardoza LM75ADP Digital Temperature Sensor Breakout Board

The **Boardoza LM75ADP** is a compact digital temperature sensor breakout board designed for **precise temperature monitoring and thermal protection** in embedded systems. Built around NXP’s LM75ADP IC, this module supports **I<sup>2</sup>C communication**, features **programmable thresholds**, and integrates a **thermal watchdog** capability.

It is ideal for applications requiring accurate temperature sensing in **industrial control**, **consumer electronics**, **smart devices**, or **overtemperature protection systems**. With its small footprint and high resolution (0.125°C per LSB), the LM75ADP ensures fast and efficient thermal feedback for both data logging and active thermal management systems.

## [Click here to purchase!](https://www.ozdisan.com/maker-ve-iot-urunleri/boardoza/boardoza-modulleri/LM75ADP-BREAKOUT-BOARD/1065559)

|Front Side|Back Side|
|:---:|:---:|
|![LM75ADP Front](./assets/LM75ADP%20Front.png)|![LM75ADP Back](./assets/LM75ADP%20Back.png)

---

## Key Features

- **Wide Temperature Range:** Operates across -55°C to +125°C for industrial and embedded use.
- **High Measurement Resolution:** Outputs data in 0.125°C increments for accurate sensing.
- **Standard I<sup>2</sup>C Interface:** Communicates seamlessly with microcontrollers and processors over I<sup>2</sup>C (default address 0x48).
- **Programmable Thresholds:** Configurable high/low alarm limits with interrupt via OS pin.
- **Thermal Watchdog:** Enables autonomous system protection during overheating events.
- **Compact & Low-Power:** Minimal footprint and power-efficient for mobile and battery-powered projects.

---

## Technical Specifications

**Model:** NXP LM75ADP  
**Input Voltage:** 5V  
**Functions:** Digital temperature sensor  
**Measurement Range:** -55°C to +125°C  
**Operating Temperature:** -55°C ~ +125°C  
**Interface:** I<sup>2</sup>C (default address: 0x48)  
**Output Resolution:** 0.125°C per bit  
**Board Dimensions:** 20mm x 20mm  

---

## Board Pinout

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | VCC | Power Supply +5V |
| 2 | SCL | I<sup>2</sup>C Serial Clock Line |
| 3 | SDA | I<sup>2</sup>C Serial Data Line |
| 4 | OS | Overtemperature Shutdown Output |
| 5 | GND | Ground |

---

## I<sup>2</sup>C Addressing

| Address Name | Description |
|:---:|---|
| A0 | Digital input. User-defined address bit 0 |
| A1 | Digital input. User-defined address bit 1 |
| A2 | Digital input. User-defined address bit 2 |

> The I<sup>2</sup>C address can be changed by configuring the A0–A2 pins, allowing up to 8 devices on the same bus. The address pins (A0, A1, A2) are pulled down to GND by default, resulting in the default I²C address of 0x48. You can change the address by shorting the respective address pads on the board to set them to logical 1.

| A2 | A1 | A0 | I²C Address (Hex) |
|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0x48 (default) |
| 0 | 0 | 1 | 0x49 |
| 0 | 1 | 0 | 0x4A |
| 0 | 1 | 1 | 0x4B |
| 1 | 0 | 0 | 0x4C |
| 1 | 0 | 1 | 0x4D |
| 1 | 1 | 0 | 0x4E |
| 1 | 1 | 1 | 0x4F |

---

## Board Dimensions

<img src="./assets/LM75ADP Dimension.png" alt="LM75 Temperature Sensor" width="330"/>

---

## Step Files

[Boardoza LM75ADP.step](./assets/LM75ADP%20Step.step)

---

## Datasheet

[LM75ADP Datasheet.pdf](./assets/LM75ADP%20Datasheet.pdf)

---

## Version History

- V1.0.0 - Initial Release

---

## Support

- If you have any questions or need support, please contact <support@boardoza.com>

---

## License

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
