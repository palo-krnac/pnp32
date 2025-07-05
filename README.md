# pnp32
Motion controller for openpnp based on ESP32.


# Features
  - Support openPNP V2
  - 
  - Use USB upload firmware
  - Printing by connect wifi web control


# Board parameters
  - MCU is ESP32-WROOM-32U, Flash: 8192K, RAM: 520K, the frequency is: 240MHz 
  - Use power dc12~24V input
  - Support power reverse connection protection and power spike protection
  - Has 2 heater end+ 1 Heater BED, 3 NTC100K: TH1, TB, TH2(Need jumper selection)
  - 2 Channel and 2 power output xh2.54-2p interface
  - 5 axis 6 motor interface(Dual Z axis in parallel)
  - STEP/DIR moode and support external for high current drives
  - Microstep settings use DIP switch
  - Has X, Y, Z, MT_DET detection interface
  - Support [3D Touch](https://www.aliexpress.com/store/group/Auto-bed-leveling-senor/1047297_516621299.html?spm=a2g0o.store_pc_groupList.pcShopHead_8325768.1_2_3)