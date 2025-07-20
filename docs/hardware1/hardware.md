# **Hardware Overview**

Welcome to the hardware section overview.

## **Stepper drivers**
| Parameter         |   **TMC5130**  |  **TMC5160**   |  **powerSTEP01**  |
|-------------------|-----------------|---------------|-------------------|
| **Voltage**       | 46V DC          | 46V DC        | 46V DC            |
| **Current**       | 2A              | 4A            | 10A               |
| **ustepping**     | 256             | 256           | 128               |


## **Board Types**

| Parameter         |   **pnp32-MC**  |  **pnp32-MCM**   |  **pnp32-MCH**  |
|-------------------|-----------------|------------------|-----------------|
| **Processor**     | ESP32-PICO-V3   | ESP32-PICO-V3    | ESP32-PICO-V3   |
| **X-driver**      | TMC5130         | TMC5160          |                 |
| **Y-driver**      | TMC5130         | TMC5160          |                 |
| **Z-driver**      | TMC5130         | TMC5160          | TMC5130         |
| **A-driver**      | TMC5130         |                  | TMC5130         |
| **B-driver**      | TMC5130         |                  | TMC5130         |
| **Voltage**       | 12-46V DC       | 12-46V DC        | 12-46V DC       |
| **VAC pump**      | 1 x PWM 24V DC  | 1 x PWM 24V DC   |                 |
| **AIR pump**      | 1 x PWM 24V DC  | 1 x PWM 24V DC   |                 |
| **VAC solenoid**  | 2 x DO 24V DC   |                  | 2 x DO 24V DC   |
| **AIR solenoid**  | 2 x DO 24V DC   |                  | 2 x DO 24V DC   |
| **Light**         | 2 ch. Neopixel  | 2 ch. Neopixel   | 2 ch. Neopixel  |
| **VAC sensor**    | 2 x VAC sensor  |                  | 2 x VAC sensor  |
| **Safety**        | DI - ESTOP      | DI - ESTOP       | DI - ESTOP      |
| **USB-serial**    | 1 x             | 1 x              | 1 x             |
| **CANopen**       | 1 X             | 1 x              | 1 x             |
| **RS485**         | 1 x             | 1 x              |                 |

    TMC5130 - 2A max.
    TMC5160 - 4A max.


