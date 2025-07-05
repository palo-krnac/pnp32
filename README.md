# pnp32
Motion controller for openpnp based on ESP32.


🎯 OpenPNP Modular Motion Controller

High-performance, fully modular motion controller for advanced Pick & Place machines. Designed to seamlessly integrate with OpenPnP and support direct SPI-controlled stepper drivers for ultra-smooth and precise motion.
🚀 Key Features

    ✅ ESP32-S3 or Teensy-based core — powerful microcontroller with floating-point, high-speed I/O, and robust connectivity

    ✅ Native SPI motion control — supports TMC5160, TMC5130, PowerSTEP01, and L6470 drivers without STEP/DIR emulation

    ✅ Flexible architecture — single-board and multi-board configurations for scalable machine designs

    ✅ Built-in CAN bus — robust communication between multiple controllers or modular head units

    ✅ RS485 interface — control feeder modules or additional peripherals with industrial reliability

    ✅ Integrated vacuum and air control — including pressure/vacuum sensing and smart valve control

    ✅ Advanced lighting and vision control — supports multi-channel LED lighting, camera triggers, and auxiliary outputs

    ✅ USB-to-Serial bridge — direct communication with OpenPnP software

🧩 Modifications & Configurations
🔹 Modification 1: Single Board Setup

    All stepper motor drivers for all axes integrated on one board

    Centralized control logic with all communication interfaces (CAN, RS485, USB)

    Simplified wiring for smaller or simpler machines

🔹 Modification 2: Dual Board Modular Setup
🟦 Main Controller Board

    Controls primary machine axes: X, Y, or duplicated X + single Y (up to 3 axes)

    Handles all communication interfaces (CAN, RS485, USB)

    Acts as the master motion controller

🟩 Head Controller Board

    Mounted on the machine head(s), connected via CAN bus

    Controls additional axes: Z, A, B, C, D, E, F

    Supports air/vacuum control, pressure/vacuum sensing

    Controls head lighting, glue/paste dispensers

    Available in two variants:

        2-head version: for two nozzles

        4-head version: supports four nozzles or combination of nozzles & dispensers

⚙️ G-code Configuration & Machine Parameters

All key motion parameters and hardware configurations are set directly from OpenPnP via custom G-code commands. This enables easy tuning, calibration, and reconfiguration without modifying firmware or recompiling code.
💬 Supported G-code Commands
G-code	Description	Example Usage
M350	Set microstepping for each axis	M350 X16 Y16 Z32
M906	Set motor current (mA) per axis	M906 X1000 Y1000 Z800
M92	Set steps per mm (axis scaling)	M92 X80 Y80 Z400
M211	Enable/disable software endstops	M211 S1
M208	Set axis travel limits (soft limits)	M208 X0:300 Y0:250 Z0:150
M569	Configure driver direction inversion	M569 X0 Y1 Z0
M912	Set driver sense resistor calibration	M912 X20 Y20 Z18
M913	Set dynamic current scaling %	M913 X70 Y70 Z80
M950	Configure pin assignments for outputs	M950 P1 S0
M355	Control LED lighting intensity	M355 P1 S255
M420	Enable bed leveling or machine compensation (if used)	M420 S1
🛠 Possible Additional Configurations

    Set acceleration, max speed, and jerk per axis (future extension)

    Configure vacuum thresholds and pressure sensor calibration

    Assign specific CAN node IDs for multi-board setups

    Control glue/paste pump parameters (pulse lengths, flow rates)

    Define custom tool offsets and head calibration parameters

🛠 Board Parameters
Parameter	Value
MCU	ESP32-S3 or Teensy 4.x
Motor Drivers	SPI controlled: TMC5160, TMC5130, PowerSTEP01, L6470
Axes	Up to 10 axes total (depending on config)
Comm. Interfaces	CAN bus, RS485, USB-Serial
Peripheral Control	Air/vacuum valves, pressure sensors, lighting
Voltage	12–48 V supply for motors
Safety	E-stop input, software limits, watchdog
💻 Software

    Developed in PlatformIO

    Custom motion control firmware optimized for SPI-based drivers

    CAN bus stack for modular multi-board communication

    Feeder and peripheral control via RS485

    OpenPnP-compatible serial communication with dynamic G-code support

💡 Highlights

    Ultra-precise motion with direct register-level SPI control (no missed steps)

    Full machine configuration and tuning via standard G-code from OpenPnP

    Modular design ready for scalable, high-end Pick & Place machines

    Multi-head and multi-function ready: placement, glue dispensing, paste dispensing

    Designed for tinkerers, prosumers, and professional machine builders alike

📦 Getting Started

1️⃣ Clone this repository
2️⃣ Install PlatformIO and dependencies
3️⃣ Configure your hardware via G-code or config.h for base defaults
4️⃣ Flash the firmware to your controller board
5️⃣ Connect to OpenPnP and start tuning!
🛡 License

This project is open-source under the MIT License. Contributions and pull requests are warmly welcome!
❤️ Credits & Inspiration

Inspired by OpenPnP community, modern motion control concepts, and the open hardware spirit. Special thanks to Trinamic (TMC), STMicroelectronics (PowerSTEP01), and the global DIY PnP community.
✨ Screenshots & Diagrams

(Insert board design images, modular connection diagrams, example machine setups, head modules, etc.)
✅ Ready to go? Let's build next-level OpenPnP machines together!